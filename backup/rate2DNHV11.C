#include "TH1F.h"
#include "TFile.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TString.h"
#include "TGraph.h"
#include "TStyle.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>


void rate2DNHV11(){
  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas("c1","2D histo",1);
  c1->Divide(2,2);

   TLatex latex;
   latex.SetNDC();
   latex.SetTextFont(42);
   latex.SetTextColor(kBlack);

  const int row=34, col=17;
  string column;
  double tmp, charge[35]={0}, alctrate[34][11]={0}, clctrate[34][11]={0}, tmbrate[34][11]={0};
  double voltage[12]={2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 2.95, 3.0};
  ifstream file1, file2, file3;
  
  file1.open("txtdir/Nme11alct.txt");
  file2.open("txtdir/Nme11clct.txt");
  file3.open("txtdir/Nme11tmb.txt");

  int i=0;
  for (string line; getline(file1,line); ){
    std::istringstream iss(line);
    iss >> column >> column >> column >> charge[i+1] >> tmp;
    for (int j=0;j<11;j++){
      iss >> alctrate[i][j];
    }
    i++;
  }
  i=0;
  for (string line; getline(file2,line); ){
    std::istringstream iss(line);
    iss >> column >> column >> column >> charge[i+1] >> tmp;
    for (int j=0;j<11;j++){
      iss >> clctrate[i][j];
    }
    i++;
  }
  i=0;
  for (string line; getline(file3,line); ){
    std::istringstream iss(line);
    iss >> column >> column >> column >> charge[i+1] >> tmp;
    for (int j=0;j<11;j++){
      iss >> tmbrate[i][j];
    }
    i++;
  }
  TH2F *alctrate2DHV = new TH2F("ALCT","ALCT rate vs. voltage & dose",34,charge,11,voltage);
  TH2F *clctrate2DHV = new TH2F("CLCT","CLCT rate vs. voltage & dose",34,charge,11,voltage);
  TH2F *tmbrate2DHV = new TH2F("TMB","TMB rate vs. voltage & dose",34,charge,11,voltage);
  for(int j=0; j<34; j++ ){
    for(int k=0; k<11; k++){
        alctrate2DHV->SetBinContent(j+1, k+1, alctrate[j][k]);
        clctrate2DHV->SetBinContent(j+1, k+1, clctrate[j][k]);
        tmbrate2DHV->SetBinContent(j+1, k+1, tmbrate[j][k]);
    }
  }

  c1->cd(4);
  latex.DrawLatex(0.4, 0.5, "ME11 Normalized value");

//  gPad->SetLogz();

  c1->cd(1);
  alctrate2DHV->SetMaximum(2);
  alctrate2DHV->GetXaxis()->SetTitle("Charge(mC/cm)");
  alctrate2DHV->GetYaxis()->SetTitle("Voltage(kV)");
  alctrate2DHV->Draw("colz"); 

  c1->cd(2);
  clctrate2DHV->SetMaximum(2);
  clctrate2DHV->GetXaxis()->SetTitle("Charge(mC/cm)");
  clctrate2DHV->GetYaxis()->SetTitle("Voltage(kV)");
  clctrate2DHV->Draw("colz");

  c1->cd(3);
  tmbrate2DHV->SetMaximum(2);
  tmbrate2DHV->GetXaxis()->SetTitle("Charge(mC/cm)");
  tmbrate2DHV->GetYaxis()->SetTitle("Voltage(kV)");
  tmbrate2DHV->Draw("colz");

  c1->SaveAs("rate2DNHV11.pdf");
}


