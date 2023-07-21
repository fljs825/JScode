// TextEntryWindow.cxx
#include "TextEntryWindow.h"
#include <TGComboBox.h>
#include <Riostream.h>
#include <TROOT.h>
#include <iostream>
#include <TApplication.h>
#include <TFile.h>
#include <Rtypes.h>
#include "NoticeKU_DRS_PROTOROOT.h"
#include "NoticeKU_DRS_PROTO.h"

#include "RtypesCore.h"
#include "DllImport.h"
 
#include "snprintf.h"   // part of stdio.h on systems that have it
#include "strlcpy.h"    // part of string.h on systems that have it
 
#include <atomic>
#include <stdio.h>
#include <string.h>
#include <typeinfo>

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"


//using namespace NKKU_DRS_PROTO;

TextEntryWindow::TextEntryWindow()
{
	fMain = new TGMainFrame(gClient -> GetRoot(), 10, 10, kVerticalFrame);
	
	fGframe = new TGGroupFrame(fMain, "ku_drs_proto_fast setting");

	// Group frame containing combobox and text entry.
	TGHorizontalFrame *hor2 = new TGHorizontalFrame(fGframe);
	fGframe -> AddFrame(hor2, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));
	TGLabel *label_file = new TGLabel(hor2, "filename : ");
	hor2 -> AddFrame(label_file, new TGLayoutHints(kLHintsLeft | kLHintsCenterY));

	TGHorizontalFrame *hor5 = new TGHorizontalFrame(fGframe);
	fGframe -> AddFrame(hor5, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));
	fEntry = new TGTextEntry(hor5);
	hor5 -> AddFrame(fEntry, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));

	TGHorizontalFrame *hor1 = new TGHorizontalFrame(fGframe);
	fGframe -> AddFrame(hor1, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));
	TGLabel *label = new TGLabel(hor1, "Software Trigger");
	hor1 -> AddFrame(label, new TGLayoutHints(kLHintsLeft | kLHintsCenterY));

	fCombo = new TGComboBox(hor1);
	hor1 -> AddFrame(fCombo, new TGLayoutHints(kLHintsRight | kLHintsExpandY, 5, 0, 5, 5));

	fCombo -> Resize(100, 20);

	TGHorizontalFrame *hor3 = new TGHorizontalFrame(fGframe);
	fGframe -> AddFrame(hor3, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));
	TGLabel *label3 = new TGLabel(hor3, "the number of events");
	hor3 -> AddFrame(label3, new TGLayoutHints(kLHintsLeft | kLHintsCenterY));

	Entry = new TGNumberEntry(hor3, 0, 9, 999, TGNumberFormat::kNESInteger,
											   TGNumberFormat::kNEANonNegative,
											   TGNumberFormat::kNELLimitMin, 0);
	
	hor3 -> AddFrame(Entry, new TGLayoutHints(kLHintsRight | kLHintsExpandY, 5, 0, 5, 5));

	TGHorizontalFrame *hor4 = new TGHorizontalFrame(fGframe);
	fGframe -> AddFrame(hor4, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));
	TGLabel *label4 = new TGLabel(hor4, "Trig Delay (ns)");
	hor4 -> AddFrame(label4, new TGLayoutHints(kLHintsLeft | kLHintsCenterY));

	Entry2 = new TGNumberEntry(hor4, 0, 9, 999, TGNumberFormat::kNESInteger,
											   TGNumberFormat::kNEANonNegative,
											   TGNumberFormat::kNELLimitMinMax,
											   0, 10000);
	
	hor4 -> AddFrame(Entry2, new TGLayoutHints(kLHintsRight | kLHintsExpandY, 5, 0, 5, 5));

	fMain -> AddFrame(fGframe, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 10, 10));
	//add entries
	fCombo -> AddEntry("On", 1);
	fCombo -> AddEntry("Off", 0);
	fCombo -> Select(0);

	// Add buttons
	TGHorizontalFrame *hframe = new TGHorizontalFrame(fMain, 200, 40);
	TGTextButton *exit = new TGTextButton(hframe, "&Exit","gApplication -> Terminate(0)");
	run = new TGTextButton(hframe, "&Run");

	run -> Connect("Clicked()","TextEntryWindow",this,"ku_drs_proto_fast()");

	hframe -> AddFrame(run, new TGLayoutHints(kLHintsCenterX, 5, 5, 3, 4));
	hframe -> AddFrame(exit, new TGLayoutHints(kLHintsCenterX, 5, 5, 3, 4));
	
	fMain -> AddFrame(hframe, new TGLayoutHints(kLHintsRight, 2, 2, 2, 2));
	
	hframe -> Resize(1000, 200);
	exit -> Resize(500, 100);
	run -> Resize (500, 100);
	
	// terminate ROOT session when window is closed
	fMain -> Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");
	fMain -> DontCallClose();

	fMain -> MapSubwindows();
	fMain -> Resize(400, 250);
	fMain -> Move(100, 200);

	// set minimum width, height
	fMain -> SetWMSizeHints(fMain -> GetDefaultWidth(), fMain -> GetDefaultHeight(), 1000, 1000, 0, 0);
	fMain -> SetWindowName("test");
	fMain -> MapRaised();

}

TextEntryWindow::~TextEntryWindow()
{
	fMain -> Cleanup();
	delete fMain;
}

ClassImp(NKKU_DRS_PROTO)

NKKU_DRS_PROTO::NKKU_DRS_PROTO() {}

NKKU_DRS_PROTO::~NKKU_DRS_PROTO() {}

int NKKU_DRS_PROTO::KU_DRS_PROTOopen(int sid)
{return ::KU_DRS_PROTOopen(sid);}

void NKKU_DRS_PROTO::KU_DRS_PROTOclose(int sid)
{::KU_DRS_PROTOclose(sid);}

void NKKU_DRS_PROTO::KU_DRS_PROTOread_DATA(int sid, int buf_cnt, char *data)
{::KU_DRS_PROTOread_DATA(sid, buf_cnt, data);}

void NKKU_DRS_PROTO::KU_DRS_PROTOreset(int sid)
{::KU_DRS_PROTOreset(sid);}

void NKKU_DRS_PROTO::KU_DRS_PROTOstart(int sid)
{::KU_DRS_PROTOstart(sid);}

void NKKU_DRS_PROTO::KU_DRS_PROTOstop(int sid)
{::KU_DRS_PROTOstop(sid);}

int NKKU_DRS_PROTO::KU_DRS_PROTOread_RUN(int sid)
{return ::KU_DRS_PROTOread_RUN(sid);}

int NKKU_DRS_PROTO::KU_DRS_PROTOread_DATASIZE(int sid)
{return ::KU_DRS_PROTOread_DATASIZE(sid);}

void NKKU_DRS_PROTO::KU_DRS_PROTOwrite_TRIG_DLY(int sid, int data)
{::KU_DRS_PROTOwrite_TRIG_DLY(sid, data);}

int NKKU_DRS_PROTO::KU_DRS_PROTOread_TRIG_DLY(int sid)
{return ::KU_DRS_PROTOread_TRIG_DLY(sid);}

void NKKU_DRS_PROTO::KU_DRS_PROTOwrite_CALMODE(int sid, int data)
{::KU_DRS_PROTOwrite_CALMODE(sid, data);}

int NKKU_DRS_PROTO::KU_DRS_PROTOread_CALMODE(int sid)
{return ::KU_DRS_PROTOread_CALMODE(sid);}

void NKKU_DRS_PROTO::KU_DRS_PROTOsend_TRIG(int sid)
{::KU_DRS_PROTOsend_TRIG(sid);}

void TextEntryWindow::ku_drs_proto_fast() 
{
	const unsigned int Nevent = Entry -> GetNumber();
	const unsigned short int dly = Entry2 -> GetNumber();
	const char *filename = fEntry -> GetTitle();
	
	TGLBEntry* selectedEntry = fCombo -> GetSelectedEntry();
	const char *softTrig_char  = selectedEntry -> GetTitle();
	const bool softTrig = (strcmp(softTrig_char, "On") == 0);
/*	
	cout << "The number of Events : "  << Nevent << endl;
	cout << "Trigger Delay : " << dly << endl;
	cout << "Filename : " << filename << endl;
	cout << "Soft Trigger is " << softTrig_char << endl;
}

void ku_drs_proto_fast(const char* filename = "hani_daq.dat", const unsigned int Nevent = 100000, const unsigned short int dly = 3000, const bool softTrg = false)
{*/
  gROOT->Reset();

  // set parameter here
  int sid = 1;  	                // KU_DRS_PROTO sid
//  int dly = 3000;                         // trigger input delay, 0 ~ 10000 ns in step of 1 ns
//  char filename[256];                   // data file name
//  sprintf(filename, "run00119.dat");     // set it here
  //sprintf(filename, "coinc.dat");     // set it here
//  int Nevent = 100000;                    // number of event to be taken

  // loading library
  R__LOAD_LIBRARY(libNoticeKU_DRS_PROTOROOT.so);

  // define KU_DRS_PROTO class
  NKKU_DRS_PROTO *drs = new NKKU_DRS_PROTO;

  // local variables for data acquisition
  int ch;
  int evt;
  FILE *fp;
  int buf_cnt;
  char data[32768];
  int i;
  float px;
  int adc[5];
  int value;
  int stop_addr;
  int stop_ch;

  // open drs
  drs->KU_DRS_PROTOopen(sid);

  drs->KU_DRS_PROTOwrite_CALMODE(sid, 0);

  // write setting registers and readback them
  drs->KU_DRS_PROTOwrite_TRIG_DLY(sid, dly);
  printf("trigger delay = %d\n", drs->KU_DRS_PROTOread_TRIG_DLY(sid));
  
  evt = 0;

  // open data file
  fp = fopen(filename, "wb");

  // reset drs
  drs->KU_DRS_PROTOreset(sid);

  // start daq
  drs->KU_DRS_PROTOstart(sid);
}

void getPanel()
{
	new TextEntryWindow();
}

int main(int argc, char *argv[])
{	
   	TApplication app("TextEntryWindow",&argc, argv);
	getPanel();
	app.Run();
	return 0;
}


