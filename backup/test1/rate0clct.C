//#include "TGraph.h"
//#include "TLatex.h"
//#include "TString.h"
//#include "TCanvas.h"
//#include "TLegend.h"

void rate0clct() {

   TCanvas *c1 = new TCanvas("rate0clct","rate vs dose",10,10,700,500);


   const int n1 = 39;

    //dates: 2016::0225, 0303, 0310, 0404, 0415, 0511, 0526, 0615, 0629, 0706, 0713, 0720, 0803, 0810, 0831, 1009, 1019, 1026, 1102, 1109, 1116, 1123;2017::0117, 0125, 0201, 0208, 0215, 0222, 0301, 0308, 0315, 0407, 0419, 0424, 0505, 0531, 0607, 0621, 0628
   double charge1[n1] = {25.5, 33.1, 40.9, 51.2, 59.38, 63.97, 77.94, 89.81, 95.44, 104.24, 113.27, 120.90, 135.62, 142.40, 152.13, 154.42, 154.58, 156.55, 163.68, 171.28, 180.46, 186.99, 193.55, 200.14, 207.45, 214.78, 222.52, 228.59, 235.27, 241.72, 250.86, 256.42, 266.13, 271.28, 277.37, 279.95, 287.51, 297.54, 305.82};
   double clct1[n1] = {21.0, 61.4, 8.6, 2.4, 0.8, 0.5, 83.0, 23.8, 30.2, 45.8, 37.8, 52.4, 33.2, 88.6, 119.8, 25.7, 22.0, 1.4, 125.5, 59.5, 45.2, 50.1, 189.4, 162.5, 144.0, 122.9, 30.4, 19.4, 19.2, 20.9, 47.5, 48.8, 51.8, 57.7, 71.0, 306.0, 567.7, 285.2, 258.7};


   TGraph *gr = new TGraph(n1, charge1, clct1);


   c1->cd();
   gr->SetTitle("; Accumulated charge [mC/cm]; Dark rate [Hz]");
   gr->SetMinimum(0);
   gr->SetMaximum(600);
   gr->SetMarkerColor(kRed);
   //gr->SetLineColor(kRed);
   gr->SetMarkerStyle(22);
   gr->SetMarkerSize(1.5);
   gr->Draw("ALP");

   TLegend *leg1 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME1/1");
   leg1->AddEntry(gr, "CLCT rate at 0V", "lp");
   leg1->SetBorderSize(0);
   leg1->Draw();

   c1->SaveAs("me11rate0clct.root");



}
