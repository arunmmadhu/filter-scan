void me11ratevslayer()
{
//=========Macro generated from canvas: me11ratevslayer/his1
//=========  (Thu Oct 26 12:11:12 2017) by ROOT version6.02/10
   TCanvas *me11ratevslayer = new TCanvas("me11ratevslayer", "his1",1090,567,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   me11ratevslayer->Range(-72.63219,-253.6585,381.319,1697.561);
   me11ratevslayer->SetFillColor(0);
   me11ratevslayer->SetBorderMode(0);
   me11ratevslayer->SetBorderSize(2);
   me11ratevslayer->SetTickx(1);
   me11ratevslayer->SetTicky(1);
   me11ratevslayer->SetLeftMargin(0.16);
   me11ratevslayer->SetRightMargin(0.02);
   me11ratevslayer->SetTopMargin(0.05);
   me11ratevslayer->SetBottomMargin(0.13);
   me11ratevslayer->SetFrameFillStyle(0);
   me11ratevslayer->SetFrameBorderMode(0);
   me11ratevslayer->SetFrameFillStyle(0);
   me11ratevslayer->SetFrameBorderMode(0);
   
   Double_t Graph0_fx7[42] = {
   17.6,
   25.5,
   33.1,
   40.9,
   51.2,
   59.38,
   77.94,
   89.81,
   95.44,
   104.24,
   113.27,
   120.9,
   135.62,
   142.4,
   152.13,
   154.42,
   154.58,
   156.55,
   171.28,
   180.46,
   186.99,
   193.55,
   200.14,
   207.45,
   214.78,
   222.52,
   228.59,
   235.27,
   241.72,
   250.86,
   256.42,
   266.13,
   271.28,
   277.37,
   287.51,
   297.54,
   305.82,
   314.79,
   316.29,
   316.67,
   324.07,
   340};
   Double_t Graph0_fy7[42] = {
   155.1667,
   149.9667,
   154.3333,
   156.1667,
   155.8667,
   158.2,
   156.6,
   154.0333,
   153.3,
   155.2667,
   153.5667,
   153.9667,
   162.8333,
   152.8333,
   157.8,
   138.1667,
   145.7333,
   181.9,
   154.9,
   153.3667,
   155.5333,
   147.2667,
   147.7667,
   151.3,
   149.3667,
   148.7,
   149.2667,
   259.9667,
   150.0667,
   179.8,
   152.2,
   154.3,
   149.2333,
   165.4,
   150.6,
   155.8667,
   160.8,
   146.1667,
   142.5667,
   156.6333,
   160.3333,
   147.3};
   TGraph *graph = new TGraph(42,Graph0_fx7,Graph0_fy7);
   graph->SetName("Graph0");
   graph->SetTitle("; Accumulated charge [mC/cm]; Dark ALCT rate [Hz]");
   graph->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#cccc00");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#cccc00");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph17 = new TH1F("Graph_Graph_Graph17","",100,0,372.24);
   Graph_Graph_Graph17->SetMinimum(0);
   Graph_Graph_Graph17->SetMaximum(1600);
   Graph_Graph_Graph17->SetDirectory(0);
   Graph_Graph_Graph17->SetStats(0);
   Graph_Graph_Graph17->SetLineStyle(0);
   Graph_Graph_Graph17->SetMarkerStyle(20);
   Graph_Graph_Graph17->GetXaxis()->SetTitle(" Accumulated charge [mC/cm]");
   Graph_Graph_Graph17->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph17->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph17->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph17->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph17->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph17->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph17->GetYaxis()->SetTitle(" Dark ALCT rate [Hz]");
   Graph_Graph_Graph17->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph17->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph17->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph17->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph17->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph17->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph17->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph17->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph17->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph17->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph17->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph17);
   
   graph->Draw("alp");
   
   Double_t Graph1_fx8[42] = {
   17.6,
   25.5,
   33.1,
   40.9,
   51.2,
   59.38,
   77.94,
   89.81,
   95.44,
   104.24,
   113.27,
   120.9,
   135.62,
   142.4,
   152.13,
   154.42,
   154.58,
   156.55,
   171.28,
   180.46,
   186.99,
   193.55,
   200.14,
   207.45,
   214.78,
   222.52,
   228.59,
   235.27,
   241.72,
   250.86,
   256.42,
   266.13,
   271.28,
   277.37,
   287.51,
   297.54,
   305.82,
   314.79,
   316.29,
   316.67,
   324.07,
   340};
   Double_t Graph1_fy8[42] = {
   157.5667,
   160.7667,
   159.1667,
   157.7333,
   158.7333,
   160.1,
   157.5333,
   159.2333,
   156,
   157.9,
   160.7667,
   160.1667,
   162.4667,
   157.3667,
   159.2667,
   143.0333,
   148.5,
   181.7333,
   155.5,
   154.0667,
   154.1,
   151.1333,
   157.0667,
   154.6333,
   154.4333,
   150.6333,
   151.4333,
   157.2,
   154.0333,
   149.4,
   152.0333,
   155.1667,
   153.5667,
   169.1,
   149.9667,
   164.7667,
   159.6667,
   147.7333,
   145.4,
   154.5667,
   165.1333,
   150.6333};
   graph = new TGraph(42,Graph1_fx8,Graph1_fy8);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#66ccff");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#66ccff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph28 = new TH1F("Graph_Graph_Graph28","Graph",100,0,372.24);
   Graph_Graph_Graph28->SetMinimum(139.1633);
   Graph_Graph_Graph28->SetMaximum(185.6033);
   Graph_Graph_Graph28->SetDirectory(0);
   Graph_Graph_Graph28->SetStats(0);
   Graph_Graph_Graph28->SetLineStyle(0);
   Graph_Graph_Graph28->SetMarkerStyle(20);
   Graph_Graph_Graph28->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph28->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph28->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph28->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph28->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph28->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph28->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph28->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph28->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph28->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph28->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph28->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph28->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph28->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph28->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph28->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph28->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph28);
   
   graph->Draw("lp ");
   
   Double_t Graph2_fx9[42] = {
   17.6,
   25.5,
   33.1,
   40.9,
   51.2,
   59.38,
   77.94,
   89.81,
   95.44,
   104.24,
   113.27,
   120.9,
   135.62,
   142.4,
   152.13,
   154.42,
   154.58,
   156.55,
   171.28,
   180.46,
   186.99,
   193.55,
   200.14,
   207.45,
   214.78,
   222.52,
   228.59,
   235.27,
   241.72,
   250.86,
   256.42,
   266.13,
   271.28,
   277.37,
   287.51,
   297.54,
   305.82,
   314.79,
   316.29,
   316.67,
   324.07,
   340};
   Double_t Graph2_fy9[42] = {
   160.7667,
   164,
   159.0333,
   160.9,
   161.5333,
   161.3667,
   165.9333,
   155.1333,
   165,
   157.7,
   167.0333,
   165.5333,
   170.7667,
   158.5,
   166.6667,
   143.0333,
   150.4667,
   187.3667,
   162.2,
   157.5333,
   154.1,
   152.5333,
   159.0333,
   159.0667,
   157.8333,
   154.9333,
   155.6667,
   158.1667,
   155.6,
   159.8,
   160.6333,
   158.1,
   154.7333,
   174.8,
   154.0667,
   166.2333,
   165.4,
   154.9333,
   149.1,
   167.4,
   164.4,
   155.5333};
   graph = new TGraph(42,Graph2_fx9,Graph2_fy9);
   graph->SetName("Graph2");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#cc3333");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#cc3333");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph39 = new TH1F("Graph_Graph_Graph39","Graph",100,0,372.24);
   Graph_Graph_Graph39->SetMinimum(138.6);
   Graph_Graph_Graph39->SetMaximum(191.8);
   Graph_Graph_Graph39->SetDirectory(0);
   Graph_Graph_Graph39->SetStats(0);
   Graph_Graph_Graph39->SetLineStyle(0);
   Graph_Graph_Graph39->SetMarkerStyle(20);
   Graph_Graph_Graph39->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph39->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph39->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph39->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph39->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph39->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph39->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph39->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph39->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph39->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph39->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph39->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph39->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph39->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph39->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph39->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph39->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph39);
   
   graph->Draw("lp ");
   
   Double_t Graph3_fx10[42] = {
   17.6,
   25.5,
   33.1,
   40.9,
   51.2,
   59.38,
   77.94,
   89.81,
   95.44,
   104.24,
   113.27,
   120.9,
   135.62,
   142.4,
   152.13,
   154.42,
   154.58,
   156.55,
   171.28,
   180.46,
   186.99,
   193.55,
   200.14,
   207.45,
   214.78,
   222.52,
   228.59,
   235.27,
   241.72,
   250.86,
   256.42,
   266.13,
   271.28,
   277.37,
   287.51,
   297.54,
   305.82,
   314.79,
   316.29,
   316.67,
   324.07,
   340};
   Double_t Graph3_fy10[42] = {
   159.4333,
   164.7667,
   166.7333,
   162.7667,
   168.9,
   164,
   166.6,
   162.1667,
   173.2333,
   170.2333,
   175.0667,
   178.7,
   183.1333,
   175.4,
   160.3333,
   147.0333,
   151.6333,
   192.1333,
   170.4,
   172.1,
   170.9667,
   158.0667,
   163,
   166.9667,
   168.6,
   178.2,
   171.0667,
   182.9333,
   177.8,
   174.1,
   164.5667,
   167.7,
   170.1,
   182.5333,
   168.0667,
   182.9667,
   177.7667,
   174.6,
   167.6333,
   164.5333,
   183.5,
   153.2667};
   graph = new TGraph(42,Graph3_fx10,Graph3_fy10);
   graph->SetName("Graph3");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#009900");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#009900");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph410 = new TH1F("Graph_Graph_Graph410","Graph",100,0,372.24);
   Graph_Graph_Graph410->SetMinimum(142.5233);
   Graph_Graph_Graph410->SetMaximum(196.6433);
   Graph_Graph_Graph410->SetDirectory(0);
   Graph_Graph_Graph410->SetStats(0);
   Graph_Graph_Graph410->SetLineStyle(0);
   Graph_Graph_Graph410->SetMarkerStyle(20);
   Graph_Graph_Graph410->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph410->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph410->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph410->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph410->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph410->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph410->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph410->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph410->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph410->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph410->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph410->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph410->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph410->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph410->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph410->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph410->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph410);
   
   graph->Draw("lp ");
   
   Double_t Graph4_fx11[42] = {
   17.6,
   25.5,
   33.1,
   40.9,
   51.2,
   59.38,
   77.94,
   89.81,
   95.44,
   104.24,
   113.27,
   120.9,
   135.62,
   142.4,
   152.13,
   154.42,
   154.58,
   156.55,
   171.28,
   180.46,
   186.99,
   193.55,
   200.14,
   207.45,
   214.78,
   222.52,
   228.59,
   235.27,
   241.72,
   250.86,
   256.42,
   266.13,
   271.28,
   277.37,
   287.51,
   297.54,
   305.82,
   314.79,
   316.29,
   316.67,
   324.07,
   340};
   Double_t Graph4_fy11[42] = {
   166.2333,
   166.3,
   170.4667,
   164.8,
   165.5,
   188.1333,
   169.9667,
   170.3667,
   175.6333,
   195.9,
   201.8333,
   189.7,
   181.7333,
   229.3333,
   224.3333,
   176.6333,
   187.3333,
   203.2667,
   243.6,
   312.7,
   435.7667,
   267.9333,
   259.9,
   263.8333,
   266.6,
   304.8,
   350.5,
   367.4,
   307.4,
   298.6333,
   516.6667,
   265.7,
   393.3667,
   846.3,
   651.8667,
   728.8333,
   966.4667,
   930.5333,
   833.2333,
   1369.767,
   1027.133,
   693.7};
   graph = new TGraph(42,Graph4_fx11,Graph4_fy11);
   graph->SetName("Graph4");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#6600cc");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#6600cc");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph511 = new TH1F("Graph_Graph_Graph511","Graph",100,0,372.24);
   Graph_Graph_Graph511->SetMinimum(44.30333);
   Graph_Graph_Graph511->SetMaximum(1490.263);
   Graph_Graph_Graph511->SetDirectory(0);
   Graph_Graph_Graph511->SetStats(0);
   Graph_Graph_Graph511->SetLineStyle(0);
   Graph_Graph_Graph511->SetMarkerStyle(20);
   Graph_Graph_Graph511->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph511->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph511->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph511->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph511->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph511->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph511->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph511->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph511->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph511->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph511->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph511->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph511->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph511->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph511->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph511->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph511->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph511);
   
   graph->Draw("lp ");
   
   Double_t Graph5_fx12[42] = {
   17.6,
   25.5,
   33.1,
   40.9,
   51.2,
   59.38,
   77.94,
   89.81,
   95.44,
   104.24,
   113.27,
   120.9,
   135.62,
   142.4,
   152.13,
   154.42,
   154.58,
   156.55,
   171.28,
   180.46,
   186.99,
   193.55,
   200.14,
   207.45,
   214.78,
   222.52,
   228.59,
   235.27,
   241.72,
   250.86,
   256.42,
   266.13,
   271.28,
   277.37,
   287.51,
   297.54,
   305.82,
   314.79,
   316.29,
   316.67,
   324.07,
   340};
   Double_t Graph5_fy12[42] = {
   171.2667,
   156.5,
   162.3,
   157.6333,
   158.1,
   164.7667,
   160.7667,
   162.6333,
   156.5,
   164.9,
   166.1667,
   157.7333,
   168.6333,
   159.5667,
   162.9333,
   144.9,
   151.9667,
   182.3,
   154.1333,
   149.6333,
   154.5,
   148.2,
   155.5333,
   152.9,
   157.1333,
   153.4,
   151.5,
   158.3667,
   150.4,
   155.8333,
   154.1333,
   153.7333,
   152.7,
   171.5,
   153.7,
   165.4,
   162.8,
   155.1667,
   150.9333,
   158.6,
   166.3,
   144.3333};
   graph = new TGraph(42,Graph5_fx12,Graph5_fy12);
   graph->SetName("Graph5");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#cc9933");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#cc9933");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph612 = new TH1F("Graph_Graph_Graph612","Graph",100,0,372.24);
   Graph_Graph_Graph612->SetMinimum(140.5367);
   Graph_Graph_Graph612->SetMaximum(186.0967);
   Graph_Graph_Graph612->SetDirectory(0);
   Graph_Graph_Graph612->SetStats(0);
   Graph_Graph_Graph612->SetLineStyle(0);
   Graph_Graph_Graph612->SetMarkerStyle(20);
   Graph_Graph_Graph612->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph612->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph612->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph612->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph612->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph_Graph612->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph612->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph612->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph612->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph612->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph612->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph_Graph612->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph612->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph612->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph612->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph612->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph612->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph612);
   
   graph->Draw("lp ");
   
   TLegend *leg = new TLegend(0.2684564,0.3811189,0.635906,0.8968531,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","ME1/1","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","L1","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#cccc00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph1","L2","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#66ccff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph2","L3","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#cc3333");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph3","L4","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#009900");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph4","L5","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#6600cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph5","L6","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#cc9933");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   me11ratevslayer->Modified();
   me11ratevslayer->cd();
   me11ratevslayer->SetSelected(me11ratevslayer);
}
