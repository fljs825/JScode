#include <iostream>
#include <fstream>
#include <string>
#include "linedraw.h"

void PMT_config(const int npeaks = 2) 
{
	// Get the Number of files (nfile)
	std::ifstream root_File_Names;
	root_File_Names.open("list.txt");
	std::string str;

	int nfile = 0;
	while (!root_File_Names.eof())
	{			
		getline(root_File_Names, str);
		nfile = nfile + 1;
	}
	root_File_Names.close();
	nfile = nfile - 1;
	
	// Allocate variables
	int n_entries[nfile];
	double area[nfile], height[nfile], ZCtime[nfile];
	ushort width[nfile], pulseN[nfile];

	int n_entriesP[nfile];
	double areaP[nfile], heightP[nfile], ZCtimeP[nfile];
	ushort widthP[nfile], pulseNP[nfile];

	// Label PMTs Numbering
	std::string filename_sub[nfile];
	const char *nPMT[nfile];

	// Load files and construct trees
	std::ifstream root_File_Names2;
	root_File_Names2.open("list.txt");
	std::string filename;

	TFile *file[nfile];
	TTree *tree[nfile];
	TTree *treeP[nfile];
	TH1D *h[nfile];
	for (int i = 0; i < nfile; i++) 
	{
        root_File_Names2 >> filename;
        file[i] = new TFile(filename.c_str());

		for (int j = 4; j < 9; j++)
		{
			filename_sub[i] += filename[j];
		}
		nPMT[i] = filename_sub[i].c_str();

		tree[i] = (TTree *) file[i] -> Get("ch2/pul_ch2");
		
		tree[i] -> SetBranchAddress("area",		&area[i]);
		tree[i] -> SetBranchAddress("height",	&height[i]);
		tree[i] -> SetBranchAddress("pulseN",	&pulseN[i]);
		tree[i] -> SetBranchAddress("width",	&width[i]);
		tree[i] -> SetBranchAddress("ZCtime",	&ZCtime[i]);
		
		treeP[i] = (TTree *) file[i] -> Get("ch2/pulp_ch2");

		treeP[i] -> SetBranchAddress("area",		&areaP[i]);
		treeP[i] -> SetBranchAddress("height",	&heightP[i]);
		treeP[i] -> SetBranchAddress("pulseN",	&pulseNP[i]);
		treeP[i] -> SetBranchAddress("width",	&widthP[i]);
		treeP[i] -> SetBranchAddress("ZCtime",	&ZCtimeP[i]);
	
		n_entries[i] = tree[i] -> GetEntries();
		n_entriesP[i] = treeP[i] -> GetEntries();
	}

	// Construct histograms : Naming histograms and title
	string n_hist[nfile];
	string n_canv[nfile];
	string hist_title[nfile];
    string n_fitf[nfile][npeaks];
	const char *n_histo[nfile];
	const char *n_canvas[nfile];
	const char *histo_title[nfile];
    const char *n_fitfunc[nfile][npeaks];
	for (int i = 0; i < nfile; i++)
	{
		n_hist[i] = "h";
		n_hist[i] += to_string(i);
		
		n_canv[i] = "c";
		n_canv[i] += to_string(i);

        for (int j = 0; j < npeaks; j++)
        {
            n_fitf[i][j] = "f";
            n_fitf[i][j] += to_string(j);
            n_fitfunc[i][j] = n_fitf[i][j].c_str();
        }
		
		n_canvas[i] = n_canv[i].c_str();
		n_histo[i] = n_hist[i].c_str();
	}

	// Construct Histograms and Filling
	for (int i = 0; i < nfile; i++)
	{
		h[i] = new TH1D(n_histo[i], nPMT[i], 300, -200, 200);
		cout << n_entries[i] << endl;
		for (int j = 0; j < n_entries[i]; j++)
		{
			tree[i] -> GetEvent(j);
			h[i] -> Fill(area[i]);
			treeP[i] -> GetEvent(j);
			h[i] -> Fill(areaP[i]);
		}
	}

	// Find peaks and construct Gaussian fit functions and get mean values
    TF1 *f[nfile][npeaks];
	TF1 *g[nfile][npeaks];
    double mean[nfile][npeaks];
    double stdev[nfile][npeaks];
    Double_t *xpeaks[nfile];
    TSpectrum *s1 = new TSpectrum(npeaks);
    for (int i = 0; i < nfile; i++)
    {
        Int_t nfound = s1 -> Search(h[i],0,"",0.000001);
        xpeaks[i] = s1 -> GetPositionX();
        for (int j = 0; j < nfile; j++)
        {
            f[i][j] = new TF1(n_fitfunc[i][j],"gaus",xpeaks[i][j] - 20, xpeaks[i][j] + 20);
            h[i] -> Fit(f[i][j], "RN");
            mean[i][j] = f[i][j] -> GetParameter(1);
            stdev[i][j] = f[i][j] -> GetParameter(2);
			
			g[i][j] = new TF1(n_fitfunc[i][j],"gaus",xpeaks[i][j] - (2.355 * stdev[i][j]), xpeaks[i][j] + (2.355*stdev[i][j]));
			h[i] -> Fit(g[i][j], "R+");
			mean[i][j] = g[i][j] -> GetParameter(1);
			stdev[i][j] = g[i][j] -> GetParameter(2);
			cout << mean[i][j] << endl;
        }
    }
/*
	// Refit by gaussian with setted parameters	
	for (int i = 0; i < nfile; i++)
	{
		for (int j = 0; j < npeaks; j++) 
		{
			g[i][j] = new TF1(n_fitfunc[i][j],"gaus",mean[i][j] - (2.355 * stdev[i][j]), mean[i][j] + (2.355*stdev[i][j]));
			h[i] -> Fit(g[i][j], "R+");
			mean[i][j] = g[i][j] -> GetParameter(1);
			stdev[i][j] = g[i][j] -> GetParameter(2);
			cout << mean[i][j] << endl;
		}
	}  
*/
	// Draw Histograms
	TCanvas *c[nfile];
	for (int i = 0; i < nfile; i++)
	{
		c[i] = new TCanvas(n_canvas[i],n_canvas[i],800,600);
		c[i] -> SetGrid();
		c[i] -> SetLogy();
		h[i] -> Draw();
	}

	// Arrange data by Tree
	TFile *output = new TFile("area_dist.root","recreate");
	TTree *tree_make = new TTree("tree","PMT_area_config.root");

	std::string PMT_Num;
	double area_mean;
	double area_stdev;
	tree_make -> Branch("PMT_Num", &PMT_Num);
	tree_make -> Branch("Area_Mean", &area_mean);
	tree_make -> Branch("Area_Stdev", &area_stdev);

	for (int i = 0; i < nfile; i++)
	{
		PMT_Num = nPMT[i];
		area_mean = mean[i][1];
		area_stdev = stdev[i][1];
		tree_make -> Fill();
	}

	tree_make -> Write();
	output -> Close();
}

	


