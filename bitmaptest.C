#include "lepTools.h"

using namespace std;

void bitmaptest()
{
	// Generate TChain for load file
	TChain *ch = new TChain("Events");
	ch -> Add("26386219-82B4-E447-A286-680A5F6E8237.root");

	// Allocate necessary variables
	int n_entry = ch->GetEntries();
	UInt_t nElectron;
	Int_t Electron_vidNestedWPBitmap[nElectron];
	Int_t Electron_cutBased[nElectron];
	int EventNUM;
	int Instance;
	int Electron_vidNestedWPBitmap_overmid;
	int Electron_cutBased_overmid;

	// Set Branch Addresses to TChain
	ch -> SetBranchAddress("Electron_vidNestedWPBitmap", &Electron_vidNestedWPBitmap);
	ch -> SetBranchAddress("nElectron", &nElectron);
	ch -> SetBranchAddress("Electron_cutBased", &Electron_cutBased);

	// Generate new TTrees and root file to contain filtered data
	TFile *output = new TFile("medium_vidNestedWPBitmap_electrons.root","recreate");
	TTree *tree_Bitmap = new TTree("tree_Bitmap", "tree_Bitmap_overmid");
	TTree *tree_cutBased = new TTree("tree_cutBased", "tree_cutBased_overmid");
	TTree *tree_Bitmap_only = new TTree("tree_Bitmap_only", "tree_Bitmap_overmid_only");
	TTree *tree_cutBased_only = new TTree("tree_cutBased_only", "tree_cutBased_overmid_only");

	// Generate Branches for new TTrees
	tree_Bitmap -> Branch("EventNUM", &EventNUM);
	tree_Bitmap -> Branch("Instance", &Instance);
	tree_Bitmap -> Branch("Electron_vidNestedWPBitmap_overmid", &Electron_vidNestedWPBitmap_overmid);
	tree_Bitmap -> Branch("Electron_cutBased_overmid", &Electron_cutBased_overmid);

	tree_cutBased -> Branch("EventNUM", &EventNUM);
	tree_cutBased -> Branch("Instance", &Instance);
	tree_cutBased -> Branch("Electron_vidNestedWPBitmap_overmid", &Electron_vidNestedWPBitmap_overmid);
	tree_cutBased -> Branch("Electron_cutBased_overmid", &Electron_cutBased_overmid);

	tree_Bitmap_only -> Branch("EventNUM", &EventNUM);
	tree_Bitmap_only -> Branch("Instance", &Instance);
	tree_Bitmap_only -> Branch("Electron_vidNestedWPBitmap_overmid", &Electron_vidNestedWPBitmap_overmid);
	tree_Bitmap_only -> Branch("Electron_cutBased_overmid", &Electron_cutBased_overmid);

	tree_cutBased_only -> Branch("EventNUM", &EventNUM);
	tree_cutBased_only -> Branch("Instance", &Instance);
	tree_cutBased_only -> Branch("Electron_vidNestedWPBitmap_overmid", &Electron_vidNestedWPBitmap_overmid);
	tree_cutBased_only -> Branch("Electron_cutBased_overmid", &Electron_cutBased_overmid);


	// Filling data to new TTrees
	for (int i = 0; i < n_entry; i++) {
		ch -> GetEvent(i);
		EventNUM = i;
		for (int j = 0; j < nElectron; j++) {
			if (idElectron_noIso(Electron_vidNestedWPBitmap[j], 3) == 1) {
				Instance = j;
				Electron_vidNestedWPBitmap_overmid = Electron_vidNestedWPBitmap[j];
				Electron_cutBased_overmid = Electron_cutBased[j];
			tree_Bitmap -> Fill(); // Construct tree with all the data just Bitmap level > 3
			}

			if (Electron_cutBased[j] >= 3) {
				Instance = j;
				Electron_vidNestedWPBitmap_overmid = Electron_vidNestedWPBitmap[j];
				Electron_cutBased_overmid = Electron_cutBased[j];
			tree_cutBased -> Fill(); // Construct tree with all the data just cutBased > 3 
			}

			if (idElectron_noIso(Electron_vidNestedWPBitmap[j], 3) == 1 && Electron_cutBased[j] < 3) {
				Instance = j;
				Electron_vidNestedWPBitmap_overmid = Electron_vidNestedWPBitmap[j];
				Electron_cutBased_overmid = Electron_cutBased[j];
				tree_Bitmap_only -> Fill(); // Construc tree with Bitmap level > 3 but cutBased < 3
			}

			if (idElectron_noIso(Electron_vidNestedWPBitmap[j], 3) == 0 && Electron_cutBased[j] >= 3) {
				Instance = j;
				Electron_vidNestedWPBitmap_overmid = Electron_vidNestedWPBitmap[j];
				Electron_cutBased_overmid = Electron_cutBased[j];
				tree_cutBased_only -> Fill(); // Construct tree with Bitmap level < 3 but cutBased > 3
			}	
			else {};
		}
	}

	// Finalize
	tree_Bitmap -> Write();
	tree_cutBased -> Write();
	tree_Bitmap_only -> Write();
	tree_cutBased_only -> Write();
	output -> Close();
}
