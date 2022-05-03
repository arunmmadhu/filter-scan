void ratevsdose() {

   TCanvas *c1 = new TCanvas("me11ratevsdose","rate vs dose",10,10,600,600);

   const int n2 = 30;

   std::string dataname[n2] = {"A6745.root","A6790.root","A6829.root","A6869.root","A6928.root","A7001.root","A7042.root","A7079.root","A7136.root","A7183.root","A7269.root","A7314.root","A7401.root","A7450.root","A7503.root","A7558.root","A7608.root","A7647.root","A7690.root","A7756.root","A7801.root","A7843.root","A7889.root","A7944.root","A7992.root","A8038.root","A8086.root","A8132.root","A8179.root","A8350.root"};

   std::string histo[6] = {"ALCT/hAhitL[0][1]", "ALCT/hAhitL[1][1]", "ALCT/hAhitL[2][1]", "ALCT/hAhitL[3][1]", "ALCT/hAhitL[4][1]", "ALCT/hAhitL[5][1]"};
   std::string histonames[6] = {"layer1","layer2","layer3","layer4","layer5","layer6"};

   double N_tot_2p[n2] = {}, N_bad_2p[n2] = {};

   for(int i=0;i<n2;i++){
     TFile *f_temp = new TFile(("../gifRates/me11data/"+dataname[i]).c_str(),"read");
     for(short unsigned int l=0; l<6; l++){
       TH1F *h_temp = (TH1F*)f_temp->Get(histo[l].c_str());
       N_tot_2p[i] += h_temp->GetEntries();
       if(l==3) N_bad_2p[i] += h_temp->GetBinContent(2);
       if(l==4) N_bad_2p[i] += h_temp->GetBinContent(7);
       delete h_temp;
     }
     delete f_temp;
   }


   double charge2[n2] = {1.92, 9.31, 15.85, 15.86, 21.59, 27.48, 27.54, 28.29, 29.63, 31.38, 32.44, 32.93, 33.88, 35.10, 41.86, 48.44, 55.30, 61.30, 66.09, 68.8, 76.03, 90.26, 97.65, 104.17, 110.26, 115.64, 121.71, 126.25, 133.31, 140.19};

   double alct2[n2] = {1212.2, 985.4, 1233.1, 983.2, 894.5, 1108.3, 855.7, 954.3, 1040.8, 844.1, 786.4, 780.1, 880.1, 827.9, 1118.6, 1028.2, 839.6, 823.1, 922.3, 937.8, 854.9, 989.5, 1095.4, 1086.5, 842.0, 904.6, 953.7, 925.6, 892.4, 891.5};

   double clct2[n2] = {1024.2, 948.9, 965.3, 925.7, 1032.4, 918.9, 965.5, 954.7, 1011, 923.7, 975.2, 1032, 582.8, 614.0, 789.8, 737.7, 749.3, 577.4, 562.8, 850.2, 911.1, 746.7, 781.6, 577.9, 604.5, 593.2, 596.2, 617.7};
                 //1096.2, 970.6, 1079.9, 999.1, 1056.5, 998.0, 987.4, 1000.7, 1104.6, 928.2, 969.1, 1021.5, 596.6, 646.9, 928.3, 822.6, 741.6, 593.6, 631.2, 861.8, 837.2, 674.4, 686.9, };
//728.7, 758.7, 861.8, 956.9, 799.7, 810.4};

   double cna2[n2] =  {743.8, 628.7, 752.2, 651.2, 579.8, 628.7, 581.0, 607.4, 655.2, 568.3, 545.1, 552.8, 574.8, 575.5, 719.5, 683.2, 584.8, 463.2, 483.1, 570.2, 553.5, 487.6, 530.3, 499.5, 523.1, 510.1, 515.5, 529.4};

   double alct_correction_2p[n2];
   for(int i = 0; i< n2; i++){
     alct_correction_2p[i] = alct2[i]*(1-(N_bad_2p[i]/N_tot_2p[i]));
   }


   TGraph *gr11_2p = new TGraph(n2, charge2, alct2);
   TGraph *gr12_2p = new TGraph(n2, charge2, clct2);
   TGraph *gr13_2p = new TGraph(n2, charge2, cna2);
   TGraph *gr10_2p = new TGraph(n2, charge2, alct_correction_2p);


   c1->cd();
   gr11_2p->SetTitle("; Accumulated charge [mC/cm]; Dark rate [Hz]");
   gr11_2p->GetYaxis()->SetTitleOffset(1.5);
   gr11_2p->SetMinimum(0);
   gr11_2p->SetMaximum(1600);
   gr11_2p->SetMarkerColor(kRed);
   gr11_2p->SetLineColor(kRed);
   gr11_2p->SetMarkerStyle(22);
   gr11_2p->SetMarkerSize(1.5);
   gr11_2p->Draw("APL");

   gr12_2p->SetMarkerColor(kBlue);
   gr12_2p->SetLineColor(kBlue);
   gr12_2p->SetMarkerStyle(23);
   gr12_2p->SetMarkerSize(1.5);
   //gr12_2p->Draw("PL same");

   gr13_2p->SetMarkerColor(kGreen);
   gr13_2p->SetLineColor(kGreen);
   gr13_2p->SetMarkerStyle(20);
   gr13_2p->SetMarkerSize(1.5);
   //gr13_2p->Draw("PL same");

   gr10_2p->SetMarkerColor(kRed);
   gr10_2p->SetLineColor(kBlack);
   gr10_2p->SetMarkerStyle(24);
   gr10_2p->SetMarkerSize(1.5);
   gr10_2p->Draw("PL same");

   TLegend *leg1 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME1/1 dark rare in whole chamber");
   leg1->AddEntry(gr11_2p, "ALCT", "pl");
   //leg1->AddEntry(gr12_2p, "CLCT", "pl");
   //leg1->AddEntry(gr13_2p, "ALCT*CLCT", "pl"); 
   leg1->AddEntry(gr10_2p, "ALCT without problem wgs", "pl");
   leg1->SetBorderSize(0);
   leg1->Draw();


   c1->SaveAs("me11ratevsdose.pdf");

}
