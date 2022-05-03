#include "tdrstyle.C"

void plot_me11_dr() {
 
   setTDRStyle();

   TCanvas *c1 = new TCanvas("c1","A Simple Graph with error bars",10,10,700,500);

   TString extraText   = "CSC ME1/1, nominal HV";
   TLatex latex;
   latex.SetNDC();
   latex.SetTextFont(42);
   latex.SetTextColor(kBlack);

   const int n = 9; //dates: 0127, 0203, 0211, 0218, 0225, 0303, 0310, 0404, 0415
   double charge[n] = {0.49, 3.08, 11.3, 17.6, 25.5, 33.1, 40.9, 51.2, 61.0,};
   double alct[n] =   {764,  766, 783,  783,  759,  789,  787,  777,  791};
   double clct[n] =   {588,  631,  511,  481,  464,  458,  467,  456,  448};
   double cna[n] =    {466,  546,  456,  450,  440,  438,  453,  448,  440};
  
   TGraph *gr1 = new TGraph(n, charge, alct);
   TGraph *gr2 = new TGraph(n, charge, clct);
   TGraph *gr3 = new TGraph(n, charge, cna);

   gr1->SetTitle("; Accumulated charge [mC/cm]; Singles counting rate [Hz]");
   gr1->SetMarkerColor(kBlue);
   gr1->GetXaxis()->SetLimits(0, 70);
   gr1->SetMinimum(0);
   gr1->SetMaximum(1200);
   gr1->Draw("ALP");

   latex.DrawLatex(0.3, 0.8, extraText);

  /*
    gr2->SetMarkerColor(kRed);
    gr2->SetMarkerStyle(21);
    gr2->Draw("LP same");
 
    gr3->SetMarkerColor(kGreen+3);
    gr3->SetMarkerStyle(21);
    gr3->Draw("LP same");
 
    TLegend *leg = new TLegend(0.15, 0.68 ,0.35, 0.88);
    leg->AddEntry(gr1, "ALCT", "p");
    leg->AddEntry(gr2, "CLCT", "p");
    leg->AddEntry(gr3, "ALCT*CLCT", "p");
 
    leg->Draw();
  */
}
