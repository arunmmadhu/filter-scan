First, some conventions: test1 refer to 10% CF4, test2 refer to 2%CF4

./Test11.py <chamber#> <HV> to obtain raw data information for test 11 (anode) from database

./Test11c.py <chamber#> <HV> to obtain raw data information for test 11c (cathode - analysis not yet implemented) from database

./TMB_AG.py <chamber#> <HV> to obtain pretrigger (TMB Dump) info

In addition one needs the accumulated charge of the chamber (try http://pnpi-cms-l1.cern.ch:8080/CSCdose/ -you may need to tunnel through a cern connection). Raw charge versus time data from the database are currently stored in `chargevtime.txt`, but it is nasty and can be parsed a little nicer and sorted into just the charges you need for your analysis using ``getcharges.py``. ``python getcharges.py -h`` for usage details.

./Geometry folder is the current working geometry for this version of CMSSW and data.

**Installation & Setup [includes repository clone plus dependencies]:**

```
cmsrel CMSSW_12_0_0_pre2
cd CMSSW_12_0_0_pre2/src
cmsenv
git cms-addpkg EventFilter/CSCRawToDigi
git clone https://gitlab.cern.ch/wvetens/gif-dark-rate-and-str2str-analysis.git
cd gif-dark-rate-and-str2str-analysis
cp -f CSCDCCUnpacker.cc ../EventFilter/CSCRawToDigi/plugins/CSCDCCUnpacker.cc 
cd ../EventFilter
scramv1 b
cd -
cd gifRates
scramv1 b
```

**DarkRate:** 

SEE ALSO README IN ``gifRates`` DIRECTORY


*  **Procedure for data preparation:**

1. Unpack raw data to root files, refer to:https://twiki.cern.ch/twiki/bin/view/CMS/CSCTestBeamDataTreatment. 
    -or equivalently use ``readFile.py`` in ``gifRates/python``
2. From the output root files, one can either write one's own analysis code to extract A(C)/LCT information, or go to 3.
3. Use the ./gifRates package provided by Katerina to skim the root file for our (anode) analysis purpose. To run it: cmsRun ./python/ConfFile_cfg.py. Details are commented in the cfg file.
4. The output would be skimmed root files for direct use, which contains histograms of ALCT dark rate in each wiregroup, total or normalized.

The previously produced data for year 2016, 2017, 2018 are in folder ./gifRates/me*1data/*

Newer data for 2% CF4 (only for ME1/1 at the moment) can be found in gifRates/me11data/2pct

NewTest11.sh and ReprocessTest11.sh can be used to do all four steps at once for new data or reprocessing as desired, just be sure to follow the format used in the text files these scripts pull from. 



*  **A few scripts for extracting plots from Data:**

with the below scripts, I will list the general purpose, but one can also run ``python <scriptname>.py -h`` to get more detailed information, or just read the file itself:

1.  ``AnodeRatePlotter_PerWG.py``: ALCT rates in each wiregroup in 2D histogram
2.  ``TMBRatePlotter.py``: Rates for the whole chamber in a 1D histogram - as the name suggests it is primarily used to produce TMB dump rates.




**Strip2strip resistence**

1.  Data are in folders ./datame11 or ./datame21, They are text files and copied from the emugif4 computer. 
2.  Use the test_plot.cc to fit the data expotentialy, and the fit parameters determines the resistence value. 
2.a.    syntax: root -l test_plot.cc; test_plot(<DIRECTORY>, <FILENAME>, <EXT>)

Use strip/Str_me11_Plot.py to plot resistance as a function of accumulated charge
charges and their corresponding dates recorded in datame11/2pct_stripdatecharges.txt



