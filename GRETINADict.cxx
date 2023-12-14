// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME GRETINADict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
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
#include "include/GRETINA.h"
#include "include/SortingStructures.h"
#include "include/GRETINAWavefunction.h"
#include "include/INLCorrection.h"
#include "include/Histos.h"
#include "include/Track.h"
#include "include/Utilities.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_controlVariables(void *p = nullptr);
   static void *newArray_controlVariables(Long_t size, void *p);
   static void delete_controlVariables(void *p);
   static void deleteArray_controlVariables(void *p);
   static void destruct_controlVariables(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::controlVariables*)
   {
      ::controlVariables *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::controlVariables >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("controlVariables", ::controlVariables::Class_Version(), "include/SortingStructures.h", 21,
                  typeid(::controlVariables), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::controlVariables::Dictionary, isa_proxy, 4,
                  sizeof(::controlVariables) );
      instance.SetNew(&new_controlVariables);
      instance.SetNewArray(&newArray_controlVariables);
      instance.SetDelete(&delete_controlVariables);
      instance.SetDeleteArray(&deleteArray_controlVariables);
      instance.SetDestructor(&destruct_controlVariables);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::controlVariables*)
   {
      return GenerateInitInstanceLocal(static_cast<::controlVariables*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::controlVariables*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_counterVariables(void *p = nullptr);
   static void *newArray_counterVariables(Long_t size, void *p);
   static void delete_counterVariables(void *p);
   static void deleteArray_counterVariables(void *p);
   static void destruct_counterVariables(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::counterVariables*)
   {
      ::counterVariables *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::counterVariables >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("counterVariables", ::counterVariables::Class_Version(), "include/SortingStructures.h", 130,
                  typeid(::counterVariables), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::counterVariables::Dictionary, isa_proxy, 4,
                  sizeof(::counterVariables) );
      instance.SetNew(&new_counterVariables);
      instance.SetNewArray(&newArray_counterVariables);
      instance.SetDelete(&delete_counterVariables);
      instance.SetDeleteArray(&deleteArray_counterVariables);
      instance.SetDestructor(&destruct_counterVariables);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::counterVariables*)
   {
      return GenerateInitInstanceLocal(static_cast<::counterVariables*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::counterVariables*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *PM_Dictionary();
   static void PM_TClassManip(TClass*);
   static void *new_PM(void *p = nullptr);
   static void *newArray_PM(Long_t size, void *p);
   static void delete_PM(void *p);
   static void deleteArray_PM(void *p);
   static void destruct_PM(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PM*)
   {
      ::PM *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PM));
      static ::ROOT::TGenericClassInfo 
         instance("PM", "include/Track.h", 40,
                  typeid(::PM), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PM_Dictionary, isa_proxy, 4,
                  sizeof(::PM) );
      instance.SetNew(&new_PM);
      instance.SetNewArray(&newArray_PM);
      instance.SetDelete(&delete_PM);
      instance.SetDeleteArray(&deleteArray_PM);
      instance.SetDestructor(&destruct_PM);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PM*)
   {
      return GenerateInitInstanceLocal(static_cast<::PM*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::PM*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PM_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::PM*>(nullptr))->GetClass();
      PM_TClassManip(theClass);
   return theClass;
   }

   static void PM_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_TrackClusterIP(void *p = nullptr);
   static void *newArray_TrackClusterIP(Long_t size, void *p);
   static void delete_TrackClusterIP(void *p);
   static void deleteArray_TrackClusterIP(void *p);
   static void destruct_TrackClusterIP(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TrackClusterIP*)
   {
      ::TrackClusterIP *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TrackClusterIP >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TrackClusterIP", ::TrackClusterIP::Class_Version(), "include/Track.h", 49,
                  typeid(::TrackClusterIP), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TrackClusterIP::Dictionary, isa_proxy, 4,
                  sizeof(::TrackClusterIP) );
      instance.SetNew(&new_TrackClusterIP);
      instance.SetNewArray(&newArray_TrackClusterIP);
      instance.SetDelete(&delete_TrackClusterIP);
      instance.SetDeleteArray(&deleteArray_TrackClusterIP);
      instance.SetDestructor(&destruct_TrackClusterIP);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TrackClusterIP*)
   {
      return GenerateInitInstanceLocal(static_cast<::TrackClusterIP*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TrackClusterIP*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TrackCluster(void *p = nullptr);
   static void *newArray_TrackCluster(Long_t size, void *p);
   static void delete_TrackCluster(void *p);
   static void deleteArray_TrackCluster(void *p);
   static void destruct_TrackCluster(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TrackCluster*)
   {
      ::TrackCluster *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TrackCluster >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TrackCluster", ::TrackCluster::Class_Version(), "include/Track.h", 70,
                  typeid(::TrackCluster), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TrackCluster::Dictionary, isa_proxy, 4,
                  sizeof(::TrackCluster) );
      instance.SetNew(&new_TrackCluster);
      instance.SetNewArray(&newArray_TrackCluster);
      instance.SetDelete(&delete_TrackCluster);
      instance.SetDeleteArray(&deleteArray_TrackCluster);
      instance.SetDestructor(&destruct_TrackCluster);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TrackCluster*)
   {
      return GenerateInitInstanceLocal(static_cast<::TrackCluster*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TrackCluster*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TrackShell(void *p = nullptr);
   static void *newArray_TrackShell(Long_t size, void *p);
   static void delete_TrackShell(void *p);
   static void deleteArray_TrackShell(void *p);
   static void destruct_TrackShell(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TrackShell*)
   {
      ::TrackShell *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TrackShell >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TrackShell", ::TrackShell::Class_Version(), "include/Track.h", 96,
                  typeid(::TrackShell), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TrackShell::Dictionary, isa_proxy, 4,
                  sizeof(::TrackShell) );
      instance.SetNew(&new_TrackShell);
      instance.SetNewArray(&newArray_TrackShell);
      instance.SetDelete(&delete_TrackShell);
      instance.SetDeleteArray(&deleteArray_TrackShell);
      instance.SetDestructor(&destruct_TrackShell);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TrackShell*)
   {
      return GenerateInitInstanceLocal(static_cast<::TrackShell*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TrackShell*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TrackCtrl(void *p = nullptr);
   static void *newArray_TrackCtrl(Long_t size, void *p);
   static void delete_TrackCtrl(void *p);
   static void deleteArray_TrackCtrl(void *p);
   static void destruct_TrackCtrl(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TrackCtrl*)
   {
      ::TrackCtrl *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TrackCtrl >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TrackCtrl", ::TrackCtrl::Class_Version(), "include/Track.h", 138,
                  typeid(::TrackCtrl), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TrackCtrl::Dictionary, isa_proxy, 4,
                  sizeof(::TrackCtrl) );
      instance.SetNew(&new_TrackCtrl);
      instance.SetNewArray(&newArray_TrackCtrl);
      instance.SetDelete(&delete_TrackCtrl);
      instance.SetDeleteArray(&deleteArray_TrackCtrl);
      instance.SetDestructor(&destruct_TrackCtrl);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TrackCtrl*)
   {
      return GenerateInitInstanceLocal(static_cast<::TrackCtrl*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TrackCtrl*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TrackStat(void *p = nullptr);
   static void *newArray_TrackStat(Long_t size, void *p);
   static void delete_TrackStat(void *p);
   static void deleteArray_TrackStat(void *p);
   static void destruct_TrackStat(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TrackStat*)
   {
      ::TrackStat *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TrackStat >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TrackStat", ::TrackStat::Class_Version(), "include/Track.h", 218,
                  typeid(::TrackStat), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TrackStat::Dictionary, isa_proxy, 4,
                  sizeof(::TrackStat) );
      instance.SetNew(&new_TrackStat);
      instance.SetNewArray(&newArray_TrackStat);
      instance.SetDelete(&delete_TrackStat);
      instance.SetDeleteArray(&deleteArray_TrackStat);
      instance.SetDestructor(&destruct_TrackStat);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TrackStat*)
   {
      return GenerateInitInstanceLocal(static_cast<::TrackStat*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TrackStat*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TrackPerm(void *p = nullptr);
   static void *newArray_TrackPerm(Long_t size, void *p);
   static void delete_TrackPerm(void *p);
   static void deleteArray_TrackPerm(void *p);
   static void destruct_TrackPerm(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TrackPerm*)
   {
      ::TrackPerm *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TrackPerm >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TrackPerm", ::TrackPerm::Class_Version(), "include/Track.h", 266,
                  typeid(::TrackPerm), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TrackPerm::Dictionary, isa_proxy, 4,
                  sizeof(::TrackPerm) );
      instance.SetNew(&new_TrackPerm);
      instance.SetNewArray(&newArray_TrackPerm);
      instance.SetDelete(&delete_TrackPerm);
      instance.SetDeleteArray(&deleteArray_TrackPerm);
      instance.SetDestructor(&destruct_TrackPerm);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TrackPerm*)
   {
      return GenerateInitInstanceLocal(static_cast<::TrackPerm*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TrackPerm*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Track(void *p = nullptr);
   static void *newArray_Track(Long_t size, void *p);
   static void delete_Track(void *p);
   static void deleteArray_Track(void *p);
   static void destruct_Track(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Track*)
   {
      ::Track *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Track >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Track", ::Track::Class_Version(), "include/Track.h", 277,
                  typeid(::Track), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Track::Dictionary, isa_proxy, 4,
                  sizeof(::Track) );
      instance.SetNew(&new_Track);
      instance.SetNewArray(&newArray_Track);
      instance.SetDelete(&delete_Track);
      instance.SetDeleteArray(&deleteArray_Track);
      instance.SetDestructor(&destruct_Track);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Track*)
   {
      return GenerateInitInstanceLocal(static_cast<::Track*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Track*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rotationMatrix(void *p = nullptr);
   static void *newArray_rotationMatrix(Long_t size, void *p);
   static void delete_rotationMatrix(void *p);
   static void deleteArray_rotationMatrix(void *p);
   static void destruct_rotationMatrix(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rotationMatrix*)
   {
      ::rotationMatrix *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rotationMatrix >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("rotationMatrix", ::rotationMatrix::Class_Version(), "include/GRETINA.h", 29,
                  typeid(::rotationMatrix), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rotationMatrix::Dictionary, isa_proxy, 4,
                  sizeof(::rotationMatrix) );
      instance.SetNew(&new_rotationMatrix);
      instance.SetNewArray(&newArray_rotationMatrix);
      instance.SetDelete(&delete_rotationMatrix);
      instance.SetDeleteArray(&deleteArray_rotationMatrix);
      instance.SetDestructor(&destruct_rotationMatrix);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rotationMatrix*)
   {
      return GenerateInitInstanceLocal(static_cast<::rotationMatrix*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::rotationMatrix*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_GRETINAVariables(void *p = nullptr);
   static void *newArray_GRETINAVariables(Long_t size, void *p);
   static void delete_GRETINAVariables(void *p);
   static void deleteArray_GRETINAVariables(void *p);
   static void destruct_GRETINAVariables(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::GRETINAVariables*)
   {
      ::GRETINAVariables *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::GRETINAVariables >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("GRETINAVariables", ::GRETINAVariables::Class_Version(), "include/GRETINA.h", 47,
                  typeid(::GRETINAVariables), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::GRETINAVariables::Dictionary, isa_proxy, 4,
                  sizeof(::GRETINAVariables) );
      instance.SetNew(&new_GRETINAVariables);
      instance.SetNewArray(&newArray_GRETINAVariables);
      instance.SetDelete(&delete_GRETINAVariables);
      instance.SetDeleteArray(&deleteArray_GRETINAVariables);
      instance.SetDestructor(&destruct_GRETINAVariables);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::GRETINAVariables*)
   {
      return GenerateInitInstanceLocal(static_cast<::GRETINAVariables*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::GRETINAVariables*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *globalHeader_Dictionary();
   static void globalHeader_TClassManip(TClass*);
   static void *new_globalHeader(void *p = nullptr);
   static void *newArray_globalHeader(Long_t size, void *p);
   static void delete_globalHeader(void *p);
   static void deleteArray_globalHeader(void *p);
   static void destruct_globalHeader(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::globalHeader*)
   {
      ::globalHeader *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::globalHeader));
      static ::ROOT::TGenericClassInfo 
         instance("globalHeader", "include/GRETINA.h", 100,
                  typeid(::globalHeader), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &globalHeader_Dictionary, isa_proxy, 4,
                  sizeof(::globalHeader) );
      instance.SetNew(&new_globalHeader);
      instance.SetNewArray(&newArray_globalHeader);
      instance.SetDelete(&delete_globalHeader);
      instance.SetDeleteArray(&deleteArray_globalHeader);
      instance.SetDestructor(&destruct_globalHeader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::globalHeader*)
   {
      return GenerateInitInstanceLocal(static_cast<::globalHeader*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::globalHeader*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *globalHeader_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::globalHeader*>(nullptr))->GetClass();
      globalHeader_TClassManip(theClass);
   return theClass;
   }

   static void globalHeader_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *mode3DataPacket_Dictionary();
   static void mode3DataPacket_TClassManip(TClass*);
   static void *new_mode3DataPacket(void *p = nullptr);
   static void *newArray_mode3DataPacket(Long_t size, void *p);
   static void delete_mode3DataPacket(void *p);
   static void deleteArray_mode3DataPacket(void *p);
   static void destruct_mode3DataPacket(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::mode3DataPacket*)
   {
      ::mode3DataPacket *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::mode3DataPacket));
      static ::ROOT::TGenericClassInfo 
         instance("mode3DataPacket", "include/GRETINA.h", 110,
                  typeid(::mode3DataPacket), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &mode3DataPacket_Dictionary, isa_proxy, 4,
                  sizeof(::mode3DataPacket) );
      instance.SetNew(&new_mode3DataPacket);
      instance.SetNewArray(&newArray_mode3DataPacket);
      instance.SetDelete(&delete_mode3DataPacket);
      instance.SetDeleteArray(&deleteArray_mode3DataPacket);
      instance.SetDestructor(&destruct_mode3DataPacket);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::mode3DataPacket*)
   {
      return GenerateInitInstanceLocal(static_cast<::mode3DataPacket*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::mode3DataPacket*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *mode3DataPacket_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::mode3DataPacket*>(nullptr))->GetClass();
      mode3DataPacket_TClassManip(theClass);
   return theClass;
   }

   static void mode3DataPacket_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_g3Waveform(void *p = nullptr);
   static void *newArray_g3Waveform(Long_t size, void *p);
   static void delete_g3Waveform(void *p);
   static void deleteArray_g3Waveform(void *p);
   static void destruct_g3Waveform(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g3Waveform*)
   {
      ::g3Waveform *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g3Waveform >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g3Waveform", ::g3Waveform::Class_Version(), "include/GRETINA.h", 117,
                  typeid(::g3Waveform), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g3Waveform::Dictionary, isa_proxy, 4,
                  sizeof(::g3Waveform) );
      instance.SetNew(&new_g3Waveform);
      instance.SetNewArray(&newArray_g3Waveform);
      instance.SetDelete(&delete_g3Waveform);
      instance.SetDeleteArray(&deleteArray_g3Waveform);
      instance.SetDestructor(&destruct_g3Waveform);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g3Waveform*)
   {
      return GenerateInitInstanceLocal(static_cast<::g3Waveform*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g3Waveform*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_g3ChannelEvent(void *p = nullptr);
   static void *newArray_g3ChannelEvent(Long_t size, void *p);
   static void delete_g3ChannelEvent(void *p);
   static void deleteArray_g3ChannelEvent(void *p);
   static void destruct_g3ChannelEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g3ChannelEvent*)
   {
      ::g3ChannelEvent *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g3ChannelEvent >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g3ChannelEvent", ::g3ChannelEvent::Class_Version(), "include/GRETINA.h", 148,
                  typeid(::g3ChannelEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g3ChannelEvent::Dictionary, isa_proxy, 4,
                  sizeof(::g3ChannelEvent) );
      instance.SetNew(&new_g3ChannelEvent);
      instance.SetNewArray(&newArray_g3ChannelEvent);
      instance.SetDelete(&delete_g3ChannelEvent);
      instance.SetDeleteArray(&deleteArray_g3ChannelEvent);
      instance.SetDestructor(&destruct_g3ChannelEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g3ChannelEvent*)
   {
      return GenerateInitInstanceLocal(static_cast<::g3ChannelEvent*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g3ChannelEvent*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_g3CrystalEvent(void *p = nullptr);
   static void *newArray_g3CrystalEvent(Long_t size, void *p);
   static void delete_g3CrystalEvent(void *p);
   static void deleteArray_g3CrystalEvent(void *p);
   static void destruct_g3CrystalEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g3CrystalEvent*)
   {
      ::g3CrystalEvent *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g3CrystalEvent >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g3CrystalEvent", ::g3CrystalEvent::Class_Version(), "include/GRETINA.h", 180,
                  typeid(::g3CrystalEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g3CrystalEvent::Dictionary, isa_proxy, 4,
                  sizeof(::g3CrystalEvent) );
      instance.SetNew(&new_g3CrystalEvent);
      instance.SetNewArray(&newArray_g3CrystalEvent);
      instance.SetDelete(&delete_g3CrystalEvent);
      instance.SetDeleteArray(&deleteArray_g3CrystalEvent);
      instance.SetDestructor(&destruct_g3CrystalEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g3CrystalEvent*)
   {
      return GenerateInitInstanceLocal(static_cast<::g3CrystalEvent*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g3CrystalEvent*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_g3OUT(void *p = nullptr);
   static void *newArray_g3OUT(Long_t size, void *p);
   static void delete_g3OUT(void *p);
   static void deleteArray_g3OUT(void *p);
   static void destruct_g3OUT(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g3OUT*)
   {
      ::g3OUT *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g3OUT >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g3OUT", ::g3OUT::Class_Version(), "include/GRETINA.h", 227,
                  typeid(::g3OUT), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g3OUT::Dictionary, isa_proxy, 4,
                  sizeof(::g3OUT) );
      instance.SetNew(&new_g3OUT);
      instance.SetNewArray(&newArray_g3OUT);
      instance.SetDelete(&delete_g3OUT);
      instance.SetDeleteArray(&deleteArray_g3OUT);
      instance.SetDestructor(&destruct_g3OUT);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g3OUT*)
   {
      return GenerateInitInstanceLocal(static_cast<::g3OUT*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g3OUT*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *mode3HistoryPacket_Dictionary();
   static void mode3HistoryPacket_TClassManip(TClass*);
   static void *new_mode3HistoryPacket(void *p = nullptr);
   static void *newArray_mode3HistoryPacket(Long_t size, void *p);
   static void delete_mode3HistoryPacket(void *p);
   static void deleteArray_mode3HistoryPacket(void *p);
   static void destruct_mode3HistoryPacket(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::mode3HistoryPacket*)
   {
      ::mode3HistoryPacket *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::mode3HistoryPacket));
      static ::ROOT::TGenericClassInfo 
         instance("mode3HistoryPacket", "include/GRETINA.h", 242,
                  typeid(::mode3HistoryPacket), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &mode3HistoryPacket_Dictionary, isa_proxy, 4,
                  sizeof(::mode3HistoryPacket) );
      instance.SetNew(&new_mode3HistoryPacket);
      instance.SetNewArray(&newArray_mode3HistoryPacket);
      instance.SetDelete(&delete_mode3HistoryPacket);
      instance.SetDeleteArray(&deleteArray_mode3HistoryPacket);
      instance.SetDestructor(&destruct_mode3HistoryPacket);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::mode3HistoryPacket*)
   {
      return GenerateInitInstanceLocal(static_cast<::mode3HistoryPacket*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::mode3HistoryPacket*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *mode3HistoryPacket_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::mode3HistoryPacket*>(nullptr))->GetClass();
      mode3HistoryPacket_TClassManip(theClass);
   return theClass;
   }

   static void mode3HistoryPacket_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *historyEvent_Dictionary();
   static void historyEvent_TClassManip(TClass*);
   static void *new_historyEvent(void *p = nullptr);
   static void *newArray_historyEvent(Long_t size, void *p);
   static void delete_historyEvent(void *p);
   static void deleteArray_historyEvent(void *p);
   static void destruct_historyEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::historyEvent*)
   {
      ::historyEvent *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::historyEvent));
      static ::ROOT::TGenericClassInfo 
         instance("historyEvent", "include/GRETINA.h", 260,
                  typeid(::historyEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &historyEvent_Dictionary, isa_proxy, 4,
                  sizeof(::historyEvent) );
      instance.SetNew(&new_historyEvent);
      instance.SetNewArray(&newArray_historyEvent);
      instance.SetDelete(&delete_historyEvent);
      instance.SetDeleteArray(&deleteArray_historyEvent);
      instance.SetDestructor(&destruct_historyEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::historyEvent*)
   {
      return GenerateInitInstanceLocal(static_cast<::historyEvent*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::historyEvent*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *historyEvent_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::historyEvent*>(nullptr))->GetClass();
      historyEvent_TClassManip(theClass);
   return theClass;
   }

   static void historyEvent_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_g3HistoryEvent(void *p = nullptr);
   static void *newArray_g3HistoryEvent(Long_t size, void *p);
   static void delete_g3HistoryEvent(void *p);
   static void deleteArray_g3HistoryEvent(void *p);
   static void destruct_g3HistoryEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g3HistoryEvent*)
   {
      ::g3HistoryEvent *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g3HistoryEvent >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g3HistoryEvent", ::g3HistoryEvent::Class_Version(), "include/GRETINA.h", 275,
                  typeid(::g3HistoryEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g3HistoryEvent::Dictionary, isa_proxy, 4,
                  sizeof(::g3HistoryEvent) );
      instance.SetNew(&new_g3HistoryEvent);
      instance.SetNewArray(&newArray_g3HistoryEvent);
      instance.SetDelete(&delete_g3HistoryEvent);
      instance.SetDeleteArray(&deleteArray_g3HistoryEvent);
      instance.SetDestructor(&destruct_g3HistoryEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g3HistoryEvent*)
   {
      return GenerateInitInstanceLocal(static_cast<::g3HistoryEvent*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g3HistoryEvent*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Bank88(void *p = nullptr);
   static void *newArray_Bank88(Long_t size, void *p);
   static void delete_Bank88(void *p);
   static void deleteArray_Bank88(void *p);
   static void destruct_Bank88(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Bank88*)
   {
      ::Bank88 *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Bank88 >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Bank88", ::Bank88::Class_Version(), "include/GRETINA.h", 288,
                  typeid(::Bank88), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Bank88::Dictionary, isa_proxy, 4,
                  sizeof(::Bank88) );
      instance.SetNew(&new_Bank88);
      instance.SetNewArray(&newArray_Bank88);
      instance.SetDelete(&delete_Bank88);
      instance.SetDeleteArray(&deleteArray_Bank88);
      instance.SetDestructor(&destruct_Bank88);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Bank88*)
   {
      return GenerateInitInstanceLocal(static_cast<::Bank88*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Bank88*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *ip_Dictionary();
   static void ip_TClassManip(TClass*);
   static void *new_ip(void *p = nullptr);
   static void *newArray_ip(Long_t size, void *p);
   static void delete_ip(void *p);
   static void deleteArray_ip(void *p);
   static void destruct_ip(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ip*)
   {
      ::ip *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ip));
      static ::ROOT::TGenericClassInfo 
         instance("ip", "include/GRETINA.h", 306,
                  typeid(::ip), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ip_Dictionary, isa_proxy, 4,
                  sizeof(::ip) );
      instance.SetNew(&new_ip);
      instance.SetNewArray(&newArray_ip);
      instance.SetDelete(&delete_ip);
      instance.SetDeleteArray(&deleteArray_ip);
      instance.SetDestructor(&destruct_ip);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ip*)
   {
      return GenerateInitInstanceLocal(static_cast<::ip*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::ip*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ip_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::ip*>(nullptr))->GetClass();
      ip_TClassManip(theClass);
   return theClass;
   }

   static void ip_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ipOLD_Dictionary();
   static void ipOLD_TClassManip(TClass*);
   static void *new_ipOLD(void *p = nullptr);
   static void *newArray_ipOLD(Long_t size, void *p);
   static void delete_ipOLD(void *p);
   static void deleteArray_ipOLD(void *p);
   static void destruct_ipOLD(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ipOLD*)
   {
      ::ipOLD *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ipOLD));
      static ::ROOT::TGenericClassInfo 
         instance("ipOLD", "include/GRETINA.h", 312,
                  typeid(::ipOLD), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ipOLD_Dictionary, isa_proxy, 4,
                  sizeof(::ipOLD) );
      instance.SetNew(&new_ipOLD);
      instance.SetNewArray(&newArray_ipOLD);
      instance.SetDelete(&delete_ipOLD);
      instance.SetDeleteArray(&deleteArray_ipOLD);
      instance.SetDestructor(&destruct_ipOLD);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ipOLD*)
   {
      return GenerateInitInstanceLocal(static_cast<::ipOLD*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::ipOLD*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ipOLD_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::ipOLD*>(nullptr))->GetClass();
      ipOLD_TClassManip(theClass);
   return theClass;
   }

   static void ipOLD_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *mode2Old_Dictionary();
   static void mode2Old_TClassManip(TClass*);
   static void *new_mode2Old(void *p = nullptr);
   static void *newArray_mode2Old(Long_t size, void *p);
   static void delete_mode2Old(void *p);
   static void deleteArray_mode2Old(void *p);
   static void destruct_mode2Old(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::mode2Old*)
   {
      ::mode2Old *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::mode2Old));
      static ::ROOT::TGenericClassInfo 
         instance("mode2Old", "include/GRETINA.h", 316,
                  typeid(::mode2Old), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &mode2Old_Dictionary, isa_proxy, 4,
                  sizeof(::mode2Old) );
      instance.SetNew(&new_mode2Old);
      instance.SetNewArray(&newArray_mode2Old);
      instance.SetDelete(&delete_mode2Old);
      instance.SetDeleteArray(&deleteArray_mode2Old);
      instance.SetDestructor(&destruct_mode2Old);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::mode2Old*)
   {
      return GenerateInitInstanceLocal(static_cast<::mode2Old*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::mode2Old*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *mode2Old_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::mode2Old*>(nullptr))->GetClass();
      mode2Old_TClassManip(theClass);
   return theClass;
   }

   static void mode2Old_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *mode2ABCD1234_Dictionary();
   static void mode2ABCD1234_TClassManip(TClass*);
   static void *new_mode2ABCD1234(void *p = nullptr);
   static void *newArray_mode2ABCD1234(Long_t size, void *p);
   static void delete_mode2ABCD1234(void *p);
   static void deleteArray_mode2ABCD1234(void *p);
   static void destruct_mode2ABCD1234(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::mode2ABCD1234*)
   {
      ::mode2ABCD1234 *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::mode2ABCD1234));
      static ::ROOT::TGenericClassInfo 
         instance("mode2ABCD1234", "include/GRETINA.h", 327,
                  typeid(::mode2ABCD1234), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &mode2ABCD1234_Dictionary, isa_proxy, 4,
                  sizeof(::mode2ABCD1234) );
      instance.SetNew(&new_mode2ABCD1234);
      instance.SetNewArray(&newArray_mode2ABCD1234);
      instance.SetDelete(&delete_mode2ABCD1234);
      instance.SetDeleteArray(&deleteArray_mode2ABCD1234);
      instance.SetDestructor(&destruct_mode2ABCD1234);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::mode2ABCD1234*)
   {
      return GenerateInitInstanceLocal(static_cast<::mode2ABCD1234*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::mode2ABCD1234*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *mode2ABCD1234_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::mode2ABCD1234*>(nullptr))->GetClass();
      mode2ABCD1234_TClassManip(theClass);
   return theClass;
   }

   static void mode2ABCD1234_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *mode2ABCD5678_Dictionary();
   static void mode2ABCD5678_TClassManip(TClass*);
   static void *new_mode2ABCD5678(void *p = nullptr);
   static void *newArray_mode2ABCD5678(Long_t size, void *p);
   static void delete_mode2ABCD5678(void *p);
   static void deleteArray_mode2ABCD5678(void *p);
   static void destruct_mode2ABCD5678(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::mode2ABCD5678*)
   {
      ::mode2ABCD5678 *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::mode2ABCD5678));
      static ::ROOT::TGenericClassInfo 
         instance("mode2ABCD5678", "include/GRETINA.h", 343,
                  typeid(::mode2ABCD5678), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &mode2ABCD5678_Dictionary, isa_proxy, 4,
                  sizeof(::mode2ABCD5678) );
      instance.SetNew(&new_mode2ABCD5678);
      instance.SetNewArray(&newArray_mode2ABCD5678);
      instance.SetDelete(&delete_mode2ABCD5678);
      instance.SetDeleteArray(&deleteArray_mode2ABCD5678);
      instance.SetDestructor(&destruct_mode2ABCD5678);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::mode2ABCD5678*)
   {
      return GenerateInitInstanceLocal(static_cast<::mode2ABCD5678*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::mode2ABCD5678*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *mode2ABCD5678_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::mode2ABCD5678*>(nullptr))->GetClass();
      mode2ABCD5678_TClassManip(theClass);
   return theClass;
   }

   static void mode2ABCD5678_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *mode2ABCD6789_Dictionary();
   static void mode2ABCD6789_TClassManip(TClass*);
   static void *new_mode2ABCD6789(void *p = nullptr);
   static void *newArray_mode2ABCD6789(Long_t size, void *p);
   static void delete_mode2ABCD6789(void *p);
   static void deleteArray_mode2ABCD6789(void *p);
   static void destruct_mode2ABCD6789(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::mode2ABCD6789*)
   {
      ::mode2ABCD6789 *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::mode2ABCD6789));
      static ::ROOT::TGenericClassInfo 
         instance("mode2ABCD6789", "include/GRETINA.h", 362,
                  typeid(::mode2ABCD6789), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &mode2ABCD6789_Dictionary, isa_proxy, 4,
                  sizeof(::mode2ABCD6789) );
      instance.SetNew(&new_mode2ABCD6789);
      instance.SetNewArray(&newArray_mode2ABCD6789);
      instance.SetDelete(&delete_mode2ABCD6789);
      instance.SetDeleteArray(&deleteArray_mode2ABCD6789);
      instance.SetDestructor(&destruct_mode2ABCD6789);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::mode2ABCD6789*)
   {
      return GenerateInitInstanceLocal(static_cast<::mode2ABCD6789*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::mode2ABCD6789*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *mode2ABCD6789_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::mode2ABCD6789*>(nullptr))->GetClass();
      mode2ABCD6789_TClassManip(theClass);
   return theClass;
   }

   static void mode2ABCD6789_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_g2IntPt(void *p = nullptr);
   static void *newArray_g2IntPt(Long_t size, void *p);
   static void delete_g2IntPt(void *p);
   static void deleteArray_g2IntPt(void *p);
   static void destruct_g2IntPt(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g2IntPt*)
   {
      ::g2IntPt *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g2IntPt >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g2IntPt", ::g2IntPt::Class_Version(), "include/GRETINA.h", 394,
                  typeid(::g2IntPt), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g2IntPt::Dictionary, isa_proxy, 4,
                  sizeof(::g2IntPt) );
      instance.SetNew(&new_g2IntPt);
      instance.SetNewArray(&newArray_g2IntPt);
      instance.SetDelete(&delete_g2IntPt);
      instance.SetDeleteArray(&deleteArray_g2IntPt);
      instance.SetDestructor(&destruct_g2IntPt);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g2IntPt*)
   {
      return GenerateInitInstanceLocal(static_cast<::g2IntPt*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g2IntPt*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_g2CrystalEvent(void *p = nullptr);
   static void *newArray_g2CrystalEvent(Long_t size, void *p);
   static void delete_g2CrystalEvent(void *p);
   static void deleteArray_g2CrystalEvent(void *p);
   static void destruct_g2CrystalEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g2CrystalEvent*)
   {
      ::g2CrystalEvent *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g2CrystalEvent >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g2CrystalEvent", ::g2CrystalEvent::Class_Version(), "include/GRETINA.h", 420,
                  typeid(::g2CrystalEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g2CrystalEvent::Dictionary, isa_proxy, 4,
                  sizeof(::g2CrystalEvent) );
      instance.SetNew(&new_g2CrystalEvent);
      instance.SetNewArray(&newArray_g2CrystalEvent);
      instance.SetDelete(&delete_g2CrystalEvent);
      instance.SetDeleteArray(&deleteArray_g2CrystalEvent);
      instance.SetDestructor(&destruct_g2CrystalEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g2CrystalEvent*)
   {
      return GenerateInitInstanceLocal(static_cast<::g2CrystalEvent*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g2CrystalEvent*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_g2OUT(void *p = nullptr);
   static void *newArray_g2OUT(Long_t size, void *p);
   static void delete_g2OUT(void *p);
   static void deleteArray_g2OUT(void *p);
   static void destruct_g2OUT(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g2OUT*)
   {
      ::g2OUT *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g2OUT >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g2OUT", ::g2OUT::Class_Version(), "include/GRETINA.h", 479,
                  typeid(::g2OUT), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g2OUT::Dictionary, isa_proxy, 4,
                  sizeof(::g2OUT) );
      instance.SetNew(&new_g2OUT);
      instance.SetNewArray(&newArray_g2OUT);
      instance.SetDelete(&delete_g2OUT);
      instance.SetDeleteArray(&deleteArray_g2OUT);
      instance.SetDestructor(&destruct_g2OUT);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g2OUT*)
   {
      return GenerateInitInstanceLocal(static_cast<::g2OUT*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g2OUT*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *trackedGamma_Dictionary();
   static void trackedGamma_TClassManip(TClass*);
   static void *new_trackedGamma(void *p = nullptr);
   static void *newArray_trackedGamma(Long_t size, void *p);
   static void delete_trackedGamma(void *p);
   static void deleteArray_trackedGamma(void *p);
   static void destruct_trackedGamma(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::trackedGamma*)
   {
      ::trackedGamma *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::trackedGamma));
      static ::ROOT::TGenericClassInfo 
         instance("trackedGamma", "include/GRETINA.h", 501,
                  typeid(::trackedGamma), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &trackedGamma_Dictionary, isa_proxy, 4,
                  sizeof(::trackedGamma) );
      instance.SetNew(&new_trackedGamma);
      instance.SetNewArray(&newArray_trackedGamma);
      instance.SetDelete(&delete_trackedGamma);
      instance.SetDeleteArray(&deleteArray_trackedGamma);
      instance.SetDestructor(&destruct_trackedGamma);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::trackedGamma*)
   {
      return GenerateInitInstanceLocal(static_cast<::trackedGamma*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::trackedGamma*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *trackedGamma_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::trackedGamma*>(nullptr))->GetClass();
      trackedGamma_TClassManip(theClass);
   return theClass;
   }

   static void trackedGamma_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_GTrackEvent(void *p = nullptr);
   static void *newArray_GTrackEvent(Long_t size, void *p);
   static void delete_GTrackEvent(void *p);
   static void deleteArray_GTrackEvent(void *p);
   static void destruct_GTrackEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::GTrackEvent*)
   {
      ::GTrackEvent *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::GTrackEvent >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("GTrackEvent", ::GTrackEvent::Class_Version(), "include/GRETINA.h", 512,
                  typeid(::GTrackEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::GTrackEvent::Dictionary, isa_proxy, 4,
                  sizeof(::GTrackEvent) );
      instance.SetNew(&new_GTrackEvent);
      instance.SetNewArray(&newArray_GTrackEvent);
      instance.SetDelete(&delete_GTrackEvent);
      instance.SetDeleteArray(&deleteArray_GTrackEvent);
      instance.SetDestructor(&destruct_GTrackEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::GTrackEvent*)
   {
      return GenerateInitInstanceLocal(static_cast<::GTrackEvent*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::GTrackEvent*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_g1GammaEvent(void *p = nullptr);
   static void *newArray_g1GammaEvent(Long_t size, void *p);
   static void delete_g1GammaEvent(void *p);
   static void deleteArray_g1GammaEvent(void *p);
   static void destruct_g1GammaEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g1GammaEvent*)
   {
      ::g1GammaEvent *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g1GammaEvent >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g1GammaEvent", ::g1GammaEvent::Class_Version(), "include/GRETINA.h", 524,
                  typeid(::g1GammaEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g1GammaEvent::Dictionary, isa_proxy, 4,
                  sizeof(::g1GammaEvent) );
      instance.SetNew(&new_g1GammaEvent);
      instance.SetNewArray(&newArray_g1GammaEvent);
      instance.SetDelete(&delete_g1GammaEvent);
      instance.SetDeleteArray(&deleteArray_g1GammaEvent);
      instance.SetDestructor(&destruct_g1GammaEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g1GammaEvent*)
   {
      return GenerateInitInstanceLocal(static_cast<::g1GammaEvent*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g1GammaEvent*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_g1OUT(void *p = nullptr);
   static void *newArray_g1OUT(Long_t size, void *p);
   static void delete_g1OUT(void *p);
   static void deleteArray_g1OUT(void *p);
   static void destruct_g1OUT(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g1OUT*)
   {
      ::g1OUT *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g1OUT >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g1OUT", ::g1OUT::Class_Version(), "include/GRETINA.h", 552,
                  typeid(::g1OUT), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g1OUT::Dictionary, isa_proxy, 4,
                  sizeof(::g1OUT) );
      instance.SetNew(&new_g1OUT);
      instance.SetNewArray(&newArray_g1OUT);
      instance.SetDelete(&delete_g1OUT);
      instance.SetDeleteArray(&deleteArray_g1OUT);
      instance.SetDestructor(&destruct_g1OUT);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g1OUT*)
   {
      return GenerateInitInstanceLocal(static_cast<::g1OUT*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g1OUT*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *g4Sim_emittedGamma_Dictionary();
   static void g4Sim_emittedGamma_TClassManip(TClass*);
   static void *new_g4Sim_emittedGamma(void *p = nullptr);
   static void *newArray_g4Sim_emittedGamma(Long_t size, void *p);
   static void delete_g4Sim_emittedGamma(void *p);
   static void deleteArray_g4Sim_emittedGamma(void *p);
   static void destruct_g4Sim_emittedGamma(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g4Sim_emittedGamma*)
   {
      ::g4Sim_emittedGamma *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::g4Sim_emittedGamma));
      static ::ROOT::TGenericClassInfo 
         instance("g4Sim_emittedGamma", "include/GRETINA.h", 570,
                  typeid(::g4Sim_emittedGamma), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &g4Sim_emittedGamma_Dictionary, isa_proxy, 4,
                  sizeof(::g4Sim_emittedGamma) );
      instance.SetNew(&new_g4Sim_emittedGamma);
      instance.SetNewArray(&newArray_g4Sim_emittedGamma);
      instance.SetDelete(&delete_g4Sim_emittedGamma);
      instance.SetDeleteArray(&deleteArray_g4Sim_emittedGamma);
      instance.SetDestructor(&destruct_g4Sim_emittedGamma);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g4Sim_emittedGamma*)
   {
      return GenerateInitInstanceLocal(static_cast<::g4Sim_emittedGamma*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g4Sim_emittedGamma*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *g4Sim_emittedGamma_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::g4Sim_emittedGamma*>(nullptr))->GetClass();
      g4Sim_emittedGamma_TClassManip(theClass);
   return theClass;
   }

   static void g4Sim_emittedGamma_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *g4Sim_abcd1234_Dictionary();
   static void g4Sim_abcd1234_TClassManip(TClass*);
   static void *new_g4Sim_abcd1234(void *p = nullptr);
   static void *newArray_g4Sim_abcd1234(Long_t size, void *p);
   static void delete_g4Sim_abcd1234(void *p);
   static void deleteArray_g4Sim_abcd1234(void *p);
   static void destruct_g4Sim_abcd1234(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g4Sim_abcd1234*)
   {
      ::g4Sim_abcd1234 *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::g4Sim_abcd1234));
      static ::ROOT::TGenericClassInfo 
         instance("g4Sim_abcd1234", "include/GRETINA.h", 577,
                  typeid(::g4Sim_abcd1234), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &g4Sim_abcd1234_Dictionary, isa_proxy, 4,
                  sizeof(::g4Sim_abcd1234) );
      instance.SetNew(&new_g4Sim_abcd1234);
      instance.SetNewArray(&newArray_g4Sim_abcd1234);
      instance.SetDelete(&delete_g4Sim_abcd1234);
      instance.SetDeleteArray(&deleteArray_g4Sim_abcd1234);
      instance.SetDestructor(&destruct_g4Sim_abcd1234);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g4Sim_abcd1234*)
   {
      return GenerateInitInstanceLocal(static_cast<::g4Sim_abcd1234*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g4Sim_abcd1234*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *g4Sim_abcd1234_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::g4Sim_abcd1234*>(nullptr))->GetClass();
      g4Sim_abcd1234_TClassManip(theClass);
   return theClass;
   }

   static void g4Sim_abcd1234_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_g4SimOUT(void *p = nullptr);
   static void *newArray_g4SimOUT(Long_t size, void *p);
   static void delete_g4SimOUT(void *p);
   static void deleteArray_g4SimOUT(void *p);
   static void destruct_g4SimOUT(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::g4SimOUT*)
   {
      ::g4SimOUT *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::g4SimOUT >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("g4SimOUT", ::g4SimOUT::Class_Version(), "include/GRETINA.h", 584,
                  typeid(::g4SimOUT), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::g4SimOUT::Dictionary, isa_proxy, 4,
                  sizeof(::g4SimOUT) );
      instance.SetNew(&new_g4SimOUT);
      instance.SetNewArray(&newArray_g4SimOUT);
      instance.SetDelete(&delete_g4SimOUT);
      instance.SetDeleteArray(&deleteArray_g4SimOUT);
      instance.SetDestructor(&destruct_g4SimOUT);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::g4SimOUT*)
   {
      return GenerateInitInstanceLocal(static_cast<::g4SimOUT*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::g4SimOUT*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_gHistos(void *p = nullptr);
   static void *newArray_gHistos(Long_t size, void *p);
   static void delete_gHistos(void *p);
   static void deleteArray_gHistos(void *p);
   static void destruct_gHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::gHistos*)
   {
      ::gHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::gHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("gHistos", ::gHistos::Class_Version(), "include/GRETINA.h", 608,
                  typeid(::gHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::gHistos::Dictionary, isa_proxy, 4,
                  sizeof(::gHistos) );
      instance.SetNew(&new_gHistos);
      instance.SetNewArray(&newArray_gHistos);
      instance.SetDelete(&delete_gHistos);
      instance.SetDeleteArray(&deleteArray_gHistos);
      instance.SetDestructor(&destruct_gHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::gHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::gHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::gHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_SuperPulse(void *p = nullptr);
   static void *newArray_SuperPulse(Long_t size, void *p);
   static void delete_SuperPulse(void *p);
   static void deleteArray_SuperPulse(void *p);
   static void destruct_SuperPulse(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SuperPulse*)
   {
      ::SuperPulse *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SuperPulse >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("SuperPulse", ::SuperPulse::Class_Version(), "include/GRETINA.h", 634,
                  typeid(::SuperPulse), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SuperPulse::Dictionary, isa_proxy, 4,
                  sizeof(::SuperPulse) );
      instance.SetNew(&new_SuperPulse);
      instance.SetNewArray(&newArray_SuperPulse);
      instance.SetDelete(&delete_SuperPulse);
      instance.SetDeleteArray(&deleteArray_SuperPulse);
      instance.SetDestructor(&destruct_SuperPulse);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SuperPulse*)
   {
      return GenerateInitInstanceLocal(static_cast<::SuperPulse*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::SuperPulse*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_GRETINA(void *p = nullptr);
   static void *newArray_GRETINA(Long_t size, void *p);
   static void delete_GRETINA(void *p);
   static void deleteArray_GRETINA(void *p);
   static void destruct_GRETINA(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::GRETINA*)
   {
      ::GRETINA *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::GRETINA >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("GRETINA", ::GRETINA::Class_Version(), "include/GRETINA.h", 766,
                  typeid(::GRETINA), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::GRETINA::Dictionary, isa_proxy, 4,
                  sizeof(::GRETINA) );
      instance.SetNew(&new_GRETINA);
      instance.SetNewArray(&newArray_GRETINA);
      instance.SetDelete(&delete_GRETINA);
      instance.SetDeleteArray(&deleteArray_GRETINA);
      instance.SetDestructor(&destruct_GRETINA);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::GRETINA*)
   {
      return GenerateInitInstanceLocal(static_cast<::GRETINA*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::GRETINA*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_INLCorrection(void *p = nullptr);
   static void *newArray_INLCorrection(Long_t size, void *p);
   static void delete_INLCorrection(void *p);
   static void deleteArray_INLCorrection(void *p);
   static void destruct_INLCorrection(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::INLCorrection*)
   {
      ::INLCorrection *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::INLCorrection >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("INLCorrection", ::INLCorrection::Class_Version(), "include/INLCorrection.h", 38,
                  typeid(::INLCorrection), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::INLCorrection::Dictionary, isa_proxy, 4,
                  sizeof(::INLCorrection) );
      instance.SetNew(&new_INLCorrection);
      instance.SetNewArray(&newArray_INLCorrection);
      instance.SetDelete(&delete_INLCorrection);
      instance.SetDeleteArray(&deleteArray_INLCorrection);
      instance.SetDestructor(&destruct_INLCorrection);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::INLCorrection*)
   {
      return GenerateInitInstanceLocal(static_cast<::INLCorrection*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::INLCorrection*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Histos(void *p = nullptr);
   static void *newArray_Histos(Long_t size, void *p);
   static void delete_Histos(void *p);
   static void deleteArray_Histos(void *p);
   static void destruct_Histos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Histos*)
   {
      ::Histos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Histos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Histos", ::Histos::Class_Version(), "include/Histos.h", 13,
                  typeid(::Histos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Histos::Dictionary, isa_proxy, 4,
                  sizeof(::Histos) );
      instance.SetNew(&new_Histos);
      instance.SetNewArray(&newArray_Histos);
      instance.SetDelete(&delete_Histos);
      instance.SetDeleteArray(&deleteArray_Histos);
      instance.SetDestructor(&destruct_Histos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Histos*)
   {
      return GenerateInitInstanceLocal(static_cast<::Histos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Histos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr controlVariables::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *controlVariables::Class_Name()
{
   return "controlVariables";
}

//______________________________________________________________________________
const char *controlVariables::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::controlVariables*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int controlVariables::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::controlVariables*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *controlVariables::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::controlVariables*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *controlVariables::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::controlVariables*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr counterVariables::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *counterVariables::Class_Name()
{
   return "counterVariables";
}

//______________________________________________________________________________
const char *counterVariables::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::counterVariables*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int counterVariables::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::counterVariables*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *counterVariables::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::counterVariables*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *counterVariables::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::counterVariables*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TrackClusterIP::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TrackClusterIP::Class_Name()
{
   return "TrackClusterIP";
}

//______________________________________________________________________________
const char *TrackClusterIP::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackClusterIP*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TrackClusterIP::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackClusterIP*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TrackClusterIP::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackClusterIP*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TrackClusterIP::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackClusterIP*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TrackCluster::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TrackCluster::Class_Name()
{
   return "TrackCluster";
}

//______________________________________________________________________________
const char *TrackCluster::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackCluster*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TrackCluster::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackCluster*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TrackCluster::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackCluster*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TrackCluster::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackCluster*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TrackShell::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TrackShell::Class_Name()
{
   return "TrackShell";
}

//______________________________________________________________________________
const char *TrackShell::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackShell*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TrackShell::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackShell*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TrackShell::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackShell*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TrackShell::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackShell*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TrackCtrl::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TrackCtrl::Class_Name()
{
   return "TrackCtrl";
}

//______________________________________________________________________________
const char *TrackCtrl::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackCtrl*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TrackCtrl::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackCtrl*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TrackCtrl::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackCtrl*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TrackCtrl::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackCtrl*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TrackStat::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TrackStat::Class_Name()
{
   return "TrackStat";
}

//______________________________________________________________________________
const char *TrackStat::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackStat*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TrackStat::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackStat*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TrackStat::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackStat*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TrackStat::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackStat*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TrackPerm::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TrackPerm::Class_Name()
{
   return "TrackPerm";
}

//______________________________________________________________________________
const char *TrackPerm::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackPerm*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TrackPerm::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackPerm*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TrackPerm::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackPerm*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TrackPerm::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackPerm*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Track::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Track::Class_Name()
{
   return "Track";
}

//______________________________________________________________________________
const char *Track::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Track*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Track::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Track*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Track::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Track*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Track::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Track*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rotationMatrix::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *rotationMatrix::Class_Name()
{
   return "rotationMatrix";
}

//______________________________________________________________________________
const char *rotationMatrix::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rotationMatrix*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int rotationMatrix::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rotationMatrix*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rotationMatrix::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rotationMatrix*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rotationMatrix::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rotationMatrix*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr GRETINAVariables::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *GRETINAVariables::Class_Name()
{
   return "GRETINAVariables";
}

//______________________________________________________________________________
const char *GRETINAVariables::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::GRETINAVariables*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int GRETINAVariables::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::GRETINAVariables*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GRETINAVariables::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::GRETINAVariables*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GRETINAVariables::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::GRETINAVariables*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g3Waveform::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g3Waveform::Class_Name()
{
   return "g3Waveform";
}

//______________________________________________________________________________
const char *g3Waveform::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g3Waveform*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g3Waveform::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g3Waveform*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g3Waveform::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g3Waveform*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g3Waveform::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g3Waveform*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g3ChannelEvent::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g3ChannelEvent::Class_Name()
{
   return "g3ChannelEvent";
}

//______________________________________________________________________________
const char *g3ChannelEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g3ChannelEvent*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g3ChannelEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g3ChannelEvent*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g3ChannelEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g3ChannelEvent*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g3ChannelEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g3ChannelEvent*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g3CrystalEvent::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g3CrystalEvent::Class_Name()
{
   return "g3CrystalEvent";
}

//______________________________________________________________________________
const char *g3CrystalEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g3CrystalEvent*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g3CrystalEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g3CrystalEvent*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g3CrystalEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g3CrystalEvent*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g3CrystalEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g3CrystalEvent*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g3OUT::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g3OUT::Class_Name()
{
   return "g3OUT";
}

//______________________________________________________________________________
const char *g3OUT::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g3OUT*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g3OUT::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g3OUT*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g3OUT::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g3OUT*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g3OUT::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g3OUT*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g3HistoryEvent::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g3HistoryEvent::Class_Name()
{
   return "g3HistoryEvent";
}

//______________________________________________________________________________
const char *g3HistoryEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g3HistoryEvent*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g3HistoryEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g3HistoryEvent*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g3HistoryEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g3HistoryEvent*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g3HistoryEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g3HistoryEvent*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Bank88::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Bank88::Class_Name()
{
   return "Bank88";
}

//______________________________________________________________________________
const char *Bank88::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Bank88*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Bank88::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Bank88*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Bank88::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Bank88*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Bank88::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Bank88*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g2IntPt::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g2IntPt::Class_Name()
{
   return "g2IntPt";
}

//______________________________________________________________________________
const char *g2IntPt::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g2IntPt*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g2IntPt::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g2IntPt*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g2IntPt::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g2IntPt*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g2IntPt::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g2IntPt*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g2CrystalEvent::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g2CrystalEvent::Class_Name()
{
   return "g2CrystalEvent";
}

//______________________________________________________________________________
const char *g2CrystalEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g2CrystalEvent*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g2CrystalEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g2CrystalEvent*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g2CrystalEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g2CrystalEvent*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g2CrystalEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g2CrystalEvent*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g2OUT::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g2OUT::Class_Name()
{
   return "g2OUT";
}

//______________________________________________________________________________
const char *g2OUT::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g2OUT*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g2OUT::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g2OUT*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g2OUT::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g2OUT*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g2OUT::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g2OUT*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr GTrackEvent::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *GTrackEvent::Class_Name()
{
   return "GTrackEvent";
}

//______________________________________________________________________________
const char *GTrackEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::GTrackEvent*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int GTrackEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::GTrackEvent*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GTrackEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::GTrackEvent*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GTrackEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::GTrackEvent*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g1GammaEvent::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g1GammaEvent::Class_Name()
{
   return "g1GammaEvent";
}

//______________________________________________________________________________
const char *g1GammaEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g1GammaEvent*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g1GammaEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g1GammaEvent*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g1GammaEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g1GammaEvent*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g1GammaEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g1GammaEvent*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g1OUT::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g1OUT::Class_Name()
{
   return "g1OUT";
}

//______________________________________________________________________________
const char *g1OUT::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g1OUT*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g1OUT::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g1OUT*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g1OUT::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g1OUT*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g1OUT::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g1OUT*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr g4SimOUT::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *g4SimOUT::Class_Name()
{
   return "g4SimOUT";
}

//______________________________________________________________________________
const char *g4SimOUT::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g4SimOUT*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int g4SimOUT::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::g4SimOUT*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *g4SimOUT::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g4SimOUT*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *g4SimOUT::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::g4SimOUT*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr gHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *gHistos::Class_Name()
{
   return "gHistos";
}

//______________________________________________________________________________
const char *gHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::gHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int gHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::gHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *gHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::gHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *gHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::gHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr SuperPulse::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *SuperPulse::Class_Name()
{
   return "SuperPulse";
}

//______________________________________________________________________________
const char *SuperPulse::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SuperPulse*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int SuperPulse::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SuperPulse*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SuperPulse::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SuperPulse*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SuperPulse::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SuperPulse*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr GRETINA::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *GRETINA::Class_Name()
{
   return "GRETINA";
}

//______________________________________________________________________________
const char *GRETINA::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::GRETINA*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int GRETINA::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::GRETINA*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GRETINA::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::GRETINA*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GRETINA::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::GRETINA*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr INLCorrection::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *INLCorrection::Class_Name()
{
   return "INLCorrection";
}

//______________________________________________________________________________
const char *INLCorrection::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::INLCorrection*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int INLCorrection::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::INLCorrection*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *INLCorrection::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::INLCorrection*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *INLCorrection::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::INLCorrection*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Histos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Histos::Class_Name()
{
   return "Histos";
}

//______________________________________________________________________________
const char *Histos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Histos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Histos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Histos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Histos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Histos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Histos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Histos*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void controlVariables::Streamer(TBuffer &R__b)
{
   // Stream an object of class controlVariables.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(controlVariables::Class(),this);
   } else {
      R__b.WriteClassBuffer(controlVariables::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_controlVariables(void *p) {
      return  p ? new(p) ::controlVariables : new ::controlVariables;
   }
   static void *newArray_controlVariables(Long_t nElements, void *p) {
      return p ? new(p) ::controlVariables[nElements] : new ::controlVariables[nElements];
   }
   // Wrapper around operator delete
   static void delete_controlVariables(void *p) {
      delete (static_cast<::controlVariables*>(p));
   }
   static void deleteArray_controlVariables(void *p) {
      delete [] (static_cast<::controlVariables*>(p));
   }
   static void destruct_controlVariables(void *p) {
      typedef ::controlVariables current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::controlVariables

//______________________________________________________________________________
void counterVariables::Streamer(TBuffer &R__b)
{
   // Stream an object of class counterVariables.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(counterVariables::Class(),this);
   } else {
      R__b.WriteClassBuffer(counterVariables::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_counterVariables(void *p) {
      return  p ? new(p) ::counterVariables : new ::counterVariables;
   }
   static void *newArray_counterVariables(Long_t nElements, void *p) {
      return p ? new(p) ::counterVariables[nElements] : new ::counterVariables[nElements];
   }
   // Wrapper around operator delete
   static void delete_counterVariables(void *p) {
      delete (static_cast<::counterVariables*>(p));
   }
   static void deleteArray_counterVariables(void *p) {
      delete [] (static_cast<::counterVariables*>(p));
   }
   static void destruct_counterVariables(void *p) {
      typedef ::counterVariables current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::counterVariables

namespace ROOT {
   // Wrappers around operator new
   static void *new_PM(void *p) {
      return  p ? new(p) ::PM : new ::PM;
   }
   static void *newArray_PM(Long_t nElements, void *p) {
      return p ? new(p) ::PM[nElements] : new ::PM[nElements];
   }
   // Wrapper around operator delete
   static void delete_PM(void *p) {
      delete (static_cast<::PM*>(p));
   }
   static void deleteArray_PM(void *p) {
      delete [] (static_cast<::PM*>(p));
   }
   static void destruct_PM(void *p) {
      typedef ::PM current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::PM

//______________________________________________________________________________
void TrackClusterIP::Streamer(TBuffer &R__b)
{
   // Stream an object of class TrackClusterIP.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TrackClusterIP::Class(),this);
   } else {
      R__b.WriteClassBuffer(TrackClusterIP::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrackClusterIP(void *p) {
      return  p ? new(p) ::TrackClusterIP : new ::TrackClusterIP;
   }
   static void *newArray_TrackClusterIP(Long_t nElements, void *p) {
      return p ? new(p) ::TrackClusterIP[nElements] : new ::TrackClusterIP[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrackClusterIP(void *p) {
      delete (static_cast<::TrackClusterIP*>(p));
   }
   static void deleteArray_TrackClusterIP(void *p) {
      delete [] (static_cast<::TrackClusterIP*>(p));
   }
   static void destruct_TrackClusterIP(void *p) {
      typedef ::TrackClusterIP current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TrackClusterIP

//______________________________________________________________________________
void TrackCluster::Streamer(TBuffer &R__b)
{
   // Stream an object of class TrackCluster.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TrackCluster::Class(),this);
   } else {
      R__b.WriteClassBuffer(TrackCluster::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrackCluster(void *p) {
      return  p ? new(p) ::TrackCluster : new ::TrackCluster;
   }
   static void *newArray_TrackCluster(Long_t nElements, void *p) {
      return p ? new(p) ::TrackCluster[nElements] : new ::TrackCluster[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrackCluster(void *p) {
      delete (static_cast<::TrackCluster*>(p));
   }
   static void deleteArray_TrackCluster(void *p) {
      delete [] (static_cast<::TrackCluster*>(p));
   }
   static void destruct_TrackCluster(void *p) {
      typedef ::TrackCluster current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TrackCluster

//______________________________________________________________________________
void TrackShell::Streamer(TBuffer &R__b)
{
   // Stream an object of class TrackShell.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TrackShell::Class(),this);
   } else {
      R__b.WriteClassBuffer(TrackShell::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrackShell(void *p) {
      return  p ? new(p) ::TrackShell : new ::TrackShell;
   }
   static void *newArray_TrackShell(Long_t nElements, void *p) {
      return p ? new(p) ::TrackShell[nElements] : new ::TrackShell[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrackShell(void *p) {
      delete (static_cast<::TrackShell*>(p));
   }
   static void deleteArray_TrackShell(void *p) {
      delete [] (static_cast<::TrackShell*>(p));
   }
   static void destruct_TrackShell(void *p) {
      typedef ::TrackShell current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TrackShell

//______________________________________________________________________________
void TrackCtrl::Streamer(TBuffer &R__b)
{
   // Stream an object of class TrackCtrl.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TrackCtrl::Class(),this);
   } else {
      R__b.WriteClassBuffer(TrackCtrl::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrackCtrl(void *p) {
      return  p ? new(p) ::TrackCtrl : new ::TrackCtrl;
   }
   static void *newArray_TrackCtrl(Long_t nElements, void *p) {
      return p ? new(p) ::TrackCtrl[nElements] : new ::TrackCtrl[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrackCtrl(void *p) {
      delete (static_cast<::TrackCtrl*>(p));
   }
   static void deleteArray_TrackCtrl(void *p) {
      delete [] (static_cast<::TrackCtrl*>(p));
   }
   static void destruct_TrackCtrl(void *p) {
      typedef ::TrackCtrl current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TrackCtrl

//______________________________________________________________________________
void TrackStat::Streamer(TBuffer &R__b)
{
   // Stream an object of class TrackStat.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TrackStat::Class(),this);
   } else {
      R__b.WriteClassBuffer(TrackStat::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrackStat(void *p) {
      return  p ? new(p) ::TrackStat : new ::TrackStat;
   }
   static void *newArray_TrackStat(Long_t nElements, void *p) {
      return p ? new(p) ::TrackStat[nElements] : new ::TrackStat[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrackStat(void *p) {
      delete (static_cast<::TrackStat*>(p));
   }
   static void deleteArray_TrackStat(void *p) {
      delete [] (static_cast<::TrackStat*>(p));
   }
   static void destruct_TrackStat(void *p) {
      typedef ::TrackStat current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TrackStat

//______________________________________________________________________________
void TrackPerm::Streamer(TBuffer &R__b)
{
   // Stream an object of class TrackPerm.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TrackPerm::Class(),this);
   } else {
      R__b.WriteClassBuffer(TrackPerm::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrackPerm(void *p) {
      return  p ? new(p) ::TrackPerm : new ::TrackPerm;
   }
   static void *newArray_TrackPerm(Long_t nElements, void *p) {
      return p ? new(p) ::TrackPerm[nElements] : new ::TrackPerm[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrackPerm(void *p) {
      delete (static_cast<::TrackPerm*>(p));
   }
   static void deleteArray_TrackPerm(void *p) {
      delete [] (static_cast<::TrackPerm*>(p));
   }
   static void destruct_TrackPerm(void *p) {
      typedef ::TrackPerm current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TrackPerm

//______________________________________________________________________________
void Track::Streamer(TBuffer &R__b)
{
   // Stream an object of class Track.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Track::Class(),this);
   } else {
      R__b.WriteClassBuffer(Track::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Track(void *p) {
      return  p ? new(p) ::Track : new ::Track;
   }
   static void *newArray_Track(Long_t nElements, void *p) {
      return p ? new(p) ::Track[nElements] : new ::Track[nElements];
   }
   // Wrapper around operator delete
   static void delete_Track(void *p) {
      delete (static_cast<::Track*>(p));
   }
   static void deleteArray_Track(void *p) {
      delete [] (static_cast<::Track*>(p));
   }
   static void destruct_Track(void *p) {
      typedef ::Track current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Track

//______________________________________________________________________________
void rotationMatrix::Streamer(TBuffer &R__b)
{
   // Stream an object of class rotationMatrix.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rotationMatrix::Class(),this);
   } else {
      R__b.WriteClassBuffer(rotationMatrix::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rotationMatrix(void *p) {
      return  p ? new(p) ::rotationMatrix : new ::rotationMatrix;
   }
   static void *newArray_rotationMatrix(Long_t nElements, void *p) {
      return p ? new(p) ::rotationMatrix[nElements] : new ::rotationMatrix[nElements];
   }
   // Wrapper around operator delete
   static void delete_rotationMatrix(void *p) {
      delete (static_cast<::rotationMatrix*>(p));
   }
   static void deleteArray_rotationMatrix(void *p) {
      delete [] (static_cast<::rotationMatrix*>(p));
   }
   static void destruct_rotationMatrix(void *p) {
      typedef ::rotationMatrix current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::rotationMatrix

//______________________________________________________________________________
void GRETINAVariables::Streamer(TBuffer &R__b)
{
   // Stream an object of class GRETINAVariables.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(GRETINAVariables::Class(),this);
   } else {
      R__b.WriteClassBuffer(GRETINAVariables::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_GRETINAVariables(void *p) {
      return  p ? new(p) ::GRETINAVariables : new ::GRETINAVariables;
   }
   static void *newArray_GRETINAVariables(Long_t nElements, void *p) {
      return p ? new(p) ::GRETINAVariables[nElements] : new ::GRETINAVariables[nElements];
   }
   // Wrapper around operator delete
   static void delete_GRETINAVariables(void *p) {
      delete (static_cast<::GRETINAVariables*>(p));
   }
   static void deleteArray_GRETINAVariables(void *p) {
      delete [] (static_cast<::GRETINAVariables*>(p));
   }
   static void destruct_GRETINAVariables(void *p) {
      typedef ::GRETINAVariables current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::GRETINAVariables

namespace ROOT {
   // Wrappers around operator new
   static void *new_globalHeader(void *p) {
      return  p ? new(p) ::globalHeader : new ::globalHeader;
   }
   static void *newArray_globalHeader(Long_t nElements, void *p) {
      return p ? new(p) ::globalHeader[nElements] : new ::globalHeader[nElements];
   }
   // Wrapper around operator delete
   static void delete_globalHeader(void *p) {
      delete (static_cast<::globalHeader*>(p));
   }
   static void deleteArray_globalHeader(void *p) {
      delete [] (static_cast<::globalHeader*>(p));
   }
   static void destruct_globalHeader(void *p) {
      typedef ::globalHeader current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::globalHeader

namespace ROOT {
   // Wrappers around operator new
   static void *new_mode3DataPacket(void *p) {
      return  p ? new(p) ::mode3DataPacket : new ::mode3DataPacket;
   }
   static void *newArray_mode3DataPacket(Long_t nElements, void *p) {
      return p ? new(p) ::mode3DataPacket[nElements] : new ::mode3DataPacket[nElements];
   }
   // Wrapper around operator delete
   static void delete_mode3DataPacket(void *p) {
      delete (static_cast<::mode3DataPacket*>(p));
   }
   static void deleteArray_mode3DataPacket(void *p) {
      delete [] (static_cast<::mode3DataPacket*>(p));
   }
   static void destruct_mode3DataPacket(void *p) {
      typedef ::mode3DataPacket current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::mode3DataPacket

//______________________________________________________________________________
void g3Waveform::Streamer(TBuffer &R__b)
{
   // Stream an object of class g3Waveform.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g3Waveform::Class(),this);
   } else {
      R__b.WriteClassBuffer(g3Waveform::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g3Waveform(void *p) {
      return  p ? new(p) ::g3Waveform : new ::g3Waveform;
   }
   static void *newArray_g3Waveform(Long_t nElements, void *p) {
      return p ? new(p) ::g3Waveform[nElements] : new ::g3Waveform[nElements];
   }
   // Wrapper around operator delete
   static void delete_g3Waveform(void *p) {
      delete (static_cast<::g3Waveform*>(p));
   }
   static void deleteArray_g3Waveform(void *p) {
      delete [] (static_cast<::g3Waveform*>(p));
   }
   static void destruct_g3Waveform(void *p) {
      typedef ::g3Waveform current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g3Waveform

//______________________________________________________________________________
void g3ChannelEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class g3ChannelEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g3ChannelEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(g3ChannelEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g3ChannelEvent(void *p) {
      return  p ? new(p) ::g3ChannelEvent : new ::g3ChannelEvent;
   }
   static void *newArray_g3ChannelEvent(Long_t nElements, void *p) {
      return p ? new(p) ::g3ChannelEvent[nElements] : new ::g3ChannelEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_g3ChannelEvent(void *p) {
      delete (static_cast<::g3ChannelEvent*>(p));
   }
   static void deleteArray_g3ChannelEvent(void *p) {
      delete [] (static_cast<::g3ChannelEvent*>(p));
   }
   static void destruct_g3ChannelEvent(void *p) {
      typedef ::g3ChannelEvent current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g3ChannelEvent

//______________________________________________________________________________
void g3CrystalEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class g3CrystalEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g3CrystalEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(g3CrystalEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g3CrystalEvent(void *p) {
      return  p ? new(p) ::g3CrystalEvent : new ::g3CrystalEvent;
   }
   static void *newArray_g3CrystalEvent(Long_t nElements, void *p) {
      return p ? new(p) ::g3CrystalEvent[nElements] : new ::g3CrystalEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_g3CrystalEvent(void *p) {
      delete (static_cast<::g3CrystalEvent*>(p));
   }
   static void deleteArray_g3CrystalEvent(void *p) {
      delete [] (static_cast<::g3CrystalEvent*>(p));
   }
   static void destruct_g3CrystalEvent(void *p) {
      typedef ::g3CrystalEvent current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g3CrystalEvent

//______________________________________________________________________________
void g3OUT::Streamer(TBuffer &R__b)
{
   // Stream an object of class g3OUT.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g3OUT::Class(),this);
   } else {
      R__b.WriteClassBuffer(g3OUT::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g3OUT(void *p) {
      return  p ? new(p) ::g3OUT : new ::g3OUT;
   }
   static void *newArray_g3OUT(Long_t nElements, void *p) {
      return p ? new(p) ::g3OUT[nElements] : new ::g3OUT[nElements];
   }
   // Wrapper around operator delete
   static void delete_g3OUT(void *p) {
      delete (static_cast<::g3OUT*>(p));
   }
   static void deleteArray_g3OUT(void *p) {
      delete [] (static_cast<::g3OUT*>(p));
   }
   static void destruct_g3OUT(void *p) {
      typedef ::g3OUT current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g3OUT

namespace ROOT {
   // Wrappers around operator new
   static void *new_mode3HistoryPacket(void *p) {
      return  p ? new(p) ::mode3HistoryPacket : new ::mode3HistoryPacket;
   }
   static void *newArray_mode3HistoryPacket(Long_t nElements, void *p) {
      return p ? new(p) ::mode3HistoryPacket[nElements] : new ::mode3HistoryPacket[nElements];
   }
   // Wrapper around operator delete
   static void delete_mode3HistoryPacket(void *p) {
      delete (static_cast<::mode3HistoryPacket*>(p));
   }
   static void deleteArray_mode3HistoryPacket(void *p) {
      delete [] (static_cast<::mode3HistoryPacket*>(p));
   }
   static void destruct_mode3HistoryPacket(void *p) {
      typedef ::mode3HistoryPacket current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::mode3HistoryPacket

namespace ROOT {
   // Wrappers around operator new
   static void *new_historyEvent(void *p) {
      return  p ? new(p) ::historyEvent : new ::historyEvent;
   }
   static void *newArray_historyEvent(Long_t nElements, void *p) {
      return p ? new(p) ::historyEvent[nElements] : new ::historyEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_historyEvent(void *p) {
      delete (static_cast<::historyEvent*>(p));
   }
   static void deleteArray_historyEvent(void *p) {
      delete [] (static_cast<::historyEvent*>(p));
   }
   static void destruct_historyEvent(void *p) {
      typedef ::historyEvent current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::historyEvent

//______________________________________________________________________________
void g3HistoryEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class g3HistoryEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g3HistoryEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(g3HistoryEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g3HistoryEvent(void *p) {
      return  p ? new(p) ::g3HistoryEvent : new ::g3HistoryEvent;
   }
   static void *newArray_g3HistoryEvent(Long_t nElements, void *p) {
      return p ? new(p) ::g3HistoryEvent[nElements] : new ::g3HistoryEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_g3HistoryEvent(void *p) {
      delete (static_cast<::g3HistoryEvent*>(p));
   }
   static void deleteArray_g3HistoryEvent(void *p) {
      delete [] (static_cast<::g3HistoryEvent*>(p));
   }
   static void destruct_g3HistoryEvent(void *p) {
      typedef ::g3HistoryEvent current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g3HistoryEvent

//______________________________________________________________________________
void Bank88::Streamer(TBuffer &R__b)
{
   // Stream an object of class Bank88.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Bank88::Class(),this);
   } else {
      R__b.WriteClassBuffer(Bank88::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Bank88(void *p) {
      return  p ? new(p) ::Bank88 : new ::Bank88;
   }
   static void *newArray_Bank88(Long_t nElements, void *p) {
      return p ? new(p) ::Bank88[nElements] : new ::Bank88[nElements];
   }
   // Wrapper around operator delete
   static void delete_Bank88(void *p) {
      delete (static_cast<::Bank88*>(p));
   }
   static void deleteArray_Bank88(void *p) {
      delete [] (static_cast<::Bank88*>(p));
   }
   static void destruct_Bank88(void *p) {
      typedef ::Bank88 current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Bank88

namespace ROOT {
   // Wrappers around operator new
   static void *new_ip(void *p) {
      return  p ? new(p) ::ip : new ::ip;
   }
   static void *newArray_ip(Long_t nElements, void *p) {
      return p ? new(p) ::ip[nElements] : new ::ip[nElements];
   }
   // Wrapper around operator delete
   static void delete_ip(void *p) {
      delete (static_cast<::ip*>(p));
   }
   static void deleteArray_ip(void *p) {
      delete [] (static_cast<::ip*>(p));
   }
   static void destruct_ip(void *p) {
      typedef ::ip current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::ip

namespace ROOT {
   // Wrappers around operator new
   static void *new_ipOLD(void *p) {
      return  p ? new(p) ::ipOLD : new ::ipOLD;
   }
   static void *newArray_ipOLD(Long_t nElements, void *p) {
      return p ? new(p) ::ipOLD[nElements] : new ::ipOLD[nElements];
   }
   // Wrapper around operator delete
   static void delete_ipOLD(void *p) {
      delete (static_cast<::ipOLD*>(p));
   }
   static void deleteArray_ipOLD(void *p) {
      delete [] (static_cast<::ipOLD*>(p));
   }
   static void destruct_ipOLD(void *p) {
      typedef ::ipOLD current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::ipOLD

namespace ROOT {
   // Wrappers around operator new
   static void *new_mode2Old(void *p) {
      return  p ? new(p) ::mode2Old : new ::mode2Old;
   }
   static void *newArray_mode2Old(Long_t nElements, void *p) {
      return p ? new(p) ::mode2Old[nElements] : new ::mode2Old[nElements];
   }
   // Wrapper around operator delete
   static void delete_mode2Old(void *p) {
      delete (static_cast<::mode2Old*>(p));
   }
   static void deleteArray_mode2Old(void *p) {
      delete [] (static_cast<::mode2Old*>(p));
   }
   static void destruct_mode2Old(void *p) {
      typedef ::mode2Old current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::mode2Old

namespace ROOT {
   // Wrappers around operator new
   static void *new_mode2ABCD1234(void *p) {
      return  p ? new(p) ::mode2ABCD1234 : new ::mode2ABCD1234;
   }
   static void *newArray_mode2ABCD1234(Long_t nElements, void *p) {
      return p ? new(p) ::mode2ABCD1234[nElements] : new ::mode2ABCD1234[nElements];
   }
   // Wrapper around operator delete
   static void delete_mode2ABCD1234(void *p) {
      delete (static_cast<::mode2ABCD1234*>(p));
   }
   static void deleteArray_mode2ABCD1234(void *p) {
      delete [] (static_cast<::mode2ABCD1234*>(p));
   }
   static void destruct_mode2ABCD1234(void *p) {
      typedef ::mode2ABCD1234 current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::mode2ABCD1234

namespace ROOT {
   // Wrappers around operator new
   static void *new_mode2ABCD5678(void *p) {
      return  p ? new(p) ::mode2ABCD5678 : new ::mode2ABCD5678;
   }
   static void *newArray_mode2ABCD5678(Long_t nElements, void *p) {
      return p ? new(p) ::mode2ABCD5678[nElements] : new ::mode2ABCD5678[nElements];
   }
   // Wrapper around operator delete
   static void delete_mode2ABCD5678(void *p) {
      delete (static_cast<::mode2ABCD5678*>(p));
   }
   static void deleteArray_mode2ABCD5678(void *p) {
      delete [] (static_cast<::mode2ABCD5678*>(p));
   }
   static void destruct_mode2ABCD5678(void *p) {
      typedef ::mode2ABCD5678 current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::mode2ABCD5678

namespace ROOT {
   // Wrappers around operator new
   static void *new_mode2ABCD6789(void *p) {
      return  p ? new(p) ::mode2ABCD6789 : new ::mode2ABCD6789;
   }
   static void *newArray_mode2ABCD6789(Long_t nElements, void *p) {
      return p ? new(p) ::mode2ABCD6789[nElements] : new ::mode2ABCD6789[nElements];
   }
   // Wrapper around operator delete
   static void delete_mode2ABCD6789(void *p) {
      delete (static_cast<::mode2ABCD6789*>(p));
   }
   static void deleteArray_mode2ABCD6789(void *p) {
      delete [] (static_cast<::mode2ABCD6789*>(p));
   }
   static void destruct_mode2ABCD6789(void *p) {
      typedef ::mode2ABCD6789 current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::mode2ABCD6789

//______________________________________________________________________________
void g2IntPt::Streamer(TBuffer &R__b)
{
   // Stream an object of class g2IntPt.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g2IntPt::Class(),this);
   } else {
      R__b.WriteClassBuffer(g2IntPt::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g2IntPt(void *p) {
      return  p ? new(p) ::g2IntPt : new ::g2IntPt;
   }
   static void *newArray_g2IntPt(Long_t nElements, void *p) {
      return p ? new(p) ::g2IntPt[nElements] : new ::g2IntPt[nElements];
   }
   // Wrapper around operator delete
   static void delete_g2IntPt(void *p) {
      delete (static_cast<::g2IntPt*>(p));
   }
   static void deleteArray_g2IntPt(void *p) {
      delete [] (static_cast<::g2IntPt*>(p));
   }
   static void destruct_g2IntPt(void *p) {
      typedef ::g2IntPt current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g2IntPt

//______________________________________________________________________________
void g2CrystalEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class g2CrystalEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g2CrystalEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(g2CrystalEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g2CrystalEvent(void *p) {
      return  p ? new(p) ::g2CrystalEvent : new ::g2CrystalEvent;
   }
   static void *newArray_g2CrystalEvent(Long_t nElements, void *p) {
      return p ? new(p) ::g2CrystalEvent[nElements] : new ::g2CrystalEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_g2CrystalEvent(void *p) {
      delete (static_cast<::g2CrystalEvent*>(p));
   }
   static void deleteArray_g2CrystalEvent(void *p) {
      delete [] (static_cast<::g2CrystalEvent*>(p));
   }
   static void destruct_g2CrystalEvent(void *p) {
      typedef ::g2CrystalEvent current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g2CrystalEvent

//______________________________________________________________________________
void g2OUT::Streamer(TBuffer &R__b)
{
   // Stream an object of class g2OUT.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g2OUT::Class(),this);
   } else {
      R__b.WriteClassBuffer(g2OUT::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g2OUT(void *p) {
      return  p ? new(p) ::g2OUT : new ::g2OUT;
   }
   static void *newArray_g2OUT(Long_t nElements, void *p) {
      return p ? new(p) ::g2OUT[nElements] : new ::g2OUT[nElements];
   }
   // Wrapper around operator delete
   static void delete_g2OUT(void *p) {
      delete (static_cast<::g2OUT*>(p));
   }
   static void deleteArray_g2OUT(void *p) {
      delete [] (static_cast<::g2OUT*>(p));
   }
   static void destruct_g2OUT(void *p) {
      typedef ::g2OUT current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g2OUT

namespace ROOT {
   // Wrappers around operator new
   static void *new_trackedGamma(void *p) {
      return  p ? new(p) ::trackedGamma : new ::trackedGamma;
   }
   static void *newArray_trackedGamma(Long_t nElements, void *p) {
      return p ? new(p) ::trackedGamma[nElements] : new ::trackedGamma[nElements];
   }
   // Wrapper around operator delete
   static void delete_trackedGamma(void *p) {
      delete (static_cast<::trackedGamma*>(p));
   }
   static void deleteArray_trackedGamma(void *p) {
      delete [] (static_cast<::trackedGamma*>(p));
   }
   static void destruct_trackedGamma(void *p) {
      typedef ::trackedGamma current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::trackedGamma

//______________________________________________________________________________
void GTrackEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class GTrackEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(GTrackEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(GTrackEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_GTrackEvent(void *p) {
      return  p ? new(p) ::GTrackEvent : new ::GTrackEvent;
   }
   static void *newArray_GTrackEvent(Long_t nElements, void *p) {
      return p ? new(p) ::GTrackEvent[nElements] : new ::GTrackEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_GTrackEvent(void *p) {
      delete (static_cast<::GTrackEvent*>(p));
   }
   static void deleteArray_GTrackEvent(void *p) {
      delete [] (static_cast<::GTrackEvent*>(p));
   }
   static void destruct_GTrackEvent(void *p) {
      typedef ::GTrackEvent current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::GTrackEvent

//______________________________________________________________________________
void g1GammaEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class g1GammaEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g1GammaEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(g1GammaEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g1GammaEvent(void *p) {
      return  p ? new(p) ::g1GammaEvent : new ::g1GammaEvent;
   }
   static void *newArray_g1GammaEvent(Long_t nElements, void *p) {
      return p ? new(p) ::g1GammaEvent[nElements] : new ::g1GammaEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_g1GammaEvent(void *p) {
      delete (static_cast<::g1GammaEvent*>(p));
   }
   static void deleteArray_g1GammaEvent(void *p) {
      delete [] (static_cast<::g1GammaEvent*>(p));
   }
   static void destruct_g1GammaEvent(void *p) {
      typedef ::g1GammaEvent current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g1GammaEvent

//______________________________________________________________________________
void g1OUT::Streamer(TBuffer &R__b)
{
   // Stream an object of class g1OUT.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g1OUT::Class(),this);
   } else {
      R__b.WriteClassBuffer(g1OUT::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g1OUT(void *p) {
      return  p ? new(p) ::g1OUT : new ::g1OUT;
   }
   static void *newArray_g1OUT(Long_t nElements, void *p) {
      return p ? new(p) ::g1OUT[nElements] : new ::g1OUT[nElements];
   }
   // Wrapper around operator delete
   static void delete_g1OUT(void *p) {
      delete (static_cast<::g1OUT*>(p));
   }
   static void deleteArray_g1OUT(void *p) {
      delete [] (static_cast<::g1OUT*>(p));
   }
   static void destruct_g1OUT(void *p) {
      typedef ::g1OUT current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g1OUT

namespace ROOT {
   // Wrappers around operator new
   static void *new_g4Sim_emittedGamma(void *p) {
      return  p ? new(p) ::g4Sim_emittedGamma : new ::g4Sim_emittedGamma;
   }
   static void *newArray_g4Sim_emittedGamma(Long_t nElements, void *p) {
      return p ? new(p) ::g4Sim_emittedGamma[nElements] : new ::g4Sim_emittedGamma[nElements];
   }
   // Wrapper around operator delete
   static void delete_g4Sim_emittedGamma(void *p) {
      delete (static_cast<::g4Sim_emittedGamma*>(p));
   }
   static void deleteArray_g4Sim_emittedGamma(void *p) {
      delete [] (static_cast<::g4Sim_emittedGamma*>(p));
   }
   static void destruct_g4Sim_emittedGamma(void *p) {
      typedef ::g4Sim_emittedGamma current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g4Sim_emittedGamma

namespace ROOT {
   // Wrappers around operator new
   static void *new_g4Sim_abcd1234(void *p) {
      return  p ? new(p) ::g4Sim_abcd1234 : new ::g4Sim_abcd1234;
   }
   static void *newArray_g4Sim_abcd1234(Long_t nElements, void *p) {
      return p ? new(p) ::g4Sim_abcd1234[nElements] : new ::g4Sim_abcd1234[nElements];
   }
   // Wrapper around operator delete
   static void delete_g4Sim_abcd1234(void *p) {
      delete (static_cast<::g4Sim_abcd1234*>(p));
   }
   static void deleteArray_g4Sim_abcd1234(void *p) {
      delete [] (static_cast<::g4Sim_abcd1234*>(p));
   }
   static void destruct_g4Sim_abcd1234(void *p) {
      typedef ::g4Sim_abcd1234 current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g4Sim_abcd1234

//______________________________________________________________________________
void g4SimOUT::Streamer(TBuffer &R__b)
{
   // Stream an object of class g4SimOUT.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(g4SimOUT::Class(),this);
   } else {
      R__b.WriteClassBuffer(g4SimOUT::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_g4SimOUT(void *p) {
      return  p ? new(p) ::g4SimOUT : new ::g4SimOUT;
   }
   static void *newArray_g4SimOUT(Long_t nElements, void *p) {
      return p ? new(p) ::g4SimOUT[nElements] : new ::g4SimOUT[nElements];
   }
   // Wrapper around operator delete
   static void delete_g4SimOUT(void *p) {
      delete (static_cast<::g4SimOUT*>(p));
   }
   static void deleteArray_g4SimOUT(void *p) {
      delete [] (static_cast<::g4SimOUT*>(p));
   }
   static void destruct_g4SimOUT(void *p) {
      typedef ::g4SimOUT current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::g4SimOUT

//______________________________________________________________________________
void gHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class gHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(gHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(gHistos::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_gHistos(void *p) {
      return  p ? new(p) ::gHistos : new ::gHistos;
   }
   static void *newArray_gHistos(Long_t nElements, void *p) {
      return p ? new(p) ::gHistos[nElements] : new ::gHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_gHistos(void *p) {
      delete (static_cast<::gHistos*>(p));
   }
   static void deleteArray_gHistos(void *p) {
      delete [] (static_cast<::gHistos*>(p));
   }
   static void destruct_gHistos(void *p) {
      typedef ::gHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::gHistos

//______________________________________________________________________________
void SuperPulse::Streamer(TBuffer &R__b)
{
   // Stream an object of class SuperPulse.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(SuperPulse::Class(),this);
   } else {
      R__b.WriteClassBuffer(SuperPulse::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SuperPulse(void *p) {
      return  p ? new(p) ::SuperPulse : new ::SuperPulse;
   }
   static void *newArray_SuperPulse(Long_t nElements, void *p) {
      return p ? new(p) ::SuperPulse[nElements] : new ::SuperPulse[nElements];
   }
   // Wrapper around operator delete
   static void delete_SuperPulse(void *p) {
      delete (static_cast<::SuperPulse*>(p));
   }
   static void deleteArray_SuperPulse(void *p) {
      delete [] (static_cast<::SuperPulse*>(p));
   }
   static void destruct_SuperPulse(void *p) {
      typedef ::SuperPulse current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::SuperPulse

//______________________________________________________________________________
void GRETINA::Streamer(TBuffer &R__b)
{
   // Stream an object of class GRETINA.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(GRETINA::Class(),this);
   } else {
      R__b.WriteClassBuffer(GRETINA::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_GRETINA(void *p) {
      return  p ? new(p) ::GRETINA : new ::GRETINA;
   }
   static void *newArray_GRETINA(Long_t nElements, void *p) {
      return p ? new(p) ::GRETINA[nElements] : new ::GRETINA[nElements];
   }
   // Wrapper around operator delete
   static void delete_GRETINA(void *p) {
      delete (static_cast<::GRETINA*>(p));
   }
   static void deleteArray_GRETINA(void *p) {
      delete [] (static_cast<::GRETINA*>(p));
   }
   static void destruct_GRETINA(void *p) {
      typedef ::GRETINA current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::GRETINA

//______________________________________________________________________________
void INLCorrection::Streamer(TBuffer &R__b)
{
   // Stream an object of class INLCorrection.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(INLCorrection::Class(),this);
   } else {
      R__b.WriteClassBuffer(INLCorrection::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_INLCorrection(void *p) {
      return  p ? new(p) ::INLCorrection : new ::INLCorrection;
   }
   static void *newArray_INLCorrection(Long_t nElements, void *p) {
      return p ? new(p) ::INLCorrection[nElements] : new ::INLCorrection[nElements];
   }
   // Wrapper around operator delete
   static void delete_INLCorrection(void *p) {
      delete (static_cast<::INLCorrection*>(p));
   }
   static void deleteArray_INLCorrection(void *p) {
      delete [] (static_cast<::INLCorrection*>(p));
   }
   static void destruct_INLCorrection(void *p) {
      typedef ::INLCorrection current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::INLCorrection

//______________________________________________________________________________
void Histos::Streamer(TBuffer &R__b)
{
   // Stream an object of class Histos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Histos::Class(),this);
   } else {
      R__b.WriteClassBuffer(Histos::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Histos(void *p) {
      return  p ? new(p) ::Histos : new ::Histos;
   }
   static void *newArray_Histos(Long_t nElements, void *p) {
      return p ? new(p) ::Histos[nElements] : new ::Histos[nElements];
   }
   // Wrapper around operator delete
   static void delete_Histos(void *p) {
      delete (static_cast<::Histos*>(p));
   }
   static void deleteArray_Histos(void *p) {
      delete [] (static_cast<::Histos*>(p));
   }
   static void destruct_Histos(void *p) {
      typedef ::Histos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Histos

namespace ROOT {
   static TClass *vectorlEtrackedGammagR_Dictionary();
   static void vectorlEtrackedGammagR_TClassManip(TClass*);
   static void *new_vectorlEtrackedGammagR(void *p = nullptr);
   static void *newArray_vectorlEtrackedGammagR(Long_t size, void *p);
   static void delete_vectorlEtrackedGammagR(void *p);
   static void deleteArray_vectorlEtrackedGammagR(void *p);
   static void destruct_vectorlEtrackedGammagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<trackedGamma>*)
   {
      vector<trackedGamma> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<trackedGamma>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<trackedGamma>", -2, "vector", 389,
                  typeid(vector<trackedGamma>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEtrackedGammagR_Dictionary, isa_proxy, 4,
                  sizeof(vector<trackedGamma>) );
      instance.SetNew(&new_vectorlEtrackedGammagR);
      instance.SetNewArray(&newArray_vectorlEtrackedGammagR);
      instance.SetDelete(&delete_vectorlEtrackedGammagR);
      instance.SetDeleteArray(&deleteArray_vectorlEtrackedGammagR);
      instance.SetDestructor(&destruct_vectorlEtrackedGammagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<trackedGamma> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<trackedGamma>","std::vector<trackedGamma, std::allocator<trackedGamma> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<trackedGamma>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEtrackedGammagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<trackedGamma>*>(nullptr))->GetClass();
      vectorlEtrackedGammagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEtrackedGammagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEtrackedGammagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<trackedGamma> : new vector<trackedGamma>;
   }
   static void *newArray_vectorlEtrackedGammagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<trackedGamma>[nElements] : new vector<trackedGamma>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEtrackedGammagR(void *p) {
      delete (static_cast<vector<trackedGamma>*>(p));
   }
   static void deleteArray_vectorlEtrackedGammagR(void *p) {
      delete [] (static_cast<vector<trackedGamma>*>(p));
   }
   static void destruct_vectorlEtrackedGammagR(void *p) {
      typedef vector<trackedGamma> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<trackedGamma>

namespace ROOT {
   static TClass *vectorlEshortgR_Dictionary();
   static void vectorlEshortgR_TClassManip(TClass*);
   static void *new_vectorlEshortgR(void *p = nullptr);
   static void *newArray_vectorlEshortgR(Long_t size, void *p);
   static void delete_vectorlEshortgR(void *p);
   static void deleteArray_vectorlEshortgR(void *p);
   static void destruct_vectorlEshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<short>*)
   {
      vector<short> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<short>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<short>", -2, "vector", 389,
                  typeid(vector<short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<short>) );
      instance.SetNew(&new_vectorlEshortgR);
      instance.SetNewArray(&newArray_vectorlEshortgR);
      instance.SetDelete(&delete_vectorlEshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEshortgR);
      instance.SetDestructor(&destruct_vectorlEshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<short> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<short>","std::vector<short, std::allocator<short> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<short>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<short>*>(nullptr))->GetClass();
      vectorlEshortgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEshortgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<short> : new vector<short>;
   }
   static void *newArray_vectorlEshortgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<short>[nElements] : new vector<short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEshortgR(void *p) {
      delete (static_cast<vector<short>*>(p));
   }
   static void deleteArray_vectorlEshortgR(void *p) {
      delete [] (static_cast<vector<short>*>(p));
   }
   static void destruct_vectorlEshortgR(void *p) {
      typedef vector<short> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<short>

namespace ROOT {
   static TClass *vectorlEipgR_Dictionary();
   static void vectorlEipgR_TClassManip(TClass*);
   static void *new_vectorlEipgR(void *p = nullptr);
   static void *newArray_vectorlEipgR(Long_t size, void *p);
   static void delete_vectorlEipgR(void *p);
   static void deleteArray_vectorlEipgR(void *p);
   static void destruct_vectorlEipgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ip>*)
   {
      vector<ip> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ip>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ip>", -2, "vector", 389,
                  typeid(vector<ip>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEipgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<ip>) );
      instance.SetNew(&new_vectorlEipgR);
      instance.SetNewArray(&newArray_vectorlEipgR);
      instance.SetDelete(&delete_vectorlEipgR);
      instance.SetDeleteArray(&deleteArray_vectorlEipgR);
      instance.SetDestructor(&destruct_vectorlEipgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ip> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<ip>","std::vector<ip, std::allocator<ip> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<ip>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEipgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<ip>*>(nullptr))->GetClass();
      vectorlEipgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEipgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEipgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<ip> : new vector<ip>;
   }
   static void *newArray_vectorlEipgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<ip>[nElements] : new vector<ip>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEipgR(void *p) {
      delete (static_cast<vector<ip>*>(p));
   }
   static void deleteArray_vectorlEipgR(void *p) {
      delete [] (static_cast<vector<ip>*>(p));
   }
   static void destruct_vectorlEipgR(void *p) {
      typedef vector<ip> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<ip>

namespace ROOT {
   static TClass *vectorlEhistoryEventgR_Dictionary();
   static void vectorlEhistoryEventgR_TClassManip(TClass*);
   static void *new_vectorlEhistoryEventgR(void *p = nullptr);
   static void *newArray_vectorlEhistoryEventgR(Long_t size, void *p);
   static void delete_vectorlEhistoryEventgR(void *p);
   static void deleteArray_vectorlEhistoryEventgR(void *p);
   static void destruct_vectorlEhistoryEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<historyEvent>*)
   {
      vector<historyEvent> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<historyEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<historyEvent>", -2, "vector", 389,
                  typeid(vector<historyEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEhistoryEventgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<historyEvent>) );
      instance.SetNew(&new_vectorlEhistoryEventgR);
      instance.SetNewArray(&newArray_vectorlEhistoryEventgR);
      instance.SetDelete(&delete_vectorlEhistoryEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEhistoryEventgR);
      instance.SetDestructor(&destruct_vectorlEhistoryEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<historyEvent> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<historyEvent>","std::vector<historyEvent, std::allocator<historyEvent> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<historyEvent>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEhistoryEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<historyEvent>*>(nullptr))->GetClass();
      vectorlEhistoryEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEhistoryEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEhistoryEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<historyEvent> : new vector<historyEvent>;
   }
   static void *newArray_vectorlEhistoryEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<historyEvent>[nElements] : new vector<historyEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEhistoryEventgR(void *p) {
      delete (static_cast<vector<historyEvent>*>(p));
   }
   static void deleteArray_vectorlEhistoryEventgR(void *p) {
      delete [] (static_cast<vector<historyEvent>*>(p));
   }
   static void destruct_vectorlEhistoryEventgR(void *p) {
      typedef vector<historyEvent> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<historyEvent>

namespace ROOT {
   static TClass *vectorlEg4Sim_abcd1234gR_Dictionary();
   static void vectorlEg4Sim_abcd1234gR_TClassManip(TClass*);
   static void *new_vectorlEg4Sim_abcd1234gR(void *p = nullptr);
   static void *newArray_vectorlEg4Sim_abcd1234gR(Long_t size, void *p);
   static void delete_vectorlEg4Sim_abcd1234gR(void *p);
   static void deleteArray_vectorlEg4Sim_abcd1234gR(void *p);
   static void destruct_vectorlEg4Sim_abcd1234gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<g4Sim_abcd1234>*)
   {
      vector<g4Sim_abcd1234> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<g4Sim_abcd1234>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<g4Sim_abcd1234>", -2, "vector", 389,
                  typeid(vector<g4Sim_abcd1234>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEg4Sim_abcd1234gR_Dictionary, isa_proxy, 0,
                  sizeof(vector<g4Sim_abcd1234>) );
      instance.SetNew(&new_vectorlEg4Sim_abcd1234gR);
      instance.SetNewArray(&newArray_vectorlEg4Sim_abcd1234gR);
      instance.SetDelete(&delete_vectorlEg4Sim_abcd1234gR);
      instance.SetDeleteArray(&deleteArray_vectorlEg4Sim_abcd1234gR);
      instance.SetDestructor(&destruct_vectorlEg4Sim_abcd1234gR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<g4Sim_abcd1234> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<g4Sim_abcd1234>","std::vector<g4Sim_abcd1234, std::allocator<g4Sim_abcd1234> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<g4Sim_abcd1234>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEg4Sim_abcd1234gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<g4Sim_abcd1234>*>(nullptr))->GetClass();
      vectorlEg4Sim_abcd1234gR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEg4Sim_abcd1234gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEg4Sim_abcd1234gR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g4Sim_abcd1234> : new vector<g4Sim_abcd1234>;
   }
   static void *newArray_vectorlEg4Sim_abcd1234gR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g4Sim_abcd1234>[nElements] : new vector<g4Sim_abcd1234>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEg4Sim_abcd1234gR(void *p) {
      delete (static_cast<vector<g4Sim_abcd1234>*>(p));
   }
   static void deleteArray_vectorlEg4Sim_abcd1234gR(void *p) {
      delete [] (static_cast<vector<g4Sim_abcd1234>*>(p));
   }
   static void destruct_vectorlEg4Sim_abcd1234gR(void *p) {
      typedef vector<g4Sim_abcd1234> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<g4Sim_abcd1234>

namespace ROOT {
   static TClass *vectorlEg3WaveformgR_Dictionary();
   static void vectorlEg3WaveformgR_TClassManip(TClass*);
   static void *new_vectorlEg3WaveformgR(void *p = nullptr);
   static void *newArray_vectorlEg3WaveformgR(Long_t size, void *p);
   static void delete_vectorlEg3WaveformgR(void *p);
   static void deleteArray_vectorlEg3WaveformgR(void *p);
   static void destruct_vectorlEg3WaveformgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<g3Waveform>*)
   {
      vector<g3Waveform> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<g3Waveform>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<g3Waveform>", -2, "vector", 389,
                  typeid(vector<g3Waveform>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEg3WaveformgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<g3Waveform>) );
      instance.SetNew(&new_vectorlEg3WaveformgR);
      instance.SetNewArray(&newArray_vectorlEg3WaveformgR);
      instance.SetDelete(&delete_vectorlEg3WaveformgR);
      instance.SetDeleteArray(&deleteArray_vectorlEg3WaveformgR);
      instance.SetDestructor(&destruct_vectorlEg3WaveformgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<g3Waveform> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<g3Waveform>","std::vector<g3Waveform, std::allocator<g3Waveform> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<g3Waveform>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEg3WaveformgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<g3Waveform>*>(nullptr))->GetClass();
      vectorlEg3WaveformgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEg3WaveformgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEg3WaveformgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g3Waveform> : new vector<g3Waveform>;
   }
   static void *newArray_vectorlEg3WaveformgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g3Waveform>[nElements] : new vector<g3Waveform>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEg3WaveformgR(void *p) {
      delete (static_cast<vector<g3Waveform>*>(p));
   }
   static void deleteArray_vectorlEg3WaveformgR(void *p) {
      delete [] (static_cast<vector<g3Waveform>*>(p));
   }
   static void destruct_vectorlEg3WaveformgR(void *p) {
      typedef vector<g3Waveform> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<g3Waveform>

namespace ROOT {
   static TClass *vectorlEg3CrystalEventgR_Dictionary();
   static void vectorlEg3CrystalEventgR_TClassManip(TClass*);
   static void *new_vectorlEg3CrystalEventgR(void *p = nullptr);
   static void *newArray_vectorlEg3CrystalEventgR(Long_t size, void *p);
   static void delete_vectorlEg3CrystalEventgR(void *p);
   static void deleteArray_vectorlEg3CrystalEventgR(void *p);
   static void destruct_vectorlEg3CrystalEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<g3CrystalEvent>*)
   {
      vector<g3CrystalEvent> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<g3CrystalEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<g3CrystalEvent>", -2, "vector", 389,
                  typeid(vector<g3CrystalEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEg3CrystalEventgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<g3CrystalEvent>) );
      instance.SetNew(&new_vectorlEg3CrystalEventgR);
      instance.SetNewArray(&newArray_vectorlEg3CrystalEventgR);
      instance.SetDelete(&delete_vectorlEg3CrystalEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEg3CrystalEventgR);
      instance.SetDestructor(&destruct_vectorlEg3CrystalEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<g3CrystalEvent> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<g3CrystalEvent>","std::vector<g3CrystalEvent, std::allocator<g3CrystalEvent> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<g3CrystalEvent>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEg3CrystalEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<g3CrystalEvent>*>(nullptr))->GetClass();
      vectorlEg3CrystalEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEg3CrystalEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEg3CrystalEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g3CrystalEvent> : new vector<g3CrystalEvent>;
   }
   static void *newArray_vectorlEg3CrystalEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g3CrystalEvent>[nElements] : new vector<g3CrystalEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEg3CrystalEventgR(void *p) {
      delete (static_cast<vector<g3CrystalEvent>*>(p));
   }
   static void deleteArray_vectorlEg3CrystalEventgR(void *p) {
      delete [] (static_cast<vector<g3CrystalEvent>*>(p));
   }
   static void destruct_vectorlEg3CrystalEventgR(void *p) {
      typedef vector<g3CrystalEvent> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<g3CrystalEvent>

namespace ROOT {
   static TClass *vectorlEg3ChannelEventgR_Dictionary();
   static void vectorlEg3ChannelEventgR_TClassManip(TClass*);
   static void *new_vectorlEg3ChannelEventgR(void *p = nullptr);
   static void *newArray_vectorlEg3ChannelEventgR(Long_t size, void *p);
   static void delete_vectorlEg3ChannelEventgR(void *p);
   static void deleteArray_vectorlEg3ChannelEventgR(void *p);
   static void destruct_vectorlEg3ChannelEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<g3ChannelEvent>*)
   {
      vector<g3ChannelEvent> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<g3ChannelEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<g3ChannelEvent>", -2, "vector", 389,
                  typeid(vector<g3ChannelEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEg3ChannelEventgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<g3ChannelEvent>) );
      instance.SetNew(&new_vectorlEg3ChannelEventgR);
      instance.SetNewArray(&newArray_vectorlEg3ChannelEventgR);
      instance.SetDelete(&delete_vectorlEg3ChannelEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEg3ChannelEventgR);
      instance.SetDestructor(&destruct_vectorlEg3ChannelEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<g3ChannelEvent> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<g3ChannelEvent>","std::vector<g3ChannelEvent, std::allocator<g3ChannelEvent> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<g3ChannelEvent>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEg3ChannelEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<g3ChannelEvent>*>(nullptr))->GetClass();
      vectorlEg3ChannelEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEg3ChannelEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEg3ChannelEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g3ChannelEvent> : new vector<g3ChannelEvent>;
   }
   static void *newArray_vectorlEg3ChannelEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g3ChannelEvent>[nElements] : new vector<g3ChannelEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEg3ChannelEventgR(void *p) {
      delete (static_cast<vector<g3ChannelEvent>*>(p));
   }
   static void deleteArray_vectorlEg3ChannelEventgR(void *p) {
      delete [] (static_cast<vector<g3ChannelEvent>*>(p));
   }
   static void destruct_vectorlEg3ChannelEventgR(void *p) {
      typedef vector<g3ChannelEvent> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<g3ChannelEvent>

namespace ROOT {
   static TClass *vectorlEg2IntPtgR_Dictionary();
   static void vectorlEg2IntPtgR_TClassManip(TClass*);
   static void *new_vectorlEg2IntPtgR(void *p = nullptr);
   static void *newArray_vectorlEg2IntPtgR(Long_t size, void *p);
   static void delete_vectorlEg2IntPtgR(void *p);
   static void deleteArray_vectorlEg2IntPtgR(void *p);
   static void destruct_vectorlEg2IntPtgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<g2IntPt>*)
   {
      vector<g2IntPt> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<g2IntPt>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<g2IntPt>", -2, "vector", 389,
                  typeid(vector<g2IntPt>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEg2IntPtgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<g2IntPt>) );
      instance.SetNew(&new_vectorlEg2IntPtgR);
      instance.SetNewArray(&newArray_vectorlEg2IntPtgR);
      instance.SetDelete(&delete_vectorlEg2IntPtgR);
      instance.SetDeleteArray(&deleteArray_vectorlEg2IntPtgR);
      instance.SetDestructor(&destruct_vectorlEg2IntPtgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<g2IntPt> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<g2IntPt>","std::vector<g2IntPt, std::allocator<g2IntPt> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<g2IntPt>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEg2IntPtgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<g2IntPt>*>(nullptr))->GetClass();
      vectorlEg2IntPtgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEg2IntPtgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEg2IntPtgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g2IntPt> : new vector<g2IntPt>;
   }
   static void *newArray_vectorlEg2IntPtgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g2IntPt>[nElements] : new vector<g2IntPt>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEg2IntPtgR(void *p) {
      delete (static_cast<vector<g2IntPt>*>(p));
   }
   static void deleteArray_vectorlEg2IntPtgR(void *p) {
      delete [] (static_cast<vector<g2IntPt>*>(p));
   }
   static void destruct_vectorlEg2IntPtgR(void *p) {
      typedef vector<g2IntPt> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<g2IntPt>

namespace ROOT {
   static TClass *vectorlEg2CrystalEventgR_Dictionary();
   static void vectorlEg2CrystalEventgR_TClassManip(TClass*);
   static void *new_vectorlEg2CrystalEventgR(void *p = nullptr);
   static void *newArray_vectorlEg2CrystalEventgR(Long_t size, void *p);
   static void delete_vectorlEg2CrystalEventgR(void *p);
   static void deleteArray_vectorlEg2CrystalEventgR(void *p);
   static void destruct_vectorlEg2CrystalEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<g2CrystalEvent>*)
   {
      vector<g2CrystalEvent> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<g2CrystalEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<g2CrystalEvent>", -2, "vector", 389,
                  typeid(vector<g2CrystalEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEg2CrystalEventgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<g2CrystalEvent>) );
      instance.SetNew(&new_vectorlEg2CrystalEventgR);
      instance.SetNewArray(&newArray_vectorlEg2CrystalEventgR);
      instance.SetDelete(&delete_vectorlEg2CrystalEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEg2CrystalEventgR);
      instance.SetDestructor(&destruct_vectorlEg2CrystalEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<g2CrystalEvent> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<g2CrystalEvent>","std::vector<g2CrystalEvent, std::allocator<g2CrystalEvent> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<g2CrystalEvent>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEg2CrystalEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<g2CrystalEvent>*>(nullptr))->GetClass();
      vectorlEg2CrystalEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEg2CrystalEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEg2CrystalEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g2CrystalEvent> : new vector<g2CrystalEvent>;
   }
   static void *newArray_vectorlEg2CrystalEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g2CrystalEvent>[nElements] : new vector<g2CrystalEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEg2CrystalEventgR(void *p) {
      delete (static_cast<vector<g2CrystalEvent>*>(p));
   }
   static void deleteArray_vectorlEg2CrystalEventgR(void *p) {
      delete [] (static_cast<vector<g2CrystalEvent>*>(p));
   }
   static void destruct_vectorlEg2CrystalEventgR(void *p) {
      typedef vector<g2CrystalEvent> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<g2CrystalEvent>

namespace ROOT {
   static TClass *vectorlEg1GammaEventgR_Dictionary();
   static void vectorlEg1GammaEventgR_TClassManip(TClass*);
   static void *new_vectorlEg1GammaEventgR(void *p = nullptr);
   static void *newArray_vectorlEg1GammaEventgR(Long_t size, void *p);
   static void delete_vectorlEg1GammaEventgR(void *p);
   static void deleteArray_vectorlEg1GammaEventgR(void *p);
   static void destruct_vectorlEg1GammaEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<g1GammaEvent>*)
   {
      vector<g1GammaEvent> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<g1GammaEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<g1GammaEvent>", -2, "vector", 389,
                  typeid(vector<g1GammaEvent>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEg1GammaEventgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<g1GammaEvent>) );
      instance.SetNew(&new_vectorlEg1GammaEventgR);
      instance.SetNewArray(&newArray_vectorlEg1GammaEventgR);
      instance.SetDelete(&delete_vectorlEg1GammaEventgR);
      instance.SetDeleteArray(&deleteArray_vectorlEg1GammaEventgR);
      instance.SetDestructor(&destruct_vectorlEg1GammaEventgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<g1GammaEvent> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<g1GammaEvent>","std::vector<g1GammaEvent, std::allocator<g1GammaEvent> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<g1GammaEvent>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEg1GammaEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<g1GammaEvent>*>(nullptr))->GetClass();
      vectorlEg1GammaEventgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEg1GammaEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEg1GammaEventgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g1GammaEvent> : new vector<g1GammaEvent>;
   }
   static void *newArray_vectorlEg1GammaEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<g1GammaEvent>[nElements] : new vector<g1GammaEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEg1GammaEventgR(void *p) {
      delete (static_cast<vector<g1GammaEvent>*>(p));
   }
   static void deleteArray_vectorlEg1GammaEventgR(void *p) {
      delete [] (static_cast<vector<g1GammaEvent>*>(p));
   }
   static void destruct_vectorlEg1GammaEventgR(void *p) {
      typedef vector<g1GammaEvent> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<g1GammaEvent>

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = nullptr);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 389,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<float>","std::vector<float, std::allocator<float> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr))->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete (static_cast<vector<float>*>(p));
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] (static_cast<vector<float>*>(p));
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace {
  void TriggerDictionaryInitialization_GRETINADict_Impl() {
    static const char* headers[] = {
"include/GRETINA.h",
"include/SortingStructures.h",
"include/GRETINAWavefunction.h",
"include/INLCorrection.h",
"include/Histos.h",
"include/Track.h",
"include/Utilities.h",
nullptr
    };
    static const char* includePaths[] = {
"/opt/root-6.28.06/include/",
"/home/sud/Desktop/Software/goddessSort/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "GRETINADict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g3ChannelEvent;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g3CrystalEvent;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g2IntPt;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g2CrystalEvent;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  trackedGamma;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g1GammaEvent;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  ip;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g3Waveform;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  controlVariables;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  counterVariables;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  PM;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  TrackClusterIP;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  TrackCluster;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  TrackShell;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  TrackCtrl;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  TrackStat;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  TrackPerm;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  Track;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  rotationMatrix;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  GRETINAVariables;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  globalHeader;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  mode3DataPacket;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g3OUT;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  mode3HistoryPacket;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  historyEvent;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g3HistoryEvent;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  Bank88;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  ipOLD;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  mode2Old;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  mode2ABCD1234;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  mode2ABCD5678;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  mode2ABCD6789;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g2OUT;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  GTrackEvent;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g1OUT;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g4Sim_emittedGamma;
struct __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g4Sim_abcd1234;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  g4SimOUT;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  gHistos;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  SuperPulse;
class __attribute__((annotate("$clingAutoload$include/GRETINA.h")))  GRETINA;
class __attribute__((annotate("$clingAutoload$include/INLCorrection.h")))  INLCorrection;
class __attribute__((annotate("$clingAutoload$include/Histos.h")))  Histos;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "GRETINADict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "include/GRETINA.h"
#include "include/SortingStructures.h"
#include "include/GRETINAWavefunction.h"
#include "include/INLCorrection.h"
#include "include/Histos.h"
#include "include/Track.h"
#include "include/Utilities.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"Bank88", payloadCode, "@",
"GRETINA", payloadCode, "@",
"GRETINAVariables", payloadCode, "@",
"GTrackEvent", payloadCode, "@",
"Histos", payloadCode, "@",
"INLCorrection", payloadCode, "@",
"PM", payloadCode, "@",
"SuperPulse", payloadCode, "@",
"Track", payloadCode, "@",
"TrackCluster", payloadCode, "@",
"TrackClusterIP", payloadCode, "@",
"TrackCtrl", payloadCode, "@",
"TrackPerm", payloadCode, "@",
"TrackShell", payloadCode, "@",
"TrackStat", payloadCode, "@",
"controlVariables", payloadCode, "@",
"counterVariables", payloadCode, "@",
"g1GammaEvent", payloadCode, "@",
"g1OUT", payloadCode, "@",
"g2CrystalEvent", payloadCode, "@",
"g2IntPt", payloadCode, "@",
"g2OUT", payloadCode, "@",
"g3ChannelEvent", payloadCode, "@",
"g3CrystalEvent", payloadCode, "@",
"g3HistoryEvent", payloadCode, "@",
"g3OUT", payloadCode, "@",
"g3Waveform", payloadCode, "@",
"g4SimOUT", payloadCode, "@",
"g4Sim_abcd1234", payloadCode, "@",
"g4Sim_emittedGamma", payloadCode, "@",
"gHistos", payloadCode, "@",
"globalHeader", payloadCode, "@",
"historyEvent", payloadCode, "@",
"ip", payloadCode, "@",
"ipOLD", payloadCode, "@",
"mode2ABCD1234", payloadCode, "@",
"mode2ABCD5678", payloadCode, "@",
"mode2ABCD6789", payloadCode, "@",
"mode2Old", payloadCode, "@",
"mode3DataPacket", payloadCode, "@",
"mode3HistoryPacket", payloadCode, "@",
"rotationMatrix", payloadCode, "@",
"trackedGamma", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("GRETINADict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_GRETINADict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_GRETINADict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_GRETINADict() {
  TriggerDictionaryInitialization_GRETINADict_Impl();
}
