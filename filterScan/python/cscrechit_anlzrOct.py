import FWCore.ParameterSet.Config as cms
from FWCore.ParameterSet.VarParsing import VarParsing

options = VarParsing ('analysis')
options.parseArguments()
process = cms.Process("Demo")

process.load("Configuration/Geometry/GeometryIdeal2015Reco_cff")
process.load("Configuration/StandardSequences/MagneticField_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("Configuration/StandardSequences/RawToDigi_Data_cff")
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.load("RecoMuon.MuonSeedGenerator.standAloneMuonSeeds_cff")

process.GlobalTag.globaltag = '80X_dataRun2_Prompt_v16'

#process.options = cms.untracked.PSet(
#    SkipEvent = cms.untracked.vstring('LogicError','ProductNotFound')
#)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
      options.inputFiles
#    'file:../../../7972_Test40.root',
#    'file:../../../7981_Test40.root',
#    'file:../../../7982_Test40.root',
    )
)
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
process.source.duplicateCheckMode = cms.untracked.string('noDuplicateCheck')

process.demo = cms.EDAnalyzer('filterScan',
    #sta = cms.int32(2),
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

process.TFileService = cms.Service("TFileService", fileName = cms.string(options.outputFile) )

process.p = cms.Path(process.muonCSCDigis  *process.csc2DRecHits * process.cscSegments * process.demo)
