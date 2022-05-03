#include "TGraph.h"
#include "TLatex.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLegend.h"

void plotHVme11() {
 
//   setTDRStyle();

   TCanvas *c1 = new TCanvas("c1","A Simple Graph with error bars",10,10,700,500);

   TString extraText   = "CSC ME1/1, Rate vs HV";
   TLatex latex;
   latex.SetNDC();
   latex.SetTextFont(42);
   latex.SetTextColor(kBlack);

   const int n = 11;
   double hv[n] = {2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 2950, 3000};
   double alct_aug[n] = {50.8, 130.3, 227.0, 352.6, 536.9, 699.9, 750.8, 766.6, 937.1, 1326.0, 3350.6};
//   float clct[n] = {};
   double cna_aug[n] = {1.2, 12.5, 47.8, 110.0, 205.3, 344.3, 484.9, 576.3, 649.5, 799.6, 1765.0};
   double alct_oct[n] = {38.6, 100.2, 178.2, 292.4, 442.5, 585.5, 658.5, 681.1, 735.6, 942.0, 1709.0};
   double cna_oct[n] = {1.7, 8.4, 34.5, 79.2, 164.0, 265.0, 403.7, 513.4, 553.7, 619.8, 970.7};

   TGraph *gr1 = new TGraph(n, hv, alct_aug);
//   TGraph *gr2 = new TGraph(n, HV, clct);
   TGraph *gr2 = new TGraph(n, hv, cna_aug);
   TGraph *gr3 = new TGraph(n, hv, alct_oct);
   TGraph *gr4 = new TGraph(n, hv, cna_oct);

   gr1->SetTitle("; High Voltage [V]; Singles counting rate [Hz]");
   gr1->SetMarkerColor(kBlue);
//   gr1->GetXaxis()->SetLimits(0, 70);
   gr1->SetMinimum(0);
   gr1->SetMaximum(3500);
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
    leg->AddEntry(gr1, "ALCT_Aug_31", "p");
    leg->AddEntry(gr2, "ALCT*CLCT_Aug_31", "p");
    leg->AddEntry(gr3, "ALCT_Oct_09", "p"); 
    leg->AddEntry(gr4, "ALCT*CLCT_Oct_09", "p");
    leg->Draw();

//c1->SaveAs("me11.pdf");  
//c1->SaveAs("me11.eps");
}
