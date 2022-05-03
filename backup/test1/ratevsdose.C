void ratevsdose() {

   TCanvas *c1 = new TCanvas("me11ratevsdose","rate vs dose",10,10,900,700);

   const int n1 =46, n2=30;
   
   ////////////////////////////////////
   //    alct correction for me11    //
   ////////////////////////////////////
   std::string dataname_10p[44] = {"A1121.root","A1169.root","A1228.root","A1336.root","A1419.root","A1558.root","A1688.root","A1845.root","A1907.root","A2064.root","A2176.root","A2213.root","A2404.root","A2576.root","A2696.root","A2775.root","A2951.root","A3182.root","A3245.root","A3449.root","A3507.root","A3698.root","A3826.root","A4062.root","A4372.root","A4444.root","A4557.root","A4719.root","A4848.root","A5011.root","A5147.root","A5284.root","A5393.root","A5536.root","A5626.root","A5694.root","A5814.root","A5905.root","A6014.root","A6119.root","A6174.root","A6267.root","A6374.root","A6557.root"};

   std::string dataname_2p[n2] = {"A6745.root","A6790.root","A6829.root","A6869.root","A6928.root","A7001.root","A7042.root","A7079.root","A7136.root","A7183.root","A7269.root","A7314.root","A7401.root","A7450.root","A7503.root","A7558.root","A7608.root","A7647.root","A7690.root","A7756.root","A7801.root","A7843.root","A7889.root","A7944.root","A7992.root","A8038.root","A8086.root","A8132.root","A8179.root","A8350.root"};

   std::string histo[6] = {"ALCT/hAhitL[0][1]", "ALCT/hAhitL[1][1]", "ALCT/hAhitL[2][1]", "ALCT/hAhitL[3][1]", "ALCT/hAhitL[4][1]", "ALCT/hAhitL[5][1]"};
   std::string histonames[6] = {"layer1","layer2","layer3","layer4","layer5","layer6"};

   double N_tot[n1]={0}, N_bad[n1]={0};
   for(int i=0;i<44;i++){
     TFile *f_temp = new TFile(("../gifRates/me11data/10pct/"+dataname_10p[i]).c_str(),"read");
     for(short unsigned int l=0; l<6; l++){
       TH1F *h_temp = (TH1F*)f_temp->Get(histo[l].c_str());
       N_tot[i+2] += h_temp->GetEntries();
       if(l==3) N_bad[i+2] += h_temp->GetBinContent(2);
       if(l==4) N_bad[i+2] += h_temp->GetBinContent(7);
       delete h_temp;
     }
     delete f_temp;
   }

   double N_tot_2p[n2] = {0}, N_bad_2p[n2] = {0};
   for(int i=0;i<n2;i++){
     TFile *f_temp = new TFile(("../gifRates/me11data/"+dataname_2p[i]).c_str(),"read");
     for(short unsigned int l=0; l<6; l++){
       TH1F *h_temp = (TH1F*)f_temp->Get(histo[l].c_str());
       N_tot_2p[i] += h_temp->GetEntries();
       //if(l==3) N_bad_2p[i] += h_temp->GetBinContent(2);
       if(l==4) N_bad_2p[i] += h_temp->GetBinContent(7);
       delete h_temp;
     }
     delete f_temp;
   }


        //dates: 2016::0203, 0211, 0218, 0225, 0303, 0310, 0404, 0415, 0511, 0526, 0615, 0629, 0706, 0713, 0720, 0803, 0810, 0831, 1009, 1019, 1026, 1102, 1109, 1116, 1123;2017::0117, 0125, 0201, 0208, 0215, 0222, 0301, 0308, 0315, 0407, 0419, 0424, 0505, 0531, 0607, 0621, 0628
   double charge1[n1] = {0.49, 11.3, 17.6, 25.5, 33.1, 40.9, 51.2, 59.38, 63.97, 77.94, 89.81, 95.44, 104.24, 113.27, 120.90, 135.62, 142.40, 152.13, 154.42, 154.58, 156.55, 163.68, 171.28, 180.46, 186.99, 193.55, 200.14, 207.45, 214.78, 222.52, 228.59, 235.27, 241.72, 250.86, 256.42, 266.13, 271.28, 277.37, 279.95, 287.51, 297.54, 305.82, 314.79, 316.67, 324.07, 340};
   double alct1[n1] = {764, 783, 783,  759,  789,  787.0,  777,  791, 785, 800, 798, 793, 802, 851, 840, 834, 832, 839, 714.6, 773.5, 845.7, 824.1, 879.3, 903.0, 1011.1, 842.2, 849.7, 870.2, 842.4, 928.6, 1001.2, 1156.2, 888.3, 915.8, 1108.2, 873.6, 980.6, 1414.9, 929.1, 1277.0, 1404.6, 1530.6, 1537.8, 1996.1, 1505.2, 1229.9};
   //double clct1[n1] = {882, 766.5, 721.5, 664.5, 594.15, 687.45, 680.25, 671.1, 616.6, 566.2, 627.5, 624.8, 616.6, 642.1, 643.9, 655.4, 568.0, 557.5, 646.1, 594.6, 685.0,  468.2, 617.6, 619.7, 657.0, 661.2, 622.4, 612.1, 616.9, 625.0, 650.7, 650.0, 631.6, 607.1, 685.8, 630.6, 628.6};
   //double clct1[n1] = {882, 766.5, 721.0, 696.0, 686.2, 700.3, 683.8, 672.3, 617.1, 649.2, 651.3, 655.0, 662.4, 679.9, 696.3, 688.6, 656.6, 677.3, 571.8, 616.6, 686.4,  593.7, 677.1, 664.9, 707.1, 850.6, 784.9, 756.1, 675.9, 655.4, 670.1, 669.2, 652.5, 654.6, 734.6, 682.4, 686.3, 821.6, 915.1, 945.0, 1047.2, 1054.7, 973.0, 2960.1, 1188.7, 1056.0, 953.4};
   double cna1[n1] =  {669, 684.0, 675.0,  660, 657, 679.5, 672, 660, 610, 624, 622, 614, 614, 635, 640, 643, 610, 619, 538.8, 579.9, 639.7, 547.1, 626.7, 610.1, 641.4, 585.3, 605.5, 615.7, 608.8, 626.4, 647.4, 645.4, 624.8, 609.0, 691.5, 624.6, 631.0, 743.6, 608.7, 664.7, 742.1, 759.2, 713.1, 888.1, 755.2, 672.0};
   double alct_correction_10p[n1]={764,783};
   for(int i = 2; i< n1; i++){
     alct_correction_10p[i] = alct1[i]*(1.-(N_bad[i]/N_tot[i]));
   }
   for(int i=0; i<n1; i++){alct1[i] /=1000; cna1[i] /=1000; alct_correction_10p[i] /=1000;}

   double charge2[n2] = {1.92, 9.31, 15.85, 15.86, 21.59, 27.48, 27.54, 28.29, 29.63, 31.38, 32.44, 32.93, 33.88, 35.10, 41.86, 48.44, 55.30, 61.30, 66.09, 68.8, 76.03, 90.26, 97.65, 104.17, 110.26, 115.64, 121.71, 126.25, 133.31, 140.19};
   for(int i=0; i<n2; i++) charge2[i] += 350.;
   double alct2[n2] = {1212.2, 985.4, 1233.1, 983.2, 894.5, 1108.3, 855.7, 954.3, 1040.8, 844.1, 786.4, 780.1, 880.1, 827.9, 1118.6, 1028.2, 839.6, 823.1, 922.3, 937.8, 854.9, 989.5, 1095.4, 1086.5, 842.0, 904.6, 953.7, 925.6, 892.4, 891.5};
   //double clct1[n2] = {1024.2, 948.9, 965.3, 925.7, 1032.4, 918.9, 965.5, 954.7, 1011, 923.7, 975.2, 1032, 582.8, 614.0, 789.8, 737.7, 749.3, 577.4, 562.8, 850.2, 911.1, 746.7, 781.6, 577.9, 604.5, 593.2, 596.2, 617.7};
   //1096.2, 970.6, 1079.9, 999.1, 1056.5, 998.0, 987.4, 1000.7, 1104.6, 928.2, 969.1, 1021.5, 596.6, 646.9, 928.3, 822.6, 741.6, 593.6, 631.2, 861.8, 837.2, 674.4, 686.9, };
   //728.7, 758.7, 861.8, 956.9, 799.7, 810.4};
   double cna2[n2] =  {743.8, 628.7, 752.2, 651.2, 579.8, 628.7, 581.0, 607.4, 655.2, 568.3, 545.1, 552.8, 574.8, 575.5, 719.5, 683.2, 584.8, 463.2, 483.1, 570.2, 553.5, 487.6, 530.3, 499.5, 523.1, 510.1, 515.5, 529.4, 529.2, 584.4};
   double alct_correction_2p[n2];
   for(int i = 0; i< n2; i++){
     alct_correction_2p[i] = alct2[i]*(1.-(N_bad_2p[i]/N_tot_2p[i]));
   }
   for(int i=0; i<n2; i++){alct2[i] /=1000; cna2[i] /=1000; alct_correction_2p[i] /=1000;}

   TGraph *gr11_10p = new TGraph(n1, charge1, alct1);
   //TGraph *gr12_10p = new TGraph(n1, charge1, clct1);
   TGraph *gr13_10p = new TGraph(n1, charge1, cna1);
   TGraph *gr10_10p = new TGraph(n1, charge1, alct_correction_10p);

   TGraph *gr11_2p = new TGraph(n2, charge2, alct2);
   //TGraph *gr12_2p = new TGraph(n2, charge2, clct2);
   TGraph *gr13_2p = new TGraph(n2, charge2, cna2);
   TGraph *gr10_2p = new TGraph(n2, charge2, alct_correction_2p);

   c1->cd();
   gr11_10p->SetTitle("; Accumulated charge [mC/cm]; Dark rate [kHz]");
   //TGaxis *a = (TGaxis*)gr11_10p->GetYaxis();
   //a->SetMaxDigits(2);
   gr11_10p->GetXaxis()->SetLimits(0., 500);
   gr11_10p->SetMinimum(0);
   gr11_10p->SetMaximum(2.0);
   gr11_10p->SetMarkerColor(kRed);
   gr11_10p->SetLineColor(kRed);
   gr11_10p->SetMarkerStyle(20);
   gr11_10p->SetMarkerSize(1.5);
   gr11_10p->Draw("APL");

   gr10_10p->SetMarkerColor(kRed);
   gr10_10p->SetLineColor(kBlack);
   gr10_10p->SetMarkerStyle(24);
   gr10_10p->SetMarkerSize(1.5);
   gr10_10p->Draw("PL same");

   //gr12_10p->SetMarkerColor(kBlue);
   //gr12_10p->SetMarkerStyle(23);
   //gr12_10p->SetMarkerSize(1.5);
   //gr12_10p->Draw("P same");

   gr13_10p->SetMarkerColor(kBlue);
   gr13_10p->SetLineColor(kBlue);
   gr13_10p->SetMarkerStyle(21);
   gr13_10p->SetMarkerSize(1.5);
   gr13_10p->Draw("PL same");


   gr11_2p->SetMarkerColor(kRed+3);
   gr11_2p->SetLineColor(kRed+3);
   gr11_2p->SetMarkerStyle(20);
   gr11_2p->SetMarkerSize(1.5);
   gr11_2p->Draw("PL same");

   gr10_2p->SetMarkerColor(kRed+3);
   gr10_2p->SetLineColor(kBlack);
   gr10_2p->SetMarkerStyle(24);
   gr10_2p->SetMarkerSize(1.5);
   gr10_2p->Draw("PL same");

   //gr12_2p->SetMarkerColor(kBlue);
   //gr12_2p->SetLineColor(kBlue);
   //gr12_2p->SetMarkerStyle(23);
   //gr12_2p->SetMarkerSize(1.5);
   //gr12_2p->Draw("PL same");

   gr13_2p->SetMarkerColor(kBlue+3);
   gr13_2p->SetLineColor(kBlue+3);
   gr13_2p->SetMarkerStyle(21);
   gr13_2p->SetMarkerSize(1.5);
   gr13_2p->Draw("PL same");



   TLegend *leg1 = new TLegend(0.1, 0.58 ,0.5, 0.88, "ME1/1");
   leg1->SetNColumns(2);
   leg1->AddEntry(gr11_10p, "ALCT, 10\% CF4", "pl");
   leg1->AddEntry(gr11_2p, "ALCT, 2\% CF4", "pl");
   leg1->AddEntry(gr10_10p, "ALCT w/o noise, 10\% CF4", "pl");
   leg1->AddEntry(gr10_2p, "ALCT w/o noise, 2\% CF4", "pl");
   //leg1->AddEntry(gr12_10p, "CLCT", "pl");
   //leg1->AddEntry(gr12_2p, "CLCT", "pl");
   leg1->AddEntry(gr13_10p, "ALCT*CLCT, 10\% CF4", "pl"); 
   leg1->AddEntry(gr13_2p, "ALCT*CLCT, 2\% CF4", "pl");
   leg1->SetBorderSize(0);
   leg1->Draw();

 
   TArrow *ar1 = new TArrow(483.31, 1.5, 483.31,0.9,0.03,"|>");
   ar1->SetAngle(40);
   ar1->SetLineWidth(2);
   ar1->SetFillColor(2);
   ar1->Draw();

   TText *t1 = new TText(465,1.6,"Before 18Aug TB");
   t1->SetTextAlign(22);
   t1->SetTextColor(kBlack);
   t1->SetTextFont(43);
   t1->SetTextSize(20);
   //t1->SetTextAngle(45);
   t1->Draw();

   TArrow *ar2 = new TArrow(490.19, 0.3, 490.19,0.55,0.03,"|>");
   ar2->SetAngle(40);
   ar2->SetLineWidth(2);
   ar2->SetFillColor(2);
   ar2->Draw();

   TText *t2 = new TText(465,0.25,"After 18Aug TB");
   t2->SetTextAlign(22);
   t2->SetTextColor(kBlack);
   t2->SetTextFont(43);
   t2->SetTextSize(20);
   //t2->SetTextAngle(45);
   t2->Draw();

   c1->SaveAs("me11ratevsdose.pdf");
}
