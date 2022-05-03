import argparse, array
from ROOT import gROOT, TCanvas, TLegend, TGraph, TGraphErrors, TDatime, TH2F, gStyle, kYellow, kCyan, kRed, kGreen, kBlack, kOrange, kViolet, TMath, gPad, TFile, TPaletteAxis
#from datetime import datetime
gStyle.SetOptStat(0)
gStyle.SetPalette(1)


parser = argparse.ArgumentParser(description='For plotting strip to strip resistances')

parser.add_argument('--tenpctzero', action='store_true', default=False, help="use the start of 10 percent irradiation as the zero point for charge\n DEFAULT: False")
parser.add_argument('--verbose', action='store_true', default=False, help="Print statements\n DEFAULT: False")
parser.add_argument('--tmbnorm', action='store_true', default=False, help="Normalize by TMB dump Total_Hit_clusters_minus_muons (NOT RECOMMENDED)\n DEFAULT: False")
parser.add_argument('--anodetotalnorm', action='store_true', default=False, help="Normalize by corrected total anode rate from test 11\n DEFAULT: False")
parser.add_argument('--tmb0v', action='store', type=str, default="TMB_0V_me11_2pct.txt", help="where to pull 0V tmb dump data from (only used if doing --tmbnorm)\n DEFAULT: TMB_0V_me11_2pct.txt")
parser.add_argument('--tmbhv0', action='store', type=str, default="TMB_HV0_me11_2pct.txt", help="where to pull HV0 tmb dump data from (only used if doing --tmbnorm)\n DEFAULT: TMB_HV0_me11_2pct.txt")
parser.add_argument('--data', action='store', default="anode_me11_2pct.txt", type=str, help="where to look for data on Total Chamber Rate\n DEFAULT: anode_me11_2pct.txt")
parser.add_argument('--chambtype', action='store', default=1, type=int, help="ME1/1 (Put 1) or ME2/1 (Put 2)?\n DEFAULT: 1")
parser.add_argument('--name', action='store', default="AnodeHitDensity2pct_ME11", type=str, help="name of output file (without the .pdf)\n DEFAULT: AnodeHitDensity2pct_ME11")
parser.add_argument('--compare2old', action='store_true', default=False, help="comparing to older treatment of the data - splits up plots into a few different ranges of charge\n DEFAULT: False")
#parser.add_argument('--charges', action ='store', default='charges_me11_2pct.txt', type=str, help="list of charges - 'outfile' from getcharges.py\n DEFAULT: charges_me11_2pct.txt")
parser.add_argument('--timeplot', action='store_true', default=False, help="Plot with time as the x axis as opposed to charge\n DEFAULT: False")

args = parser.parse_args()

if args.tenpctzero:
    plus300 = True
else:
    plus300 = False
if args.compare2old:
    plus300 = True
if args.anodetotalnorm:
    Test11_TotalClusters = []
    def GetTotalCorrectedRate(rootfilename):
        summedhits = 0
        corrections = 0
        rootfile = TFile(rootfilename, "read")
        for layernum in xrange(0,6):
            hname = str("ALCT/hNofAhitL["+str(layernum)+"][2]")
            hist = rootfile.Get(hname)
            if hist != 0:
                entries = hist.GetEntries()
                summedhits += entries
        hist2 = rootfile.Get("ALCT/hNofAhit[2]")
        for binnum in xrange(2, 8):
            NumOfLayers = binnum - 2
            NHits = hist2.GetBinContent(binnum)
            LayerCorrection = 0
            if NumOfLayers != 0:
                LayerCorrection = NHits * (NumOfLayers - 1) / NumOfLayers
            corrections += LayerCorrection
        CorrectedTotalRate = (summedhits - corrections) / 30
        rootfile.Close()
        return CorrectedTotalRate
if args.tmbnorm:
    tmbdump_alctrates = []
    def GetTMBRate():
        tmb_0v = []
        tmb_hv0 = []
        tmb_alctrate = []
        with open(args.tmb0v, "r") as f0v:
            for linenum, line in enumerate(f0v):
                alct0hits = 0
                time = 10.0
                if linenum <= 5:
                    continue
                for index, item in enumerate(line.split()):
                    if index == 6:
                        time = float(item)
                        if time == 0:
                            return "ERROR: TMB dump time zero seconds"
                    if index == 7:
                        alct0hits = float(item)
                    else: continue
                tmb_0v += [alct0hits/time]
        with open(args.tmbhv0, "r") as fhv0:
            for linenum, line in enumerate(fhv0):
                time = 10.0
                alct0hits = 0
                if linenum <= 5:
                    continue
                for index, item in enumerate(line.split()):
                    if index == 6:
                        time = float(item)
                        if time == 0:
                            print "ERROR: TMB dump time zero seconds at line ", linenum
                    if index == 7:
                        alct0hits = float(item)
                    else: continue
                tmb_hv0 += [alct0hits/time]
        for i in xrange(len(tmb_hv0)):
            tmb_alctrate += [tmb_hv0[i] - tmb_0v[i]]
        return tmb_alctrate
    tmbdump_alctrates = GetTMBRate()
# importing data
charges = array.array('d')
rootfiles = []
# Due to some interesting behavior which appears uniquely for bad points with test 11 normalization, it was decided to use Test 11 Total_Hit_clusters_minus_muons
if not args.tmbnorm and not args.anodetotalnorm:
    Test11_Total_Hit_clusters_minus_muons = True
else:
    Test11_Total_Hit_clusters_minus_muons = False
if Test11_Total_Hit_clusters_minus_muons:
    Test11_Total_Hit_clusters_minus_muonsrates = []
with open(args.data, "r") as f1:
    for lnum, line in enumerate(f1):
        if lnum == 0: continue
        rootfiles += [line.split()[0]]
        charges.append(float(line.split()[1]))
        if Test11_Total_Hit_clusters_minus_muons:
            tmpfile = TFile(line.split()[0], "read")
            Test11_Total_Hit_clusters_minus_muonsrates += [float(tmpfile.Get("ALCT/hNofAhit[2]").GetBinContent(3)/30.0)]
            tmpfile.Close()
            if args.verbose:
                print "Test11 Total_Hit_clusters_minus_muons:", Test11_Total_Hit_clusters_minus_muonsrates[-1]
        if args.anodetotalnorm:
            Test11_TotalClusters += [GetTotalCorrectedRate(rootfiles[-1])]
    f1.close()
if args.tmbnorm:
    if len(rootfiles) != len(tmbdump_alctrates):
        print "ERROR: incongruency in number of TMB dump measurements vs Test 11 measurements"
        print "TMB dump measurements: ", len(tmbdump_alctrates), "Test 11 measurements: ", len(rootfiles)
        quit()
zeropoint = ''
if plus300: 
    for i in xrange(len(charges)):
        charges[i] += 330
    zeropoint = '330_mCcm_'
# creating the range for split histograms
# I commented out functionality which will plot a third histogram in a range complementary to the one used for comparison plot - though in practice I haven't needed it.
if args.compare2old:
    chargecut = 500
    range1 = array.array('d')
    range2 = array.array('d')
    # we want the first bins here to be empty because we are comparing to plots that start at 0
    range1.append(0)
    meascut = 0
    for imeas, charge in enumerate(charges):
        if charge <= chargecut:
            range1.append(charge)
            meascut += 1
        else:
            range2.append(charge)
    #Histograms go up to the final value of the defined range, so if we want to be able to see this final point we must append an extra point to the end of our ranges for the last bin to go up to
    range1.append(range1[-1]+5)
    range2.append(range2[-1]+5)

#added Limits, Legend, Graph
class Limits:
    def __init__(self, innername, title, xtitle, ytitle, xbins, xmin, xmax, ybins, ymin, ymax):
        self.lims = TH2F(innername, title+";"+ xtitle + ";" + ytitle, xbins, xmin, xmax, ybins, ymin, ymax)
        self.lims.Draw()
        self.lims.GetXaxis().SetLabelSize(0.03)
        self.lims.GetYaxis().SetLabelSize(0.03)
        self.lims.GetYaxis().SetTitleSize(0.08)
        self.lims.GetYaxis().SetTitleOffset(0.5)
        if args.timeplot:
            self.lims.GetXaxis().SetTimeDisplay(1)
            self.lims.GetXaxis().SetTimeOffset(0)
            self.lims.GetXaxis().SetTimeFormat("%d.%b.%Y")
            #self.lims.GetXaxis().SetNdivisions(507)
            #self.lims.GetXaxis().SetTimeOffset(24, "gmt")
            
class Legend:
    def __init__(self, xmin=0.1, ymin=0.7, xmax=0.3, ymax=0.9):
        self.legend = TLegend(xmin, ymin, xmax, ymax)
        self.legend.SetHeader("Legend", "C")
    def fill(self, tgraphs):
        for tgraph in tgraphs:
            self.legend.AddEntry(tgraph.graph, tgraph.title, "lp")
    def draw(self):
        self.legend.Draw()

class Graph:
    def __init__(self, length, name, color, cathodeOrTMB = False, correction=False):
        self.graph = TGraph(length)
        self.title = name
        self.color = color
        self.iscorrection = correction
        self.iscathodeortmb = correction
    def fill(self, i, xpoint, ypoint):
        self.graph.SetPoint(i, xpoint, ypoint)
    def draw(self):
        self.graph.SetMarkerColor(self.color)
        self.graph.SetMarkerSize(2)
        if self.iscorrection:
            self.graph.SetLineColor(kBlack)
            self.graph.SetMarkerStyle(24)
        elif self.iscathodeortmb:
            self.graph.SetLineColor(self.color)
            self.graph.SetMarkerStyle(21)
        else:
            self.graph.SetLineColor(self.color)
            self.graph.SetMarkerStyle(20)
        self.graph.Draw("PL SAME")

class Layer:
    def __init__(self, nmeas, layernum, charges, chambtype, name=''):
        if chambtype == 1:
            self.nwg = 48
        elif chambtype == 2:
            self.nwg = 112
        else:
            print "only ME11 (type = 1) and ME21 (type = 2) Are supported. Number of wire groups set to 0 in protest."
            self.nwg = 0
        self.meas = nmeas
        domain = charges
        domain.append(domain[-1] +5)
        self.num = int(layernum+1)
        self.hist = TH2F("L"+str(self.num)+name, "L"+str(self.num)+name, nmeas, domain, self.nwg+1, 0, self.nwg+2)
        self.hist.GetXaxis().SetTitle("Accumulated charge [mC/cm]")
        self.hist.GetYaxis().SetTitle("Wire group")
        self.hist.GetXaxis().SetLabelSize(0.03)
        self.hist.GetYaxis().SetLabelSize(0.03)
        self.hist.GetYaxis().SetTitleSize(0.03)
        self.hist.GetYaxis().SetTitleOffset(1)
        if args.compare2old:
            self.hist2 = TH2F("L"+str(self.num)+name+"_2", "L"+str(self.num)+name+"_2", len(range1)-1, range1, self.nwg+1, 0, self.nwg+2)
            #self.hist3 = TH2F("L"+str(self.num)+name+"_3", "L"+str(self.num)+name+"_3", len(range2)-1, range2, self.nwg+1, 0, self.nwg+2)
            self.hist2.GetXaxis().SetTitle("Accumulated charge [mC/cm]")
            self.hist2.GetYaxis().SetTitle("Wire group")
            self.hist2.GetXaxis().SetLabelSize(0.03)
            self.hist2.GetYaxis().SetLabelSize(0.03)
            self.hist2.GetYaxis().SetTitleSize(0.03)
            self.hist2.GetYaxis().SetTitleOffset(1)
            #self.hist3.GetXaxis().SetTitle("Accumulated charge [mC/cm]")
            #self.hist3.GetYaxis().SetTitle("Wire group")
            #self.hist3.GetXaxis().SetLabelSize(0.03)
            #self.hist3.GetYaxis().SetLabelSize(0.03)
            #self.hist3.GetYaxis().SetTitleSize(0.03)
            #self.hist3.GetYaxis().SetTitleOffset(1)
    def measure(self, measnum, ratehist, normrate):
        for wg in xrange(self.nwg+1):
            #+1 is because the histogram's bins start counting at 1
            self.hist.SetBinContent(measnum+1, wg+1, ratehist.GetBinContent(wg+1) * normrate)
            if args.compare2old:
                if measnum < meascut:
                    # The +2 here is to account for the zero charge bin in this range - to show we are only looking at 2%
                    self.hist2.SetBinContent(measnum+2, wg+1, ratehist.GetBinContent(wg+1) * normrate)
                #else:
                #    self.hist3.SetBinContent(measnum+1 - meascut, wg+1, ratehist.GetBinContent(wg+1) * normrate)
def doplots(layerlist, plotname):
    Canvas = TCanvas("Canvas", "Normalized Single Layer Anode Dark Rate Density", 200, 10, 1400, 1000)
    Canvas.Divide(3,2)
    for layer in layerlist:
        Canvas.cd(layer.num)
        layer.hist.SetMaximum(0.03)
        layer.hist.SetTitle("Normalized Layer "+ str(layer.num) +" Anode Dark Rate Density")
        layer.hist.Draw("colz")
        gPad.Update()
        layer.hist.GetZaxis().SetLabelSize(0.025)
    if not args.name:
        Canvas.SaveAs(plotname +"ME"+str(args.chambtype)+"1_Anode_Rate_vs_WG_vs_charge.pdf")
    else:
        Canvas.SaveAs(args.name+"_330+.pdf")
    Canvas.Close()
    if args.compare2old:
        Canvas2 = TCanvas("Canvas2", "Normalized Single Layer Anode Dark Rate Density", 200, 10, 1400, 1000)
        Canvas2.Divide(3,2)
        for layer in layerlist:
            Canvas2.cd(layer.num)
            layer.hist2.SetMaximum(0.03)
            layer.hist2.SetTitle("Normalized Layer "+ str(layer.num) +" Anode Dark Rate Density")
            layer.hist2.Draw("colz")
            gPad.Update()
            layer.hist2.GetZaxis().SetLabelSize(0.025)
        if not args.name:
            Canvas2.SaveAs(plotname +"ME"+str(args.chambtype)+"1_Anode_Rate_vs_WG_vs_charge_2.pdf")
        else:
            Canvas2.SaveAs(args.name+"_0-500.pdf")
        Canvas2.Close()
        #Canvas3 = TCanvas("Canvas3", "Normalized Single Layer Anode Dark Rate", 200, 10, 1400, 1000)
        #Canvas3.Divide(3,2)
        #for layer in layerlist:
        #    Canvas3.cd(layer.num)
        #    layer.hist3.SetMaximum(0.03)
        #    layer.hist3.SetTitle("Normalized Layer "+ str(layer.num) +" Anode Dark Rate Density")
        #    layer.hist3.Draw("colz")
        #    gPad.Update()
        #    layer.hist3.GetZaxis().SetLabelSize(0.025)
        #if not args.name:
        #    Canvas3.SaveAs(plotname +"ME"+str(args.chambtype)+"1_Anode_Rate_vs_WG_vs_charge_3.pdf")
        #else:
        #    Canvas3.SaveAs(args.name+"_500+.pdf")
        #Canvas3.Close()
#initialize histos
nummeas = len(charges)
if Test11_Total_Hit_clusters_minus_muons:
    LayersTotal_Hit_clusters_minus_muons = []
if args.anodetotalnorm:
    LayersTotal_Hit_clusters = []
if args.tmbnorm:
    LayersTMB = []
for i in xrange(6):
    if Test11_Total_Hit_clusters_minus_muons:
        liTotal_Hit_clusters_minus_muons = Layer(nummeas, i, charges, args.chambtype, "Test11_Total_Hit_clusters_minus_muons_Normalized")
        LayersTotal_Hit_clusters_minus_muons.append(liTotal_Hit_clusters_minus_muons)
    if args.anodetotalnorm:
        liTotal_Hit_clusters = Layer(nummeas, i, charges, args.chambtype)
        LayersTotal_Hit_clusters.append(liTotal_Hit_clusters)
    if args.tmbnorm:
        liTMB = Layer(nummeas, i, charges, args.chambtype, "TMBDumpNormalized")
        LayersTMB.append(liTMB)
        
        
#produce final arrays for plotting
#kYellow, kCyan, kRed, kGreen, kBlack, kOrange, kViolet
#Layer1_WG47 = Graph(len(Test11_Total_Hit_clusters_minus_muonsrates), "Layer5_WG27", kGreen+3)
#Layer2_WG45 = Graph(len(Test11_Total_Hit_clusters_minus_muonsrates), "Layer5_WG28", kRed+3, False, True)
#Layer4_WG44 = Graph(len(Test11_Total_Hit_clusters_minus_muonsrates), "Layer5_WG29", kOrange+3)
Layer1_WG47 = Graph(len(Test11_Total_Hit_clusters_minus_muonsrates), "Layer1_WG47", kGreen+3)
Layer2_WG45 = Graph(len(Test11_Total_Hit_clusters_minus_muonsrates), "Layer2_WG45", kRed+3, False, True)
Layer4_WG44 = Graph(len(Test11_Total_Hit_clusters_minus_muonsrates), "Layer4_WG44", kOrange+3)
Layer4_WG40 = Graph(len(Test11_Total_Hit_clusters_minus_muonsrates), "Layer4_WG40", kBlack+3)
Layer4_WG01 = Graph(len(Test11_Total_Hit_clusters_minus_muonsrates), "Layer4_WG01", kYellow+3)
Layer5_WG07 = Graph(len(Test11_Total_Hit_clusters_minus_muonsrates), "Layer5_WG06", kViolet+3)
Layer6_WG38 = Graph(len(Test11_Total_Hit_clusters_minus_muonsrates), "Layer6_WG38", kCyan+3)

qmax = 0

# filling histograms for each layer for each measurement
if Test11_Total_Hit_clusters_minus_muons:
    for imeas, anoderate in enumerate(Test11_Total_Hit_clusters_minus_muonsrates):
        measfile = TFile(rootfiles[imeas], "read")
        for iL, layer in enumerate(LayersTotal_Hit_clusters_minus_muons):
            ratehist = measfile.Get("ALCT/hAhitLNorm["+str(iL)+"][1]")
            layer.measure(imeas, ratehist, anoderate)
        measfile.Close()
    for i in xrange(int(len(Test11_Total_Hit_clusters_minus_muonsrates))):
      yvar = charges[i]
      if yvar > qmax:
          qmax = yvar
      Layer1_WG47.fill(i, yvar, LayersTotal_Hit_clusters_minus_muons[1-1].hist.GetBinContent(i+1, 47)) 
      Layer2_WG45.fill(i, yvar, LayersTotal_Hit_clusters_minus_muons[2-1].hist.GetBinContent(i+1, 45)) 
      Layer4_WG44.fill(i, yvar, LayersTotal_Hit_clusters_minus_muons[4-1].hist.GetBinContent(i+1, 44))
      #Layer1_WG47.fill(i, yvar, LayersTotal_Hit_clusters_minus_muons[5-1].hist.GetBinContent(i+1, 27)) 
      #Layer2_WG45.fill(i, yvar, LayersTotal_Hit_clusters_minus_muons[5-1].hist.GetBinContent(i+1, 28)) 
      #Layer4_WG44.fill(i, yvar, LayersTotal_Hit_clusters_minus_muons[5-1].hist.GetBinContent(i+1, 29))
      Layer4_WG40.fill(i, yvar, LayersTotal_Hit_clusters_minus_muons[4-1].hist.GetBinContent(i+1, 40)) 
      Layer4_WG01.fill(i, yvar, LayersTotal_Hit_clusters_minus_muons[4-1].hist.GetBinContent(i+1, 2)) 
      Layer5_WG07.fill(i, yvar, LayersTotal_Hit_clusters_minus_muons[5-1].hist.GetBinContent(i+1, 7))
      Layer6_WG38.fill(i, yvar, LayersTotal_Hit_clusters_minus_muons[6-1].hist.GetBinContent(i+1, 38))
    AnodeRateCanvas = TCanvas("AnodeRateCanvas", "Dark rate vs Time", 200, 10, 1400, 1000)
    AnodeRateCanvas.cd()
    AnodeRateLimits = Limits("AnodeRatelimits", "Normalized Anode Dark Rate Density", "Accumulated Charge (mC/cm)", "Dark Rate Density (/cm)", 1000, 330, qmax + 10, 100, 0, 0.03)
    Layer1_WG47.draw()
    Layer2_WG45.draw()
    Layer4_WG44.draw()
    Layer4_WG40.draw()
    Layer4_WG01.draw()
    Layer5_WG07.draw()
    Layer6_WG38.draw()
    toplot = [Layer1_WG47, Layer2_WG45, Layer4_WG44, Layer4_WG40, Layer4_WG01, Layer5_WG07, Layer6_WG38 ]
    #toplot = [Layer1_WG47, Layer2_WG45, Layer4_WG44 ]
    TMBDumpLegend = Legend()
    TMBDumpLegend.fill(toplot)
    TMBDumpLegend.draw()
    AnodeRateCanvas.SaveAs("AnodeSingleRate_" + ".pdf")
    
#    for imeas, anoderate in enumerate(Test11_Total_Hit_clusters_minus_muonsrates):
#        measfile = TFile(rootfiles[imeas], "read")
#        for iL, layer in enumerate(LayersTotal_Hit_clusters_minus_muons):
#            ratehist = measfile.Get("ALCT/hAhitLNorm["+str(iL)+"][1]")
#            layer.measure(imeas, ratehist, anoderate)
#        measfile.Close()
#    doplots(LayersTotal_Hit_clusters_minus_muons, zeropoint + "Test11_Total_Hit_clusters_minus_muons_Normalized_")
if args.tmbnorm:
    for imeas, anoderate in enumerate(tmbdump_alctrates):
        measfile = TFile(rootfiles[imeas], "read")
        for iL, layer in enumerate(LayersTMB):
            ratehist = measfile.Get("ALCT/hAhitLNorm["+str(iL)+"][1]")
            layer.measure(imeas, ratehist, anoderate)
        measfile.Close()
    doplots(LayersTMB, zeropoint + "TMB_Normalized_")
if args.anodetotalnorm:
    for imeas, anoderate in enumerate(Test11_TotalClusters):
        measfile = TFile(rootfiles[imeas], "read")
        for iL, layer in enumerate(LayersTotal_Hit_clusters):
            ratehist = measfile.Get("ALCT/hAhitLNorm["+str(iL)+"][1]")
            layer.measure(imeas, ratehist, anoderate)
        measfile.Close()
    doplots(LayersTotal_Hit_clusters, zeropoint + "Test11_Total_Hit_clusters_Normalized_")
