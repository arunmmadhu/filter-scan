#!/bin/bash
workdir=$PWD
inlist=${1:-$workdir/Test11_HV0_me11_2pct.txt}
outdir=${2:-$workdir/me11data/2pct}
maxevents=${3:-100000}
#input data taken from eos backup rather than original machines - see GIF++ CSC elog from MON 12.JUL.21
#otherwise will have to change cp to scp or wget or curl or something
# MaxEvents should be larger than the number of events in any of your files' DQM plots (usually of order 40000) because this is the number of events to convert from Raw
# The analyzer automatically skips empty events so setting this high isn't too much of a problem
# Since the data I am accessing at time of writing (Nov 26 2021) is only accessible through backup and I can not see the DQM plots to get an idea for how many events there are in each measurement,
# I am being conservative and setting it at 100000, when more likely 60000 or so would suffice.
ConvertRaw() {
    cmsRun $workdir/python/readFile.py inputFile=$1 outputFile=$2 maxEvents=$3
}

Analyze() {
    cmsRun $workdir/python/analyzeGifRatesFromDigis.py inputFile=$1 maxEvents=-1
    mv histos.root $2
}
mkdir -p $outdir
while read line; do
    #echo "$line"        
    measnum=$(echo "$line" | sed -n 's&^ *\([0-9]\{4\}\) \+.*&\1&p')
    #echo "$measnum"
    filename=$(echo "$line" | sed -n 's&.* \+\(\/*.*\.raw\) *.*$&\1&p')
    #echo "$filename"
    cp $filename $outdir/${measnum}.raw
    ConvertRaw $outdir/${measnum}.raw $outdir/${measnum}_raw.root $maxevents
    # some module called by readFile.py seems to change the desired output file name by inserting _numEvent$measnum at the end, so we need to account for that
    # rather than change something and need to waste a bunch of time propagating it through code I am unfamiliar with, I am instead doing this simpler option
    Analyze $outdir/${measnum}_raw_numEvent${maxevents}.root ${outdir}/A${measnum}.root $maxevents
    rm $outdir/${measnum}_raw_numEvent${maxevents}.root $outdir/${measnum}.raw

done < $inlist
