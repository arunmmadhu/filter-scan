void ptest() {
   const int n=35;

   ////////////////////////////////////
   //    alct correction for me11    //
   ////////////////////////////////////
   std::string dataname[n] = {"A1121.root","A1169.root","A1228.root","A1336.root","A1419.root","A1558.root","A1688.root","A1845.root","A1907.root","A2064.root","A2176.root","A2213.root","A2404.root","A2576.root","A2696.root","A2775.root","A2951.root","A3182.root","A3245.root","A3449.root","A3507.root","A3698.root","A3826.root","A4062.root","A4372.root","A4444.root","A4557.root","A4719.root","A4848.root","A5011.root","A5147.root","A5284.root","A5393.root","A5536.root","A5626.root"};
   std::string histo[6] = {"hAhitL[0]", "hAhitL[1]", "hAhitL[2]", "hAhitL[3]", "hAhitL[4]", "hAhitL[5]"};
   std::string histonames[6] = {"layer1","layer2","layer3","layer4","layer5","layer6"};
   std::string data[n];
   std::fill_n(data, 35, "gifRates/me11data/");
   TFile *fi[n];
   TH1F *h[n];
   for(int i=0; i<n; i++){
     data[i].append(dataname[i]);
     fi[i]=new TFile(data[i].c_str(),"read");
   }

   for(int i=n-6;i<n;i++){
     for(short unsigned int l=0; l<6; l++){
       h[i] = (TH1F*)fi[i]->Get(histo[l].c_str());
       //N_tot[i+2] += h[i]->GetEntries();
       if(l==3) for(int j=0; j<44; j++) cout << l << "-" << j << "::" << h[i]->GetBinContent(j) << endl;//N_bad[i+2] += h[i]->GetBinContent(2);
       if(l==4) for(int j=0; j<44; j++) cout << l << "-" << j << "::" << h[i]->GetBinContent(j) << endl;//N_bad[i+2] += h[i]->GetBinContent(7);
     }
   }

}
