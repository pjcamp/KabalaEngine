/*---------------------------------------------------------------------------*\
 *                             Kabala Engine                                 *
 *                                                                           *
 *               Copyright (C) 2009-2010 by David Kabala                     *
 *                                                                           *
 *   authors:  David Kabala (djkabala@gmail.com)                             *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published            *
 * by the Free Software Foundation, version 3.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU General Public                 *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _KESCENECOMPONENTTREEFIELDS_H_
#define _KESCENECOMPONENTTREEFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "KEKabalaEngineDef.h"

#include <OpenSG/OSGFieldContainerFields.h>
#include <OpenSG/OSGPointerSField.h>
#include <OpenSG/OSGPointerMField.h>


OSG_BEGIN_NAMESPACE

class SceneComponentTree;

OSG_GEN_CONTAINERPTR(SceneComponentTree);

/*! \ingroup GrpKabalaEngineFieldTraits
    \ingroup GrpLibOSGKabalaEngine
 */
template <>
struct FieldTraits<SceneComponentTree *> :
    public FieldTraitsFCPtrBase<SceneComponentTree *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<SceneComponentTree *>  Self;

    enum                        { Convertible = NotConvertible };

    static KE_KABALAENGINE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFSceneComponentTreePtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFSceneComponentTreePtr"; }
};

template<> inline
const Char8 *FieldTraits<SceneComponentTree *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecSceneComponentTreePtr"; 
}

template<> inline
const Char8 *FieldTraits<SceneComponentTree *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecSceneComponentTreePtr"; 
}

template<> inline
const Char8 *FieldTraits<SceneComponentTree *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakSceneComponentTreePtr"; 
}

template<> inline
const Char8 *FieldTraits<SceneComponentTree *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdSceneComponentTreePtr"; 
}

template<> inline
const Char8 *FieldTraits<SceneComponentTree *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecSceneComponentTreePtr"; 
}

template<> inline
const Char8 *FieldTraits<SceneComponentTree *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecSceneComponentTreePtr"; 
}

template<> inline
const Char8 *FieldTraits<SceneComponentTree *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakSceneComponentTreePtr"; 
}

template<> inline
const Char8 *FieldTraits<SceneComponentTree *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdSceneComponentTreePtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<SceneComponentTree *,
                      RecordedRefCountPolicy  > SFRecSceneComponentTreePtr;
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<SceneComponentTree *,
                      UnrecordedRefCountPolicy> SFUnrecSceneComponentTreePtr;
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<SceneComponentTree *,
                      WeakRefCountPolicy      > SFWeakSceneComponentTreePtr;
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<SceneComponentTree *,
                      NoRefCountPolicy        > SFUncountedSceneComponentTreePtr;


/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<SceneComponentTree *,
                      RecordedRefCountPolicy  > MFRecSceneComponentTreePtr;
/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<SceneComponentTree *,
                      UnrecordedRefCountPolicy> MFUnrecSceneComponentTreePtr;
/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<SceneComponentTree *,
                      WeakRefCountPolicy      > MFWeakSceneComponentTreePtr;
/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<SceneComponentTree *,
                      NoRefCountPolicy        > MFUncountedSceneComponentTreePtr;




#else // these are the doxygen hacks

/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFRecSceneComponentTreePtr : 
    public PointerSField<SceneComponentTree *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFUnrecSceneComponentTreePtr : 
    public PointerSField<SceneComponentTree *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFWeakSceneComponentTreePtr :
    public PointerSField<SceneComponentTree *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFUncountedSceneComponentTreePtr :
    public PointerSField<SceneComponentTree *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFRecSceneComponentTreePtr :
    public PointerMField<SceneComponentTree *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFUnrecSceneComponentTreePtr :
    public PointerMField<SceneComponentTree *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFWeakSceneComponentTreePtr :
    public PointerMField<SceneComponentTree *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFUncountedSceneComponentTreePtr :
    public PointerMField<SceneComponentTree *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _KESCENECOMPONENTTREEFIELDS_H_ */