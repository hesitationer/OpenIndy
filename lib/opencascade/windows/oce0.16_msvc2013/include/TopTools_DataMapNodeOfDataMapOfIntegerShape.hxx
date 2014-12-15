// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopTools_DataMapNodeOfDataMapOfIntegerShape_HeaderFile
#define _TopTools_DataMapNodeOfDataMapOfIntegerShape_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_TopTools_DataMapNodeOfDataMapOfIntegerShape_HeaderFile
#include <Handle_TopTools_DataMapNodeOfDataMapOfIntegerShape.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class TopoDS_Shape;
class TColStd_MapIntegerHasher;
class TopTools_DataMapOfIntegerShape;
class TopTools_DataMapIteratorOfDataMapOfIntegerShape;



class TopTools_DataMapNodeOfDataMapOfIntegerShape : public TCollection_MapNode {

public:

  
      TopTools_DataMapNodeOfDataMapOfIntegerShape(const Standard_Integer& K,const TopoDS_Shape& I,const TCollection_MapNodePtr& n);
  
        Standard_Integer& Key() const;
  
        TopoDS_Shape& Value() const;




  DEFINE_STANDARD_RTTI(TopTools_DataMapNodeOfDataMapOfIntegerShape)

protected:




private: 


Standard_Integer myKey;
TopoDS_Shape myValue;


};

#define TheKey Standard_Integer
#define TheKey_hxx <Standard_Integer.hxx>
#define TheItem TopoDS_Shape
#define TheItem_hxx <TopoDS_Shape.hxx>
#define Hasher TColStd_MapIntegerHasher
#define Hasher_hxx <TColStd_MapIntegerHasher.hxx>
#define TCollection_DataMapNode TopTools_DataMapNodeOfDataMapOfIntegerShape
#define TCollection_DataMapNode_hxx <TopTools_DataMapNodeOfDataMapOfIntegerShape.hxx>
#define TCollection_DataMapIterator TopTools_DataMapIteratorOfDataMapOfIntegerShape
#define TCollection_DataMapIterator_hxx <TopTools_DataMapIteratorOfDataMapOfIntegerShape.hxx>
#define Handle_TCollection_DataMapNode Handle_TopTools_DataMapNodeOfDataMapOfIntegerShape
#define TCollection_DataMapNode_Type_() TopTools_DataMapNodeOfDataMapOfIntegerShape_Type_()
#define TCollection_DataMap TopTools_DataMapOfIntegerShape
#define TCollection_DataMap_hxx <TopTools_DataMapOfIntegerShape.hxx>

#include <TCollection_DataMapNode.lxx>

#undef TheKey
#undef TheKey_hxx
#undef TheItem
#undef TheItem_hxx
#undef Hasher
#undef Hasher_hxx
#undef TCollection_DataMapNode
#undef TCollection_DataMapNode_hxx
#undef TCollection_DataMapIterator
#undef TCollection_DataMapIterator_hxx
#undef Handle_TCollection_DataMapNode
#undef TCollection_DataMapNode_Type_
#undef TCollection_DataMap
#undef TCollection_DataMap_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif