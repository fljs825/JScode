// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME NoticeKU_DRS_PROTOROOT_gui_Dict
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
#include "NoticeKU_DRS_PROTOROOT_gui.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_NKKU_DRS_PROTO(void *p = 0);
   static void *newArray_NKKU_DRS_PROTO(Long_t size, void *p);
   static void delete_NKKU_DRS_PROTO(void *p);
   static void deleteArray_NKKU_DRS_PROTO(void *p);
   static void destruct_NKKU_DRS_PROTO(void *p);
   static void streamer_NKKU_DRS_PROTO(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::NKKU_DRS_PROTO*)
   {
      ::NKKU_DRS_PROTO *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::NKKU_DRS_PROTO >(0);
      static ::ROOT::TGenericClassInfo 
         instance("NKKU_DRS_PROTO", ::NKKU_DRS_PROTO::Class_Version(), "NoticeKU_DRS_PROTOROOT_gui.h", 21,
                  typeid(::NKKU_DRS_PROTO), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::NKKU_DRS_PROTO::Dictionary, isa_proxy, 18,
                  sizeof(::NKKU_DRS_PROTO) );
      instance.SetNew(&new_NKKU_DRS_PROTO);
      instance.SetNewArray(&newArray_NKKU_DRS_PROTO);
      instance.SetDelete(&delete_NKKU_DRS_PROTO);
      instance.SetDeleteArray(&deleteArray_NKKU_DRS_PROTO);
      instance.SetDestructor(&destruct_NKKU_DRS_PROTO);
      instance.SetStreamerFunc(&streamer_NKKU_DRS_PROTO);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::NKKU_DRS_PROTO*)
   {
      return GenerateInitInstanceLocal((::NKKU_DRS_PROTO*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::NKKU_DRS_PROTO*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

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
         instance("TextEntryWindow", "NoticeKU_DRS_PROTOROOT_gui.h", 43,
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

//______________________________________________________________________________
atomic_TClass_ptr NKKU_DRS_PROTO::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *NKKU_DRS_PROTO::Class_Name()
{
   return "NKKU_DRS_PROTO";
}

//______________________________________________________________________________
const char *NKKU_DRS_PROTO::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::NKKU_DRS_PROTO*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int NKKU_DRS_PROTO::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::NKKU_DRS_PROTO*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *NKKU_DRS_PROTO::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::NKKU_DRS_PROTO*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *NKKU_DRS_PROTO::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::NKKU_DRS_PROTO*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void NKKU_DRS_PROTO::Streamer(TBuffer &R__b)
{
   // Stream an object of class NKKU_DRS_PROTO.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_NKKU_DRS_PROTO(void *p) {
      return  p ? new(p) ::NKKU_DRS_PROTO : new ::NKKU_DRS_PROTO;
   }
   static void *newArray_NKKU_DRS_PROTO(Long_t nElements, void *p) {
      return p ? new(p) ::NKKU_DRS_PROTO[nElements] : new ::NKKU_DRS_PROTO[nElements];
   }
   // Wrapper around operator delete
   static void delete_NKKU_DRS_PROTO(void *p) {
      delete ((::NKKU_DRS_PROTO*)p);
   }
   static void deleteArray_NKKU_DRS_PROTO(void *p) {
      delete [] ((::NKKU_DRS_PROTO*)p);
   }
   static void destruct_NKKU_DRS_PROTO(void *p) {
      typedef ::NKKU_DRS_PROTO current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_NKKU_DRS_PROTO(TBuffer &buf, void *obj) {
      ((::NKKU_DRS_PROTO*)obj)->::NKKU_DRS_PROTO::Streamer(buf);
   }
} // end of namespace ROOT for class ::NKKU_DRS_PROTO

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
  void TriggerDictionaryInitialization_NoticeKU_DRS_PROTOROOT_gui_Dict_Impl() {
    static const char* headers[] = {
"NoticeKU_DRS_PROTOROOT_gui.h",
0
    };
    static const char* includePaths[] = {
"/mnt/raid/opt/root/root-6.24.06/include/",
"/mnt/raid/home/yjs825/drs_proto_gui/ku_drs_protoroot/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "NoticeKU_DRS_PROTOROOT_gui_Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate(R"ATTRDUMP(NKKU_DRS_PROTO wrapper class for root)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$NoticeKU_DRS_PROTOROOT_gui.h")))  NKKU_DRS_PROTO;
class __attribute__((annotate("$clingAutoload$NoticeKU_DRS_PROTOROOT_gui.h")))  TextEntryWindow;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "NoticeKU_DRS_PROTOROOT_gui_Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "NoticeKU_DRS_PROTOROOT_gui.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"NKKU_DRS_PROTO", payloadCode, "@",
"TextEntryWindow", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("NoticeKU_DRS_PROTOROOT_gui_Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_NoticeKU_DRS_PROTOROOT_gui_Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_NoticeKU_DRS_PROTOROOT_gui_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_NoticeKU_DRS_PROTOROOT_gui_Dict() {
  TriggerDictionaryInitialization_NoticeKU_DRS_PROTOROOT_gui_Dict_Impl();
}
