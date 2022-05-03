#!/bin/bash
workdir=$PWD
filename=$1
measnum=$2
outdir=${3:-$workdir/me11data/2pct}
maxevents=${4:-60000}
# you want this to be set larger than the number of events in your DQM plot for test 11 - this is just the number of events to be converted, while the analyzer runs over all events and automatically skips empty ones.
# You definitely will want your number of events in the DQM plot to exceed 40000 as well, otherwise you need to redo the measurement
ConvertRaw() {
    cmsRun $workdir/python/readFile.py inputFile=$1 outputFile=$2 maxEvents=$3
}

Analyze() {
    cmsRun $workdir/python/analyzeFilterScanFromDigis.py inputFile=$1 maxEvents=-1
    mv histos.root $2
}
mkdir -p $outdir
#Check where it's stored first! If it was moved to eos storage for example, then SCP isn't gonna work. Comment it out and uncomment the cp line below
#scp localuser@$filename $outdir/${measnum}.raw
wget -c http://emugif6.cern.ch/data/current/${filename}.raw -O $outdir/${measnum}.raw
#cp $filename $outdir/${measnum}.raw
ConvertRaw $outdir/${measnum}.raw $outdir/${measnum}_raw.root $maxevents
# some module called by readFile.py seems to change the desired output file name by inserting _numEvent$measnum at the end, so we need to account for that
# rather than change something and need to waste a bunch of time propagating it through code I am unfamiliar with, I am instead doing this simpler option
Analyze $outdir/${measnum}_raw_numEvent${maxevents}.root ${outdir}/A${measnum}.root 
rm $outdir/${measnum}_raw_numEvent${maxevents}.root $outdir/${measnum}.raw
