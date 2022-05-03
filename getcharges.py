from datetime import datetime
import re
import argparse

parser = argparse.ArgumentParser(description='copy and paste dose information table from http://pnpi-cms-l1.cern.ch:8080/CSCdose/ to an input text file (--chargevtime). This macro makes it more readable and selects only the charges corresponding to dates you care about (--inmeas) and outputs to a text file (--outfile) for easier use. See default files for the formats used for that respective variable')
parser.add_argument('--chargevtime', action ='store', default='chargevtime.txt', type=str, help="Text file where you paste the Table of charge vs time data found here: http://pnpi-cms-l1.cern.ch:8080/CSCdose/ \n DEFAULT: chargevtime.txt")
parser.add_argument('--inmeas', action ='store', default='gifRates/TMB_HV0_me11_2pct.txt', type=str, help="Text file with desired measurement info. Just make sure the second column is the date in the format: DD-MTH-YYYY, where MTH is the 3 letter abbreviation for the month. \n DEFAULT: gifrates/TMB_HV0_me11_2pct")
parser.add_argument('--strip', action ='store_true', default=False, help="Use this option if getting charge info for strip to strip measurements - NOTE: Date formatted differently, see strip/datame11/stripdates.txt for example (YYYY_MMDD) \n DEFAULT: False")
parser.add_argument('--endpreamble', action ='store', default=6, type=int, help="if your list of measurements has a preamble before it gets to the data table, store the line number where the table starts in this variable. \n DEFAULT: 6 (The length of the preamble in gifRates/TMB_HV0_me11_2pct.txt))")
parser.add_argument('--outfile', action ='store', default='gifRates/charges_me11_2pct.txt', type=str, help="Text file where the parsed and much more legible charge info is stored\n DEFAULT: gifRates/charges_me11_2pct.txt")

args = parser.parse_args()

numlines = sum(1 for line in open(args.inmeas, "r"))

dates = []

if not args.strip:
    with open(args.inmeas, "r") as f0:
        for linenum, line in enumerate(f0):
            if linenum < args.endpreamble: continue
            for index, item in enumerate(line.split()):
                if index == 1:
                    dates += [datetime.strptime(item, "%d-%b-%Y")]
        f0.close()
else:
    with open(args.inmeas, "r") as f0:
        for linenum, line in enumerate(f0):
            if linenum < args.endpreamble: continue
            datesearch = re.search('\d\d\d\d_\d\d\d\d', line).group(0)
            dates += [datetime.strptime(datesearch, "%Y_%m%d")]
        f0.close()

subline = 0
qtot = []
t_q = []
ti = 0
iline = -1
# importing charge and time data for me11
with open(args.chargevtime, "r") as f2:
    for linenum, line in enumerate(f2):
        if "TDatime" in line:
            datestr = line[line.find("TDatime("):line.find(");")+1]
            t_q += [datetime.strptime(datestr, 'TDatime(%Y, %m, %d, %H, %M, %S)')]
        if "q1m[i] =" in line:
            # if sought substring is at the end of a line, then the charge is simply the next line
            if len(line) - line.find("q1m[i] =") < 10:
                #print "its on the next line: ", linenum+1
                iline = linenum+1
            else:
                qstr = line[line.find("q1m[i] = ")+9:len(line)-2]
                qtot += [float(qstr)]
        elif "q1m[i] =" not in line and "TDatime" not in line:
            # cashing in on the previously found substring
            if iline == linenum:
                qtot += [float(line.replace(';',''))]
        if len(t_q) > len(qtot)+1:
            print "problem here: "
            print linenum
            quit()
        #if linenum > 1000:
        #    quit()
qout = open(args.outfile, 'w')
j=0
for date in dates:
    for k in range(j,len(t_q)):
        if t_q[k].day == date.day and t_q[k].month == date.month and t_q[k].year == date.year:
            qout.write(str(qtot[k])+'\n')
            j=k
