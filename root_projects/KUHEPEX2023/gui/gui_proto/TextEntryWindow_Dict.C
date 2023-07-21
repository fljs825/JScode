// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME TextEntryWindow_Dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
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

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "TextEntryWindow.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *TextEntryWindow_Dictionary();
   static void TextEntryWindow_TClassManip(TClass*);
   static void *new_TextEntryWindow(void *p = 0);
   static void *newArray_TextEntryWindow(Long_t size, void *p);
   static void delete_TextEntryWindow(void *p);
   static void deleteArray_TextEntryWindow(void *p);
   static void destruct_TextEntryWindow(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TextEntryWindow*)
   {
      ::TextEntryWindow *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TextEntryWindow));
      static ::ROOT::TGenericClassInfo 
         instance("TextEntryWindow", "TextEntryWindow.h", 20,
                  typeid(::TextEntryWindow), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TextEntryWindow_Dictionary, isa_proxy, 4,
                  sizeof(::TextEntryWindow) );
      instance.SetNew(&new_TextEntryWindow);
      instance.SetNewArray(&newArray_TextEntryWindow);
      instance.SetDelete(&delete_TextEntryWindow);
      instance.SetDeleteArray(&deleteArray_TextEntryWindow);
      instance.SetDestructor(&destruct_TextEntryWindow);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TextEntryWindow*)
   {
      return GenerateInitInstanceLocal((::TextEntryWindow*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TextEntryWindow*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TextEntryWindow_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TextEntryWindow*)0x0)->GetClass();
      TextEntryWindow_TClassManip(theClass);
   return theClass;
   }

   static void TextEntryWindow_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_TextEntryWindow(void *p) {
      return  p ? new(p) ::TextEntryWindow : new ::TextEntryWindow;
   }
   static void *newArray_TextEntryWindow(Long_t nElements, void *p) {
      return p ? new(p) ::TextEntryWindow[nElements] : new ::TextEntryWindow[nElements];
   }
   // Wrapper around operator delete
   static void delete_TextEntryWindow(void *p) {
      delete ((::TextEntryWindow*)p);
   }
   static void deleteArray_TextEntryWindow(void *p) {
      delete [] ((::TextEntryWindow*)p);
   }
   static void destruct_TextEntryWindow(void *p) {
      typedef ::TextEntryWindow current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TextEntryWindow

namespace {
  void TriggerDictionaryInitialization_TextEntryWindow_Dict_Impl() {
    static const char* headers[] = {
"TextEntryWindow.h",
0
    };
    static const char* includePaths[] = {
"/mnt/raid/opt/root/root-6.24.06/include/",
"/mnt/raid/home/yjs825/drs_proto_gui/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TextEntryWindow_Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$TextEntryWindow.h")))  TextEntryWindow;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TextEntryWindow_Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TextEntryWindow.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TextEntryWindow", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TextEntryWindow_Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TextEntryWindow_Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TextEntryWindow_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TextEntryWindow_Dict() {
  TriggerDictionaryInitialization_TextEntryWindow_Dict_Impl();
}
