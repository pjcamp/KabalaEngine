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


#ifndef _KELIGHTEDITORFIELDS_H_
#define _KELIGHTEDITORFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "KEKabalaEngineDef.h"

#include <OpenSG/OSGFieldContainerFields.h>
#include <OpenSG/OSGPointerSField.h>
#include <OpenSG/OSGPointerMField.h>


OSG_BEGIN_NAMESPACE

class LightEditor;

OSG_GEN_CONTAINERPTR(LightEditor);

/*! \ingroup GrpKabalaEngineFieldTraits
    \ingroup GrpLibOSGKabalaEngine
 */
template <>
struct FieldTraits<LightEditor *> :
    public FieldTraitsFCPtrBase<LightEditor *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<LightEditor *>  Self;

    enum                        { Convertible = NotConvertible };

    static KE_KABALAENGINE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFLightEditorPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFLightEditorPtr"; }
};

template<> inline
const Char8 *FieldTraits<LightEditor *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecLightEditorPtr"; 
}

template<> inline
const Char8 *FieldTraits<LightEditor *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecLightEditorPtr"; 
}

template<> inline
const Char8 *FieldTraits<LightEditor *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakLightEditorPtr"; 
}

template<> inline
const Char8 *FieldTraits<LightEditor *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdLightEditorPtr"; 
}

template<> inline
const Char8 *FieldTraits<LightEditor *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecLightEditorPtr"; 
}

template<> inline
const Char8 *FieldTraits<LightEditor *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecLightEditorPtr"; 
}

template<> inline
const Char8 *FieldTraits<LightEditor *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakLightEditorPtr"; 
}

template<> inline
const Char8 *FieldTraits<LightEditor *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdLightEditorPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<LightEditor *,
                      RecordedRefCountPolicy  > SFRecLightEditorPtr;
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<LightEditor *,
                      UnrecordedRefCountPolicy> SFUnrecLightEditorPtr;
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<LightEditor *,
                      WeakRefCountPolicy      > SFWeakLightEditorPtr;
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<LightEditor *,
                      NoRefCountPolicy        > SFUncountedLightEditorPtr;


/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<LightEditor *,
                      RecordedRefCountPolicy  > MFRecLightEditorPtr;
/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<LightEditor *,
                      UnrecordedRefCountPolicy> MFUnrecLightEditorPtr;
/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<LightEditor *,
                      WeakRefCountPolicy      > MFWeakLightEditorPtr;
/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<LightEditor *,
                      NoRefCountPolicy        > MFUncountedLightEditorPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFRecLightEditorPtr : 
    public PointerSField<LightEditor *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFUnrecLightEditorPtr : 
    public PointerSField<LightEditor *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFWeakLightEditorPtr :
    public PointerSField<LightEditor *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFUncountedLightEditorPtr :
    public PointerSField<LightEditor *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFRecLightEditorPtr :
    public PointerMField<LightEditor *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFUnrecLightEditorPtr :
    public PointerMField<LightEditor *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFWeakLightEditorPtr :
    public PointerMField<LightEditor *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFUncountedLightEditorPtr :
    public PointerMField<LightEditor *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _KELIGHTEDITORFIELDS_H_ */
