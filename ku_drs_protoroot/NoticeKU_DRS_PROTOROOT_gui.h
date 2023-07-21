#ifndef NKKU_DRS_PROTO_ROOT_GUI_H
#define NKKU_DRS_PROTO_ROOT_GUI_H

#include "TObject.h"
#include "LinkDef.h"
#include <TApplication.h>
#include <TGClient.h>
#include <TGButton.h>
#include <TGFrame.h>
#include <TGLabel.h>
#include <TGComboBox.h>
#include <TGTextEntry.h>
#include <TGNumberEntry.h>
#include <iostream>
#include <RQ_OBJECT.h>

using namespace std;

struct libusb_context;

class NKKU_DRS_PROTO : public TObject {
public:
	
  NKKU_DRS_PROTO();
  virtual ~NKKU_DRS_PROTO();
  int KU_DRS_PROTOopen(int sid);
  void KU_DRS_PROTOclose(int sid);
  void KU_DRS_PROTOread_DATA(int sid, int buf_cnt, char *data);
  void KU_DRS_PROTOreset(int sid);
  void KU_DRS_PROTOstart(int sid);
  void KU_DRS_PROTOstop(int sid);
  int KU_DRS_PROTOread_RUN(int sid);
  int KU_DRS_PROTOread_DATASIZE(int sid);
  void KU_DRS_PROTOwrite_TRIG_DLY(int sid, int data);
  int KU_DRS_PROTOread_TRIG_DLY(int sid);
  void KU_DRS_PROTOwrite_CALMODE(int sid, int data);
  int KU_DRS_PROTOread_CALMODE(int sid);
  void KU_DRS_PROTOsend_TRIG(int sid);

  ClassDef(NKKU_DRS_PROTO, 0) // NKKU_DRS_PROTO wrapper class for root
};

class TextEntryWindow {

private:
    TGMainFrame     *fMain;
    TGGroupFrame    *fGframe;
    TGComboBox      *fCombo; // combo box
    TGTextEntry     *fEntry; // text entry
    TGNumberEntry   *Entry;  // number entry
    TGNumberEntry   *Entry2;
    TGTextButton    *run;

public:
    TextEntryWindow();
    virtual ~TextEntryWindow(); //{ delete fMain; }
    void ku_drs_proto_fast();
    TGTextButton *GetRunButton() { return run; }

//    ClassDef(TextEntryWindow, 0)
};

#endif
