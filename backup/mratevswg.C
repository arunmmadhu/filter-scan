{
  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas("c1","his1",1);
  TCanvas *c2 = new TCanvas("c2","his2",1);
  c1->Divide(3,2);
  c2->Divide(3,2);
/*
   TString extraText   = "CSC ME1/1, ALCT:anode hit occupancy per unit wire group in each layer";
   TLatex latex;
   latex.SetNDC();
   latex.SetTextFont(42);
   latex.SetTextColor(kBlack);
*/

  const int n1=17, n2=9;
  double dose1[18] = {0, 32.1, 50.9, 64.0, 104.2, 120.9, 142.4, 152.1, 207.5, 214.8, 222.5, 228.6, 235.3, 243.5, 250.9, 279.9, 287.5, 305.82};
  int alct1[n1] = {255673, 475894, 2329, 26430, 44563, 1275, 21757, 908, 869, 981, 1497, 1310, 970, 1011, 959, 1385, 1316};
  std::string dataname1[n1] = {"A1186.root", "A1374.root", "A1729.root", "A2165.root", "A2393.root", "A2665.root", "A2766.root", "A4403.root", "A4531.root", "A4674.root", "A4799.root", "A4970.root", "A5105.root", "A5243.root", "A5719.root", "A5822.root", "A5925.root"};

  //2016: 0218, 0303, 0404, 0414, 0415, 0511, 0515, 0518, 0615, 0629, 0715, 0720, 0803, 0810, 0907, 0921, 1012, 1019, 1026, 1102, 1109, 1116, 1216; 2017: 0117, 0125, 0201, 0208, 0215, 0222, 0301, 0308, 0315, 0409, 0419, 0424, 0505, 0526, 0531, 0607, 0621
  double dose2[10] = {0, 30.4, 49.1, 60.7, 89.6, 181.0, 187.1, 265.3, 272.8, 314.30};
  int alct2[n2] = {361163, 475894, 1279514, 2339, 3482, 2802, 3055, 3238, 3681};
  std::string dataname2[n2] = {"A1190.root", "A1374.root", "A1721.root", "A1992.root","A3870.root", "A4270.root", "A5725.root", "A5828.root", "A5931.root"};


  std::string Normhisto[6] = {"ALCT/hAhitLNorm[0][1]", "ALCT/hAhitLNorm[1][1]", "ALCT/hAhitLNorm[2][1]", "ALCT/hAhitLNorm[3][1]", "ALCT/hAhitLNorm[4][1]", "ALCT/hAhitLNorm[5][1]"};
  std::string histonames1[6] = {"me11layer1","me11layer2","me11layer3","me11layer4","me11layer5","me11layer6"};
  std::string histonames2[6] = {"me21layer1","me21layer2","me21layer3","me21layer4","me21layer5","me21layer6"};
  std::string data1[n1], data2[n2];
  std::fill_n(data1, 17, "gifRates/ME11/");
  std::fill_n(data2, 9, "gifRates/ME21/");

  int i, j;
  TFile *fi1[n1], *fi2[n2];
  TH1F *h1[n1], *h2[n2];
  TH2F *histo1[6], *histo2[6];

  for(i=0; i<n1; i++){
    data1[i].append(dataname1[i]);
    fi1[i]=new TFile(data1[i].c_str(),"read");
  }
  for(i=0; i<n2; i++){
    data2[i].append(dataname2[i]);
    fi2[i]=new TFile(data2[i].c_str(),"read");
  }
  //TFile *f = new TFile("histo2Dme11.root","RECREATE");  
  for(short unsigned int l=0; l<6; l++){
    histo1[l] = new TH2F(histonames1[l].c_str(),histonames1[l].c_str(),17,dose1,44,0,44);
    histo2[l] = new TH2F(histonames2[l].c_str(),histonames2[l].c_str(),9,dose2,112,0,112);

    for(i=0;i<n1;i++){
      h1[i] = (TH1F*)fi1[i]->Get(Normhisto[l].c_str());
      for(j=0;j<44;j++){
        Float_t binc = h1[i]->GetBinContent(j);
        histo1[l]->SetBinContent(i+1,j,binc*alct1[i]);
      }
    }

    for(i=0;i<n2;i++){
      h2[i] = (TH1F*)fi2[i]->Get(Normhisto[l].c_str());
      for(j=0;j<112;j++){
        Float_t binc = h2[i]->GetBinContent(j);
        histo2[l]->SetBinContent(i+1,j,binc*alct2[i]);
      }
    }

    c1->cd(l+1);
    histo1[l]->SetMaximum(0.2);
    histo1[l]->GetXaxis()->SetTitle("Accumulated charge [mC/cm]");
    histo1[l]->GetYaxis()->SetTitle("Wire group");
    histo1[l]->Draw("colz");



    c2->cd(l+1);
    histo2[l]->SetMaximum(0.2);
    histo2[l]->GetXaxis()->SetTitle("Accumulated charge [mC/cm]");
    histo2[l]->GetYaxis()->SetTitle("Wire group");
    histo2[l]->Draw("colz");



  }
  

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
  c1->SaveAs("malter11.pdf");
  c2->SaveAs("malter21.pdf");
//  f->Write();
//  c1->Close();
//  f->Close();

}
