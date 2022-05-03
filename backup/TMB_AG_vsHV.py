#! /usr/bin/env python

import sys

from string import *
import os
import cx_Oracle

from datetime import timedelta, datetime, tzinfo
import time

import getpass

# ---------------------------------------------------------------------------
def isfloat(text):
    try:
        int(text)
        return True
    except (ValueError, TypeError) as e:
        pass

    try:
        float(text)
        return True    
    except (ValueError, TypeError) as e:
        pass

    return False

class connectDBbookkeeping:
    def __init__(self):
        magic='Read_gif_mnl1%'
        connect= 'cms_emu_fast_r/' + magic + '@cmsr'
        print "connecting to bookkeeping db..."
        self.orcl = cx_Oracle.connect(connect)
        self.curs = self.orcl.cursor()
        print "                                       ...done"        
        
    def __del__(self):
        print "\n\nclosing connection to bookkeeping db..."
        self.orcl.close()
        print "                                       ...done"        
        
    def cursor(self):
        return self.curs

class connectDBdose:
    def __init__(self):
        magic='HV_pvss_emu1'
        connect= 'cms_emu_hvwrite_r/' + magic + '@cmsr'
        print "connecting to dose db..."
        self.orcl = cx_Oracle.connect(connect)
        self.curs = self.orcl.cursor()
        print "                    ...done"
        
    def __del__(self):
        print "\n\nclosing connection to dose db..."
        self.orcl.close()
        print "                                ...done"        
        
    def cursor(self):
        return self.curs


listofinterest=['0ALCT: alct0 valid pattern flag received',
                        '13CLCT: Pretrigger',
                        'TMB:  TMB clct*alct matched trigger']

Voltages1 = [0, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 2950, 3000]
Voltages2 = [0, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900]
HVref     = 'HV0'

wireLengthME11 = 20468; # cm                                       
wireLengthME21 = 55428; # cm                                       

#Voltages1 = [2900]
#Voltages2 = [3600]

# excluded:
#  - corrapted TMBdump records
#  - high electronics noise 0V runs
#  - beam
#  - runs between [29.09.16-02.11.16] if L1A is not 0 (automated periodic dumper was allowed during the test27s running and additional TMBdump is taken by hand had lower rate)
badRuns1=[3149,   3153, 3216, 3400,   3157, 3220, 3404,   3161, 3224, 3408,   3228,3412,   3169,3232,3416,  3236,3420,   3177,   3459,   3256,3436,3461,   3260,3440,   1716,3264, 3458] # does not include HV1
badRuns2=[1627,2459,2461,   3271,3339,   3343,3964,  3098,   3287,   3291,   3110,3363,   3114,   3053,3303,   3383,   3126]

def checkRecTime(datetimeTimeSave, stringTestStart):
    theDate = datetimeTimeSave
    if(len(stringTestStart)>7):
        try:
            theDate = datetime.strptime(stringTestStart[:8], '%d.%m.%y')            
        except (ValueError) as e:
            pass
    return theDate


class oneHVrecord:
    def __init__(self, cursor, chamber):
        self.aRecordAtHV = {} # 'date':[ALCT, CLCT, TMB]
        self.HV = -1
        self.cursor = cursor
        if(chamber==1):
            self.ME_state   = "ME11_state" 
            self.HV_ME      = "HV_ME11"
            self.HV_SETTING = "HV_SETTING1"
            self.badRuns    = badRuns1
        elif(chamber==2):
            self.ME_state   = "ME21_state" 
            self.HV_ME      = "HV_ME21"
            self.HV_SETTING = "HV_SETTING2"
            self.badRuns    = badRuns2
        else:
            print "unknown chamber number, exiting..."
            exit
        
    def getRecod(self, HV):
        self.HV = HV
        
        
        ##Tables gif_table (Tests DB, "blue") and gif_ageing_tab (Ageing DB,"rose")
        cmd  = """ select MEASUR_NUM, TIME_SAVE, TEST_START, %s, %s, %s, RUN_COMMENT, SOURCE_STATE,  ATTENUAT_UP, TMB_DUMP_TIME from gif_ageing_tab  where  MEASUR_TYPE='Dark rate' and RUN_TYPE='TMB dump (test 27s)' and %s='on' """%(self.ME_state, self.HV_ME, self.HV_SETTING, self.ME_state)
        if(HV=='HV0'):
            cmd += " and " + self.HV_SETTING + """ like '%""" + HV + """%' """
        else:
            cmd += " and " + self.HV_ME + """=""" + str(HV)
        cmd += """ order by MEASUR_NUM"""
        print cmd

        self.cursor.execute(cmd)
        rows  = self.cursor.fetchall()
        if(len(rows)>0):
            print "\n\n%5s %25s %25s %25s %6s %5s" % ("A#", "save time", "start time", "HV", "SRCdwn", "t[sec]"),
            for tmbs in listofinterest:
                print "%12s"%tmbs.split()[0],
            print "   comment"

            for data in rows:
                if int(data[0]) in self.badRuns:
                    continue
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
                
                print "%5d %25s %25s %25s %6s %5s" % (data[0], data[1], data[2], HV, source, data[9]),
                datevar = datetime.strptime(data[1], '%d-%b-%Y , %H:%M:%S')
                if(data[2]!=None):
                    datevar = checkRecTime(datevar, data[2])
                datevar = datevar.replace(hour=12, minute=0, second=0)
                
                self.aRecordAtHV[datevar]=[-1,-1,-1]
                cmd  = """ select TMB_DUMP_COMMENT from gif_ageing_tab where MEASUR_NUM=%s """%(data[0])
                #print cmd
                self.cursor.execute(cmd)
                datatmb=""
                for frows in self.cursor:
                    #print frows
                    for col in frows:
                        try:
                            datatmb=col.read().split('\n')
                        except:
                            print "=============== can't read tmbdump"
                indx = 0
                for countstr in listofinterest:
                    thestr = next((st for st in datatmb if countstr in st),None)#.split()
                    count  = "???"
                    if(thestr!=None):
                        count = thestr.split()                
                    print "%12s"%count[len(count)-1],
                    if(isfloat(count[len(count)-1])):
                        self.aRecordAtHV[datevar][indx] = float(count[len(count)-1])
                    indx = indx+1
                #print "   ", datevar, "   ", comment
                print "   ", comment
                
            print "done"
            
            
# ---------------------------------------------------------------------------
def createMapOfRateData(chamber):
            
    Voltages = Voltages1
    if(chamber==2):
        Voltages = Voltages2
        
    allRecords   = {}
    fullDateList = []
    Voltages.append(HVref)
    
    orac = connectDBbookkeeping()
    curs = orac.cursor()
    for HV in Voltages:
        allRecords[HV] = oneHVrecord(curs, chamber)        
        allRecords[HV].getRecod(HV)
        for aDate in allRecords[HV].aRecordAtHV.keys():
            if not(aDate in fullDateList):
                fullDateList.append(aDate)
    del orac

    return allRecords, fullDateList

# ---------------------------------------------------------------------------

def createMapOfDoses(chamber, dateList, debug=False):
    aveDoses = {}

    orac = connectDBdose()
    curs = orac.cursor()
    maxSec = 1
    WL     = wireLengthME11
    if(chamber==2):
        maxSec = 3
        WL     = wireLengthME21
        
    for aDate in dateList:
        ok   = True
        dose = 0
        if(debug):
            print aDate.strftime('%d.%m.%Y'), "\t",
        for L in range(2,6):
            for S in range(1,maxSec+1):
                cmd  = """select value from (select value, version_id from accumulated_currents where chamber=%d and layer=%d and sector=%d and time_stop=TO_DATE('%s','DD.MM.yyyy') order by version_id desc) where rownum=1"""%(chamber, L, S, aDate.strftime('%d.%m.%Y'))
                #print cmd
                curs.execute(cmd)
                rows  = curs.fetchall()        
                if(len(rows)>0):
                    if(debug):
                        print "%6.2f"%(rows[0][0]/float(WL)/1000.0/4.),
                    dose+=rows[0][0]
                else:
                    ok = False
                    if(debug):
                        print "%6s"%("None"),
        if(ok):
            dose=dose/float(WL)/1000.0/4.0
        else:
            dose=-1
            
        if(debug):
            print " => %6.2f"%dose
            
        aveDoses[aDate]=dose
        
    del orac

    return aveDoses


# ---------------------------------------------------------------------------
# ---------------------------------------------------------------------------
# ---------------------------------------------------------------------------


if __name__ == "__main__":
    if(len(sys.argv)<2):
        print "usage: python ", sys.argv[0], " ch <norm> <corr0> #where ch=1 for ME1/1 and ch=2 for ME2/1"
        exit()
    chamber = int(sys.argv[1])
    norm    = (len(sys.argv)>2)
    corr0   = (len(sys.argv)>3)
    if (chamber!=1 and chamber!=2):
        print "usage: python ", sys.argv[0], " ch norm corr0 #where ch=1 for ME1/1 and ch=2 for ME2/1"
        exit()
    Voltages = Voltages1
    if(chamber==2):
        Voltages = Voltages2
        
    

    allRecords, fullDateList = createMapOfRateData(chamber)
    #print allRecords
    
    averageDoses = createMapOfDoses(chamber,fullDateList,False)
    
    dateList = sorted(fullDateList)
    
    for id in range (0,3):
        print "\n\n", listofinterest[id]
        print "%15s %19s"%("date","<dose(2-5)> [mC/cm]"),
        for HV in Voltages:
            print "%9s"%(str(HV)),
        print ""
                
        for aDate in dateList:
            print "%15s %19.2f"%(aDate.strftime('%d %b %Y'), averageDoses[aDate]), 
            for HV in Voltages:
                value = -1
                formatstr="%9d"
                if(aDate in allRecords[HV].aRecordAtHV.keys()):
                    value = allRecords[HV].aRecordAtHV[aDate][id]/10
                    if(norm):
                        if( (aDate in allRecords[HVref].aRecordAtHV.keys()) and (allRecords[HVref].aRecordAtHV[aDate][id]!=0) ):
                            if(corr0):
                                if(aDate in allRecords[0].aRecordAtHV.keys()):
                                    formatstr="%9.2f"
                                    value = (allRecords[HV].aRecordAtHV[aDate][id]-allRecords[0].aRecordAtHV[aDate][id])/allRecords[HVref].aRecordAtHV[aDate][id]                                    
                                else:
                                    value = -1
                            else:
                                formatstr="%9.2f"
                                value = allRecords[HV].aRecordAtHV[aDate][id]/allRecords[HVref].aRecordAtHV[aDate][id]                                    
                        else:
                            value = -1
                print formatstr%(value),
            print ""
        
        
    #for aDate in dateList:
        #print aDate, "\t" 
        #for HV in Voltages:
            #if (aDate in allRecords[HV].aRecordAtHV.keys()):
                #print HV,
        #print
        
    
    
