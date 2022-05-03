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
            
    listofinterest=['0ALCT: alct0 valid pattern flag received',
                    '13CLCT: Pretrigger',
                    'TMB:  TMB clct*alct matched trigger',
                    'L1A:  L1A received']
    
    print "connecting..."
    orac    = connectDB()
    curs = orac.cursor()
    print "ok"
    

    #Tables gif_table (Tests DB, "blue") and gif_ageing_tab (Ageing DB,"rose")
#    cmd  = """ select MEASUR_NUM, TIME_SAVE, TEST_START, %s, %s, %s, RUN_COMMENT, SOURCE_STATE,  ATTENUAT_UP, TMB_DUMP_TIME from gif_ageing_tab  where  MEASUR_TYPE='Dark rate' and RUN_TYPE='TMB dump (test 27s)' and %s='on' """%(ME_state, HV_ME, HV_SETTING, ME_state)
    cmd  = """ select MEASUR_NUM, TIME_SAVE, TIME_START, %s, %s, %s, RUN_COMMENT, SOURCE_STATE,  ATTENUAT_UP, TMB_DUMP_TIME from gif_table  where  RUN_TYPE='TMB dump' and %s='on' """%(ME_state, HV_ME, HV_SETTING, ME_state)

    cmd += HVcond
    cmd += """order by MEASUR_NUM """
    print cmd

    curs.execute(cmd)
    rows  = curs.fetchall()
    if(len(rows)>0):
        #print "%5s %25s %25s %25s %6s %5s %s" % ("A#", "rec date", "start time", "HV", "SRCdwn", "t[sec]", "comment")
        print "\n\n%5s %25s %25s %6s %5s" % ("A#", "start time", "HV", "SRCdwn", "t[sec]"),
        for tmbs in listofinterest:
            print "%12s"%tmbs.split()[0],
        print "   comment"

    for data in rows:
        #print data[4], data[5]
        HV = ""
        if(data[4]==None):
            HV = data[5]
        else:
            HV = data[4]
        source = 'off'
        if(data[7]=='on'):
            source = data[8]
        comment = ""
        if(data[6]!=None):
            comment = ' '.join(data[6].rstrip('\r\n').split())
        
        print "%5d %25s %25s %6s %5s" % (data[0], data[2], HV, source, data[9]),
        cmd  = """ select TMB_DUMP_COMMENT from gif_table where MEASUR_NUM=%s """%(data[0])
        curs.execute(cmd)
        datatmb=""
        for frows in curs:
            for col in frows:
                try:
                    datatmb=col.read().split('\n')
                except:
                    print "=============== can't read tmbdump"
        for countstr in listofinterest:
            thestr = next((st for st in datatmb if countstr in st),None)#.split()
            count  = "???"
            if(thestr!=None):
                count = thestr.split()                
            print "%12s"%count[len(count)-1],
        print "   ",comment
    print "done"
