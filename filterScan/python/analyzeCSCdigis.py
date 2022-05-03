import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

# command line arguments
import FWCore.ParameterSet.VarParsing as VarParsing 
options = VarParsing.VarParsing ('analysis')
options.maxEvents = 10 
options.register ("debug", False, VarParsing.VarParsing.multiplicity.singleton, VarParsing.VarParsing.varType.bool)
options.parseArguments()
# end command line arguments

process = cms.Process("TEST", eras.Run3)
process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("CondCore.CondDB.CondDB_cfi")
process.load("Configuration/StandardSequences/RawToDigi_Data_cff")
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")

#from Configuration.AlCa.autoCond import autoCond
from Configuration.AlCa.GlobalTag import GlobalTag as gtCustomise
process.GlobalTag = gtCustomise(process.GlobalTag, 'auto:run2_data', '')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(options.maxEvents)
)

process.MessageLogger = cms.Service("MessageLogger",
    cerr = cms.untracked.PSet(enable = cms.untracked.bool(False)),
    cout = cms.untracked.PSet(
        WARNING = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        enable = cms.untracked.bool(True),
        threshold = cms.untracked.string('WARNING')
    ),
    debugModules = cms.untracked.vstring('*')
)


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:testRF839_27_000_220224_212343_UTC.root')
)

process.FEVT = cms.OutputModule("PoolOutputModule",
        fileName = cms.untracked.string("testD_27.root"),
        outputCommands = cms.untracked.vstring("keep *")
)


process.muonCSCDigis.UnpackStatusDigis = True
process.muonCSCDigis.PrintEventNumber  = True
process.muonCSCDigis.FormatedEventDump = False

process.muonCSCDigis.UseExaminer           = True  #should be true!
process.muonCSCDigis.UseSelectiveUnpacking = True  #should be true!

process.muonCSCDigis.Debug             = options.debug


process.gif = cms.EDAnalyzer('filterScan',
                   wireDigiTag = cms.InputTag("muonCSCDigis","MuonCSCWireDigi"),
                   alctDigiTag = cms.InputTag("muonCSCDigis","MuonCSCALCTDigi"),
                   
                   stripDigiTag = cms.untracked.InputTag("muonCSCDigis","MuonCSCStripDigi"),
                   compDigiTag = cms.untracked.InputTag("muonCSCDigis","MuonCSCComparatorDigi"),
                   clctDigiTag = cms.untracked.InputTag("muonCSCDigis","MuonCSCCLCTDigi"),
                   corrlctDigiTag = cms.untracked.InputTag("muonCSCDigis","MuonCSCCorrelatedLCTDigi"),
    
                   cscRecHitTag = cms.untracked.InputTag("csc2DRecHits"), #just for compatibility
                   cscSegTag    = cms.untracked.InputTag("cscSegments"),     #just for compatibility

                   chamberTag   = cms.untracked.int32(2),   # 1 - ME1/1, 2 - ME2/1 
                   anodeOnlyTag = cms.untracked.bool(False), # test11 only!a
                   debugTag    = cms.untracked.bool(options.debug)
)

process.p = cms.Path( process.muonCSCDigis * process.csc2DRecHits * process.gif)
#process.p = cms.Path( process.muonCSCDigis * process.gif)

process.outpath = cms.EndPath(process.FEVT)
