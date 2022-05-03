import FWCore.ParameterSet.Config as cms

process = cms.Process("FilterScan")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:/afs/cern.ch/user/k/kkuzn/public/tmp/csc_00000001_EmuRUI01_Test_11_000_210331_124024_UTC.root')  # data to be skimmed
#    fileNames = cms.untracked.vstring('file:/afs/cern.ch/user/l/lowang/GIF/CMSSW_6_2_12/src/IORawData/CSCCommissioning/me21/A59.root')

)

## https://cmssdt.cern.ch/SDT/doxygen/CMSSW_7_5_1/doc/html/da/d3d/GeometryIdeal2015Reco__cff_8py_source.html
###    4 from Configuration.Geometry.GeometryIdeal2015_cff import *
###    5 from Configuration.Geometry.GeometryReco_cff import * 

## https://cmssdt.cern.ch/SDT/doxygen/CMSSW_7_5_1/doc/html/d4/d9a/GeometryIdeal2015__cff_8py_source.html
###    7 from Geometry.CMSCommonData.cmsIdealGeometry2015XML_cfi import *
###    8 from Geometry.TrackerNumberingBuilder.trackerNumberingGeometry_cfi import *

## https://cmssdt.cern.ch/SDT/doxygen/CMSSW_7_5_1/doc/html/d4/d24/cmsIdealGeometry2015XML__cfi_8py_source.html
###    5 XMLIdealGeometryESSource = cms.ESSource("XMLIdealGeometryESSource",
###    6     geomXMLFiles = cms.vstring('Geometry/CMSCommonData/data/materials.xml',
###    7                                'Geometry/CMSCommonData/data/rotations.xml',
###    ...
###   254                               'Geometry/CSCGeometryBuilder/data/cscSpecs.xml',  

process.load("Configuration/Geometry/GeometryIdeal2015Reco_cff")
#process.load("test.gifRates.ConfGIFgeom")

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load("Configuration/StandardSequences/RawToDigi_Data_cff")
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.load("RecoMuon.MuonSeedGenerator.standAloneMuonSeeds_cff")

process.GlobalTag.globaltag = '74X_dataRun2_Prompt_v0'

process.options = cms.untracked.PSet(
        SkipEvent = cms.untracked.vstring('LogicError','ProductNotFound')
)

process.MessageLogger = cms.Service("MessageLogger",
       destinations   = cms.untracked.vstring('myDebugOutputFile.txt'),
       debugModules = cms.untracked.vstring('*'),
       message = cms.untracked.PSet(threshold = cms.untracked.vstring('DEBUG'))
)
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000
process.source.duplicateCheckMode = cms.untracked.string('noDuplicateCheck')


process.FILTERScan = cms.EDAnalyzer('filterScan',
		   wireDigiTag  = cms.InputTag("muonCSCDigis", "MuonCSCWireDigi"),
                   alctDigiTag  = cms.InputTag('muonCSCDigis', 'MuonCSCALCTDigi'),
                   #stripDigiTag = cms.InputTag("muonCSCDigis","MuonCSCStripDigi"),
                   #comparatorDigiTag = cms.InputTag("muonCSCDigis", "MuonCSCComparatorDigi"),
                   cscRecHitTag = cms.InputTag("csc2DRecHits",""),
				   cscSegTag    = cms.InputTag("cscSegments"),
                   chamberTag   = cms.untracked.int32(1),
                   anodeOnlyTag = cms.untracked.bool(True), # test11 only!a
                   debugTag     = cms.untracked.bool(True)
                   #debugTag    = cms.untracked.bool(False)
)

process.p = cms.Path( process.muonCSCDigis 
		     #*process.csc2DRecHits 
		     #*process.cscSegments
		     *process.FILTERScan
)
