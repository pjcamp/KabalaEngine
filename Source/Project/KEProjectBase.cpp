/*---------------------------------------------------------------------------*\
 *                             Kabala Engine                                 *
 *                                                                           *
 *                                                                           *
 *   contact: djkabala@gmail.com                                             *
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
 **     class Project!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define KE_COMPILEPROJECTINST

#include <stdlib.h>
#include <stdio.h>

#include <OpenSG/OSGConfig.h>

#include "KEProjectBase.h"
#include "KEProject.h"


OSG_BEGIN_NAMESPACE

const OSG::BitVector  ProjectBase::NameFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::NameFieldId);

const OSG::BitVector  ProjectBase::VersionFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::VersionFieldId);

const OSG::BitVector  ProjectBase::MainWindowTitleFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::MainWindowTitleFieldId);

const OSG::BitVector  ProjectBase::FilePathFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::FilePathFieldId);

const OSG::BitVector  ProjectBase::ScenesFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::ScenesFieldId);

const OSG::BitVector  ProjectBase::InitialSceneFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::InitialSceneFieldId);

const OSG::BitVector  ProjectBase::InternalActiveSceneFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::InternalActiveSceneFieldId);

const OSG::BitVector  ProjectBase::BackgroundsFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::BackgroundsFieldId);

const OSG::BitVector  ProjectBase::InternalActiveBackgroundFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::InternalActiveBackgroundFieldId);

const OSG::BitVector  ProjectBase::ForegroundsFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::ForegroundsFieldId);

const OSG::BitVector  ProjectBase::InternalActiveForegroundsFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::InternalActiveForegroundsFieldId);

const OSG::BitVector  ProjectBase::GlobalActiveForegroundsFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::GlobalActiveForegroundsFieldId);

const OSG::BitVector  ProjectBase::ModelNodesFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::ModelNodesFieldId);

const OSG::BitVector  ProjectBase::InternalActiveModelNodesFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::InternalActiveModelNodesFieldId);

const OSG::BitVector  ProjectBase::GlobalActiveModelNodesFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::GlobalActiveModelNodesFieldId);

const OSG::BitVector  ProjectBase::CamerasFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::CamerasFieldId);

const OSG::BitVector  ProjectBase::InternalActiveCameraFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::InternalActiveCameraFieldId);

const OSG::BitVector  ProjectBase::InternalActiveViewportFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::InternalActiveViewportFieldId);

const OSG::BitVector  ProjectBase::ActiveAnimationsFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::ActiveAnimationsFieldId);

const OSG::BitVector  ProjectBase::ActiveParticleSystemsFieldMask = 
    (TypeTraits<BitVector>::One << ProjectBase::ActiveParticleSystemsFieldId);

const OSG::BitVector ProjectBase::MTInfluenceMask = 
    (Inherited::MTInfluenceMask) | 
    (static_cast<BitVector>(0x0) << Inherited::NextFieldId); 


// Field descriptions

/*! \var std::string     ProjectBase::_sfName
    
*/
/*! \var std::string     ProjectBase::_sfVersion
    
*/
/*! \var std::string     ProjectBase::_sfMainWindowTitle
    
*/
/*! \var Path            ProjectBase::_sfFilePath
    
*/
/*! \var ScenePtr        ProjectBase::_mfScenes
    
*/
/*! \var ScenePtr        ProjectBase::_sfInitialScene
    
*/
/*! \var ScenePtr        ProjectBase::_sfInternalActiveScene
    
*/
/*! \var BackgroundPtr   ProjectBase::_mfBackgrounds
    
*/
/*! \var BackgroundPtr   ProjectBase::_sfInternalActiveBackground
    
*/
/*! \var ForegroundPtr   ProjectBase::_mfForegrounds
    
*/
/*! \var ForegroundPtr   ProjectBase::_mfInternalActiveForegrounds
    
*/
/*! \var ForegroundPtr   ProjectBase::_mfGlobalActiveForegrounds
    
*/
/*! \var NodePtr         ProjectBase::_mfModelNodes
    
*/
/*! \var NodePtr         ProjectBase::_mfInternalActiveModelNodes
    
*/
/*! \var NodePtr         ProjectBase::_mfGlobalActiveModelNodes
    
*/
/*! \var CameraPtr       ProjectBase::_mfCameras
    
*/
/*! \var CameraPtr       ProjectBase::_sfInternalActiveCamera
    
*/
/*! \var ViewportPtr     ProjectBase::_sfInternalActiveViewport
    
*/
/*! \var AnimationPtr    ProjectBase::_mfActiveAnimations
    
*/
/*! \var ParticleSystemPtr ProjectBase::_mfActiveParticleSystems
    
*/

//! Project description

FieldDescription *ProjectBase::_desc[] = 
{
    new FieldDescription(SFString::getClassType(), 
                     "Name", 
                     NameFieldId, NameFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editSFName)),
    new FieldDescription(SFString::getClassType(), 
                     "Version", 
                     VersionFieldId, VersionFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editSFVersion)),
    new FieldDescription(SFString::getClassType(), 
                     "MainWindowTitle", 
                     MainWindowTitleFieldId, MainWindowTitleFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editSFMainWindowTitle)),
    new FieldDescription(SFPath::getClassType(), 
                     "FilePath", 
                     FilePathFieldId, FilePathFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editSFFilePath)),
    new FieldDescription(MFScenePtr::getClassType(), 
                     "Scenes", 
                     ScenesFieldId, ScenesFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFScenes)),
    new FieldDescription(SFScenePtr::getClassType(), 
                     "InitialScene", 
                     InitialSceneFieldId, InitialSceneFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editSFInitialScene)),
    new FieldDescription(SFScenePtr::getClassType(), 
                     "InternalActiveScene", 
                     InternalActiveSceneFieldId, InternalActiveSceneFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editSFInternalActiveScene)),
    new FieldDescription(MFBackgroundPtr::getClassType(), 
                     "Backgrounds", 
                     BackgroundsFieldId, BackgroundsFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFBackgrounds)),
    new FieldDescription(SFBackgroundPtr::getClassType(), 
                     "InternalActiveBackground", 
                     InternalActiveBackgroundFieldId, InternalActiveBackgroundFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editSFInternalActiveBackground)),
    new FieldDescription(MFForegroundPtr::getClassType(), 
                     "Foregrounds", 
                     ForegroundsFieldId, ForegroundsFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFForegrounds)),
    new FieldDescription(MFForegroundPtr::getClassType(), 
                     "InternalActiveForegrounds", 
                     InternalActiveForegroundsFieldId, InternalActiveForegroundsFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFInternalActiveForegrounds)),
    new FieldDescription(MFForegroundPtr::getClassType(), 
                     "GlobalActiveForegrounds", 
                     GlobalActiveForegroundsFieldId, GlobalActiveForegroundsFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFGlobalActiveForegrounds)),
    new FieldDescription(MFNodePtr::getClassType(), 
                     "ModelNodes", 
                     ModelNodesFieldId, ModelNodesFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFModelNodes)),
    new FieldDescription(MFNodePtr::getClassType(), 
                     "InternalActiveModelNodes", 
                     InternalActiveModelNodesFieldId, InternalActiveModelNodesFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFInternalActiveModelNodes)),
    new FieldDescription(MFNodePtr::getClassType(), 
                     "GlobalActiveModelNodes", 
                     GlobalActiveModelNodesFieldId, GlobalActiveModelNodesFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFGlobalActiveModelNodes)),
    new FieldDescription(MFCameraPtr::getClassType(), 
                     "Cameras", 
                     CamerasFieldId, CamerasFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFCameras)),
    new FieldDescription(SFCameraPtr::getClassType(), 
                     "InternalActiveCamera", 
                     InternalActiveCameraFieldId, InternalActiveCameraFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editSFInternalActiveCamera)),
    new FieldDescription(SFViewportPtr::getClassType(), 
                     "InternalActiveViewport", 
                     InternalActiveViewportFieldId, InternalActiveViewportFieldMask,
                     true,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editSFInternalActiveViewport)),
    new FieldDescription(MFAnimationPtr::getClassType(), 
                     "ActiveAnimations", 
                     ActiveAnimationsFieldId, ActiveAnimationsFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFActiveAnimations)),
    new FieldDescription(MFParticleSystemPtr::getClassType(), 
                     "ActiveParticleSystems", 
                     ActiveParticleSystemsFieldId, ActiveParticleSystemsFieldMask,
                     false,
                     reinterpret_cast<FieldAccessMethod>(&ProjectBase::editMFActiveParticleSystems))
};


FieldContainerType ProjectBase::_type(
    "Project",
    "AttachmentContainer",
    NULL,
    reinterpret_cast<PrototypeCreateF>(&ProjectBase::createEmpty),
    Project::initMethod,
    _desc,
    sizeof(_desc));

//OSG_FIELD_CONTAINER_DEF(ProjectBase, ProjectPtr)

/*------------------------------ get -----------------------------------*/

FieldContainerType &ProjectBase::getType(void) 
{
    return _type; 
} 

const FieldContainerType &ProjectBase::getType(void) const 
{
    return _type;
} 


FieldContainerPtr ProjectBase::shallowCopy(void) const 
{ 
    ProjectPtr returnValue; 

    newPtr(returnValue, dynamic_cast<const Project *>(this)); 

    return returnValue; 
}

UInt32 ProjectBase::getContainerSize(void) const 
{ 
    return sizeof(Project); 
}


#if !defined(OSG_FIXED_MFIELDSYNC)
void ProjectBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField)
{
    this->executeSyncImpl(static_cast<ProjectBase *>(&other),
                          whichField);
}
#else
void ProjectBase::executeSync(      FieldContainer &other,
                                    const BitVector      &whichField,                                    const SyncInfo       &sInfo     )
{
    this->executeSyncImpl((ProjectBase *) &other, whichField, sInfo);
}
void ProjectBase::execBeginEdit(const BitVector &whichField, 
                                            UInt32     uiAspect,
                                            UInt32     uiContainerSize) 
{
    this->execBeginEditImpl(whichField, uiAspect, uiContainerSize);
}

void ProjectBase::onDestroyAspect(UInt32 uiId, UInt32 uiAspect)
{
    Inherited::onDestroyAspect(uiId, uiAspect);

    _mfScenes.terminateShare(uiAspect, this->getContainerSize());
    _mfBackgrounds.terminateShare(uiAspect, this->getContainerSize());
    _mfForegrounds.terminateShare(uiAspect, this->getContainerSize());
    _mfInternalActiveForegrounds.terminateShare(uiAspect, this->getContainerSize());
    _mfGlobalActiveForegrounds.terminateShare(uiAspect, this->getContainerSize());
    _mfModelNodes.terminateShare(uiAspect, this->getContainerSize());
    _mfInternalActiveModelNodes.terminateShare(uiAspect, this->getContainerSize());
    _mfGlobalActiveModelNodes.terminateShare(uiAspect, this->getContainerSize());
    _mfCameras.terminateShare(uiAspect, this->getContainerSize());
    _mfActiveAnimations.terminateShare(uiAspect, this->getContainerSize());
    _mfActiveParticleSystems.terminateShare(uiAspect, this->getContainerSize());
}
#endif

/*------------------------- constructors ----------------------------------*/

#ifdef OSG_WIN32_ICL
#pragma warning (disable : 383)
#endif

ProjectBase::ProjectBase(void) :
    _sfName                   (), 
    _sfVersion                (), 
    _sfMainWindowTitle        (), 
    _sfFilePath               (), 
    _mfScenes                 (), 
    _sfInitialScene           (ScenePtr(NullFC)), 
    _sfInternalActiveScene    (ScenePtr(NullFC)), 
    _mfBackgrounds            (), 
    _sfInternalActiveBackground(BackgroundPtr(NullFC)), 
    _mfForegrounds            (), 
    _mfInternalActiveForegrounds(), 
    _mfGlobalActiveForegrounds(), 
    _mfModelNodes             (), 
    _mfInternalActiveModelNodes(), 
    _mfGlobalActiveModelNodes (), 
    _mfCameras                (), 
    _sfInternalActiveCamera   (CameraPtr(NullFC)), 
    _sfInternalActiveViewport (ViewportPtr(NullFC)), 
    _mfActiveAnimations       (), 
    _mfActiveParticleSystems  (), 
    Inherited() 
{
}

#ifdef OSG_WIN32_ICL
#pragma warning (default : 383)
#endif

ProjectBase::ProjectBase(const ProjectBase &source) :
    _sfName                   (source._sfName                   ), 
    _sfVersion                (source._sfVersion                ), 
    _sfMainWindowTitle        (source._sfMainWindowTitle        ), 
    _sfFilePath               (source._sfFilePath               ), 
    _mfScenes                 (source._mfScenes                 ), 
    _sfInitialScene           (source._sfInitialScene           ), 
    _sfInternalActiveScene    (source._sfInternalActiveScene    ), 
    _mfBackgrounds            (source._mfBackgrounds            ), 
    _sfInternalActiveBackground(source._sfInternalActiveBackground), 
    _mfForegrounds            (source._mfForegrounds            ), 
    _mfInternalActiveForegrounds(source._mfInternalActiveForegrounds), 
    _mfGlobalActiveForegrounds(source._mfGlobalActiveForegrounds), 
    _mfModelNodes             (source._mfModelNodes             ), 
    _mfInternalActiveModelNodes(source._mfInternalActiveModelNodes), 
    _mfGlobalActiveModelNodes (source._mfGlobalActiveModelNodes ), 
    _mfCameras                (source._mfCameras                ), 
    _sfInternalActiveCamera   (source._sfInternalActiveCamera   ), 
    _sfInternalActiveViewport (source._sfInternalActiveViewport ), 
    _mfActiveAnimations       (source._mfActiveAnimations       ), 
    _mfActiveParticleSystems  (source._mfActiveParticleSystems  ), 
    Inherited                 (source)
{
}

/*-------------------------- destructors ----------------------------------*/

ProjectBase::~ProjectBase(void)
{
}

/*------------------------------ access -----------------------------------*/

UInt32 ProjectBase::getBinSize(const BitVector &whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (NameFieldMask & whichField))
    {
        returnValue += _sfName.getBinSize();
    }

    if(FieldBits::NoField != (VersionFieldMask & whichField))
    {
        returnValue += _sfVersion.getBinSize();
    }

    if(FieldBits::NoField != (MainWindowTitleFieldMask & whichField))
    {
        returnValue += _sfMainWindowTitle.getBinSize();
    }

    if(FieldBits::NoField != (FilePathFieldMask & whichField))
    {
        returnValue += _sfFilePath.getBinSize();
    }

    if(FieldBits::NoField != (ScenesFieldMask & whichField))
    {
        returnValue += _mfScenes.getBinSize();
    }

    if(FieldBits::NoField != (InitialSceneFieldMask & whichField))
    {
        returnValue += _sfInitialScene.getBinSize();
    }

    if(FieldBits::NoField != (InternalActiveSceneFieldMask & whichField))
    {
        returnValue += _sfInternalActiveScene.getBinSize();
    }

    if(FieldBits::NoField != (BackgroundsFieldMask & whichField))
    {
        returnValue += _mfBackgrounds.getBinSize();
    }

    if(FieldBits::NoField != (InternalActiveBackgroundFieldMask & whichField))
    {
        returnValue += _sfInternalActiveBackground.getBinSize();
    }

    if(FieldBits::NoField != (ForegroundsFieldMask & whichField))
    {
        returnValue += _mfForegrounds.getBinSize();
    }

    if(FieldBits::NoField != (InternalActiveForegroundsFieldMask & whichField))
    {
        returnValue += _mfInternalActiveForegrounds.getBinSize();
    }

    if(FieldBits::NoField != (GlobalActiveForegroundsFieldMask & whichField))
    {
        returnValue += _mfGlobalActiveForegrounds.getBinSize();
    }

    if(FieldBits::NoField != (ModelNodesFieldMask & whichField))
    {
        returnValue += _mfModelNodes.getBinSize();
    }

    if(FieldBits::NoField != (InternalActiveModelNodesFieldMask & whichField))
    {
        returnValue += _mfInternalActiveModelNodes.getBinSize();
    }

    if(FieldBits::NoField != (GlobalActiveModelNodesFieldMask & whichField))
    {
        returnValue += _mfGlobalActiveModelNodes.getBinSize();
    }

    if(FieldBits::NoField != (CamerasFieldMask & whichField))
    {
        returnValue += _mfCameras.getBinSize();
    }

    if(FieldBits::NoField != (InternalActiveCameraFieldMask & whichField))
    {
        returnValue += _sfInternalActiveCamera.getBinSize();
    }

    if(FieldBits::NoField != (InternalActiveViewportFieldMask & whichField))
    {
        returnValue += _sfInternalActiveViewport.getBinSize();
    }

    if(FieldBits::NoField != (ActiveAnimationsFieldMask & whichField))
    {
        returnValue += _mfActiveAnimations.getBinSize();
    }

    if(FieldBits::NoField != (ActiveParticleSystemsFieldMask & whichField))
    {
        returnValue += _mfActiveParticleSystems.getBinSize();
    }


    return returnValue;
}

void ProjectBase::copyToBin(      BinaryDataHandler &pMem,
                                  const BitVector         &whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (NameFieldMask & whichField))
    {
        _sfName.copyToBin(pMem);
    }

    if(FieldBits::NoField != (VersionFieldMask & whichField))
    {
        _sfVersion.copyToBin(pMem);
    }

    if(FieldBits::NoField != (MainWindowTitleFieldMask & whichField))
    {
        _sfMainWindowTitle.copyToBin(pMem);
    }

    if(FieldBits::NoField != (FilePathFieldMask & whichField))
    {
        _sfFilePath.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ScenesFieldMask & whichField))
    {
        _mfScenes.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InitialSceneFieldMask & whichField))
    {
        _sfInitialScene.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveSceneFieldMask & whichField))
    {
        _sfInternalActiveScene.copyToBin(pMem);
    }

    if(FieldBits::NoField != (BackgroundsFieldMask & whichField))
    {
        _mfBackgrounds.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveBackgroundFieldMask & whichField))
    {
        _sfInternalActiveBackground.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ForegroundsFieldMask & whichField))
    {
        _mfForegrounds.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveForegroundsFieldMask & whichField))
    {
        _mfInternalActiveForegrounds.copyToBin(pMem);
    }

    if(FieldBits::NoField != (GlobalActiveForegroundsFieldMask & whichField))
    {
        _mfGlobalActiveForegrounds.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ModelNodesFieldMask & whichField))
    {
        _mfModelNodes.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveModelNodesFieldMask & whichField))
    {
        _mfInternalActiveModelNodes.copyToBin(pMem);
    }

    if(FieldBits::NoField != (GlobalActiveModelNodesFieldMask & whichField))
    {
        _mfGlobalActiveModelNodes.copyToBin(pMem);
    }

    if(FieldBits::NoField != (CamerasFieldMask & whichField))
    {
        _mfCameras.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveCameraFieldMask & whichField))
    {
        _sfInternalActiveCamera.copyToBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveViewportFieldMask & whichField))
    {
        _sfInternalActiveViewport.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActiveAnimationsFieldMask & whichField))
    {
        _mfActiveAnimations.copyToBin(pMem);
    }

    if(FieldBits::NoField != (ActiveParticleSystemsFieldMask & whichField))
    {
        _mfActiveParticleSystems.copyToBin(pMem);
    }


}

void ProjectBase::copyFromBin(      BinaryDataHandler &pMem,
                                    const BitVector    &whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (NameFieldMask & whichField))
    {
        _sfName.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (VersionFieldMask & whichField))
    {
        _sfVersion.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (MainWindowTitleFieldMask & whichField))
    {
        _sfMainWindowTitle.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (FilePathFieldMask & whichField))
    {
        _sfFilePath.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ScenesFieldMask & whichField))
    {
        _mfScenes.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InitialSceneFieldMask & whichField))
    {
        _sfInitialScene.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveSceneFieldMask & whichField))
    {
        _sfInternalActiveScene.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (BackgroundsFieldMask & whichField))
    {
        _mfBackgrounds.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveBackgroundFieldMask & whichField))
    {
        _sfInternalActiveBackground.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ForegroundsFieldMask & whichField))
    {
        _mfForegrounds.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveForegroundsFieldMask & whichField))
    {
        _mfInternalActiveForegrounds.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (GlobalActiveForegroundsFieldMask & whichField))
    {
        _mfGlobalActiveForegrounds.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ModelNodesFieldMask & whichField))
    {
        _mfModelNodes.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveModelNodesFieldMask & whichField))
    {
        _mfInternalActiveModelNodes.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (GlobalActiveModelNodesFieldMask & whichField))
    {
        _mfGlobalActiveModelNodes.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (CamerasFieldMask & whichField))
    {
        _mfCameras.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveCameraFieldMask & whichField))
    {
        _sfInternalActiveCamera.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (InternalActiveViewportFieldMask & whichField))
    {
        _sfInternalActiveViewport.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActiveAnimationsFieldMask & whichField))
    {
        _mfActiveAnimations.copyFromBin(pMem);
    }

    if(FieldBits::NoField != (ActiveParticleSystemsFieldMask & whichField))
    {
        _mfActiveParticleSystems.copyFromBin(pMem);
    }


}

#if !defined(OSG_FIXED_MFIELDSYNC)
void ProjectBase::executeSyncImpl(      ProjectBase *pOther,
                                        const BitVector         &whichField)
{

    Inherited::executeSyncImpl(pOther, whichField);

    if(FieldBits::NoField != (NameFieldMask & whichField))
        _sfName.syncWith(pOther->_sfName);

    if(FieldBits::NoField != (VersionFieldMask & whichField))
        _sfVersion.syncWith(pOther->_sfVersion);

    if(FieldBits::NoField != (MainWindowTitleFieldMask & whichField))
        _sfMainWindowTitle.syncWith(pOther->_sfMainWindowTitle);

    if(FieldBits::NoField != (FilePathFieldMask & whichField))
        _sfFilePath.syncWith(pOther->_sfFilePath);

    if(FieldBits::NoField != (ScenesFieldMask & whichField))
        _mfScenes.syncWith(pOther->_mfScenes);

    if(FieldBits::NoField != (InitialSceneFieldMask & whichField))
        _sfInitialScene.syncWith(pOther->_sfInitialScene);

    if(FieldBits::NoField != (InternalActiveSceneFieldMask & whichField))
        _sfInternalActiveScene.syncWith(pOther->_sfInternalActiveScene);

    if(FieldBits::NoField != (BackgroundsFieldMask & whichField))
        _mfBackgrounds.syncWith(pOther->_mfBackgrounds);

    if(FieldBits::NoField != (InternalActiveBackgroundFieldMask & whichField))
        _sfInternalActiveBackground.syncWith(pOther->_sfInternalActiveBackground);

    if(FieldBits::NoField != (ForegroundsFieldMask & whichField))
        _mfForegrounds.syncWith(pOther->_mfForegrounds);

    if(FieldBits::NoField != (InternalActiveForegroundsFieldMask & whichField))
        _mfInternalActiveForegrounds.syncWith(pOther->_mfInternalActiveForegrounds);

    if(FieldBits::NoField != (GlobalActiveForegroundsFieldMask & whichField))
        _mfGlobalActiveForegrounds.syncWith(pOther->_mfGlobalActiveForegrounds);

    if(FieldBits::NoField != (ModelNodesFieldMask & whichField))
        _mfModelNodes.syncWith(pOther->_mfModelNodes);

    if(FieldBits::NoField != (InternalActiveModelNodesFieldMask & whichField))
        _mfInternalActiveModelNodes.syncWith(pOther->_mfInternalActiveModelNodes);

    if(FieldBits::NoField != (GlobalActiveModelNodesFieldMask & whichField))
        _mfGlobalActiveModelNodes.syncWith(pOther->_mfGlobalActiveModelNodes);

    if(FieldBits::NoField != (CamerasFieldMask & whichField))
        _mfCameras.syncWith(pOther->_mfCameras);

    if(FieldBits::NoField != (InternalActiveCameraFieldMask & whichField))
        _sfInternalActiveCamera.syncWith(pOther->_sfInternalActiveCamera);

    if(FieldBits::NoField != (InternalActiveViewportFieldMask & whichField))
        _sfInternalActiveViewport.syncWith(pOther->_sfInternalActiveViewport);

    if(FieldBits::NoField != (ActiveAnimationsFieldMask & whichField))
        _mfActiveAnimations.syncWith(pOther->_mfActiveAnimations);

    if(FieldBits::NoField != (ActiveParticleSystemsFieldMask & whichField))
        _mfActiveParticleSystems.syncWith(pOther->_mfActiveParticleSystems);


}
#else
void ProjectBase::executeSyncImpl(      ProjectBase *pOther,
                                        const BitVector         &whichField,
                                        const SyncInfo          &sInfo      )
{

    Inherited::executeSyncImpl(pOther, whichField, sInfo);

    if(FieldBits::NoField != (NameFieldMask & whichField))
        _sfName.syncWith(pOther->_sfName);

    if(FieldBits::NoField != (VersionFieldMask & whichField))
        _sfVersion.syncWith(pOther->_sfVersion);

    if(FieldBits::NoField != (MainWindowTitleFieldMask & whichField))
        _sfMainWindowTitle.syncWith(pOther->_sfMainWindowTitle);

    if(FieldBits::NoField != (FilePathFieldMask & whichField))
        _sfFilePath.syncWith(pOther->_sfFilePath);

    if(FieldBits::NoField != (InitialSceneFieldMask & whichField))
        _sfInitialScene.syncWith(pOther->_sfInitialScene);

    if(FieldBits::NoField != (InternalActiveSceneFieldMask & whichField))
        _sfInternalActiveScene.syncWith(pOther->_sfInternalActiveScene);

    if(FieldBits::NoField != (InternalActiveBackgroundFieldMask & whichField))
        _sfInternalActiveBackground.syncWith(pOther->_sfInternalActiveBackground);

    if(FieldBits::NoField != (InternalActiveCameraFieldMask & whichField))
        _sfInternalActiveCamera.syncWith(pOther->_sfInternalActiveCamera);

    if(FieldBits::NoField != (InternalActiveViewportFieldMask & whichField))
        _sfInternalActiveViewport.syncWith(pOther->_sfInternalActiveViewport);


    if(FieldBits::NoField != (ScenesFieldMask & whichField))
        _mfScenes.syncWith(pOther->_mfScenes, sInfo);

    if(FieldBits::NoField != (BackgroundsFieldMask & whichField))
        _mfBackgrounds.syncWith(pOther->_mfBackgrounds, sInfo);

    if(FieldBits::NoField != (ForegroundsFieldMask & whichField))
        _mfForegrounds.syncWith(pOther->_mfForegrounds, sInfo);

    if(FieldBits::NoField != (InternalActiveForegroundsFieldMask & whichField))
        _mfInternalActiveForegrounds.syncWith(pOther->_mfInternalActiveForegrounds, sInfo);

    if(FieldBits::NoField != (GlobalActiveForegroundsFieldMask & whichField))
        _mfGlobalActiveForegrounds.syncWith(pOther->_mfGlobalActiveForegrounds, sInfo);

    if(FieldBits::NoField != (ModelNodesFieldMask & whichField))
        _mfModelNodes.syncWith(pOther->_mfModelNodes, sInfo);

    if(FieldBits::NoField != (InternalActiveModelNodesFieldMask & whichField))
        _mfInternalActiveModelNodes.syncWith(pOther->_mfInternalActiveModelNodes, sInfo);

    if(FieldBits::NoField != (GlobalActiveModelNodesFieldMask & whichField))
        _mfGlobalActiveModelNodes.syncWith(pOther->_mfGlobalActiveModelNodes, sInfo);

    if(FieldBits::NoField != (CamerasFieldMask & whichField))
        _mfCameras.syncWith(pOther->_mfCameras, sInfo);

    if(FieldBits::NoField != (ActiveAnimationsFieldMask & whichField))
        _mfActiveAnimations.syncWith(pOther->_mfActiveAnimations, sInfo);

    if(FieldBits::NoField != (ActiveParticleSystemsFieldMask & whichField))
        _mfActiveParticleSystems.syncWith(pOther->_mfActiveParticleSystems, sInfo);


}

void ProjectBase::execBeginEditImpl (const BitVector &whichField, 
                                                 UInt32     uiAspect,
                                                 UInt32     uiContainerSize)
{
    Inherited::execBeginEditImpl(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (ScenesFieldMask & whichField))
        _mfScenes.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (BackgroundsFieldMask & whichField))
        _mfBackgrounds.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (ForegroundsFieldMask & whichField))
        _mfForegrounds.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (InternalActiveForegroundsFieldMask & whichField))
        _mfInternalActiveForegrounds.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (GlobalActiveForegroundsFieldMask & whichField))
        _mfGlobalActiveForegrounds.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (ModelNodesFieldMask & whichField))
        _mfModelNodes.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (InternalActiveModelNodesFieldMask & whichField))
        _mfInternalActiveModelNodes.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (GlobalActiveModelNodesFieldMask & whichField))
        _mfGlobalActiveModelNodes.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (CamerasFieldMask & whichField))
        _mfCameras.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (ActiveAnimationsFieldMask & whichField))
        _mfActiveAnimations.beginEdit(uiAspect, uiContainerSize);

    if(FieldBits::NoField != (ActiveParticleSystemsFieldMask & whichField))
        _mfActiveParticleSystems.beginEdit(uiAspect, uiContainerSize);

}
#endif



OSG_END_NAMESPACE

#include <OpenSG/OSGSFieldTypeDef.inl>
#include <OpenSG/OSGMFieldTypeDef.inl>

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldDataTraits<ProjectPtr>::_type("ProjectPtr", "AttachmentContainerPtr");
#endif

OSG_DLLEXPORT_SFIELD_DEF1(ProjectPtr, KE_KABALAENGINELIB_DLLTMPLMAPPING);
OSG_DLLEXPORT_MFIELD_DEF1(ProjectPtr, KE_KABALAENGINELIB_DLLTMPLMAPPING);


OSG_END_NAMESPACE

