void ratevsdose() {

   TCanvas *c1 = new TCanvas("me11ratevsdose","rate vs dose",10,10,600,600);
   TCanvas *c2 = new TCanvas("me21ratevsdose","rate vs does",10,10,600,600);
   TCanvas *c3 = new TCanvas("me11ratevsdose_correction","rate vs does",10,10,600,600);

   //TString extraText1   = "CSC ME1/1, nominal HV";
   //TString extraText2   = "CSC ME2/1, nominal HV";
   //TString date = "up to Apr. 7, 2017";
   //TLatex latex;
   //latex.SetNDC();
   //latex.SetTextFont(42);
   //latex.SetTextColor(kBlack);

   const int n1 =47, n2=47;

   ////////////////////////////////////
   //    alct correction for me11    //
   ////////////////////////////////////
   std::string dataname[45] = {"A1121.root","A1169.root","A1228.root","A1336.root","A1419.root","A1558.root","A1688.root","A1845.root","A1907.root","A2064.root","A2176.root","A2213.root","A2404.root","A2576.root","A2696.root","A2775.root","A2951.root","A3182.root","A3245.root","A3449.root","A3507.root","A3698.root","A3826.root","A4062.root","A4372.root","A4444.root","A4557.root","A4719.root","A4848.root","A5011.root","A5147.root","A5284.root","A5393.root","A5536.root","A5626.root","A5694.root","A5814.root","A5905.root","A6014.root","A6119.root","A6174.root","A6232.root","A6267.root","A6374.root","A6557.root"};
   std::string histo[6] = {"ALCT/hAhitL[0][1]", "ALCT/hAhitL[1][1]", "ALCT/hAhitL[2][1]", "ALCT/hAhitL[3][1]", "ALCT/hAhitL[4][1]", "ALCT/hAhitL[5][1]"};
   std::string histonames[6] = {"layer1","layer2","layer3","layer4","layer5","layer6"};

   double N_tot[n1]={0}, N_bad[n1]={0};

   for(int i=0;i<45;i++){
     TFile *f_temp = new TFile(("../gifRates/me11data/test1/"+dataname[i]).c_str(),"read");
     for(short unsigned int l=0; l<6; l++){
       TH1F *h_temp = (TH1F*)f_temp->Get(histo[l].c_str());
       N_tot[i+2] += h_temp->GetEntries();
       if(l==3) N_bad[i+2] += h_temp->GetBinContent(2);
       if(l==4) N_bad[i+2] += h_temp->GetBinContent(7);
       delete h_temp;
     }
     delete f_temp;
   }


        //dates: 2016::0203, 0211, 0218, 0225, 0303, 0310, 0404, 0415, 0511, 0526, 0615, 0629, 0706, 0713, 0720, 0803, 0810, 0831, 1009, 1019, 1026, 1102, 1109, 1116, 1123;2017::0117, 0125, 0201, 0208, 0215, 0222, 0301, 0308, 0315, 0407, 0419, 0424, 0505, 0531, 0607, 0621, 0628
   double charge1[n1] = {0.49, 11.3, 17.6, 25.5, 33.1, 40.9, 51.2, 59.38, 63.97, 77.94, 89.81, 95.44, 104.24, 113.27, 120.90, 135.62, 142.40, 152.13, 154.42, 154.58, 156.55, 163.68, 171.28, 180.46, 186.99, 193.55, 200.14, 207.45, 214.78, 222.52, 228.59, 235.27, 241.72, 250.86, 256.42, 266.13, 271.28, 277.37, 279.95, 287.51, 297.54, 305.82, 314.79, 316.29, 316.67, 324.07, 340};

   double alct1[n1] = {764, 783, 783,  759,  789,  787.0,  777,  791, 785, 800, 798, 793, 802, 851, 840, 834, 832, 839, 714.6, 773.5, 845.7, 824.1, 879.3, 903.0, 1011.1, 842.2, 849.7, 870.2, 842.4, 928.6, 1001.2, 1156.2, 888.3, 915.8, 1108.2, 873.6, 980.6, 1414.9, 929.1, 1277.0, 1404.6, 1530.6, 1537.8, 4300.4, 1996.1, 1505.2, 1229.9};

   //double clct1[n1] = {882, 766.5, 721.5, 664.5, 594.15, 687.45, 680.25, 671.1, 616.6, 566.2, 627.5, 624.8, 616.6, 642.1, 643.9, 655.4, 568.0, 557.5, 646.1, 594.6, 685.0,  468.2, 617.6, 619.7, 657.0, 661.2, 622.4, 612.1, 616.9, 625.0, 650.7, 650.0, 631.6, 607.1, 685.8, 630.6, 628.6};

   double clct1[n1] = {882, 766.5, 721.0, 696.0, 686.2, 700.3, 683.8, 672.3, 617.1, 649.2, 651.3, 655.0, 662.4, 679.9, 696.3, 688.6, 656.6, 677.3, 571.8, 616.6, 686.4,  593.7, 677.1, 664.9, 707.1, 850.6, 784.9, 756.1, 675.9, 655.4, 670.1, 669.2, 652.5, 654.6, 734.6, 682.4, 686.3, 821.6, 915.1, 945.0, 1047.2, 1054.7, 973.0, 2960.1, 1188.7, 1056.0, 953.4};

   double cna1[n1] =  {669, 684.0, 675.0,  660, 657, 679.5, 672, 660, 610, 624, 622, 614, 614, 635, 640, 643, 610, 619, 538.8, 579.9, 639.7, 547.1, 626.7, 610.1, 641.4, 585.3, 605.5, 615.7, 608.8, 626.4, 647.4, 645.4, 624.8, 609.0, 691.5, 624.6, 631.0, 743.6, 608.7, 664.7, 742.1, 759.2, 713.1, 1992.7, 888.1, 755.2, 672.0};

   double alct_correction[n1]={764,783};
   for(int i = 2; i< n1; i++){
     alct_correction[i] = alct1[i]*(1-(N_bad[i]/N_tot[i]));
   }

   for(int i=0; i<n1; i++){alct1[i] /=1000; cna1[i] /=1000; alct_correction[i] /=1000;}
//dates: 2016::0127, 0203, 0218, 0303, 0310, 0415, 0511, 0515, 0518, 0615, 0629, 0715, 0720, 0803, 0907, 1012, 1019, 1026, 1102, 1109, 1116, 1123, 1216; 2017::0117, 0125, 0201, 0208, 0215, 0222, 0301, 0308, 0315, 0407, 0419, 0424, 0505, 0526, 0531, 0607, 0621
   double charge2[n2] = {0.68, 11.6, 17.95, 33.83, 53.84, 62.36, 66.59, 69.87, 73.12, 93.13, 98.86, 118.96, 124.68, 140.28, 158.52, 158.82, 158.99, 161.09, 168.38, 176.53, 186.31, 191.84, 197.36, 197.54, 204.07, 211.80, 219.56, 227.74, 233.97, 240.84, 247.69, 257.44, 263.47, 273.86, 279.19, 285.78, 285.88, 288.49, 296.40, 306.13, 314.30, 322.94, 324.40, 324.77, 332.99, 340.75, 350};
   double alct2[n2] =   {2620, 2557, 2526.4, 2788.9, 2716.9, 2866.7, 2851.1, 2799.2, 2890.2, 2830.4, 2816.6, 2827.4, 2943.8, 2886.3, 2750.0, 2378.0, 2475.5, 2681.2, 2648.2, 2604.2, 2556.0, 2565.9, 2559.3, 2543.0, 2590.3, 2650.3, 2574.0, 2595.1, 2555.5, 2626.3, 2597.3, 2626.0, 2638.3, 2625.2, 2630.2, 2832.1, 2759.6, 2550.7, 2598.1, 2853.6, 2798.4, 2615.4, 7646.7, 2713.9, 2792.3, 2609.6, 2554.2};
   double clct2[n2] =   {2200, 2236, 2216.8, 2305.0, 2723.4, 2225.4, 2100.4, 2157.6, 2172.8, 2080.3, 2029.8, 2050.5, 2144.1, 2286.8, 2119.0, 1952.8, 1855.4, 2281.8, 2132.4, 1957.6, 1967.8, 1927.2, 1958.5, 1863.1, 1965.9, 1996.8, 1949.6, 1944.2, 1914.8, 1962.2, 1961.3, 1957.7, 2081.2, 1962.9, 1966.2, 2204.0, 2051.0, 1886.9, 1922.4, 2134.8, 2134.8, 1937.8, 5596.2, 2211.4, 2792.3, 2609.6, 1859.2};
   double cna2[n2] =    {2182, 2186, 2181.8, 2224.4, 2196.2, 2212.2, 1778.8, 2028.9, 2002.7, 1994.2, 1960.6, 1975.1, 2074.6, 2049.6, 1980.1, 1765.9, 1830.0, 1965.7, 1938.1, 1920.9, 1905.1, 1901.1, 1926.6, 1842.4, 1925.4, 1930.2, 1919.2, 1913.2, 1885.8, 1913.2, 1912.0, 1914.9, 1904.7, 1929.2, 1924.6, 1925.5, 2004.9, 1847.1, 1882.9, 2078.3, 1960.1, 1885.7, 5485.1, 1933.4, 1974.1, 1890.4, 1831.2};
   for(int i=0; i<n2; i++){alct2[i] /=1000; cna2[i] /=1000;}


   TGraph *gr11 = new TGraph(n1, charge1, alct1);
   TGraph *gr12 = new TGraph(n1, charge1, clct1);
   TGraph *gr13 = new TGraph(n1, charge1, cna1);
   TGraph *gr10 = new TGraph(n1, charge1, alct_correction);

   TGraph *gr21 = new TGraph(n2, charge2, alct2);
   TGraph *gr22 = new TGraph(n2, charge2, clct2);
   TGraph *gr23 = new TGraph(n2, charge2, cna2);

   c3->cd();
   gr10->SetTitle("; Accumulated charge [mC/cm]; Dark rate [kHz]");
   gr10->SetMinimum(0);
   gr10->SetMaximum(1.6);
   gr10->SetMarkerColor(kRed);
   gr10->SetMarkerStyle(22);
   gr10->SetMarkerSize(1.5);
   gr10->Draw("AP");

   gr12->SetMarkerColor(kBlue);
   gr12->SetMarkerStyle(23);
   gr12->SetMarkerSize(1.5);
   //gr12->Draw("P same");

   gr13->SetMarkerColor(kGreen);
   gr13->SetMarkerStyle(20);
   gr13->SetMarkerSize(1.5);
   gr13->Draw("P same");

   TLegend *leg3 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME1/1");
   leg3->AddEntry(gr10, "ALCT selected wgs", "p");
   //leg3->AddEntry(gr12, "CLCT", "p");
   leg3->AddEntry(gr13, "ALCT*CLCT", "p");
   leg3->SetBorderSize(0);
   leg3->Draw();


   c1->cd();
   gr11->SetTitle("; Accumulated charge [mC/cm]; Dark rate [kHz]");
   gr11->SetMinimum(0);
   gr11->SetMaximum(1.6);
   gr11->SetMarkerColor(kRed);
   gr11->SetMarkerStyle(22);
   gr11->SetMarkerSize(1.5);
   gr11->Draw("AP");

   gr12->SetMarkerColor(kBlue);
   gr12->SetMarkerStyle(23);
   gr12->SetMarkerSize(1.5);
   //gr12->Draw("P same");

   gr13->SetMarkerColor(kGreen);
   gr13->SetMarkerStyle(20);
   gr13->SetMarkerSize(1.5);
   gr13->Draw("P same");

   TLegend *leg1 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME1/1");
   leg1->AddEntry(gr11, "ALCT", "p");
   //leg1->AddEntry(gr12, "CLCT", "p");
   leg1->AddEntry(gr13, "ALCT*CLCT", "p"); 
   leg1->SetBorderSize(0);
   leg1->Draw();

 
   c2->cd();
   gr21->SetTitle("; Acculumated charge [mC/cm]; Dark rate [kHz]");
   gr21->SetMinimum(0);
   gr21->SetMaximum(5);
   gr21->SetMarkerColor(kRed);
   gr21->SetMarkerStyle(22);
   gr21->SetMarkerSize(1.5);
   gr21->Draw("AP");

   gr22->SetMarkerColor(kBlue);
   gr22->SetMarkerStyle(23);
   gr22->SetMarkerSize(1.5);
   //gr22->Draw("P same");

   gr23->SetMarkerColor(kGreen);
   gr23->SetMarkerStyle(20);
   gr23->SetMarkerSize(1.5);
   gr23->Draw("P same");

   TLegend *leg2 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME2/1");
   leg2->AddEntry(gr21, "ALCT", "p");
   //leg2->AddEntry(gr22, "CLCT", "p");
   leg2->AddEntry(gr23, "ALCT*CLCT", "p");
   leg2->SetBorderSize(0);
   leg2->Draw();

   c1->SaveAs("me11ratevsdose.pdf");
   c2->SaveAs("me21ratevsdose.pdf");
   c3->SaveAs("me11ratevsdose_correction.pdf");
 //  TArrow *ar4 = new TArrow(80,200,5,800,0.03,"|>");
 //  ar4->SetAngle(60);
 //  ar4->SetLineWidth(2);
 //  ar4->SetFillColor(2);
 //  ar4->Draw();



}
