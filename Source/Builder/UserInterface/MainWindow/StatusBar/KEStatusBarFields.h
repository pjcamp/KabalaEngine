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


#ifndef _KESTATUSBARFIELDS_H_
#define _KESTATUSBARFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include <OpenSG/OSGConfig.h>
#include "KEKabalaEngineDef.h"

#include <OpenSG/OSGFieldContainerFields.h>
#include <OpenSG/OSGPointerSField.h>
#include <OpenSG/OSGPointerMField.h>


OSG_BEGIN_NAMESPACE

class StatusBar;

OSG_GEN_CONTAINERPTR(StatusBar);

/*! \ingroup GrpKabalaEngineFieldTraits
    \ingroup GrpLibOSGKabalaEngine
 */
template <>
struct FieldTraits<StatusBar *> :
    public FieldTraitsFCPtrBase<StatusBar *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<StatusBar *>  Self;

    enum                        { Convertible = NotConvertible };

    static KE_KABALAENGINE_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFStatusBarPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFStatusBarPtr"; }
};

template<> inline
const Char8 *FieldTraits<StatusBar *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecStatusBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<StatusBar *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecStatusBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<StatusBar *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakStatusBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<StatusBar *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdStatusBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<StatusBar *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecStatusBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<StatusBar *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecStatusBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<StatusBar *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakStatusBarPtr"; 
}

template<> inline
const Char8 *FieldTraits<StatusBar *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdStatusBarPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<StatusBar *,
                      RecordedRefCountPolicy  > SFRecStatusBarPtr;
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<StatusBar *,
                      UnrecordedRefCountPolicy> SFUnrecStatusBarPtr;
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<StatusBar *,
                      WeakRefCountPolicy      > SFWeakStatusBarPtr;
/*! \ingroup GrpKabalaEngineFieldSFields */
typedef PointerSField<StatusBar *,
                      NoRefCountPolicy        > SFUncountedStatusBarPtr;


/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<StatusBar *,
                      RecordedRefCountPolicy  > MFRecStatusBarPtr;
/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<StatusBar *,
                      UnrecordedRefCountPolicy> MFUnrecStatusBarPtr;
/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<StatusBar *,
                      WeakRefCountPolicy      > MFWeakStatusBarPtr;
/*! \ingroup GrpKabalaEngineFieldMFields */
typedef PointerMField<StatusBar *,
                      NoRefCountPolicy        > MFUncountedStatusBarPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFRecStatusBarPtr : 
    public PointerSField<StatusBar *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFUnrecStatusBarPtr : 
    public PointerSField<StatusBar *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFWeakStatusBarPtr :
    public PointerSField<StatusBar *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldSFields \ingroup GrpLibOSGKabalaEngine */
struct SFUncountedStatusBarPtr :
    public PointerSField<StatusBar *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFRecStatusBarPtr :
    public PointerMField<StatusBar *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFUnrecStatusBarPtr :
    public PointerMField<StatusBar *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFWeakStatusBarPtr :
    public PointerMField<StatusBar *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpKabalaEngineFieldMFields \ingroup GrpLibOSGKabalaEngine */
struct MFUncountedStatusBarPtr :
    public PointerMField<StatusBar *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _KESTATUSBARFIELDS_H_ */
