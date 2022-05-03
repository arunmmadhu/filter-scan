#! /usr/bin/env python

import sys

from string import *
import os
import cx_Oracle

from datetime import timedelta, datetime, tzinfo
import time

import getpass

# ---------------------------------------------------------------------------
class connectDB:
    def __init__(self):
        magic='Read_gif_mnl1%'
        connect= 'cms_emu_fast_r/' + magic + '@cmsr'
        self.orcl = cx_Oracle.connect(connect)
        self.curs = self.orcl.cursor()
    def cursor(self):
        return self.curs

# ---------------------------------------------------------------------------


if __name__ == "__main__":
        
    if(len(sys.argv)<2):
        print "usage: python ", sys.argv[0], " ch <HV> #where ch=1 for ME1/1 and ch=2 for ME2/1"
        exit()
        
    if(sys.argv[1]=='1'):
        ME_state   = "ME11_state" 
        HV_ME      = "HV_ME11"
        HV_SETTING = "HV_SETTING1"
    elif(sys.argv[1]=='2'):
        ME_state   = "ME21_state" 
        HV_ME      = "HV_ME21"
        HV_SETTING = "HV_SETTING2"
    else:
        print "usage: python ", sys.argv[0], " ch, HV #where ch=1 for ME1/1 and ch=2 for ME2/1"
        exit()
    HVcond = ""
    if( len(sys.argv)>2 ):
        if (sys.argv[2]=='HV0' or sys.argv[2]=='HV1'):
            HVcond = """ and """ + HV_SETTING + """ like '%""" + sys.argv[2] + """%' """
        else:
            HVcond = """ and """ + HV_ME + """=""" + sys.argv[2] + """ """
            
    print "connecting..."
    orac    = connectDB()
    curs = orac.cursor()
    print "ok"
    

    cmd  = """ select MEASUR_TYPE, RUN_TYPE, MEASUR_NUM, TIME_SAVE, TEST_START, %s, %s, %s, FILE_NAME, RUN_COMMENT from gif_ageing_tab  where %s='on'"""%(ME_state, HV_ME, HV_SETTING, ME_state)
    cmd += HVcond
    cmd += """order by MEASUR_NUM """
    #print cmd

    curs.execute(cmd)
    rows  = curs.fetchall()
    if(len(rows)>0):
        print "%10s %30s %20s %25s %100s\t%s" % ("A#", "rec date", "start time", "HV", "file name", "comment")
    for data in rows:
        if(data[0]=="Dark rate" and data[1]=="test 11"):
            #print data
            HV = ""
            if(data[6]==None):
                HV = data[7]
            else:
                HV = data[6]
            comment = ""
            if(data[9]!=None):
                comment = ' '.join(data[9].rstrip('\r\n').split())
            print "%10d %30s %20s %25s %100s\t%s" % (data[2], data[3], data[4], HV, data[8], comment)
        
    print "done"
