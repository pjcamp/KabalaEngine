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
 **     class SceneTreeModel!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OpenSG/OSGConfig.h>



#include "Project/Scene/KEScene.h"      // InternalRoot Class

#include "KESceneTreeModelBase.h"
#include "KESceneTreeModel.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::SceneTreeModel
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Scene *         SceneTreeModelBase::_sfInternalRoot
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<SceneTreeModel *>::_type("SceneTreeModelPtr", "AbstractTreeModelPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(SceneTreeModel *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           SceneTreeModel *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           SceneTreeModel *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void SceneTreeModelBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecScenePtr::Description(
        SFUnrecScenePtr::getClassType(),
        "InternalRoot",
        "",
        InternalRootFieldId, InternalRootFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SceneTreeModel::editHandleInternalRoot),
        static_cast<FieldGetMethodSig >(&SceneTreeModel::getHandleInternalRoot));

    oType.addInitialDesc(pDesc);
}


SceneTreeModelBase::TypeObject SceneTreeModelBase::_type(
    SceneTreeModelBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&SceneTreeModelBase::createEmptyLocal),
    SceneTreeModel::initMethod,
    SceneTreeModel::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&SceneTreeModel::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"SceneTreeModel\"\n"
    "\tparent=\"AbstractTreeModel\"\n"
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
    "\n"
    "\t<Field\n"
    "\t\tname=\"InternalRoot\"\n"
    "\t\ttype=\"Scene\"\n"
    "        category=\"pointer\"\n"
    "\t\tcardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "\t\tdefaultValue=\"NULL\"\n"
    "\t\tfieldHeader=\"Project/Scene/KESceneFields.h\"\n"
    "\t\ttypeHeader=\"Project/Scene/KEScene.h\"\n"
    "\t\taccess=\"protected\"\n"
    "\t>\n"
    "   </Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &SceneTreeModelBase::getType(void)
{
    return _type;
}

const FieldContainerType &SceneTreeModelBase::getType(void) const
{
    return _type;
}

UInt32 SceneTreeModelBase::getContainerSize(void) const
{
    return sizeof(SceneTreeModel);
}

/*------------------------- decorator get ------------------------------*/


//! Get the SceneTreeModel::_sfInternalRoot field.
const SFUnrecScenePtr *SceneTreeModelBase::getSFInternalRoot(void) const
{
    return &_sfInternalRoot;
}

SFUnrecScenePtr     *SceneTreeModelBase::editSFInternalRoot   (void)
{
    editSField(InternalRootFieldMask);

    return &_sfInternalRoot;
}





/*------------------------------ access -----------------------------------*/

UInt32 SceneTreeModelBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (InternalRootFieldMask & whichField))
    {
        returnValue += _sfInternalRoot.getBinSize();
    }

    return returnValue;
}

void SceneTreeModelBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (InternalRootFieldMask & whichField))
    {
        _sfInternalRoot.copyToBin(pMem);
    }
}

void SceneTreeModelBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (InternalRootFieldMask & whichField))
    {
        _sfInternalRoot.copyFromBin(pMem);
    }
}

//! create a new instance of the class
SceneTreeModelTransitPtr SceneTreeModelBase::createLocal(BitVector bFlags)
{
    SceneTreeModelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<SceneTreeModel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
SceneTreeModelTransitPtr SceneTreeModelBase::createDependent(BitVector bFlags)
{
    SceneTreeModelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<SceneTreeModel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
SceneTreeModelTransitPtr SceneTreeModelBase::create(void)
{
    SceneTreeModelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<SceneTreeModel>(tmpPtr);
    }

    return fc;
}

SceneTreeModel *SceneTreeModelBase::createEmptyLocal(BitVector bFlags)
{
    SceneTreeModel *returnValue;

    newPtr<SceneTreeModel>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
SceneTreeModel *SceneTreeModelBase::createEmpty(void)
{
    SceneTreeModel *returnValue;

    newPtr<SceneTreeModel>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr SceneTreeModelBase::shallowCopyLocal(
    BitVector bFlags) const
{
    SceneTreeModel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SceneTreeModel *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr SceneTreeModelBase::shallowCopyDependent(
    BitVector bFlags) const
{
    SceneTreeModel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SceneTreeModel *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr SceneTreeModelBase::shallowCopy(void) const
{
    SceneTreeModel *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const SceneTreeModel *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

SceneTreeModelBase::SceneTreeModelBase(void) :
    Inherited(),
    _sfInternalRoot           (NULL)
{
}

SceneTreeModelBase::SceneTreeModelBase(const SceneTreeModelBase &source) :
    Inherited(source),
    _sfInternalRoot           (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

SceneTreeModelBase::~SceneTreeModelBase(void)
{
}

void SceneTreeModelBase::onCreate(const SceneTreeModel *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        SceneTreeModel *pThis = static_cast<SceneTreeModel *>(this);

        pThis->setInternalRoot(source->getInternalRoot());
    }
}

GetFieldHandlePtr SceneTreeModelBase::getHandleInternalRoot    (void) const
{
    SFUnrecScenePtr::GetHandlePtr returnValue(
        new  SFUnrecScenePtr::GetHandle(
             &_sfInternalRoot,
             this->getType().getFieldDesc(InternalRootFieldId),
             const_cast<SceneTreeModelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SceneTreeModelBase::editHandleInternalRoot   (void)
{
    SFUnrecScenePtr::EditHandlePtr returnValue(
        new  SFUnrecScenePtr::EditHandle(
             &_sfInternalRoot,
             this->getType().getFieldDesc(InternalRootFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SceneTreeModel::setInternalRoot,
                    static_cast<SceneTreeModel *>(this), _1));

    editSField(InternalRootFieldMask);

    return returnValue;
}



#ifdef OSG_MT_CPTR_ASPECT
void SceneTreeModelBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    SceneTreeModel *pThis = static_cast<SceneTreeModel *>(this);

    pThis->execSync(static_cast<SceneTreeModel *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *SceneTreeModelBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    SceneTreeModel *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const SceneTreeModel *>(pRefAspect),
                  dynamic_cast<const SceneTreeModel *>(this));

    return returnValue;
}
#endif

void SceneTreeModelBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<SceneTreeModel *>(this)->setInternalRoot(NULL);


}


OSG_END_NAMESPACE
