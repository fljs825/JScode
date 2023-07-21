// TextEntryWindow.h

#ifndef TEXTENTRYWINDOW_H
#define TEXTENTRYWINDOW_H

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

