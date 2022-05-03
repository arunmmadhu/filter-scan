#include "TGraph.h"
#include "TLatex.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLegend.h"

void plotHVme21() {
 
//   setTDRStyle();

   TCanvas *c1 = new TCanvas("c1","A Simple Graph with error bars",10,10,700,500);

   TString extraText   = "CSC ME2/1, Rate vs HV";
   TLatex latex;
   latex.SetNDC();
   latex.SetTextFont(42);
   latex.SetTextColor(kBlack);

   const int n = 13, m=11;
   double hv1[n] = {2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900};
   double alct_sep[n] = {28.4, 246.1, 359.8, 845.4, 1289.7, 1791.2, 2259.9, 2528.5, 2623.0, 2747.9, 3039.5, 4942.4, 22588.8};
//   float clct[n] = {};
   double cna_sep[n] = {4.0, 77.2, 170.6, 438.4, 709.3, 1102.9, 1494.1, 1793.1, 1960.7, 1999.7, 2012.5, 2273.0, 6718.2};
   double alct_oct[m] = {28.7, 589.6, 956.9, 1387.9, 1121.2, 2113.4, 2292.3, 2404.4, 2547.8, 3259.9, 10300.9};
   double cna_oct[m] = {4.4, 291.6, 491.7, 805.9, 711.6, 1454.1, 1688.9, 1775.2, 1773.3, 1863.3, 2949.3};
   double hv2[m] = {2700, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900};

   TGraph *gr1 = new TGraph(n, hv1, alct_sep);
//   TGraph *gr2 = new TGraph(n, HV, clct);
   TGraph *gr2 = new TGraph(n, hv1, cna_sep);
   TGraph *gr3 = new TGraph(m, hv2, alct_oct);
   TGraph *gr4 = new TGraph(m, hv2, cna_oct);

   gr1->SetTitle("; High Voltage [V]; Singles counting rate [Hz]");
   gr1->SetMarkerColor(kBlue);
//   gr1->GetXaxis()->SetLimits(0, 70);
   gr1->SetMinimum(0);
   gr1->SetMaximum(11000);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(22);
   gr1->Draw("ALP");

   latex.DrawLatex(0.5, 0.8, extraText);

  
    gr2->SetMarkerColor(kGreen+3);
    gr2->SetMarkerStyle(22);
    gr2->Draw("LP same");
 
    gr3->SetMarkerColor(kRed);
    gr3->SetMarkerStyle(21);
    gr3->Draw("LP same");

    gr4->SetMarkerColor(kRed+3);
    gr4->SetMarkerStyle(21);
    gr4->Draw("LP same");
 
    TLegend *leg = new TLegend(0.18, 0.68 ,0.48, 0.88);
    leg->AddEntry(gr1, "ALCT_Sep_07", "p");
    leg->AddEntry(gr2, "ALCT*CLCT_Sep_07", "p");
    leg->AddEntry(gr3, "ALCT_Oct_12", "p"); 
    leg->AddEntry(gr4, "ALCT*CLCT_Oct_12", "p");
    leg->Draw();

//c1->SaveAs("me11.pdf");  
//c1->SaveAs("me11.eps");
}
