// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape_HeaderFile
#define _BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape_HeaderFile
#include <Handle_BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape.hxx>
#endif

#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif
#ifndef _Handle_TopTools_HArray2OfShape_HeaderFile
#include <Handle_TopTools_HArray2OfShape.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class TopTools_HArray2OfShape;
class TopoDS_Shape;
class TopTools_ShapeMapHasher;
class BRepFill_DataMapOfShapeHArray2OfShape;
class BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape;



class BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape : public TCollection_MapNode {

public:

  
      BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape(const TopoDS_Shape& K,const Handle(TopTools_HArray2OfShape)& I,const TCollection_MapNodePtr& n);
  
        TopoDS_Shape& Key() const;
  
        Handle_TopTools_HArray2OfShape& Value() const;




  DEFINE_STANDARD_RTTI(BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape)

protected:




private: 


TopoDS_Shape myKey;
Handle_TopTools_HArray2OfShape myValue;


};

#define TheKey TopoDS_Shape
#define TheKey_hxx <TopoDS_Shape.hxx>
#define TheItem Handle_TopTools_HArray2OfShape
#define TheItem_hxx <TopTools_HArray2OfShape.hxx>
#define Hasher TopTools_ShapeMapHasher
#define Hasher_hxx <TopTools_ShapeMapHasher.hxx>
#define TCollection_DataMapNode BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape
#define TCollection_DataMapNode_hxx <BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape.hxx>
#define TCollection_DataMapIterator BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape
#define TCollection_DataMapIterator_hxx <BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape.hxx>
#define Handle_TCollection_DataMapNode Handle_BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape
#define TCollection_DataMapNode_Type_() BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape_Type_()
#define TCollection_DataMap BRepFill_DataMapOfShapeHArray2OfShape
#define TCollection_DataMap_hxx <BRepFill_DataMapOfShapeHArray2OfShape.hxx>

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