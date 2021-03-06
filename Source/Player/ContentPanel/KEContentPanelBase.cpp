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
 **     class ContentPanel!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OpenSG/OSGConfig.h>




#include "KEContentPanelBase.h"
#include "KEContentPanel.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::ContentPanel
    The ContentPanel. Shows the content of files 
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<ContentPanel *>::_type("ContentPanelPtr", "PanelPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(ContentPanel *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           ContentPanel *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           ContentPanel *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ContentPanelBase::classDescInserter(TypeObject &oType)
{
}


ContentPanelBase::TypeObject ContentPanelBase::_type(
    ContentPanelBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&ContentPanelBase::createEmptyLocal),
    ContentPanel::initMethod,
    ContentPanel::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&ContentPanel::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"ContentPanel\"\n"
    "\tparent=\"Panel\"\n"
    "\tlibrary=\"KabalaEngine\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"false\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "\tuseLocalIncludes=\"false\"\n"
    "\tlibnamespace=\"KE\"\n"
    "    authors=\"David Kabala (djkabala@gmail.com)                             \"\n"
    ">\n"
    "The ContentPanel. Shows the content of files \n"
    "\n"
    "</FieldContainer>\n",
    "The ContentPanel. Shows the content of files \n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &ContentPanelBase::getType(void)
{
    return _type;
}

const FieldContainerType &ContentPanelBase::getType(void) const
{
    return _type;
}

UInt32 ContentPanelBase::getContainerSize(void) const
{
    return sizeof(ContentPanel);
}

/*------------------------- decorator get ------------------------------*/






/*------------------------------ access -----------------------------------*/

UInt32 ContentPanelBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void ContentPanelBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

}

void ContentPanelBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

}

//! create a new instance of the class
ContentPanelTransitPtr ContentPanelBase::createLocal(BitVector bFlags)
{
    ContentPanelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<ContentPanel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ContentPanelTransitPtr ContentPanelBase::createDependent(BitVector bFlags)
{
    ContentPanelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<ContentPanel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ContentPanelTransitPtr ContentPanelBase::create(void)
{
    ContentPanelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<ContentPanel>(tmpPtr);
    }

    return fc;
}

ContentPanel *ContentPanelBase::createEmptyLocal(BitVector bFlags)
{
    ContentPanel *returnValue;

    newPtr<ContentPanel>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
ContentPanel *ContentPanelBase::createEmpty(void)
{
    ContentPanel *returnValue;

    newPtr<ContentPanel>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr ContentPanelBase::shallowCopyLocal(
    BitVector bFlags) const
{
    ContentPanel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ContentPanel *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ContentPanelBase::shallowCopyDependent(
    BitVector bFlags) const
{
    ContentPanel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ContentPanel *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ContentPanelBase::shallowCopy(void) const
{
    ContentPanel *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const ContentPanel *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

ContentPanelBase::ContentPanelBase(void) :
    Inherited()
{
}

ContentPanelBase::ContentPanelBase(const ContentPanelBase &source) :
    Inherited(source)
{
}


/*-------------------------- destructors ----------------------------------*/

ContentPanelBase::~ContentPanelBase(void)
{
}



#ifdef OSG_MT_CPTR_ASPECT
void ContentPanelBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    ContentPanel *pThis = static_cast<ContentPanel *>(this);

    pThis->execSync(static_cast<ContentPanel *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ContentPanelBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    ContentPanel *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const ContentPanel *>(pRefAspect),
                  dynamic_cast<const ContentPanel *>(this));

    return returnValue;
}
#endif

void ContentPanelBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
