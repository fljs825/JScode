void LED_HA028_tot_ZCtime()
{
	// Load root files
	TFile *file1 = new TFile("/home/yjs825/230711/events_100000/LED_HA028_5000mV_t1.root");
	TFile *file2 = new TFile("/home/yjs825/230711/events_100000/LED_HA028_5000mV_TL_t1.root");
	TFile *file3 = new TFile("/home/yjs825/230711/events_100000/LED_HA028_6000mV_t1.root");
	TFile *file4 = new TFile("/home/yjs825/230711/events_100000/LED_HA028_6000mV_TL_t1.root");
	
	// Get data in tree
	TTree *tree1 = (TTree *) file1 -> Get("ch2/pul_ch2");
	TTree *tree2 = (TTree *) file2 -> Get("ch2/pul_ch2");
	TTree *tree3 = (TTree *) file3 -> Get("ch2/pul_ch2");
	TTree *tree4 = (TTree *) file4 -> Get("ch2/pul_ch2");

	TTree *treeP1 = (TTree *) file1 -> Get("ch2/pulp_ch2");
	TTree *treeP2 = (TTree *) file2 -> Get("ch2/pulp_ch2");
	TTree *treeP3 = (TTree *) file3 -> Get("ch2/pulp_ch2");
	TTree *treeP4 = (TTree *) file4 -> Get("ch2/pulp_ch2");

	// Get the number of Entries for each pul_ch2 and pulp_ch2
	int n1 = tree1->GetEntries();
	int n2 = tree2->GetEntries();
	int n3 = tree3->GetEntries();
	int n4 = tree4->GetEntries();

	int nP1 = treeP1->GetEntries();
	int nP2 = treeP2->GetEntries();
	int nP3 = treeP3->GetEntries();
	int nP4 = treeP4->GetEntries();

	// Allocate variables
	double area1, area2, area3, area4;
	double height1, height2, height3, height4;
	double ZCtime1, ZCtime2, ZCtime3, ZCtime4;
	ushort width1, width2, width3, width4;
	ushort pulseN1, pulseN2, pulseN3, pulseN4;

	double areaP1, areaP2, areaP3, areaP4;
	double heightP1, heightP2, heightP3, heightP4;
	double ZCtimeP1, ZCtimeP2, ZCtimeP3, ZCtimeP4;
	ushort widthP1, widthP2, widthP3, widthP4;
	ushort pulseNP1, pulseNP2, pulseNP3, pulseNP4;

	// Set Branch Addresses
	tree1 -> SetBranchAddress("area",   &area1);
    tree1 -> SetBranchAddress("height", &height1);
    tree1 -> SetBranchAddress("pulseN", &pulseN1);
    tree1 -> SetBranchAddress("width",  &width1);
    tree1 -> SetBranchAddress("ZCtime", &ZCtime1);

    treeP1 -> SetBranchAddress("area",  &areaP1);
    treeP1 -> SetBranchAddress("height",    &heightP1);
    treeP1 -> SetBranchAddress("pulseN",    &pulseNP1);
    treeP1 -> SetBranchAddress("width", &widthP1);
    treeP1 -> SetBranchAddress("ZCtime",    &ZCtimeP1);

	tree2 -> SetBranchAddress("area",   &area2);
    tree2 -> SetBranchAddress("height", &height2);
    tree2 -> SetBranchAddress("pulseN", &pulseN2);
    tree2 -> SetBranchAddress("width",  &width2);
    tree2 -> SetBranchAddress("ZCtime", &ZCtime2);

    treeP2 -> SetBranchAddress("area",  &areaP2);
    treeP2 -> SetBranchAddress("height",    &heightP2);
    treeP2 -> SetBranchAddress("pulseN",    &pulseNP2);
    treeP2 -> SetBranchAddress("width", &widthP2);
    treeP2 -> SetBranchAddress("ZCtime",    &ZCtimeP2);

	tree3 -> SetBranchAddress("area",   &area3);
    tree3 -> SetBranchAddress("height", &height3);
    tree3 -> SetBranchAddress("pulseN", &pulseN3);
    tree3 -> SetBranchAddress("width",  &width3);
    tree3 -> SetBranchAddress("ZCtime", &ZCtime3);

    treeP3 -> SetBranchAddress("area",  &areaP3);
    treeP3 -> SetBranchAddress("height",    &heightP3);
    treeP3 -> SetBranchAddress("pulseN",    &pulseNP3);
    treeP3 -> SetBranchAddress("width", &widthP3);
    treeP3 -> SetBranchAddress("ZCtime",    &ZCtimeP3);

	tree4 -> SetBranchAddress("area",   &area4);
    tree4 -> SetBranchAddress("height", &height4);
    tree4 -> SetBranchAddress("pulseN", &pulseN4);
    tree4 -> SetBranchAddress("width",  &width4);
    tree4 -> SetBranchAddress("ZCtime", &ZCtime4);

    treeP4 -> SetBranchAddress("area",  &areaP4);
    treeP4 -> SetBranchAddress("height",    &heightP4);
    treeP4 -> SetBranchAddress("pulseN",    &pulseNP4);
    treeP4 -> SetBranchAddress("width", &widthP4);
    treeP4 -> SetBranchAddress("ZCtime",    &ZCtimeP4);

	// construct histograms
	TH1D *h1 = new TH1D("h1","HA028 5000 mV SPE ZCtime dist;TDC;The number of events", 300, 0, 4096);
   TH1D *h2 = new TH1D("h2","HA028 5000 mV with TL SPE ZCtime dist;TDC;The number of events", 300, 0, 4096);
    TH1D *h3 = new TH1D("h3","HA028 6000 mV SPE ZCtime dist;TDC;The number of events", 300, 0, 4096);
	TH1D *h4 = new TH1D("h4","HA028 6000 mV with TL SPE ZCtime dist;TDC;The number of events", 300, 0, 4096);

	// Fill data to histogram
	printf("Progressing (1) : \n");
	for (int i = 0; i < n1; i++)
	{
		tree1 -> GetEvent(i);
		h1 -> Fill(ZCtime1);
	}
	for (int i = 0; i < n2; i++)
	{
		tree2 -> GetEvent(i);
		h2 -> Fill(ZCtime2);
	}
	for (int i = 0; i < n3; i++)
	{
		tree3 -> GetEvent(i);
		h3 -> Fill(ZCtime3);
	}
	for (int i = 0; i < n4; i++)
	{
		tree4 -> GetEvent(i);
		h4 -> Fill(ZCtime4);
	}

	printf("Progressing (2) : \n");	
	for (int i = 0; i < nP1; i++)
	{
		treeP1 -> GetEvent(i);
		h1 -> Fill(ZCtimeP1);
	}
	for (int i = 0; i < nP2; i++)
	{
		treeP2 -> GetEvent(i);
		h2 -> Fill(ZCtimeP2);
	}
	for (int i = 0; i < nP3; i++)
	{
		treeP3 -> GetEvent(i);
		h3 -> Fill(ZCtimeP3);
	}
	for (int i = 0; i < nP4; i++)
	{
		treeP4 -> GetEvent(i);
		h4 -> Fill(ZCtimeP4);
	}

	TCanvas *c1 = new TCanvas("c1","c1",1200,800);
	c1->Divide(2,2);
	c1->cd(1);
	c1->SetGrid();
	c1->SetLogy();
	h1->Draw();

	c1->cd(2);
	h2->Draw();

	c1->cd(3);
	h3->Draw();

	c1->cd(4);
	h4->Draw();

    c1->cd(1)->SetGrid();
    c1->cd(1)->SetLogy();
    c1->cd(2)->SetGrid();
    c1->cd(2)->SetLogy();
    c1->cd(3)->SetGrid();
    c1->cd(3)->SetLogy();
	c1->cd(4)->SetGrid();
	c1->cd(4)->SetLogy();
}

