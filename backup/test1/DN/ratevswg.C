{

  gStyle->SetOptStat(0);

  TFile *fi = new TFile("wgvsrate.root", "RECREATE");
  TCanvas *c1 = new TCanvas("me11ratevswg","rate vs dose",10,10,1200,800);
  TCanvas *c2 = new TCanvas("me21ratevswg","rate vs dose",10,10,1200,800);
  c1->Divide(3,2);
  c2->Divide(3,2);


  const int n1=46, n2=46;
  double dose1[47] = {0,17.42,25.23,40.40,47.87,50.94,59.38,59.39,59.43,77.94,89.81,95.44,104.24,113.27,120.90,135.62,142.40,152.13,154.06,154.07,154.42,154.58, 158.07, 173.13, 180.46, 186.99, 193.55, 200.14, 207.45, 214.78, 222.52, 228.59, 235.27, 241.72, 250.86, 256.42, 271.28, 277.37, 279.95, 287.51, 297.54, 305.82, 314.79, 316.29, 316.67, 324.07, 340};
  int alct1[n1] = {7827,7591,7870,7768,7774,8555,7913,7575,8001,7977,7930,8018,8512,8395,8341,8316,8387,7359,7069,7146,7735,8457,8793,9030, 10111, 8422, 8497, 8702, 8424, 9286, 10012, 11562, 8883, 9158, 11082, 9806, 14149, 9291, 12770, 14046, 15306, 15378, 43004/3, 19961, 15052, 12299};
  for(int t=0; t<n1; t++) alct1[t] /= 10;
  std::string dataname1[n1] = {"A1121.root","A1169.root","A1336.root","A1368.root","A1419.root","A1544.root","A1558.root","A1600.root","A1845.root","A1907.root","A2064.root","A2176.root","A2213.root","A2404.root","A2576.root","A2696.root","A2775.root","A2930.root","A2942.root","A2951.root","A3182.root","A3245.root","A3507.root","A3698.root","A3826.root","A4062.root","A4372.root","A4444.root","A4557.root","A4719.root","A4848.root","A5011.root","A5147.root","A5284.root","A5393.root","A5626.root","A5694.root","A5814.root","A5905.root","A6014.root","A6119.root","A6174.root","A6232.root","A6267.root","A6374.root","A6557.root"};

  //2016: 0218, 0303, 0404, 0414, 0415, 0511, 0515, 0518, 0615, 0629, 0715, 0720, 0803, 0810, 0907, 0921, 1012, 1019, 1026, 1102, 1109, 1116, 1216; 2017: 0117, 0125, 0201, 0208, 0215, 0222, 0301, 0308, 0315, 0409, 0419, 0424, 0505, 0526, 0531, 0607, 0621
  double dose2[47] = {0,17.95,33.83,53.84,62.33,62.36,66.59,69.87,73.12,93.13, 98.86,118.96,124.68,140.28,/*147.37,*/158.52,158.72,158.99,159.00,162.72, 169.92,178.52,186.31,190.61,195.32,197.36, 204.07, 211.80, 219.56, 227.74, 233.97, 240.84, 247.69, 257.44, 263.47, 273.86, 279.19, /*285.78,*/ 285.88, 288.49, 296.40, 306.13, 314.30, 322.94, 324.40, 324.77, 332.99, 340.75, 350};
  int alct2[n2] = {25264,27889,27169,30839,30069,28511,27992,28902,28304,28166,28274,29438,28863,/*27335,*/27500,26606,24164,24755,26812,26482,26042,25560,25659,25593,25430,25903,26503,25740,25951,25555,26263,25973,26260,26383,26252,26302,/*28321,*/27596,25507,25981,28536,27984, 26154, 76467/3, 27139, 27923, 26096, 25542};
  for(int t=0; t<n2; t++) alct2[t] /= 10; 
  std::string dataname2[n2] = {"A1053.root","A1252.root","A1382.root","A1458.root","A1574.root","A1663.root","A1737.root","A1754.root","A1974.root","A2003.root","A2314.root","A2463.root","A2539.root",/*"A2713.root",*/"A2856.root","A2937.root","A3058.root","A3123.root","A3308.root","A3376.root","A3570.root","A3643.root","A3771.root","A3911.root","A3998.root","A4319.root","A4505.root","A4548.root","A4780.root","A4909.root","A5076.root","A5209.root","A5345.root","A5437.root","A5579.root","A5666.root",/*"A5692.root",*/"A5698.root","A5762.root","A5865.root","A5965.root","A6085.root","A6208.root","A6236.root","A6310.root","A6411.root","A6504.root","A6598.root"};

  std::string Normhisto[6] = {"ALCT/hAhitLNorm[0][1]", "ALCT/hAhitLNorm[1][1]", "ALCT/hAhitLNorm[2][1]", "ALCT/hAhitLNorm[3][1]", "ALCT/hAhitLNorm[4][1]", "ALCT/hAhitLNorm[5][1]"};
  std::string histonames1[6] = {"me11 layer1","me11 layer2","me11 layer3","me11 layer4","me11 layer5","me11 layer6"};
  std::string histonames2[6] = {"me21 layer1","me21 layer2","me21 layer3","me21 layer4","me21 layer5","me21 layer6"};


  for(short unsigned int l=0; l<6; l++){
    TH2F *histo1_temp = new TH2F(histonames1[l].c_str(),histonames1[l].c_str(),46,dose1,49,0,49);
    TH2F *histo2_temp = new TH2F(histonames2[l].c_str(),histonames2[l].c_str(),46,dose2,112,0,112);

    for(int i=0;i<n1;i++){
      TFile *fi1_temp = new TFile(("../gifRates/me11data/test1/"+dataname1[i]).c_str(),"read");
      TH1F *h1_temp = (TH1F*)fi1_temp->Get(Normhisto[l].c_str());
      for(int j=0;j<49;j++){
        Float_t binc = h1_temp->GetBinContent(j);
        histo1_temp->SetBinContent(i+1,j,binc*alct1[i]);
      }
    }

    for(int i=0;i<n2;i++){
      TFile *fi2_temp = new TFile(("../gifRates/me21data/"+dataname2[i]).c_str(),"read");
      TH1F *h2_temp = (TH1F*)fi2_temp->Get(Normhisto[l].c_str());
      for(int j=0;j<112;j++){
        Float_t binc = h2_temp->GetBinContent(j);
        histo2_temp->SetBinContent(i+1,j,binc*alct2[i]);
      }
    }


    c1->cd(l+1);
    histo1_temp->SetMaximum(0.03);
    histo1_temp->GetXaxis()->SetTitle("Accumulated charge [mC/cm]");
    histo1_temp->GetYaxis()->SetTitle("Wire group");
    histo1_temp->SetTitleSize(0.05);
    histo1_temp->GetXaxis()->SetTitleSize(0.05);
    histo1_temp->GetYaxis()->SetTitleSize(0.05);
    histo1_temp->Draw("colz");



    c2->cd(l+1);
    histo2_temp->SetMaximum(0.04);
    histo2_temp->GetXaxis()->SetTitle("Accumulated charge [mC/cm]");
    histo2_temp->GetYaxis()->SetTitle("Wire group");
    histo2_temp->SetTitleSize(0.05);
    histo2_temp->GetXaxis()->SetTitleSize(0.05);
    histo2_temp->GetYaxis()->SetTitleSize(0.05);
    histo2_temp->Draw("colz");

fi->cd();
histo1_temp->Write();
histo2_temp->Write();

  }
fi->cd();
c1->Write("me11ratevswg");
c2->Write("me21ratevswg");
fi->Close();
  //c1->SaveAs("me11ratevswg.root");
  //c2->SaveAs("me21ratevswg.root");

}
