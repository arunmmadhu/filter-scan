TMB Dark rate
-----------------
In the parent directory to this one there is the program ``TMB_AG.py`` which queries the Ageing database for TMB dump results in the requested date range at the requested voltage. For the purposes of this analysis we are interested in HV0 and 0 V. Example data as handled by the analysis code is in `TMB_0V_me11_2pct.txt` and `TMB_HV0_me11_2pct.txt` - you can create ones like them just by querying the database and dumping to a text file and cleaning it up a bit.

In addition one needs the accumulated charge of the chamber (try http://pnpi-cms-l1.cern.ch:8080/CSCdose/ -you may need to tunnel through a cern connection). Raw charge versus time data from the database are currently stored in `../chargevtime.txt`, but it can be parsed a little nicer and sorted into just the charges you need for your measurement using ``../getcharges.py``

TMBRatePlotter.py then handles the calculation and plotting of the TMB dark rates. It can also plot other things of interest such as a comparison of the bad wg in layer 5 to an adjacent good neighboring wire group - and it can also produce a comparison plot for the different potential normalizations one would use in the analysis of test 11

Anode Dark rate (Test 11)
----------------------------
In the parent directory to this one there is the program ``Test11.py`` which queries the Ageing database for test 11 results in the requested date range at the requested voltage. For the purposes of this analysis we are interested in HV0. 

For a New measurement, one must first process the raw data from test 11

Here <MEASNUM> refers to the database number for said measurement and A refers to the Ageing database.
Note that `readFile.py` tacks `_numEvent<maxEvents>` onto the end of its output file name, and `analyzeGifRatesFromDigis.py` always outputs `histos.root` so be careful with the names of your files when you are doing this.

```
cmsenv
scp server:path/to/raw/file.raw file.raw
cmsRun python/readFile.py inputFile=file.raw outputFile=converted_raw.root maxEvents=100000
cmsRun python/analyzeGifRatesFromDigis.py inputFile=converted_raw_numEvent100000.root maxEvents=100000
mv histos.root <desired output path>/A<MEASNUM>.root
```
Be careful here with maxEvents - you want it to outnumber the number of events in your sample (can be found by looking at the DQM plot) because maxEvents tells readFile how many events to convert from raw. Any extra events will be empty events, and the ``plugins/gifRates.cc`` macro called by ``analyzeGifRatesFromDigis.py`` Should automatically skip empty digi collections in its processing. It is still best to just find the number of events from your DQM plot and use that. If you don't have access to DQM for this measurement, perhaps because you are working from a backup somewhere, just make sure the number is higher than about 60000

For a new measurement, you must then paste the relevant info into the relevant text file (`anode_me11_2pct.txt` i.e. for 2% CF4 ME11), namely `<desired output path>/A<MEASNUM>.root`, the charge accumulated on the chamber from the day of that measurement (try http://pnpi-cms-l1.cern.ch:8080/CSCdose/ -you may need to tunnel through a cern connection).

One can also batch process test 11 results using the script ``NewTest11.sh`` or ``ReprocessTest11.sh``, the latter of which takes as input a text file formatted as i.e. ``Test11_HV0_me11_2pct.txt`` (one can pipe the output of ``Test11.py`` into a text file and then clean it up a little bit - removing extraneous info and unwanted data points)

For ``NewTest11.sh`` the command is as follows

```
./NewTest11.sh <Name of Raw File> <Ageing Database number of measurement (####)> <output directory> <Number of events (See DQM plot)>
```
This tool uses scp to fetch the file so it will ask you the password to the machine you are fetching it from - alternatively if you already have the raw, you can go into ``NewTest11.sh`` and comment the scp line and uncomment the cp line below it. 
If you are scp-ing, you will want to use the full filename like what is pasted in the database, i.e. ``emugif5.cern.ch:/data/csc_00000001_EmuRUI01_Test_11_000_210623_103602_UTC.raw``

Finally to create the plots one uses ``AnodeRatePlotter_perWG.py``, which takes the information stored in ``anode_me11_2pct.txt`` or another similarly formatted file of your choosing.

For both ``AnodeRatePlotter_perWG.py`` and ``TMBRatePlotter.py`` try using ``python <X>.py --help`` to see a list of other arguments which can be parsed.

