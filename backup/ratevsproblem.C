#include "TGraph.h"

void ratevsproblem() {
  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas("c1","graph",1);

  //c1->Divide(2,1);

  const int n=48;
  double dose[n] = {17.42,25.23,40.40,47.87,50.94,59.38,59.39,59.43,77.94,89.81,95.44,104.24,113.27,120.90,135.62,142.40,152.13,154.06,154.07,154.42,154.58, 158.07, 173.13, 180.46, 185.52, 193.55, 200.14, 207.45, 214.78, 222.52, 228.59, 235.27, 241.72, 250.86, 256.42, 266.13, 271.28, 277.37, 279.95, 287.51, 297.54, 305.82, 314.79, 316.29, 316.67, 324.07, 331.52, 331.60};
  double alct4[n], alct4_N[n], alct5[n], alct5_N[n];
  std::string dataname[n] = {"A1121.root","A1169.root","A1336.root","A1368.root","A1419.root","A1544.root","A1558.root","A1600.root","A1845.root","A1907.root","A2064.root","A2176.root","A2213.root","A2404.root","A2576.root","A2696.root","A2775.root","A2930.root","A2942.root","A2951.root","A3182.root","A3245.root","A3507.root","A3698.root","A3826.root","A4062.root","A4372.root","A4444.root","A4557.root","A4719.root","A4848.root","A5011.root","A5147.root","A5284.root","A5393.root","A5536.root","A5626.root","A5694.root","A5814.root","A5905.root","A6014.root","A6119.root","A6174.root","A6232.root","A6267.root","A6374.root","A6470.root","A6557.root"};
  std::string Normhisto[6] = {"ALCT/hAhitLNorm[0][1]", "ALCT/hAhitLNorm[1][1]", "ALCT/hAhitLNorm[2][1]", "ALCT/hAhitLNorm[3][1]", "ALCT/hAhitLNorm[4][1]", "ALCT/hAhitLNorm[5][1]"};
  std::string histonames[6] = {"layer1","layer2","layer3","layer4","layer5","layer6"};
  std::string data[n];
  std::fill_n(data, 48, "gifRates/me11data/");
  int i, j;
  TFile *fi[n];
  TH1F *h[n];

  for(i=0; i<n; i++){
    data[i].append(dataname[i]);
    fi[i]=new TFile(data[i].c_str(),"read");
  }

  //TFile *f = new TFile("p_wiregroup.root","RECREATE");  

  for(short unsigned int l=0; l<2; l++){
    for(i=0;i<n;i++){
      h[i] = (TH1F*)fi[i]->Get(Normhisto[l+3].c_str()); 
      if(l==0){
        alct4[i] = h[i]->GetBinContent(2);
        alct4_N[i] = h[i]->GetBinContent(3);
      } else {
        alct5[i] = h[i]->GetBinContent(7);
        alct5_N[i] = h[i]->GetBinContent(8);
      }
    }
  }
    c1->cd();
    //gPad->SetLogy();
    TGraph *gr1 = new TGraph(n, dose, alct4);
    TGraph *gr2 = new TGraph(n, dose, alct4_N);
    TGraph *gr3 = new TGraph(n, dose, alct5);
    TGraph *gr4 = new TGraph(n, dose, alct5_N);
    
    gr3->SetTitle("; Accumulated charge [mC/cm]; Normalized dark rate [Hz/cm]");
    gr3->SetLineColor(kRed);
    gr3->SetMarkerColor(kRed);
    gr3->SetMarkerStyle(22);
    gr3->Draw("ALP");
    gr4->SetLineColor(kGreen);
    gr4->SetMarkerColor(kGreen);
    gr4->SetMarkerStyle(23);
    gr4->Draw("LP same");
    gr1->SetLineColor(kRed);
    gr1->SetMarkerColor(kRed);
    gr1->SetMarkerStyle(26);
    gr1->Draw("LP same");
    gr2->SetLineColor(kGreen);
    gr2->SetMarkerColor(kGreen);
    gr2->SetMarkerStyle(32);
    gr2->Draw("LP same");
    TLegend *leg = new TLegend(0.2, 0.68 ,0.5, 0.88, "ME1/1");
    leg->AddEntry(gr1, "problematic WG in L4", "p");
    leg->AddEntry(gr2, "normal WG in L4", "p");
    leg->AddEntry(gr3, "problematic WG in L5", "p");
    leg->AddEntry(gr4, "normal WG in L5", "p");
    leg->SetBorderSize(0);
    leg->Draw();
  /*
    TArrow *ar1 = new TArrow(135,0.003,135,0.001,0.02,"|>");
    ar1->SetAngle(60);
    ar1->SetLineWidth(1);
    ar1->Draw();

    TArrow *ar2 = new TArrow(158,0.005,158,0.001,0.02,"|>");
    ar2->SetAngle(60);
    ar2->SetLineWidth(1);
    ar2->Draw();

    TArrow *ar3 = new TArrow(193,0.01,193,0.0055,0.02,"|>");
    ar3->SetAngle(60);
    ar3->SetLineWidth(1);
    ar3->Draw();

    TArrow *ar4 = new TArrow(257,0.002,257,0.0005,0.02,"|>");
    ar4->SetAngle(60);
    ar4->SetLineWidth(1);
    ar4->Draw();

    TArrow *ar5 = new TArrow(257,0.004,257,0.008,0.02,"|>");
    ar5->SetAngle(60);
    ar5->SetLineWidth(1);
    ar5->Draw();

    TLatex latex;
    latex.SetNDC();
    latex.SetTextFont(42);
    latex.SetTextSize(0.03);
    latex.SetTextColor(kBlack);
    latex.DrawLatex(0.42,0.34,"10 days");
    latex.DrawLatex(0.46,0.35,"pause");
    latex.DrawLatex(0.48,0.50,"12 days");
    latex.DrawLatex(0.51,0.50,"pause");
    latex.DrawLatex(0.58,0.75,"34 days");
    latex.DrawLatex(0.61,0.82,"pause");
    latex.DrawLatex(0.71,0.30,"14 days");
    latex.DrawLatex(0.76,0.32,"pause");*/
//   c1->cd();
//   latex.DrawLatex(0.1, 0.3, extraText);

 
//  TH1D * projh2X = histo2DL[0]->ProjectionX();
//  TH1D * projh2Y = histo2DL[0]->ProjectionY();
//  c1->cd(7);
//  projh2X->Draw();
//  c1->cd(8);
//  projh2Y->Draw();
//  c1->cd(9);
//  histo2DL[0]->Draw("lego");
  c1->SaveAs("me11ratevsproblem.root");
//  f->Write();
//  c1->Close();
//  f->Close();
}
