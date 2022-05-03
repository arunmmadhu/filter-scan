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


void rate2DNHV21(){
  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas("c1","2D histo",1);
  c1->Divide(2,2);

   TLatex latex;
   latex.SetNDC();
   latex.SetTextFont(42);
   latex.SetTextColor(kBlack);

  const int row=33, col=17;
  string column;
  double tmp, charge[34]={0}, alctrate[33][13]={0}, clctrate[33][13]={0}, tmbrate[33][13]={0};
  double voltage[14]={2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9};
  ifstream file1, file2, file3;
  
  file1.open("txtdir/Nme21alct.txt");
  file2.open("txtdir/Nme21clct.txt");
  file3.open("txtdir/Nme21tmb.txt");

  int i=0;
  for (string line; getline(file1,line); ){
    std::istringstream iss(line);
    iss >> column >> column >> column >> charge[i+1] >> tmp;
    for (int j=0;j<13;j++){
      iss >> alctrate[i][j];
    }
    i++;
  }
  i=0;
  for (string line; getline(file2,line); ){
    std::istringstream iss(line);
    iss >> column >> column >> column >> charge[i+1] >> tmp;
    for (int j=0;j<13;j++){
      iss >> clctrate[i][j];
    }
    i++;
  }
  i=0;
  for (string line; getline(file3,line); ){
    std::istringstream iss(line);
    iss >> column >> column >> column >> charge[i+1] >> tmp;
    for (int j=0;j<13;j++){
      iss >> tmbrate[i][j];
    }
//cout << charge[i] << endl;
    i++;
  }
  TH2F *alctrate2DHV = new TH2F("ALCT","ALCT rate vs. voltage & dose",33,charge,13,voltage);
  TH2F *clctrate2DHV = new TH2F("CLCT","CLCT rate vs. voltage & dose",33,charge,13,voltage);
  TH2F *tmbrate2DHV = new TH2F("TMB","TMB rate vs. voltage & dose",33,charge,13,voltage);
  for(int j=0; j<33; j++ ){
    for(int k=0; k<13; k++){
        alctrate2DHV->SetBinContent(j+1, k+1, alctrate[j][k]);
        clctrate2DHV->SetBinContent(j+1, k+1, clctrate[j][k]);
        tmbrate2DHV->SetBinContent(j+1, k+1, tmbrate[j][k]);
    }
  }

  c1->cd(4);
  latex.DrawLatex(0.4, 0.5, "ME21 Normalized value");

//  gPad->SegLogz();
  
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

  c1->SaveAs("rate2DNHV21.pdf");
}


