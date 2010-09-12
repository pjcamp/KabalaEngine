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
 **     Do not change this file, changes should be done in the derived      **
 **     class SceneEventDetails!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OpenSG/OSGConfig.h>




#include "KESceneEventDetailsBase.h"
#include "KESceneEventDetails.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::SceneEventDetails
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<SceneEventDetails *>::_type("SceneEventDetailsPtr", "EventDetailsPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(SceneEventDetails *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           SceneEventDetails *,
                           0);


/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void SceneEventDetailsBase::classDescInserter(TypeObject &oType)
{
}


SceneEventDetailsBase::TypeObject SceneEventDetailsBase::_type(
    SceneEventDetailsBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&SceneEventDetailsBase::createEmptyLocal),
    SceneEventDetails::initMethod,
    SceneEventDetails::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&SceneEventDetails::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"SceneEventDetails\"\n"
    "\tparent=\"EventDetails\"\n"
    "\tlibrary=\"KabalaEngine\"\n"
    "\tpointerfieldtypes=\"single\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"false\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "\tuseLocalIncludes=\"false\"\n"
    "\tlibnamespace=\"KE\"\n"
    "\tsupportUnregisteredCreate=\"true\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &SceneEventDetailsBase::getType(void)
{
    return _type;
}

const FieldContainerType &SceneEventDetailsBase::getType(void) const
{
    return _type;
}

UInt32 SceneEventDetailsBase::getContainerSize(void) const
{
    return sizeof(SceneEventDetails);
}

/*------------------------- decorator get ------------------------------*/






/*------------------------------ access -----------------------------------*/

UInt32 SceneEventDetailsBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void SceneEventDetailsBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

}

void SceneEventDetailsBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

}

//! create a new instance of the class
SceneEventDetailsTransitPtr SceneEventDetailsBase::createLocal(BitVector bFlags)
{
    SceneEventDetailsTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<SceneEventDetails>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
SceneEventDetailsTransitPtr SceneEventDetailsBase::createDependent(BitVector bFlags)
{
    SceneEventDetailsTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<SceneEventDetails>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
SceneEventDetailsTransitPtr SceneEventDetailsBase::create(void)
{
    SceneEventDetailsTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<SceneEventDetails>(tmpPtr);
    }

    return fc;
}

SceneEventDetails *SceneEventDetailsBase::createEmptyLocal(BitVector bFlags)
{
    SceneEventDetails *returnValue;

    newPtr<SceneEventDetails>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
SceneEventDetails *SceneEventDetailsBase::createEmpty(void)
{
    SceneEventDetails *returnValue;

    newPtr<SceneEventDetails>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}

SceneEventDetails *SceneEventDetailsBase::createUnregistered(void)
{
    SceneEventDetails *returnValue = new SceneEventDetails;

#ifdef OSG_MT_CPTR_ASPECT
    returnValue->setupAspectStore();
#endif
    //Do not register with the FieldContainer Factory

    returnValue->onCreate      (      );
    returnValue->onCreateAspect(returnValue);
    
    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();
    
    return returnValue;
}


FieldContainerTransitPtr SceneEventDetailsBase::shallowCopyLocal(
    BitVector bFlags) const
{
    SceneEventDetails *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SceneEventDetails *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr SceneEventDetailsBase::shallowCopyDependent(
    BitVector bFlags) const
{
    SceneEventDetails *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SceneEventDetails *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr SceneEventDetailsBase::shallowCopy(void) const
{
    SceneEventDetails *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const SceneEventDetails *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

SceneEventDetailsBase::SceneEventDetailsBase(void) :
    Inherited()
{
}

SceneEventDetailsBase::SceneEventDetailsBase(const SceneEventDetailsBase &source) :
    Inherited(source)
{
}


/*-------------------------- destructors ----------------------------------*/

SceneEventDetailsBase::~SceneEventDetailsBase(void)
{
}




#ifdef OSG_MT_CPTR_ASPECT
void SceneEventDetailsBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    SceneEventDetails *pThis = static_cast<SceneEventDetails *>(this);

    pThis->execSync(static_cast<SceneEventDetails *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *SceneEventDetailsBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    SceneEventDetails *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const SceneEventDetails *>(pRefAspect),
                  dynamic_cast<const SceneEventDetails *>(this));

    return returnValue;
}
#endif

void SceneEventDetailsBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE