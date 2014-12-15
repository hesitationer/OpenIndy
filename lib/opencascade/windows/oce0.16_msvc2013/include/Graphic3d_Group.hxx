// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Graphic3d_Group_HeaderFile
#define _Graphic3d_Group_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Graphic3d_Group_HeaderFile
#include <Handle_Graphic3d_Group.hxx>
#endif

#ifndef _Graphic3d_CGroup_HeaderFile
#include <Graphic3d_CGroup.hxx>
#endif
#ifndef _Handle_Graphic3d_GraphicDriver_HeaderFile
#include <Handle_Graphic3d_GraphicDriver.hxx>
#endif
#ifndef _Graphic3d_CBitFields4_HeaderFile
#include <Graphic3d_CBitFields4.hxx>
#endif
#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Graphic3d_CBounds_HeaderFile
#include <Graphic3d_CBounds.hxx>
#endif
#ifndef _Graphic3d_ListOfPArray_HeaderFile
#include <Graphic3d_ListOfPArray.hxx>
#endif
#ifndef _Handle_TColStd_HArray1OfByte_HeaderFile
#include <Handle_TColStd_HArray1OfByte.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Handle_Graphic3d_Group_HeaderFile
#include <Handle_Graphic3d_Group.hxx>
#endif
#ifndef _Graphic3d_Structure_HeaderFile
#include <Graphic3d_Structure.hxx>
#endif
#ifndef _Handle_Graphic3d_Structure_HeaderFile
#include <Handle_Graphic3d_Structure.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Graphic3d_AspectLine3d_HeaderFile
#include <Handle_Graphic3d_AspectLine3d.hxx>
#endif
#ifndef _Handle_Graphic3d_AspectFillArea3d_HeaderFile
#include <Handle_Graphic3d_AspectFillArea3d.hxx>
#endif
#ifndef _Handle_Graphic3d_AspectText3d_HeaderFile
#include <Handle_Graphic3d_AspectText3d.hxx>
#endif
#ifndef _Handle_Graphic3d_AspectMarker3d_HeaderFile
#include <Handle_Graphic3d_AspectMarker3d.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
#ifndef _Graphic3d_Vertex_HeaderFile
#include <Graphic3d_Vertex.hxx>
#endif
#ifndef _Quantity_PlaneAngle_HeaderFile
#include <Quantity_PlaneAngle.hxx>
#endif
#ifndef _Graphic3d_TextPath_HeaderFile
#include <Graphic3d_TextPath.hxx>
#endif
#ifndef _Graphic3d_HorizontalTextAlignment_HeaderFile
#include <Graphic3d_HorizontalTextAlignment.hxx>
#endif
#ifndef _Graphic3d_VerticalTextAlignment_HeaderFile
#include <Graphic3d_VerticalTextAlignment.hxx>
#endif
#ifndef _Handle_Graphic3d_ArrayOfPrimitives_HeaderFile
#include <Handle_Graphic3d_ArrayOfPrimitives.hxx>
#endif
#ifndef _Graphic3d_GroupAspect_HeaderFile
#include <Graphic3d_GroupAspect.hxx>
#endif
class Graphic3d_GraphicDriver;
class TColStd_HArray1OfByte;
class Graphic3d_GroupDefinitionError;
class Graphic3d_PickIdDefinitionError;
class Standard_OutOfRange;
class Graphic3d_Structure;
class Graphic3d_AspectLine3d;
class Graphic3d_AspectFillArea3d;
class Graphic3d_AspectText3d;
class Graphic3d_AspectMarker3d;
class TCollection_ExtendedString;
class Graphic3d_ArrayOfPrimitives;
class gp_Ax2;


//! This class allows the definition of groups <br>
//!     of primitives inside of graphic objects (presentations). <br>
//!     A group contains the primitives and attributes <br>
//!     for which the range is limited to this group. <br>
//!     The primitives of a group can be globally suppressed. <br>
//! <br>
//!      There are two main group usage models: <br>
//! <br>
//!        1) Non-modifiable, or unbounded, group ('black box'). <br>
//!           Developers can repeat a sequence of <br>
//!           SetPrimitivesAspect() with AddPrimitiveArray() methods arbitrary number of times <br>
//!           to define arbitrary number of primitive "blocks" each having individual apect values. <br>
//!           Any modification of such a group is forbidden, as aspects and primitives are mixed <br>
//!           in memory without any high-level logical structure, and any modification is very likely to result <br>
//!           in corruption of the group internal data. <br>
//!           It is necessary to recreate such a group as a whole when some attribute should be changed. <br>
//!           (for example, in terms of AIS it is necessary to re-Compute() the whole presentation each time). <br>
//!        2) Bounded group. Developers should specify the necessary group aspects with help of <br>
//!           SetGroupPrimitivesAspect() and then add primitives to the group. <br>
//!           Such a group have simplified organization in memory (a single block of attributes <br>
//!           followed by a block of primitives) and therefore it can be modified, if it is necessary to <br>
//!           change parameters of some aspect that has already been set, using methods: <br>
//!           IsGroupPrimitivesAspectSet() to detect which aspect was set for primitives; <br>
//!           GroupPrimitivesAspect() to read current aspect values <br>
//!           and SetGroupPrimitivesAspect() to set new values. <br>
//! <br>
//!        Developers are strongly recommended to take all the above into account when filling Graphic3d_Group <br>
//!        with aspects and primitives and choose the group usage model beforehand out of application needs. <br>
class Graphic3d_Group : public MMgt_TShared {

public:

  //! Creates a group in the structure <AStructure>. <br>
  Standard_EXPORT   Graphic3d_Group(const Handle(Graphic3d_Structure)& AStructure);
  //! Supress all primitives and attributes of <me>. <br>
//!          To clear group without update in Graphic3d_StructureManager <br>
//!          pass Standard_False as <theUpdateStructureMgr>. This <br>
//!          used on context and viewer destruction, when the pointer <br>
//!          to structure manager in Graphic3d_Structure could be <br>
//!          already released (pointers are used here to avoid handle <br>
//!          cross-reference); <br>
  Standard_EXPORT     void Clear(const Standard_Boolean theUpdateStructureMgr = Standard_True) ;
  //! Supress the group <me> in the structure. <br>
  Standard_EXPORT     void Destroy() ;
~Graphic3d_Group()
{
  Destroy();
}
  //! Supress the group <me> in the structure. <br>
//!  Warning: No more graphic operations in <me> after this call. <br>//! Modifies the current modelling transform persistence (pan, zoom or rotate) <br>//! Get the current modelling transform persistence (pan, zoom or rotate) <br>
  Standard_EXPORT     void Remove() ;
  //! Removes the context for all the line primitives <br>
//!      of the group. <br>
  Standard_EXPORT     void SetGroupPrimitivesAspect() ;
  //! Modifies the context for all the line primitives <br>
//!      of the group. <br>
  Standard_EXPORT     void SetGroupPrimitivesAspect(const Handle(Graphic3d_AspectLine3d)& CTX) ;
  //! Modifies the context for all the face primitives <br>
//!      of the group. <br>
  Standard_EXPORT     void SetGroupPrimitivesAspect(const Handle(Graphic3d_AspectFillArea3d)& CTX) ;
  //! Modifies the context for all the text primitives <br>
//!      of the group. <br>
  Standard_EXPORT     void SetGroupPrimitivesAspect(const Handle(Graphic3d_AspectText3d)& CTX) ;
  //! Modifies the context for all the marker primitives <br>
//!      of the group. <br>
  Standard_EXPORT     void SetGroupPrimitivesAspect(const Handle(Graphic3d_AspectMarker3d)& CTX) ;
  //! Modifies the current context of the group to give <br>
//!      another aspect for all the line primitives created <br>
//!      after this call in the group. <br>
  Standard_EXPORT     void SetPrimitivesAspect(const Handle(Graphic3d_AspectLine3d)& CTX) ;
  //! Modifies the current context of the group to give <br>
//!      another aspect for all the face primitives created <br>
//!      after this call in the group. <br>
  Standard_EXPORT     void SetPrimitivesAspect(const Handle(Graphic3d_AspectFillArea3d)& CTX) ;
  //! Modifies the current context of the group to give <br>
//!      another aspect for all the text primitives created <br>
//!      after this call in the group. <br>
  Standard_EXPORT     void SetPrimitivesAspect(const Handle(Graphic3d_AspectText3d)& CTX) ;
  //! Modifies the current context of the group to give <br>
//!      another aspect for all the marker primitives created <br>
//!      after this call in the group. <br>
  Standard_EXPORT     void SetPrimitivesAspect(const Handle(Graphic3d_AspectMarker3d)& CTX) ;
  //! Sets the coordinates of the boundary box of the <br>
//!      group <me>. <br>
  Standard_EXPORT     void SetMinMaxValues(const Standard_Real XMin,const Standard_Real YMin,const Standard_Real ZMin,const Standard_Real XMax,const Standard_Real YMax,const Standard_Real ZMax) ;
  //! Creates the string <AText> at position <APoint>. <br>
//!      The 3D point of attachment is projected. The text is <br>
//!      written in the plane of projection. <br>
//!      The attributes are given with respect to the plane of <br>
//!      projection. <br>
//!      AHeight : Height of text. <br>
//!            (Relative to the Normalized Projection <br>
//!              Coordinates (NPC) Space). <br>
//!      AAngle  : Orientation of the text <br>
//!            (with respect to the horizontal). <br>
  Standard_EXPORT     void Text(const Standard_CString AText,const Graphic3d_Vertex& APoint,const Standard_Real AHeight,const Quantity_PlaneAngle AAngle,const Graphic3d_TextPath ATp,const Graphic3d_HorizontalTextAlignment AHta,const Graphic3d_VerticalTextAlignment AVta,const Standard_Boolean EvalMinMax = Standard_True) ;
  //! Creates the string <AText> at position <APoint>. <br>
//!      The 3D point of attachment is projected. The text is <br>
//!      written in the plane of projection. <br>
//!      The attributes are given with respect to the plane of <br>
//!      projection. <br>
//!      AHeight : Height of text. <br>
//!            (Relative to the Normalized Projection <br>
//!              Coordinates (NPC) Space). <br>
//!      The other attributes have the following default values: <br>
//!      AAngle  : PI / 2. <br>
//!      ATp     : TP_RIGHT <br>
//!      AHta    : HTA_LEFT <br>
//!      AVta    : VTA_BOTTOM <br>
  Standard_EXPORT     void Text(const Standard_CString AText,const Graphic3d_Vertex& APoint,const Standard_Real AHeight,const Standard_Boolean EvalMinMax = Standard_True) ;
  //! Creates the string <AText> at position <APoint>. <br>
//!      The 3D point of attachment is projected. The text is <br>
//!      written in the plane of projection. <br>
//!      The attributes are given with respect to the plane of <br>
//!      projection. <br>
//!      AHeight : Height of text. <br>
//!            (Relative to the Normalized Projection <br>
//!              Coordinates (NPC) Space). <br>
//!      AAngle  : Orientation of the text <br>
//!            (with respect to the horizontal). <br>
  Standard_EXPORT     void Text(const TCollection_ExtendedString& AText,const Graphic3d_Vertex& APoint,const Standard_Real AHeight,const Quantity_PlaneAngle AAngle,const Graphic3d_TextPath ATp,const Graphic3d_HorizontalTextAlignment AHta,const Graphic3d_VerticalTextAlignment AVta,const Standard_Boolean EvalMinMax = Standard_True) ;
  //! Creates the string <AText> at position <APoint>. <br>
//!      The 3D point of attachment is projected. The text is <br>
//!      written in the plane of projection. <br>
//!      The attributes are given with respect to the plane of <br>
//!      projection. <br>
//!      AHeight : Height of text. <br>
//!            (Relative to the Normalized Projection <br>
//!              Coordinates (NPC) Space). <br>
//!      The other attributes have the following default values: <br>
//!      AAngle  : PI / 2. <br>
//!      ATp     : TP_RIGHT <br>
//!      AHta    : HTA_LEFT <br>
//!      AVta    : VTA_BOTTOM <br>
  Standard_EXPORT     void Text(const TCollection_ExtendedString& AText,const Graphic3d_Vertex& APoint,const Standard_Real AHeight,const Standard_Boolean EvalMinMax = Standard_True) ;
  //! Adds an array of primitives for display <br>
  Standard_EXPORT     void AddPrimitiveArray(const Handle(Graphic3d_ArrayOfPrimitives)& elem,const Standard_Boolean EvalMinMax = Standard_True) ;
  //! Creates a primitive array with single marker using AddPrimitiveArray(). <br>
  Standard_EXPORT     void Marker(const Graphic3d_Vertex& thePoint,const Standard_Boolean theToEvalMinMax = Standard_True) ;
  //! Creates an UserDraw primitive <br>
//!  Category: Methods to create UserDraw <br>
//!  Warning: Raises GroupDefinitionError if ... <br>
  Standard_EXPORT     void UserDraw(const Standard_Address AnObject,const Standard_Boolean EvalMinMax = Standard_True,const Standard_Boolean ContainsFacet = Standard_False) ;
  //! sets the stencil test to theIsEnabled state; <br>
  Standard_EXPORT     void SetStencilTestOptions(const Standard_Boolean theIsEnabled) ;
  //! sets the flipping to theIsEnabled state. <br>
  Standard_EXPORT     void SetFlippingOptions(const Standard_Boolean theIsEnabled,const gp_Ax2& theRefPlane) ;
  //! Returns TRUE if aspect is set for the group. <br>
  Standard_EXPORT     Standard_Boolean IsGroupPrimitivesAspectSet(const Graphic3d_GroupAspect theAspect) const;
  //! Returns the context of all the primitives of the group. <br>
  Standard_EXPORT     void GroupPrimitivesAspect(const Handle(Graphic3d_AspectLine3d)& CTXL,const Handle(Graphic3d_AspectText3d)& CTXT,const Handle(Graphic3d_AspectMarker3d)& CTXM,const Handle(Graphic3d_AspectFillArea3d)& CTXF) const;
  //! Returns the last inserted context in the group <me> <br>
//!	    foreach kind of primitives. <br>
  Standard_EXPORT     void PrimitivesAspect(const Handle(Graphic3d_AspectLine3d)& CTXL,const Handle(Graphic3d_AspectText3d)& CTXT,const Handle(Graphic3d_AspectMarker3d)& CTXM,const Handle(Graphic3d_AspectFillArea3d)& CTXF) const;
  //! Returns Standard_True if the group <me> contains <br>
//!      Polygons, Triangles or Quadrangles. <br>
  Standard_EXPORT     Standard_Boolean ContainsFacet() const;
  //! Returns Standard_True if the group <me> is deleted. <br>
//!      <me> is deleted after the call Remove (me) or the <br>
//!      associated structure is deleted. <br>
  Standard_EXPORT     Standard_Boolean IsDeleted() const;
  //! Returns Standard_True if the group <me> is empty. <br>
  Standard_EXPORT     Standard_Boolean IsEmpty() const;
  //! Returns the coordinates of the boundary box of the <br>
//!      group <me>. <br>
  Standard_EXPORT     void MinMaxValues(Standard_Real& XMin,Standard_Real& YMin,Standard_Real& ZMin,Standard_Real& XMax,Standard_Real& YMax,Standard_Real& ZMax) const;
  //! Returns the structure containing the group <me>. <br>
  Standard_EXPORT     Handle_Graphic3d_Structure Structure() const;

friend   //! Suppress in the structure <me>, the group <AGroup>. <br>
//!	    It will be erased at the next screen update. <br>
  Standard_EXPORT   void Graphic3d_Structure::Remove(const Handle(Graphic3d_Group)& AGroup) ;


  DEFINE_STANDARD_RTTI(Graphic3d_Group)

protected:




private: 

  //! Returns the extreme coordinates found in the group. <br>
  Standard_EXPORT     void MinMaxCoord(Standard_Real& XMin,Standard_Real& YMin,Standard_Real& ZMin,Standard_Real& XMax,Standard_Real& YMax,Standard_Real& ZMax) const;
  //! Calls the Update method of the StructureManager which <br>
//!      contains the associated Structure of the Group <me>. <br>
  Standard_EXPORT     void Update() const;

Graphic3d_CGroup MyCGroup;
Handle_Graphic3d_GraphicDriver MyGraphicDriver;
Graphic3d_CBitFields4 MyCBitFields;
Standard_Address MyPtrStructure;
Graphic3d_CBounds MyBounds;
Graphic3d_ListOfPArray MyListOfPArray;
Handle_TColStd_HArray1OfByte MyMarkArray;
Standard_Integer MyMarkWidth;
Standard_Integer MyMarkHeight;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif