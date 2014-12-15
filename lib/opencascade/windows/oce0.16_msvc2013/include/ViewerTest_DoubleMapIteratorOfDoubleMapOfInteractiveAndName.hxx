// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ViewerTest_DoubleMapIteratorOfDoubleMapOfInteractiveAndName_HeaderFile
#define _ViewerTest_DoubleMapIteratorOfDoubleMapOfInteractiveAndName_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMapIterator_HeaderFile
#include <TCollection_BasicMapIterator.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Handle_ViewerTest_DoubleMapNodeOfDoubleMapOfInteractiveAndName_HeaderFile
#include <Handle_ViewerTest_DoubleMapNodeOfDoubleMapOfInteractiveAndName.hxx>
#endif
class Standard_NoSuchObject;
class Standard_Transient;
class TCollection_AsciiString;
class TColStd_MapTransientHasher;
class ViewerTest_DoubleMapOfInteractiveAndName;
class ViewerTest_DoubleMapNodeOfDoubleMapOfInteractiveAndName;



class ViewerTest_DoubleMapIteratorOfDoubleMapOfInteractiveAndName  : public TCollection_BasicMapIterator {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   ViewerTest_DoubleMapIteratorOfDoubleMapOfInteractiveAndName();
  
  Standard_EXPORT   ViewerTest_DoubleMapIteratorOfDoubleMapOfInteractiveAndName(const ViewerTest_DoubleMapOfInteractiveAndName& aMap);
  
  Standard_EXPORT     void Initialize(const ViewerTest_DoubleMapOfInteractiveAndName& aMap) ;
  
  Standard_EXPORT    const Handle_Standard_Transient& Key1() const;
  
  Standard_EXPORT    const TCollection_AsciiString& Key2() const;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif