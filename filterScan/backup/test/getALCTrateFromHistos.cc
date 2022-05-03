void getALCTrateFromHistos(const char * hfname, bool old=false){
	TFile * f = TFile::Open(hfname);
	//f->Get("ALCT/hAhitL[0][1]")
	TString hname;
	TString hbasename="";
	if(!old){
		hbasename="ALCT/";
	};

	unsigned int sum = 0;

	std::cout << "number of any hits per layer (each fired WG contributes)" << std::endl;
	for(short unsigned int l0=0; l0<6; l0++){
		hname = hbasename; hname+="hAhitL["; hname+=l0;
		if(!old){
			hname+="][0]";
		}else{
			hname+="]";
		};
		//std::cout << "==> " << hname.Data() << std::endl;
		TH1F * h = (TH1F*)(f->Get(hname.Data()));
		if(h!=0){
			unsigned int entries = h->GetEntries();
			std::cout << hname.Data() << " : " << entries << std::endl;
		};
	};
	std::cout << "number of separated hits per layer (can be more that 1!)" << std::endl;
	for(short unsigned int l0=0; l0<6; l0++){
		hname = hbasename; hname+="hAhitL["; hname+=l0; hname+="][1]";
		TH1F * h = (TH1F*)(f->Get(hname.Data()));
		if(h!=0){
			unsigned int entries = h->GetEntries();
			std::cout << hname.Data() << " : " << entries << std::endl;
		};
	};
	std::cout << "number of fired layer" << std::endl;
	for(short unsigned int l0=0; l0<6; l0++){
		hname = hbasename; hname+="hNofAhitL["; hname+=l0; hname+="][2]";
		TH1F * h = (TH1F*)(f->Get(hname.Data()));
		if(h!=0){
			unsigned int entries = h->GetEntries();
			std::cout << hname.Data() << " : " << entries << std::endl;
			sum+=entries;
		};
	};

	TH1F * h = (TH1F*)(f->Get("ALCT/hNofAhit[2]"));
	unsigned int corrections = 0;
	if(h!=0){
		unsigned int singleLayerEvents = h->GetEntries();
		for(short unsigned int b=2; b<9; b++){
			unsigned int NofL = b-2;
			unsigned int N = h->GetBinContent(b);
			unsigned int corrForL = 0;
			if(NofL!=0){
				corrForL = N*(NofL-1)/NofL;
			};
			corrections+=corrForL;
			std::cout << NofL << " layers fired : " << N << " to be subtracted " << corrForL << std::endl;
		};
	};
	if(!old){
		std::cout << "sum of individual layers (ALCT/hNofAhitL[l][2]) = " << sum << std::endl;
		std::cout << "correction from multi-layer events              = " << corrections << " (" << corrections*100/sum << "%)"<< std::endl;
		std::cout << "total ALCT  rate as (sum-correction)/30s        = " << (sum-corrections)/30 << std::endl;
		std::cout << "total ALCT0 rate from ALCT/hNofAhit[2] first bin = " <<  h->GetBinContent(3)/30 << std::endl;
	};
}
