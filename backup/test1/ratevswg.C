{

  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas("me11ratevswg","rate vs dose",10,10,1200,800);
  c1->Divide(3,2);


  const int n1=46, n2=30;
  double dose1[47+n2] = {0,17.42,25.23,40.40,47.87,50.94,59.38,59.39,59.43,77.94,89.81,95.44,104.24,113.27,120.90,135.62,142.40,152.13,154.06,154.07,154.42,154.58, 158.07, 173.13, 180.46, 186.99, 193.55, 200.14, 207.45, 214.78, 222.52, 228.59, 235.27, 241.72, 250.86, 256.42, 271.28, 277.37, 279.95, 287.51, 297.54, 305.82, 314.79, 316.29, 316.67, 324.07, 340};
  double dose2[n2] = {1.92, 9.31, 15.85, 15.86, 21.59, 27.48, 27.54, 28.29, 29.63, 31.38, 32.44, 32.93, 33.88, 35.10, 41.86, 48.44, 55.30, 61.30, 66.09, 68.8, 76.03, 90.26, 97.65, 104.17, 110.26, 115.64, 121.71, 126.25, 133.31, 140.19};
  for(int i=0; i<n2; i++) dose1[47+i] += (350. + dose2[i]);

  int alct1[n1+n2] = {7827,7591,7870,7768,7774,8555,7913,7575,8001,7977,7930,8018,8512,8395,8341,8316,8387,7359,7069,7146,7735,8457,8793,9030, 10111, 8422, 8497, 8702, 8424, 9286, 10012, 11562, 8883, 9158, 11082, 9806, 14149, 9291, 12770, 14046, 15306, 15378, 43004/3, 19961, 15052, 12299, 12122, 9854, 12331, 9832, 8945, 11083, 8557, 9543, 10408, 8441, 7864, 7801, 8801, 8279, 11186, 10282, 8396, 8231, 9223, 9378, 8549, 9895, 10954, 10865, 8420, 9046, 9537, 9256, 8924, 8915};
  for(int t=0; t<n1+n2; t++) alct1[t] /= 10;
  std::string dataname1[n1+n2] = {"A1121.root","A1169.root","A1336.root","A1368.root","A1419.root","A1544.root","A1558.root","A1600.root","A1845.root","A1907.root","A2064.root","A2176.root","A2213.root","A2404.root","A2576.root","A2696.root","A2775.root","A2930.root","A2942.root","A2951.root","A3182.root","A3245.root","A3507.root","A3698.root","A3826.root","A4062.root","A4372.root","A4444.root","A4557.root","A4719.root","A4848.root","A5011.root","A5147.root","A5284.root","A5393.root","A5626.root","A5694.root","A5814.root","A5905.root","A6014.root","A6119.root","A6174.root","A6232.root","A6267.root","A6374.root","A6557.root","A6745.root","A6790.root","A6829.root","A6869.root","A6928.root","A7001.root","A7042.root","A7079.root","A7136.root","A7183.root","A7269.root","A7314.root","A7401.root","A7450.root","A7503.root","A7558.root","A7608.root","A7647.root","A7690.root","A7756.root","A7801.root","A7843.root","A7889.root","A7944.root","A7992.root","A8038.root","A8086.root","A8132.root","A8179.root","A8350.root"};


  std::string Normhisto[6] = {"ALCT/hAhitLNorm[0][1]", "ALCT/hAhitLNorm[1][1]", "ALCT/hAhitLNorm[2][1]", "ALCT/hAhitLNorm[3][1]", "ALCT/hAhitLNorm[4][1]", "ALCT/hAhitLNorm[5][1]"};
  std::string histonames1[6] = {"me11 layer1","me11 layer2","me11 layer3","me11 layer4","me11 layer5","me11 layer6"};


  for(short unsigned int l=0; l<6; l++){
    TH2F *histo1_temp = new TH2F(histonames1[l].c_str(),histonames1[l].c_str(),n1+n2,dose1,49,0,49);

    for(int i=0;i<n1+n2;i++){
      TFile *fi1_temp;
      if(i<n1) fi1_temp = new TFile(("../gifRates/me11data/10pct/"+dataname1[i]).c_str(),"read");
      else if(i>=n1) fi1_temp = new TFile(("../gifRates/me11data/"+dataname1[i]).c_str(),"read");
      TH1F *h1_temp = (TH1F*)fi1_temp->Get(Normhisto[l].c_str());
      for(int j=0;j<49;j++){
        Float_t binc = h1_temp->GetBinContent(j);
        histo1_temp->SetBinContent(i+1,j,binc*alct1[i]);
      }
    }

    c1->cd(l+1);
    gPad->SetRightMargin(0.15);
    histo1_temp->SetMaximum(0.03);
    histo1_temp->GetXaxis()->SetTitle("Accumulated charge [mC/cm]");
    histo1_temp->GetYaxis()->SetTitle("Wire group");
    histo1_temp->SetTitleSize(0.05);
    histo1_temp->GetXaxis()->SetTitleSize(0.05);
    histo1_temp->GetYaxis()->SetTitleSize(0.05);
    histo1_temp->Draw("colz");

    TLine *line = new TLine(340., 0., 340., 49.);
    line->SetLineWidth(2);
    line->SetLineStyle(2);
    line->Draw();

    TArrow *ar1 = new TArrow(290, 25, 340, 25, 0.01,"<|");
    //ar1->SetAngle(40);
    ar1->SetLineWidth(2);
    //ar1->SetFillColor(2);
    ar1->Draw();

    TText *t1 = new TText(200, 25,"10\% CF4");
    t1->SetTextAlign(22);
    t1->SetTextColor(kBlack);
    t1->SetTextFont(43);
    t1->SetTextSize(20);
    t1->SetTextAngle(45);
    t1->Draw();

    TArrow *ar2 = new TArrow(340, 25, 390, 25, 0.01,"|>");
    //ar2->SetAngle(40);
    ar2->SetLineWidth(2);
    //ar2->SetFillColor(2);
    ar2->Draw();

    TText *t2 = new TText(430, 25,"2\% CF4");
    t2->SetTextAlign(22);
    t2->SetTextColor(kBlack);
    t2->SetTextFont(43);
    t2->SetTextSize(20);
    t2->SetTextAngle(45);
    t2->Draw();

  }

  c1->SaveAs("me11ratevswg.pdf");

}
