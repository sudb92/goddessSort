// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME S800Dict
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
#include "include/S800Parameters.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_S800ImMap(void *p = nullptr);
   static void *newArray_S800ImMap(Long_t size, void *p);
   static void delete_S800ImMap(void *p);
   static void deleteArray_S800ImMap(void *p);
   static void destruct_S800ImMap(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800ImMap*)
   {
      ::S800ImMap *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800ImMap >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800ImMap", ::S800ImMap::Class_Version(), "include/S800Parameters.h", 54,
                  typeid(::S800ImMap), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800ImMap::Dictionary, isa_proxy, 4,
                  sizeof(::S800ImMap) );
      instance.SetNew(&new_S800ImMap);
      instance.SetNewArray(&newArray_S800ImMap);
      instance.SetDelete(&delete_S800ImMap);
      instance.SetDeleteArray(&deleteArray_S800ImMap);
      instance.SetDestructor(&destruct_S800ImMap);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800ImMap*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800ImMap*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800ImMap*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Map(void *p = nullptr);
   static void *newArray_S800Map(Long_t size, void *p);
   static void delete_S800Map(void *p);
   static void deleteArray_S800Map(void *p);
   static void destruct_S800Map(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Map*)
   {
      ::S800Map *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Map >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Map", ::S800Map::Class_Version(), "include/S800Parameters.h", 145,
                  typeid(::S800Map), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Map::Dictionary, isa_proxy, 4,
                  sizeof(::S800Map) );
      instance.SetNew(&new_S800Map);
      instance.SetNewArray(&newArray_S800Map);
      instance.SetDelete(&delete_S800Map);
      instance.SetDeleteArray(&deleteArray_S800Map);
      instance.SetDestructor(&destruct_S800Map);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Map*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Map*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Map*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800FpCrdcPads(void *p = nullptr);
   static void *newArray_S800FpCrdcPads(Long_t size, void *p);
   static void delete_S800FpCrdcPads(void *p);
   static void deleteArray_S800FpCrdcPads(void *p);
   static void destruct_S800FpCrdcPads(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800FpCrdcPads*)
   {
      ::S800FpCrdcPads *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800FpCrdcPads >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800FpCrdcPads", ::S800FpCrdcPads::Class_Version(), "include/S800Parameters.h", 218,
                  typeid(::S800FpCrdcPads), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800FpCrdcPads::Dictionary, isa_proxy, 4,
                  sizeof(::S800FpCrdcPads) );
      instance.SetNew(&new_S800FpCrdcPads);
      instance.SetNewArray(&newArray_S800FpCrdcPads);
      instance.SetDelete(&delete_S800FpCrdcPads);
      instance.SetDeleteArray(&deleteArray_S800FpCrdcPads);
      instance.SetDestructor(&destruct_S800FpCrdcPads);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800FpCrdcPads*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800FpCrdcPads*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800FpCrdcPads*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800FpCrdcCalc(void *p = nullptr);
   static void *newArray_S800FpCrdcCalc(Long_t size, void *p);
   static void delete_S800FpCrdcCalc(void *p);
   static void deleteArray_S800FpCrdcCalc(void *p);
   static void destruct_S800FpCrdcCalc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800FpCrdcCalc*)
   {
      ::S800FpCrdcCalc *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800FpCrdcCalc >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800FpCrdcCalc", ::S800FpCrdcCalc::Class_Version(), "include/S800Parameters.h", 283,
                  typeid(::S800FpCrdcCalc), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800FpCrdcCalc::Dictionary, isa_proxy, 4,
                  sizeof(::S800FpCrdcCalc) );
      instance.SetNew(&new_S800FpCrdcCalc);
      instance.SetNewArray(&newArray_S800FpCrdcCalc);
      instance.SetDelete(&delete_S800FpCrdcCalc);
      instance.SetDeleteArray(&deleteArray_S800FpCrdcCalc);
      instance.SetDestructor(&destruct_S800FpCrdcCalc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800FpCrdcCalc*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800FpCrdcCalc*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800FpCrdcCalc*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800FpCrdc(void *p = nullptr);
   static void *newArray_S800FpCrdc(Long_t size, void *p);
   static void delete_S800FpCrdc(void *p);
   static void deleteArray_S800FpCrdc(void *p);
   static void destruct_S800FpCrdc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800FpCrdc*)
   {
      ::S800FpCrdc *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800FpCrdc >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800FpCrdc", ::S800FpCrdc::Class_Version(), "include/S800Parameters.h", 353,
                  typeid(::S800FpCrdc), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800FpCrdc::Dictionary, isa_proxy, 4,
                  sizeof(::S800FpCrdc) );
      instance.SetNew(&new_S800FpCrdc);
      instance.SetNewArray(&newArray_S800FpCrdc);
      instance.SetDelete(&delete_S800FpCrdc);
      instance.SetDeleteArray(&deleteArray_S800FpCrdc);
      instance.SetDestructor(&destruct_S800FpCrdc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800FpCrdc*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800FpCrdc*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800FpCrdc*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Tppac(void *p = nullptr);
   static void *newArray_S800Tppac(Long_t size, void *p);
   static void delete_S800Tppac(void *p);
   static void deleteArray_S800Tppac(void *p);
   static void destruct_S800Tppac(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Tppac*)
   {
      ::S800Tppac *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Tppac >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Tppac", ::S800Tppac::Class_Version(), "include/S800Parameters.h", 391,
                  typeid(::S800Tppac), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Tppac::Dictionary, isa_proxy, 4,
                  sizeof(::S800Tppac) );
      instance.SetNew(&new_S800Tppac);
      instance.SetNewArray(&newArray_S800Tppac);
      instance.SetDelete(&delete_S800Tppac);
      instance.SetDeleteArray(&deleteArray_S800Tppac);
      instance.SetDestructor(&destruct_S800Tppac);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Tppac*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Tppac*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Tppac*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Track(void *p = nullptr);
   static void *newArray_S800Track(Long_t size, void *p);
   static void delete_S800Track(void *p);
   static void deleteArray_S800Track(void *p);
   static void destruct_S800Track(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Track*)
   {
      ::S800Track *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Track >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Track", ::S800Track::Class_Version(), "include/S800Parameters.h", 441,
                  typeid(::S800Track), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Track::Dictionary, isa_proxy, 4,
                  sizeof(::S800Track) );
      instance.SetNew(&new_S800Track);
      instance.SetNewArray(&newArray_S800Track);
      instance.SetDelete(&delete_S800Track);
      instance.SetDeleteArray(&deleteArray_S800Track);
      instance.SetDestructor(&destruct_S800Track);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Track*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Track*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Track*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800FpIonChamber(void *p = nullptr);
   static void *newArray_S800FpIonChamber(Long_t size, void *p);
   static void delete_S800FpIonChamber(void *p);
   static void deleteArray_S800FpIonChamber(void *p);
   static void destruct_S800FpIonChamber(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800FpIonChamber*)
   {
      ::S800FpIonChamber *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800FpIonChamber >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800FpIonChamber", ::S800FpIonChamber::Class_Version(), "include/S800Parameters.h", 511,
                  typeid(::S800FpIonChamber), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800FpIonChamber::Dictionary, isa_proxy, 4,
                  sizeof(::S800FpIonChamber) );
      instance.SetNew(&new_S800FpIonChamber);
      instance.SetNewArray(&newArray_S800FpIonChamber);
      instance.SetDelete(&delete_S800FpIonChamber);
      instance.SetDeleteArray(&deleteArray_S800FpIonChamber);
      instance.SetDestructor(&destruct_S800FpIonChamber);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800FpIonChamber*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800FpIonChamber*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800FpIonChamber*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800FpScintillator(void *p = nullptr);
   static void *newArray_S800FpScintillator(Long_t size, void *p);
   static void delete_S800FpScintillator(void *p);
   static void deleteArray_S800FpScintillator(void *p);
   static void destruct_S800FpScintillator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800FpScintillator*)
   {
      ::S800FpScintillator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800FpScintillator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800FpScintillator", ::S800FpScintillator::Class_Version(), "include/S800Parameters.h", 575,
                  typeid(::S800FpScintillator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800FpScintillator::Dictionary, isa_proxy, 4,
                  sizeof(::S800FpScintillator) );
      instance.SetNew(&new_S800FpScintillator);
      instance.SetNewArray(&newArray_S800FpScintillator);
      instance.SetDelete(&delete_S800FpScintillator);
      instance.SetDeleteArray(&deleteArray_S800FpScintillator);
      instance.SetDestructor(&destruct_S800FpScintillator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800FpScintillator*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800FpScintillator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800FpScintillator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800FpTrack(void *p = nullptr);
   static void *newArray_S800FpTrack(Long_t size, void *p);
   static void delete_S800FpTrack(void *p);
   static void deleteArray_S800FpTrack(void *p);
   static void destruct_S800FpTrack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800FpTrack*)
   {
      ::S800FpTrack *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800FpTrack >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800FpTrack", ::S800FpTrack::Class_Version(), "include/S800Parameters.h", 601,
                  typeid(::S800FpTrack), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800FpTrack::Dictionary, isa_proxy, 4,
                  sizeof(::S800FpTrack) );
      instance.SetNew(&new_S800FpTrack);
      instance.SetNewArray(&newArray_S800FpTrack);
      instance.SetDelete(&delete_S800FpTrack);
      instance.SetDeleteArray(&deleteArray_S800FpTrack);
      instance.SetDestructor(&destruct_S800FpTrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800FpTrack*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800FpTrack*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800FpTrack*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800FpHodo(void *p = nullptr);
   static void *newArray_S800FpHodo(Long_t size, void *p);
   static void delete_S800FpHodo(void *p);
   static void deleteArray_S800FpHodo(void *p);
   static void destruct_S800FpHodo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800FpHodo*)
   {
      ::S800FpHodo *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800FpHodo >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800FpHodo", ::S800FpHodo::Class_Version(), "include/S800Parameters.h", 660,
                  typeid(::S800FpHodo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800FpHodo::Dictionary, isa_proxy, 4,
                  sizeof(::S800FpHodo) );
      instance.SetNew(&new_S800FpHodo);
      instance.SetNewArray(&newArray_S800FpHodo);
      instance.SetDelete(&delete_S800FpHodo);
      instance.SetDeleteArray(&deleteArray_S800FpHodo);
      instance.SetDestructor(&destruct_S800FpHodo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800FpHodo*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800FpHodo*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800FpHodo*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800FocalPlane(void *p = nullptr);
   static void *newArray_S800FocalPlane(Long_t size, void *p);
   static void delete_S800FocalPlane(void *p);
   static void deleteArray_S800FocalPlane(void *p);
   static void destruct_S800FocalPlane(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800FocalPlane*)
   {
      ::S800FocalPlane *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800FocalPlane >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800FocalPlane", ::S800FocalPlane::Class_Version(), "include/S800Parameters.h", 712,
                  typeid(::S800FocalPlane), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800FocalPlane::Dictionary, isa_proxy, 4,
                  sizeof(::S800FocalPlane) );
      instance.SetNew(&new_S800FocalPlane);
      instance.SetNewArray(&newArray_S800FocalPlane);
      instance.SetDelete(&delete_S800FocalPlane);
      instance.SetDeleteArray(&deleteArray_S800FocalPlane);
      instance.SetDestructor(&destruct_S800FocalPlane);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800FocalPlane*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800FocalPlane*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800FocalPlane*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800ClassicPpac(void *p = nullptr);
   static void *newArray_S800ClassicPpac(Long_t size, void *p);
   static void delete_S800ClassicPpac(void *p);
   static void deleteArray_S800ClassicPpac(void *p);
   static void destruct_S800ClassicPpac(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800ClassicPpac*)
   {
      ::S800ClassicPpac *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800ClassicPpac >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800ClassicPpac", ::S800ClassicPpac::Class_Version(), "include/S800Parameters.h", 752,
                  typeid(::S800ClassicPpac), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800ClassicPpac::Dictionary, isa_proxy, 4,
                  sizeof(::S800ClassicPpac) );
      instance.SetNew(&new_S800ClassicPpac);
      instance.SetNewArray(&newArray_S800ClassicPpac);
      instance.SetDelete(&delete_S800ClassicPpac);
      instance.SetDeleteArray(&deleteArray_S800ClassicPpac);
      instance.SetDestructor(&destruct_S800ClassicPpac);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800ClassicPpac*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800ClassicPpac*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800ClassicPpac*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Image(void *p = nullptr);
   static void *newArray_S800Image(Long_t size, void *p);
   static void delete_S800Image(void *p);
   static void deleteArray_S800Image(void *p);
   static void destruct_S800Image(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Image*)
   {
      ::S800Image *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Image >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Image", ::S800Image::Class_Version(), "include/S800Parameters.h", 793,
                  typeid(::S800Image), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Image::Dictionary, isa_proxy, 4,
                  sizeof(::S800Image) );
      instance.SetNew(&new_S800Image);
      instance.SetNewArray(&newArray_S800Image);
      instance.SetDelete(&delete_S800Image);
      instance.SetDeleteArray(&deleteArray_S800Image);
      instance.SetDestructor(&destruct_S800Image);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Image*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Image*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Image*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800TimeStamp(void *p = nullptr);
   static void *newArray_S800TimeStamp(Long_t size, void *p);
   static void delete_S800TimeStamp(void *p);
   static void deleteArray_S800TimeStamp(void *p);
   static void destruct_S800TimeStamp(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800TimeStamp*)
   {
      ::S800TimeStamp *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800TimeStamp >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800TimeStamp", ::S800TimeStamp::Class_Version(), "include/S800Parameters.h", 838,
                  typeid(::S800TimeStamp), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800TimeStamp::Dictionary, isa_proxy, 4,
                  sizeof(::S800TimeStamp) );
      instance.SetNew(&new_S800TimeStamp);
      instance.SetNewArray(&newArray_S800TimeStamp);
      instance.SetDelete(&delete_S800TimeStamp);
      instance.SetDeleteArray(&deleteArray_S800TimeStamp);
      instance.SetDestructor(&destruct_S800TimeStamp);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800TimeStamp*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800TimeStamp*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800TimeStamp*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800EventNumber(void *p = nullptr);
   static void *newArray_S800EventNumber(Long_t size, void *p);
   static void delete_S800EventNumber(void *p);
   static void deleteArray_S800EventNumber(void *p);
   static void destruct_S800EventNumber(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800EventNumber*)
   {
      ::S800EventNumber *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800EventNumber >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800EventNumber", ::S800EventNumber::Class_Version(), "include/S800Parameters.h", 861,
                  typeid(::S800EventNumber), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800EventNumber::Dictionary, isa_proxy, 4,
                  sizeof(::S800EventNumber) );
      instance.SetNew(&new_S800EventNumber);
      instance.SetNewArray(&newArray_S800EventNumber);
      instance.SetDelete(&delete_S800EventNumber);
      instance.SetDeleteArray(&deleteArray_S800EventNumber);
      instance.SetDestructor(&destruct_S800EventNumber);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800EventNumber*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800EventNumber*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800EventNumber*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Trigger(void *p = nullptr);
   static void *newArray_S800Trigger(Long_t size, void *p);
   static void delete_S800Trigger(void *p);
   static void deleteArray_S800Trigger(void *p);
   static void destruct_S800Trigger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Trigger*)
   {
      ::S800Trigger *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Trigger >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Trigger", ::S800Trigger::Class_Version(), "include/S800Parameters.h", 894,
                  typeid(::S800Trigger), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Trigger::Dictionary, isa_proxy, 4,
                  sizeof(::S800Trigger) );
      instance.SetNew(&new_S800Trigger);
      instance.SetNewArray(&newArray_S800Trigger);
      instance.SetDelete(&delete_S800Trigger);
      instance.SetDeleteArray(&deleteArray_S800Trigger);
      instance.SetDestructor(&destruct_S800Trigger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Trigger*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Trigger*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Trigger*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800TimeOfFlight(void *p = nullptr);
   static void *newArray_S800TimeOfFlight(Long_t size, void *p);
   static void delete_S800TimeOfFlight(void *p);
   static void deleteArray_S800TimeOfFlight(void *p);
   static void destruct_S800TimeOfFlight(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800TimeOfFlight*)
   {
      ::S800TimeOfFlight *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800TimeOfFlight >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800TimeOfFlight", ::S800TimeOfFlight::Class_Version(), "include/S800Parameters.h", 962,
                  typeid(::S800TimeOfFlight), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800TimeOfFlight::Dictionary, isa_proxy, 4,
                  sizeof(::S800TimeOfFlight) );
      instance.SetNew(&new_S800TimeOfFlight);
      instance.SetNewArray(&newArray_S800TimeOfFlight);
      instance.SetDelete(&delete_S800TimeOfFlight);
      instance.SetDeleteArray(&deleteArray_S800TimeOfFlight);
      instance.SetDestructor(&destruct_S800TimeOfFlight);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800TimeOfFlight*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800TimeOfFlight*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800TimeOfFlight*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Pin(void *p = nullptr);
   static void *newArray_S800Pin(Long_t size, void *p);
   static void delete_S800Pin(void *p);
   static void deleteArray_S800Pin(void *p);
   static void destruct_S800Pin(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Pin*)
   {
      ::S800Pin *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Pin >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Pin", ::S800Pin::Class_Version(), "include/S800Parameters.h", 1079,
                  typeid(::S800Pin), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Pin::Dictionary, isa_proxy, 4,
                  sizeof(::S800Pin) );
      instance.SetNew(&new_S800Pin);
      instance.SetNewArray(&newArray_S800Pin);
      instance.SetDelete(&delete_S800Pin);
      instance.SetDeleteArray(&deleteArray_S800Pin);
      instance.SetDestructor(&destruct_S800Pin);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Pin*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Pin*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Pin*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800LaBr(void *p = nullptr);
   static void *newArray_S800LaBr(Long_t size, void *p);
   static void delete_S800LaBr(void *p);
   static void deleteArray_S800LaBr(void *p);
   static void destruct_S800LaBr(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800LaBr*)
   {
      ::S800LaBr *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800LaBr >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800LaBr", ::S800LaBr::Class_Version(), "include/S800Parameters.h", 1109,
                  typeid(::S800LaBr), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800LaBr::Dictionary, isa_proxy, 4,
                  sizeof(::S800LaBr) );
      instance.SetNew(&new_S800LaBr);
      instance.SetNewArray(&newArray_S800LaBr);
      instance.SetDelete(&delete_S800LaBr);
      instance.SetDeleteArray(&deleteArray_S800LaBr);
      instance.SetDestructor(&destruct_S800LaBr);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800LaBr*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800LaBr*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800LaBr*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Object(void *p = nullptr);
   static void *newArray_S800Object(Long_t size, void *p);
   static void delete_S800Object(void *p);
   static void deleteArray_S800Object(void *p);
   static void destruct_S800Object(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Object*)
   {
      ::S800Object *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Object >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Object", ::S800Object::Class_Version(), "include/S800Parameters.h", 1129,
                  typeid(::S800Object), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Object::Dictionary, isa_proxy, 4,
                  sizeof(::S800Object) );
      instance.SetNew(&new_S800Object);
      instance.SetNewArray(&newArray_S800Object);
      instance.SetDelete(&delete_S800Object);
      instance.SetDeleteArray(&deleteArray_S800Object);
      instance.SetDestructor(&destruct_S800Object);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Object*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Object*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Object*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Ppac(void *p = nullptr);
   static void *newArray_S800Ppac(Long_t size, void *p);
   static void delete_S800Ppac(void *p);
   static void deleteArray_S800Ppac(void *p);
   static void destruct_S800Ppac(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Ppac*)
   {
      ::S800Ppac *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Ppac >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Ppac", ::S800Ppac::Class_Version(), "include/S800Parameters.h", 1151,
                  typeid(::S800Ppac), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Ppac::Dictionary, isa_proxy, 4,
                  sizeof(::S800Ppac) );
      instance.SetNew(&new_S800Ppac);
      instance.SetNewArray(&newArray_S800Ppac);
      instance.SetDelete(&delete_S800Ppac);
      instance.SetDeleteArray(&deleteArray_S800Ppac);
      instance.SetDestructor(&destruct_S800Ppac);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Ppac*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Ppac*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Ppac*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Target(void *p = nullptr);
   static void *newArray_S800Target(Long_t size, void *p);
   static void delete_S800Target(void *p);
   static void deleteArray_S800Target(void *p);
   static void destruct_S800Target(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Target*)
   {
      ::S800Target *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Target >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Target", ::S800Target::Class_Version(), "include/S800Parameters.h", 1201,
                  typeid(::S800Target), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Target::Dictionary, isa_proxy, 4,
                  sizeof(::S800Target) );
      instance.SetNew(&new_S800Target);
      instance.SetNewArray(&newArray_S800Target);
      instance.SetDelete(&delete_S800Target);
      instance.SetDeleteArray(&deleteArray_S800Target);
      instance.SetDestructor(&destruct_S800Target);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Target*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Target*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Target*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *s800Phys_Dictionary();
   static void s800Phys_TClassManip(TClass*);
   static void *new_s800Phys(void *p = nullptr);
   static void *newArray_s800Phys(Long_t size, void *p);
   static void delete_s800Phys(void *p);
   static void deleteArray_s800Phys(void *p);
   static void destruct_s800Phys(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::s800Phys*)
   {
      ::s800Phys *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::s800Phys));
      static ::ROOT::TGenericClassInfo 
         instance("s800Phys", "include/S800Parameters.h", 1232,
                  typeid(::s800Phys), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &s800Phys_Dictionary, isa_proxy, 4,
                  sizeof(::s800Phys) );
      instance.SetNew(&new_s800Phys);
      instance.SetNewArray(&newArray_s800Phys);
      instance.SetDelete(&delete_s800Phys);
      instance.SetDeleteArray(&deleteArray_s800Phys);
      instance.SetDestructor(&destruct_s800Phys);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::s800Phys*)
   {
      return GenerateInitInstanceLocal(static_cast<::s800Phys*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::s800Phys*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *s800Phys_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::s800Phys*>(nullptr))->GetClass();
      s800Phys_TClassManip(theClass);
   return theClass;
   }

   static void s800Phys_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Physics(void *p = nullptr);
   static void *newArray_S800Physics(Long_t size, void *p);
   static void delete_S800Physics(void *p);
   static void deleteArray_S800Physics(void *p);
   static void destruct_S800Physics(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Physics*)
   {
      ::S800Physics *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Physics >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Physics", ::S800Physics::Class_Version(), "include/S800Parameters.h", 1253,
                  typeid(::S800Physics), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Physics::Dictionary, isa_proxy, 4,
                  sizeof(::S800Physics) );
      instance.SetNew(&new_S800Physics);
      instance.SetNewArray(&newArray_S800Physics);
      instance.SetDelete(&delete_S800Physics);
      instance.SetDeleteArray(&deleteArray_S800Physics);
      instance.SetDestructor(&destruct_S800Physics);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Physics*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Physics*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Physics*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Full(void *p = nullptr);
   static void *newArray_S800Full(Long_t size, void *p);
   static void delete_S800Full(void *p);
   static void deleteArray_S800Full(void *p);
   static void destruct_S800Full(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Full*)
   {
      ::S800Full *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Full >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Full", ::S800Full::Class_Version(), "include/S800Parameters.h", 1266,
                  typeid(::S800Full), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Full::Dictionary, isa_proxy, 4,
                  sizeof(::S800Full) );
      instance.SetNew(&new_S800Full);
      instance.SetNewArray(&newArray_S800Full);
      instance.SetDelete(&delete_S800Full);
      instance.SetDeleteArray(&deleteArray_S800Full);
      instance.SetDestructor(&destruct_S800Full);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Full*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Full*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Full*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_S800Scaler(void *p = nullptr);
   static void *newArray_S800Scaler(Long_t size, void *p);
   static void delete_S800Scaler(void *p);
   static void deleteArray_S800Scaler(void *p);
   static void destruct_S800Scaler(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S800Scaler*)
   {
      ::S800Scaler *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::S800Scaler >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("S800Scaler", ::S800Scaler::Class_Version(), "include/S800Parameters.h", 1324,
                  typeid(::S800Scaler), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::S800Scaler::Dictionary, isa_proxy, 4,
                  sizeof(::S800Scaler) );
      instance.SetNew(&new_S800Scaler);
      instance.SetNewArray(&newArray_S800Scaler);
      instance.SetDelete(&delete_S800Scaler);
      instance.SetDeleteArray(&deleteArray_S800Scaler);
      instance.SetDestructor(&destruct_S800Scaler);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S800Scaler*)
   {
      return GenerateInitInstanceLocal(static_cast<::S800Scaler*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::S800Scaler*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr S800ImMap::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800ImMap::Class_Name()
{
   return "S800ImMap";
}

//______________________________________________________________________________
const char *S800ImMap::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800ImMap*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800ImMap::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800ImMap*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800ImMap::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800ImMap*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800ImMap::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800ImMap*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Map::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Map::Class_Name()
{
   return "S800Map";
}

//______________________________________________________________________________
const char *S800Map::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Map*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Map::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Map*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Map::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Map*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Map::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Map*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800FpCrdcPads::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800FpCrdcPads::Class_Name()
{
   return "S800FpCrdcPads";
}

//______________________________________________________________________________
const char *S800FpCrdcPads::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdcPads*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800FpCrdcPads::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdcPads*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800FpCrdcPads::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdcPads*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800FpCrdcPads::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdcPads*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800FpCrdcCalc::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800FpCrdcCalc::Class_Name()
{
   return "S800FpCrdcCalc";
}

//______________________________________________________________________________
const char *S800FpCrdcCalc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdcCalc*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800FpCrdcCalc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdcCalc*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800FpCrdcCalc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdcCalc*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800FpCrdcCalc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdcCalc*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800FpCrdc::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800FpCrdc::Class_Name()
{
   return "S800FpCrdc";
}

//______________________________________________________________________________
const char *S800FpCrdc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdc*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800FpCrdc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdc*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800FpCrdc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdc*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800FpCrdc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpCrdc*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Tppac::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Tppac::Class_Name()
{
   return "S800Tppac";
}

//______________________________________________________________________________
const char *S800Tppac::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Tppac*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Tppac::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Tppac*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Tppac::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Tppac*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Tppac::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Tppac*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Track::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Track::Class_Name()
{
   return "S800Track";
}

//______________________________________________________________________________
const char *S800Track::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Track*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Track::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Track*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Track::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Track*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Track::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Track*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800FpIonChamber::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800FpIonChamber::Class_Name()
{
   return "S800FpIonChamber";
}

//______________________________________________________________________________
const char *S800FpIonChamber::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpIonChamber*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800FpIonChamber::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpIonChamber*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800FpIonChamber::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpIonChamber*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800FpIonChamber::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpIonChamber*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800FpScintillator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800FpScintillator::Class_Name()
{
   return "S800FpScintillator";
}

//______________________________________________________________________________
const char *S800FpScintillator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpScintillator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800FpScintillator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpScintillator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800FpScintillator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpScintillator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800FpScintillator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpScintillator*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800FpTrack::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800FpTrack::Class_Name()
{
   return "S800FpTrack";
}

//______________________________________________________________________________
const char *S800FpTrack::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpTrack*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800FpTrack::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpTrack*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800FpTrack::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpTrack*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800FpTrack::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpTrack*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800FpHodo::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800FpHodo::Class_Name()
{
   return "S800FpHodo";
}

//______________________________________________________________________________
const char *S800FpHodo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpHodo*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800FpHodo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FpHodo*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800FpHodo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpHodo*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800FpHodo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FpHodo*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800FocalPlane::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800FocalPlane::Class_Name()
{
   return "S800FocalPlane";
}

//______________________________________________________________________________
const char *S800FocalPlane::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FocalPlane*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800FocalPlane::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800FocalPlane*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800FocalPlane::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FocalPlane*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800FocalPlane::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800FocalPlane*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800ClassicPpac::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800ClassicPpac::Class_Name()
{
   return "S800ClassicPpac";
}

//______________________________________________________________________________
const char *S800ClassicPpac::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800ClassicPpac*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800ClassicPpac::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800ClassicPpac*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800ClassicPpac::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800ClassicPpac*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800ClassicPpac::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800ClassicPpac*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Image::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Image::Class_Name()
{
   return "S800Image";
}

//______________________________________________________________________________
const char *S800Image::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Image*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Image::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Image*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Image::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Image*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Image::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Image*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800TimeStamp::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800TimeStamp::Class_Name()
{
   return "S800TimeStamp";
}

//______________________________________________________________________________
const char *S800TimeStamp::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800TimeStamp*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800TimeStamp::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800TimeStamp*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800TimeStamp::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800TimeStamp*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800TimeStamp::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800TimeStamp*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800EventNumber::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800EventNumber::Class_Name()
{
   return "S800EventNumber";
}

//______________________________________________________________________________
const char *S800EventNumber::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800EventNumber*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800EventNumber::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800EventNumber*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800EventNumber::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800EventNumber*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800EventNumber::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800EventNumber*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Trigger::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Trigger::Class_Name()
{
   return "S800Trigger";
}

//______________________________________________________________________________
const char *S800Trigger::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Trigger*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Trigger::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Trigger*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Trigger::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Trigger*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Trigger::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Trigger*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800TimeOfFlight::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800TimeOfFlight::Class_Name()
{
   return "S800TimeOfFlight";
}

//______________________________________________________________________________
const char *S800TimeOfFlight::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800TimeOfFlight*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800TimeOfFlight::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800TimeOfFlight*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800TimeOfFlight::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800TimeOfFlight*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800TimeOfFlight::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800TimeOfFlight*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Pin::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Pin::Class_Name()
{
   return "S800Pin";
}

//______________________________________________________________________________
const char *S800Pin::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Pin*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Pin::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Pin*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Pin::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Pin*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Pin::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Pin*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800LaBr::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800LaBr::Class_Name()
{
   return "S800LaBr";
}

//______________________________________________________________________________
const char *S800LaBr::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800LaBr*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800LaBr::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800LaBr*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800LaBr::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800LaBr*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800LaBr::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800LaBr*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Object::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Object::Class_Name()
{
   return "S800Object";
}

//______________________________________________________________________________
const char *S800Object::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Object*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Object::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Object*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Object::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Object*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Object::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Object*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Ppac::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Ppac::Class_Name()
{
   return "S800Ppac";
}

//______________________________________________________________________________
const char *S800Ppac::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Ppac*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Ppac::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Ppac*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Ppac::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Ppac*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Ppac::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Ppac*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Target::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Target::Class_Name()
{
   return "S800Target";
}

//______________________________________________________________________________
const char *S800Target::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Target*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Target::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Target*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Target::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Target*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Target::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Target*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Physics::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Physics::Class_Name()
{
   return "S800Physics";
}

//______________________________________________________________________________
const char *S800Physics::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Physics*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Physics::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Physics*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Physics::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Physics*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Physics::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Physics*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Full::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Full::Class_Name()
{
   return "S800Full";
}

//______________________________________________________________________________
const char *S800Full::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Full*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Full::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Full*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Full::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Full*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Full::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Full*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr S800Scaler::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *S800Scaler::Class_Name()
{
   return "S800Scaler";
}

//______________________________________________________________________________
const char *S800Scaler::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Scaler*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int S800Scaler::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::S800Scaler*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *S800Scaler::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Scaler*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *S800Scaler::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::S800Scaler*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void S800ImMap::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800ImMap.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800ImMap::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800ImMap::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800ImMap(void *p) {
      return  p ? new(p) ::S800ImMap : new ::S800ImMap;
   }
   static void *newArray_S800ImMap(Long_t nElements, void *p) {
      return p ? new(p) ::S800ImMap[nElements] : new ::S800ImMap[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800ImMap(void *p) {
      delete (static_cast<::S800ImMap*>(p));
   }
   static void deleteArray_S800ImMap(void *p) {
      delete [] (static_cast<::S800ImMap*>(p));
   }
   static void destruct_S800ImMap(void *p) {
      typedef ::S800ImMap current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800ImMap

//______________________________________________________________________________
void S800Map::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Map.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Map::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Map::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Map(void *p) {
      return  p ? new(p) ::S800Map : new ::S800Map;
   }
   static void *newArray_S800Map(Long_t nElements, void *p) {
      return p ? new(p) ::S800Map[nElements] : new ::S800Map[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Map(void *p) {
      delete (static_cast<::S800Map*>(p));
   }
   static void deleteArray_S800Map(void *p) {
      delete [] (static_cast<::S800Map*>(p));
   }
   static void destruct_S800Map(void *p) {
      typedef ::S800Map current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Map

//______________________________________________________________________________
void S800FpCrdcPads::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800FpCrdcPads.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800FpCrdcPads::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800FpCrdcPads::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800FpCrdcPads(void *p) {
      return  p ? new(p) ::S800FpCrdcPads : new ::S800FpCrdcPads;
   }
   static void *newArray_S800FpCrdcPads(Long_t nElements, void *p) {
      return p ? new(p) ::S800FpCrdcPads[nElements] : new ::S800FpCrdcPads[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800FpCrdcPads(void *p) {
      delete (static_cast<::S800FpCrdcPads*>(p));
   }
   static void deleteArray_S800FpCrdcPads(void *p) {
      delete [] (static_cast<::S800FpCrdcPads*>(p));
   }
   static void destruct_S800FpCrdcPads(void *p) {
      typedef ::S800FpCrdcPads current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800FpCrdcPads

//______________________________________________________________________________
void S800FpCrdcCalc::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800FpCrdcCalc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800FpCrdcCalc::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800FpCrdcCalc::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800FpCrdcCalc(void *p) {
      return  p ? new(p) ::S800FpCrdcCalc : new ::S800FpCrdcCalc;
   }
   static void *newArray_S800FpCrdcCalc(Long_t nElements, void *p) {
      return p ? new(p) ::S800FpCrdcCalc[nElements] : new ::S800FpCrdcCalc[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800FpCrdcCalc(void *p) {
      delete (static_cast<::S800FpCrdcCalc*>(p));
   }
   static void deleteArray_S800FpCrdcCalc(void *p) {
      delete [] (static_cast<::S800FpCrdcCalc*>(p));
   }
   static void destruct_S800FpCrdcCalc(void *p) {
      typedef ::S800FpCrdcCalc current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800FpCrdcCalc

//______________________________________________________________________________
void S800FpCrdc::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800FpCrdc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800FpCrdc::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800FpCrdc::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800FpCrdc(void *p) {
      return  p ? new(p) ::S800FpCrdc : new ::S800FpCrdc;
   }
   static void *newArray_S800FpCrdc(Long_t nElements, void *p) {
      return p ? new(p) ::S800FpCrdc[nElements] : new ::S800FpCrdc[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800FpCrdc(void *p) {
      delete (static_cast<::S800FpCrdc*>(p));
   }
   static void deleteArray_S800FpCrdc(void *p) {
      delete [] (static_cast<::S800FpCrdc*>(p));
   }
   static void destruct_S800FpCrdc(void *p) {
      typedef ::S800FpCrdc current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800FpCrdc

//______________________________________________________________________________
void S800Tppac::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Tppac.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Tppac::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Tppac::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Tppac(void *p) {
      return  p ? new(p) ::S800Tppac : new ::S800Tppac;
   }
   static void *newArray_S800Tppac(Long_t nElements, void *p) {
      return p ? new(p) ::S800Tppac[nElements] : new ::S800Tppac[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Tppac(void *p) {
      delete (static_cast<::S800Tppac*>(p));
   }
   static void deleteArray_S800Tppac(void *p) {
      delete [] (static_cast<::S800Tppac*>(p));
   }
   static void destruct_S800Tppac(void *p) {
      typedef ::S800Tppac current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Tppac

//______________________________________________________________________________
void S800Track::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Track.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Track::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Track::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Track(void *p) {
      return  p ? new(p) ::S800Track : new ::S800Track;
   }
   static void *newArray_S800Track(Long_t nElements, void *p) {
      return p ? new(p) ::S800Track[nElements] : new ::S800Track[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Track(void *p) {
      delete (static_cast<::S800Track*>(p));
   }
   static void deleteArray_S800Track(void *p) {
      delete [] (static_cast<::S800Track*>(p));
   }
   static void destruct_S800Track(void *p) {
      typedef ::S800Track current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Track

//______________________________________________________________________________
void S800FpIonChamber::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800FpIonChamber.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800FpIonChamber::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800FpIonChamber::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800FpIonChamber(void *p) {
      return  p ? new(p) ::S800FpIonChamber : new ::S800FpIonChamber;
   }
   static void *newArray_S800FpIonChamber(Long_t nElements, void *p) {
      return p ? new(p) ::S800FpIonChamber[nElements] : new ::S800FpIonChamber[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800FpIonChamber(void *p) {
      delete (static_cast<::S800FpIonChamber*>(p));
   }
   static void deleteArray_S800FpIonChamber(void *p) {
      delete [] (static_cast<::S800FpIonChamber*>(p));
   }
   static void destruct_S800FpIonChamber(void *p) {
      typedef ::S800FpIonChamber current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800FpIonChamber

//______________________________________________________________________________
void S800FpScintillator::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800FpScintillator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800FpScintillator::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800FpScintillator::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800FpScintillator(void *p) {
      return  p ? new(p) ::S800FpScintillator : new ::S800FpScintillator;
   }
   static void *newArray_S800FpScintillator(Long_t nElements, void *p) {
      return p ? new(p) ::S800FpScintillator[nElements] : new ::S800FpScintillator[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800FpScintillator(void *p) {
      delete (static_cast<::S800FpScintillator*>(p));
   }
   static void deleteArray_S800FpScintillator(void *p) {
      delete [] (static_cast<::S800FpScintillator*>(p));
   }
   static void destruct_S800FpScintillator(void *p) {
      typedef ::S800FpScintillator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800FpScintillator

//______________________________________________________________________________
void S800FpTrack::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800FpTrack.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800FpTrack::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800FpTrack::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800FpTrack(void *p) {
      return  p ? new(p) ::S800FpTrack : new ::S800FpTrack;
   }
   static void *newArray_S800FpTrack(Long_t nElements, void *p) {
      return p ? new(p) ::S800FpTrack[nElements] : new ::S800FpTrack[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800FpTrack(void *p) {
      delete (static_cast<::S800FpTrack*>(p));
   }
   static void deleteArray_S800FpTrack(void *p) {
      delete [] (static_cast<::S800FpTrack*>(p));
   }
   static void destruct_S800FpTrack(void *p) {
      typedef ::S800FpTrack current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800FpTrack

//______________________________________________________________________________
void S800FpHodo::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800FpHodo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800FpHodo::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800FpHodo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800FpHodo(void *p) {
      return  p ? new(p) ::S800FpHodo : new ::S800FpHodo;
   }
   static void *newArray_S800FpHodo(Long_t nElements, void *p) {
      return p ? new(p) ::S800FpHodo[nElements] : new ::S800FpHodo[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800FpHodo(void *p) {
      delete (static_cast<::S800FpHodo*>(p));
   }
   static void deleteArray_S800FpHodo(void *p) {
      delete [] (static_cast<::S800FpHodo*>(p));
   }
   static void destruct_S800FpHodo(void *p) {
      typedef ::S800FpHodo current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800FpHodo

//______________________________________________________________________________
void S800FocalPlane::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800FocalPlane.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800FocalPlane::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800FocalPlane::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800FocalPlane(void *p) {
      return  p ? new(p) ::S800FocalPlane : new ::S800FocalPlane;
   }
   static void *newArray_S800FocalPlane(Long_t nElements, void *p) {
      return p ? new(p) ::S800FocalPlane[nElements] : new ::S800FocalPlane[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800FocalPlane(void *p) {
      delete (static_cast<::S800FocalPlane*>(p));
   }
   static void deleteArray_S800FocalPlane(void *p) {
      delete [] (static_cast<::S800FocalPlane*>(p));
   }
   static void destruct_S800FocalPlane(void *p) {
      typedef ::S800FocalPlane current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800FocalPlane

//______________________________________________________________________________
void S800ClassicPpac::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800ClassicPpac.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800ClassicPpac::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800ClassicPpac::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800ClassicPpac(void *p) {
      return  p ? new(p) ::S800ClassicPpac : new ::S800ClassicPpac;
   }
   static void *newArray_S800ClassicPpac(Long_t nElements, void *p) {
      return p ? new(p) ::S800ClassicPpac[nElements] : new ::S800ClassicPpac[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800ClassicPpac(void *p) {
      delete (static_cast<::S800ClassicPpac*>(p));
   }
   static void deleteArray_S800ClassicPpac(void *p) {
      delete [] (static_cast<::S800ClassicPpac*>(p));
   }
   static void destruct_S800ClassicPpac(void *p) {
      typedef ::S800ClassicPpac current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800ClassicPpac

//______________________________________________________________________________
void S800Image::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Image.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Image::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Image::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Image(void *p) {
      return  p ? new(p) ::S800Image : new ::S800Image;
   }
   static void *newArray_S800Image(Long_t nElements, void *p) {
      return p ? new(p) ::S800Image[nElements] : new ::S800Image[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Image(void *p) {
      delete (static_cast<::S800Image*>(p));
   }
   static void deleteArray_S800Image(void *p) {
      delete [] (static_cast<::S800Image*>(p));
   }
   static void destruct_S800Image(void *p) {
      typedef ::S800Image current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Image

//______________________________________________________________________________
void S800TimeStamp::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800TimeStamp.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800TimeStamp::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800TimeStamp::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800TimeStamp(void *p) {
      return  p ? new(p) ::S800TimeStamp : new ::S800TimeStamp;
   }
   static void *newArray_S800TimeStamp(Long_t nElements, void *p) {
      return p ? new(p) ::S800TimeStamp[nElements] : new ::S800TimeStamp[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800TimeStamp(void *p) {
      delete (static_cast<::S800TimeStamp*>(p));
   }
   static void deleteArray_S800TimeStamp(void *p) {
      delete [] (static_cast<::S800TimeStamp*>(p));
   }
   static void destruct_S800TimeStamp(void *p) {
      typedef ::S800TimeStamp current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800TimeStamp

//______________________________________________________________________________
void S800EventNumber::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800EventNumber.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800EventNumber::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800EventNumber::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800EventNumber(void *p) {
      return  p ? new(p) ::S800EventNumber : new ::S800EventNumber;
   }
   static void *newArray_S800EventNumber(Long_t nElements, void *p) {
      return p ? new(p) ::S800EventNumber[nElements] : new ::S800EventNumber[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800EventNumber(void *p) {
      delete (static_cast<::S800EventNumber*>(p));
   }
   static void deleteArray_S800EventNumber(void *p) {
      delete [] (static_cast<::S800EventNumber*>(p));
   }
   static void destruct_S800EventNumber(void *p) {
      typedef ::S800EventNumber current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800EventNumber

//______________________________________________________________________________
void S800Trigger::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Trigger.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Trigger::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Trigger::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Trigger(void *p) {
      return  p ? new(p) ::S800Trigger : new ::S800Trigger;
   }
   static void *newArray_S800Trigger(Long_t nElements, void *p) {
      return p ? new(p) ::S800Trigger[nElements] : new ::S800Trigger[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Trigger(void *p) {
      delete (static_cast<::S800Trigger*>(p));
   }
   static void deleteArray_S800Trigger(void *p) {
      delete [] (static_cast<::S800Trigger*>(p));
   }
   static void destruct_S800Trigger(void *p) {
      typedef ::S800Trigger current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Trigger

//______________________________________________________________________________
void S800TimeOfFlight::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800TimeOfFlight.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800TimeOfFlight::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800TimeOfFlight::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800TimeOfFlight(void *p) {
      return  p ? new(p) ::S800TimeOfFlight : new ::S800TimeOfFlight;
   }
   static void *newArray_S800TimeOfFlight(Long_t nElements, void *p) {
      return p ? new(p) ::S800TimeOfFlight[nElements] : new ::S800TimeOfFlight[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800TimeOfFlight(void *p) {
      delete (static_cast<::S800TimeOfFlight*>(p));
   }
   static void deleteArray_S800TimeOfFlight(void *p) {
      delete [] (static_cast<::S800TimeOfFlight*>(p));
   }
   static void destruct_S800TimeOfFlight(void *p) {
      typedef ::S800TimeOfFlight current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800TimeOfFlight

//______________________________________________________________________________
void S800Pin::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Pin.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Pin::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Pin::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Pin(void *p) {
      return  p ? new(p) ::S800Pin : new ::S800Pin;
   }
   static void *newArray_S800Pin(Long_t nElements, void *p) {
      return p ? new(p) ::S800Pin[nElements] : new ::S800Pin[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Pin(void *p) {
      delete (static_cast<::S800Pin*>(p));
   }
   static void deleteArray_S800Pin(void *p) {
      delete [] (static_cast<::S800Pin*>(p));
   }
   static void destruct_S800Pin(void *p) {
      typedef ::S800Pin current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Pin

//______________________________________________________________________________
void S800LaBr::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800LaBr.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800LaBr::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800LaBr::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800LaBr(void *p) {
      return  p ? new(p) ::S800LaBr : new ::S800LaBr;
   }
   static void *newArray_S800LaBr(Long_t nElements, void *p) {
      return p ? new(p) ::S800LaBr[nElements] : new ::S800LaBr[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800LaBr(void *p) {
      delete (static_cast<::S800LaBr*>(p));
   }
   static void deleteArray_S800LaBr(void *p) {
      delete [] (static_cast<::S800LaBr*>(p));
   }
   static void destruct_S800LaBr(void *p) {
      typedef ::S800LaBr current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800LaBr

//______________________________________________________________________________
void S800Object::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Object.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Object::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Object::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Object(void *p) {
      return  p ? new(p) ::S800Object : new ::S800Object;
   }
   static void *newArray_S800Object(Long_t nElements, void *p) {
      return p ? new(p) ::S800Object[nElements] : new ::S800Object[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Object(void *p) {
      delete (static_cast<::S800Object*>(p));
   }
   static void deleteArray_S800Object(void *p) {
      delete [] (static_cast<::S800Object*>(p));
   }
   static void destruct_S800Object(void *p) {
      typedef ::S800Object current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Object

//______________________________________________________________________________
void S800Ppac::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Ppac.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Ppac::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Ppac::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Ppac(void *p) {
      return  p ? new(p) ::S800Ppac : new ::S800Ppac;
   }
   static void *newArray_S800Ppac(Long_t nElements, void *p) {
      return p ? new(p) ::S800Ppac[nElements] : new ::S800Ppac[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Ppac(void *p) {
      delete (static_cast<::S800Ppac*>(p));
   }
   static void deleteArray_S800Ppac(void *p) {
      delete [] (static_cast<::S800Ppac*>(p));
   }
   static void destruct_S800Ppac(void *p) {
      typedef ::S800Ppac current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Ppac

//______________________________________________________________________________
void S800Target::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Target.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Target::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Target::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Target(void *p) {
      return  p ? new(p) ::S800Target : new ::S800Target;
   }
   static void *newArray_S800Target(Long_t nElements, void *p) {
      return p ? new(p) ::S800Target[nElements] : new ::S800Target[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Target(void *p) {
      delete (static_cast<::S800Target*>(p));
   }
   static void deleteArray_S800Target(void *p) {
      delete [] (static_cast<::S800Target*>(p));
   }
   static void destruct_S800Target(void *p) {
      typedef ::S800Target current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Target

namespace ROOT {
   // Wrappers around operator new
   static void *new_s800Phys(void *p) {
      return  p ? new(p) ::s800Phys : new ::s800Phys;
   }
   static void *newArray_s800Phys(Long_t nElements, void *p) {
      return p ? new(p) ::s800Phys[nElements] : new ::s800Phys[nElements];
   }
   // Wrapper around operator delete
   static void delete_s800Phys(void *p) {
      delete (static_cast<::s800Phys*>(p));
   }
   static void deleteArray_s800Phys(void *p) {
      delete [] (static_cast<::s800Phys*>(p));
   }
   static void destruct_s800Phys(void *p) {
      typedef ::s800Phys current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::s800Phys

//______________________________________________________________________________
void S800Physics::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Physics.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Physics::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Physics::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Physics(void *p) {
      return  p ? new(p) ::S800Physics : new ::S800Physics;
   }
   static void *newArray_S800Physics(Long_t nElements, void *p) {
      return p ? new(p) ::S800Physics[nElements] : new ::S800Physics[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Physics(void *p) {
      delete (static_cast<::S800Physics*>(p));
   }
   static void deleteArray_S800Physics(void *p) {
      delete [] (static_cast<::S800Physics*>(p));
   }
   static void destruct_S800Physics(void *p) {
      typedef ::S800Physics current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Physics

//______________________________________________________________________________
void S800Full::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Full.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Full::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Full::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Full(void *p) {
      return  p ? new(p) ::S800Full : new ::S800Full;
   }
   static void *newArray_S800Full(Long_t nElements, void *p) {
      return p ? new(p) ::S800Full[nElements] : new ::S800Full[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Full(void *p) {
      delete (static_cast<::S800Full*>(p));
   }
   static void deleteArray_S800Full(void *p) {
      delete [] (static_cast<::S800Full*>(p));
   }
   static void destruct_S800Full(void *p) {
      typedef ::S800Full current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Full

//______________________________________________________________________________
void S800Scaler::Streamer(TBuffer &R__b)
{
   // Stream an object of class S800Scaler.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(S800Scaler::Class(),this);
   } else {
      R__b.WriteClassBuffer(S800Scaler::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_S800Scaler(void *p) {
      return  p ? new(p) ::S800Scaler : new ::S800Scaler;
   }
   static void *newArray_S800Scaler(Long_t nElements, void *p) {
      return p ? new(p) ::S800Scaler[nElements] : new ::S800Scaler[nElements];
   }
   // Wrapper around operator delete
   static void delete_S800Scaler(void *p) {
      delete (static_cast<::S800Scaler*>(p));
   }
   static void deleteArray_S800Scaler(void *p) {
      delete [] (static_cast<::S800Scaler*>(p));
   }
   static void destruct_S800Scaler(void *p) {
      typedef ::S800Scaler current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::S800Scaler

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = nullptr);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 389,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr))->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete (static_cast<vector<int>*>(p));
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] (static_cast<vector<int>*>(p));
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = nullptr);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 389,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr))->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete (static_cast<vector<double>*>(p));
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] (static_cast<vector<double>*>(p));
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlETStringgR_Dictionary();
   static void vectorlETStringgR_TClassManip(TClass*);
   static void *new_vectorlETStringgR(void *p = nullptr);
   static void *newArray_vectorlETStringgR(Long_t size, void *p);
   static void delete_vectorlETStringgR(void *p);
   static void deleteArray_vectorlETStringgR(void *p);
   static void destruct_vectorlETStringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TString>*)
   {
      vector<TString> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TString>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TString>", -2, "vector", 389,
                  typeid(vector<TString>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETStringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TString>) );
      instance.SetNew(&new_vectorlETStringgR);
      instance.SetNewArray(&newArray_vectorlETStringgR);
      instance.SetDelete(&delete_vectorlETStringgR);
      instance.SetDeleteArray(&deleteArray_vectorlETStringgR);
      instance.SetDestructor(&destruct_vectorlETStringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TString> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TString>","std::vector<TString, std::allocator<TString> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TString>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETStringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TString>*>(nullptr))->GetClass();
      vectorlETStringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETStringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETStringgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TString> : new vector<TString>;
   }
   static void *newArray_vectorlETStringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TString>[nElements] : new vector<TString>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETStringgR(void *p) {
      delete (static_cast<vector<TString>*>(p));
   }
   static void deleteArray_vectorlETStringgR(void *p) {
      delete [] (static_cast<vector<TString>*>(p));
   }
   static void destruct_vectorlETStringgR(void *p) {
      typedef vector<TString> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TString>

namespace {
  void TriggerDictionaryInitialization_S800Dict_Impl() {
    static const char* headers[] = {
"include/S800Parameters.h",
nullptr
    };
    static const char* includePaths[] = {
"/opt/root-6.28.06/include/",
"/home/sud/Desktop/Software/goddessSort/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "S800Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800ImMap;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Map;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800FpCrdcPads;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800FpCrdcCalc;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800FpCrdc;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Tppac;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Track;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800FpIonChamber;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800FpScintillator;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800FpTrack;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800FpHodo;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800FocalPlane;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800ClassicPpac;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Image;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800TimeStamp;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800EventNumber;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Trigger;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800TimeOfFlight;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Pin;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800LaBr;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Object;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Ppac;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Target;
struct __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  s800Phys;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Physics;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Full;
class __attribute__((annotate("$clingAutoload$include/S800Parameters.h")))  S800Scaler;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "S800Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "include/S800Parameters.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"S800ClassicPpac", payloadCode, "@",
"S800EventNumber", payloadCode, "@",
"S800FocalPlane", payloadCode, "@",
"S800FpCrdc", payloadCode, "@",
"S800FpCrdcCalc", payloadCode, "@",
"S800FpCrdcPads", payloadCode, "@",
"S800FpHodo", payloadCode, "@",
"S800FpIonChamber", payloadCode, "@",
"S800FpScintillator", payloadCode, "@",
"S800FpTrack", payloadCode, "@",
"S800Full", payloadCode, "@",
"S800ImMap", payloadCode, "@",
"S800Image", payloadCode, "@",
"S800LaBr", payloadCode, "@",
"S800Map", payloadCode, "@",
"S800Object", payloadCode, "@",
"S800Physics", payloadCode, "@",
"S800Pin", payloadCode, "@",
"S800Ppac", payloadCode, "@",
"S800Scaler", payloadCode, "@",
"S800Target", payloadCode, "@",
"S800TimeOfFlight", payloadCode, "@",
"S800TimeStamp", payloadCode, "@",
"S800Tppac", payloadCode, "@",
"S800Track", payloadCode, "@",
"S800Trigger", payloadCode, "@",
"s800Phys", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("S800Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_S800Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_S800Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_S800Dict() {
  TriggerDictionaryInitialization_S800Dict_Impl();
}
