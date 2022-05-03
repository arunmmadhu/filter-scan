# based on CMSSW_12_0_0_pre2/src/IORawData/CSCCommissioning/test/readFile_b904_Run3.py
import FWCore.ParameterSet.Config as cms
from FWCore.ParameterSet.VarParsing import VarParsing

process = cms.Process("reader")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cout.threshold = cms.untracked.string('DEBUG')
process.MessageLogger.debugModules = cms.untracked.vstring('*')
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

options = VarParsing ('analysis')
#first run is needed only for running L1Emulator (see p.2 of
#https://indico.cern.ch/event/1046913/contributions/4398858/attachments/2261412/3838507/CSCDPG_SD_20210609.pdf)
#options.register ("firstRun", 341761, VarParsing.multiplicity.singleton, VarParsing.varType.int)

options.maxEvents = 100000
options.register(
                    'inputFile',                #varname
                    '/afs/cern.ch/user/k/kkuzn/public/tmp/csc_00000001_EmuRUI01_Test_11_000_210526_164333_UTC.raw',             #Default Value
                    VarParsing.multiplicity.singleton,
                    VarParsing.varType.string,
                    "Name of Input File, set in command line with inputFile=varname"
)
options.outputFile = 'test.root'
options.parseArguments()


# Better to know actual number of events in the .raw data file to set maxEvents.
# Otherwise it doesn't stop automatically at the end of reading of .raw data file
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(options.maxEvents) )

process.source = cms.Source("EmptySource",
       #firstRun= cms.untracked.uint32(options.firstRun),
       firstRun= cms.untracked.uint32(1),
       numberEventsInLuminosityBlock = cms.untracked.uint32(200),
       numberEventsInRun       = cms.untracked.uint32(0)
 )

# GIF++: FED838 vme1 dmb2 corresponds  to E:1 S:1 R:1 C:1
process.rawDataCollector = cms.EDProducer('CSCFileReader',
    firstEvent  = cms.untracked.int32(0),
    FED838 = cms.untracked.vstring('RUI01'),
    FED839 = cms.untracked.vstring('RUI01'), #ME2/1
    RUI01  = cms.untracked.vstring(options.inputFile)
)

process.FEVT = cms.OutputModule("PoolOutputModule",
        fileName = cms.untracked.string(options.outputFile),
        outputCommands = cms.untracked.vstring("keep *")
)

process.p = cms.Path( process.rawDataCollector)

process.outpath = cms.EndPath(process.FEVT)

