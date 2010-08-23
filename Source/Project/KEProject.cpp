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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#define KE_COMPILEKABALAENGINELIB

#include <OpenSG/OSGConfig.h>

#include "KEProject.h"
#include "KEUtils.h"
#include "Application/KEMainApplication.h"
#include <OpenSG/OSGViewport.h>
#include <OpenSG/OSGTransform.h>
#include <OpenSG/OSGPerspectiveCamera.h>
#include <OpenSG/OSGOrthographicCamera.h>
#include "Project/Scene/KEScene.h"
#include <OpenSG/OSGWindowEventProducer.h>
#include <OpenSG/OSGFCFileHandler.h>
#include <OpenSG/OSGFilePathAttachment.h>
#include <OpenSG/OSGWindowEventProducer.h>

#include <OpenSG/OSGAnimation.h>
#include <OpenSG/OSGUIDrawingSurface.h>
#include <OpenSG/OSGPhysicsHandler.h>
#include <OpenSG/OSGPhysicsWorld.h>
#include <OpenSG/OSGSoundManager.h>
#include <OpenSG/OSGLuaManager.h>
#include <OpenSG/OSGWindowUtils.h>
#include <OpenSG/OSGParticleSystem.h>

#include <boost/filesystem/operations.hpp>

//Bindings for the OSGToolbox libraries
#include <OpenSG/OSGToolbox_wrap.h>

//Kabala Engine Lua Bindings
#include "LuaBindings/KELuaBindings.h"

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGProjectBase.cpp file.
// To modify it, please change the .fcd file (OSGProject.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void Project::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}

ProjectRefPtr Project::load(const BoostPath& ProjectFile)
{
    return create(ProjectFile);
}

ProjectRefPtr Project::create(const BoostPath& ProjectFile)
{
    FCFileType::FCPtrStore NewContainers;
    NewContainers = FCFileHandler::the()->read(ProjectFile);

    for(FCFileType::FCPtrStore::iterator Itor(NewContainers.begin()) ; Itor!= NewContainers.end() ; ++Itor)
    {
        if((*Itor)->getType() == Project::getClassType())
        {
            dynamic_pointer_cast<Project>(*Itor)->setFilePath(ProjectFile);
            dynamic_pointer_cast<Project>(*Itor)->attachNames();

            //Attach the FilePath to me
            //FilePathAttachment::setFilePath(dynamic_pointer_cast<Project>(*Itor), ProjectFile);

            return dynamic_pointer_cast<Project>(*Itor);
        }
    }
    return NULL;
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

Scene* Project::getSceneByName(const std::string& FindSceneName) const
{
    const Char8* SceneName;
    for(UInt32 i(0) ; i<getMFScenes()->size() ; ++i)
    {
        //Get the Name of the Scene
        SceneName = getName(getScenes(i));

        if(SceneName != NULL &&
           strcmp(SceneName,FindSceneName.c_str()) == 0)
        {
            return getScenes(i);
        }
    }
    return NULL;
}

WindowEventProducer* Project::getEventProducer(void) const
{
    return MainApplication::the()->getMainWindow();
}

void Project::save(void)
{
    FCFileType::FCPtrStore Containers;
    Containers.insert(ProjectRefPtr(this));

    FCFileType::FCTypeVector IgnoreTypes;
    IgnoreTypes.push_back(getNativeWindowType()->getId());

    FCFileHandler::the()->write(Containers,getFilePath(),IgnoreTypes);
}

void Project::save(const BoostPath& ProjectFile)
{
    setFilePath(ProjectFile);

    save();
}

void Project::start(void)
{
    //Temporarily validate all openGL Objects
    //SLOG << "Starting to validate all OpenGL Objects." << std::endl;
    //MainApplication::the()->getMainWindow()->validateAllGLObjects();
    //SLOG << "Finished validating all OpenGL Objects." << std::endl;

    //Attach the listeners
   _UpdateConnection = MainApplication::the()->getMainWindow()->connectUpdate(boost::bind(&Project::handleUpdate, this, _1));
   _MouseClickedConnection = MainApplication::the()->getMainWindow()->connectMouseClicked(boost::bind(&Project::handleMouseClicked, this, _1));
   _MouseEnteredConnection = MainApplication::the()->getMainWindow()->connectMouseEntered(boost::bind(&Project::handleMouseEntered, this, _1));
   _MouseExitedConnection = MainApplication::the()->getMainWindow()->connectMouseExited(boost::bind(&Project::handleMouseExited, this, _1));
   _MousePressedConnection = MainApplication::the()->getMainWindow()->connectMousePressed(boost::bind(&Project::handleMousePressed, this, _1));
   _MouseReleasedConnection = MainApplication::the()->getMainWindow()->connectMouseReleased(boost::bind(&Project::handleMouseReleased, this, _1));
   _MouseMovedConnection = MainApplication::the()->getMainWindow()->connectMouseMoved(boost::bind(&Project::handleMouseMoved, this, _1));
   _MouseDraggedConnection = MainApplication::the()->getMainWindow()->connectMouseDragged(boost::bind(&Project::handleMouseDragged, this, _1));
   _MouseWheelMovedConnection = MainApplication::the()->getMainWindow()->connectMouseWheelMoved(boost::bind(&Project::handleMouseWheelMoved, this, _1));
   _KeyPressedConnection = MainApplication::the()->getMainWindow()->connectKeyPressed(boost::bind(&Project::handleKeyPressed, this, _1));
   _KeyReleasedConnection = MainApplication::the()->getMainWindow()->connectKeyReleased(boost::bind(&Project::handleKeyReleased, this, _1));
   _KeyTypedConnection = MainApplication::the()->getMainWindow()->connectKeyTyped(boost::bind(&Project::handleKeyTyped, this, _1));
   _WindowOpenedConnection = MainApplication::the()->getMainWindow()->connectWindowOpened(boost::bind(&Project::handleWindowOpened, this, _1));
   _WindowClosingConnection = MainApplication::the()->getMainWindow()->connectWindowClosing(boost::bind(&Project::handleWindowClosing, this, _1));
   _WindowClosedConnection = MainApplication::the()->getMainWindow()->connectWindowClosed(boost::bind(&Project::handleWindowClosed, this, _1));
   _WindowIconifiedConnection = MainApplication::the()->getMainWindow()->connectWindowIconified(boost::bind(&Project::handleWindowIconified, this, _1));
   _WindowDeiconifiedConnection = MainApplication::the()->getMainWindow()->connectWindowDeiconified(boost::bind(&Project::handleWindowDeiconified, this, _1));
   _WindowActivatedConnection = MainApplication::the()->getMainWindow()->connectWindowActivated(boost::bind(&Project::handleWindowActivated, this, _1));
   _WindowDeactivatedConnection = MainApplication::the()->getMainWindow()->connectWindowDeactivated(boost::bind(&Project::handleWindowDeactivated, this, _1));
   _WindowEnteredConnection = MainApplication::the()->getMainWindow()->connectWindowEntered(boost::bind(&Project::handleWindowEntered, this, _1));
   _WindowExitedConnection = MainApplication::the()->getMainWindow()->connectWindowExited(boost::bind(&Project::handleWindowExited, this, _1));

    //Attach the SoundManager
    SoundManager::the()->attachUpdateProducer(MainApplication::the()->getMainWindow());

    //If I have an initial Scene then enter it
    if(getInitialScene() != NULL)
    {
        setActiveScene(getInitialScene());
    }
    else
    {
        SFATAL << "Project has no Initial Scene set." << std::endl;
    }

    loadScripts();


    produceProjectStarted();
}

void Project::reset(void)
{
    //Scene Active Scene To NULL
    setActiveScene(NULL);

    //Send end to all scenes
    for(UInt32 i(0) ; i<getMFScenes()->size() ; ++i)
    {
        getScenes(i)->end();
    }

    //Recreate the Lua State
    LuaManager::the()->recreateLuaState();

    //Load the Bindings Libs

    //Toolbox Bindings
    LuaManager::the()->openLuaBindingLib(getOSGToolboxLuaBindingsLibFunctor());

    //Kabala Engine Bindings
    LuaManager::the()->openLuaBindingLib(getKabalaEngineLuaBindingsLibFunctor());

    //Reload this projects Script
    loadScripts();

    //Reset all scenes
    for(UInt32 i(0) ; i<getMFScenes()->size() ; ++i)
    {
        getScenes(i)->reset();
    }


    //If I have an initial Scene then enter it
    if(getInitialScene() != NULL)
    {
        setActiveScene(getInitialScene());
    }

    produceProjectReset();
}

void Project::stop(void)
{
    produceProjectStopping();

    setActiveScene(NULL);

    //Detach the listeners
    _UpdateConnection.disconnect();
    _MouseClickedConnection.disconnect();
    _MouseEnteredConnection.disconnect();
    _MouseExitedConnection.disconnect();
    _MousePressedConnection.disconnect();
    _MouseReleasedConnection.disconnect();
    _MouseMovedConnection.disconnect();
    _MouseDraggedConnection.disconnect();
    _MouseWheelMovedConnection.disconnect();
    _KeyPressedConnection.disconnect();
    _KeyReleasedConnection.disconnect();
    _KeyTypedConnection.disconnect();
    _WindowOpenedConnection.disconnect();
    _WindowClosingConnection.disconnect();
    _WindowClosedConnection.disconnect();
    _WindowIconifiedConnection.disconnect();
    _WindowDeiconifiedConnection.disconnect();
    _WindowActivatedConnection.disconnect();
    _WindowDeactivatedConnection.disconnect();
    _WindowEnteredConnection.disconnect();
    _WindowExitedConnection.disconnect();

    //Detach the SoundManager
    SoundManager::the()->detachUpdateProducer();

    //End all Scenes
    for(UInt32 i(0) ; i<getMFScenes()->size(); ++i)
    {
        getScenes(i)->end();
    }

    produceProjectStopped();
}

BoostPath Project::getProjectFilePath(void) const
{
    BoostPath ProjectBaseDir("");
    const BoostPath* ProjectFilePath = FilePathAttachment::getFilePath(this);
    if(ProjectFilePath != NULL)
    {
        ProjectBaseDir = ProjectFilePath->parent_path();
    }

    return ProjectBaseDir;
}

BoostPath Project::getLuaModulePath(void) const
{
    return getLuaModulesDirectory();
}

void Project::loadScripts(void)
{
    //Get the directory that the project is located in

    //Set the BoostPath used for finding modules by lua
    std::string PackagePath("?;"
                            + (getLuaModulePath() / "?" ).file_string() + ";"
                            + (getLuaModulePath() / "?.lua" ).file_string() + ";"
                            + (getLuaModulePath() / "?" /  "init.lua").file_string());

    LuaManager::the()->setPackagePath(PackagePath);

    std::string PackageCPath("?;"
                             + (getLuaModulePath() / "?" ).file_string() + ";"
                             + (getLuaModulePath() / "?.so" ).file_string() + ";"
                             + (getLuaModulePath() / "?.dylib" ).file_string() + ";"
                             + (getLuaModulePath() / "?.dll" ).file_string());
    LuaManager::the()->setPackageCPath(PackageCPath);

    //If I have a Lua Module then load it
    if(!getLuaModule().string().empty())
    {
        if(!boost::filesystem::exists(getLuaModule()))
        {
            SWARNING << "Cannot load script for project because file: "
                << getLuaModule().string() << " does not exist." << std::endl;
        }
        else if(!boost::filesystem::is_regular_file(getLuaModule()))
        {
            SWARNING << "Cannot load script for project because file: "
                << getLuaModule().string() << " is not a regular file." << std::endl;
        }
        else
        {
            LuaManager::the()->runScript(getLuaModule());
        }
    }

}

void Project::setActiveScene(SceneRefPtr TheScene)
{
    if(getInternalActiveScene() != TheScene)
    {
        if(getInternalActiveScene() != NULL)
        {
            _LastActiveScene = getInternalActiveScene();
            getInternalActiveScene()->exit();
        }

        setInternalActiveScene(TheScene);
        if(getInternalActiveScene() != NULL)
        {
            //Start the scene if it hasn't allready
            if(!getInternalActiveScene()->isStarted())
            {    
                getInternalActiveScene()->start();
            }

            getInternalActiveScene()->enter();
        }

        produceSceneChanged();
    }
}

void Project::setActiveNode(NodeRefPtr TheNode)
{
    //TODO: Implement
}

Node* Project::getActiveNode(void)
{
    return NULL;
}

void Project::attachNames(void)
{
    //Backgrounds
    for(::OSG::UInt32 i(0); i<getMFBackgrounds()->size() ; ++i)
    {
        attachName(getBackgrounds(i));
    }

    //Foregrounds
    for(::OSG::UInt32 i(0); i<getMFForegrounds()->size() ; ++i)
    {
        attachName(getForegrounds(i));
    }

    //Cameras
    for(::OSG::UInt32 i(0); i<getMFCameras()->size() ; ++i)
    {
        attachName(getCameras(i));
    }

    //ModelNodes
    for(::OSG::UInt32 i(0); i<getMFModelNodes()->size() ; ++i)
    {
        attachName(getModelNodes(i));
    }

    //Scenes
    for(::OSG::UInt32 i(0) ; i<getMFScenes()->size() ; ++i)
    {
        getScenes(i)->attachNames();
    }

}

void Project::addActiveAnimation(AnimationRefPtr TheAnimation)
{
    if(editMFActiveAnimations()->find(TheAnimation) == editMFActiveAnimations()->end())
    {
        pushToActiveAnimations(TheAnimation);
    }
}

void Project::removeActiveAnimation(AnimationRefPtr TheAnimation)
{
    if(editMFActiveAnimations()->find(TheAnimation) != editMFActiveAnimations()->end())
    {
        removeObjFromActiveAnimations(TheAnimation);
    }
}


void Project::addActiveParticleSystem(ParticleSystemRefPtr TheParticleSystem)
{
    if(editMFActiveParticleSystems()->find(TheParticleSystem) ==
       editMFActiveParticleSystems()->end())
    {
        pushToActiveParticleSystems(TheParticleSystem);
        TheParticleSystem->attachUpdateProducer(this);
    }
}

void Project::removeActiveParticleSystem(ParticleSystemRefPtr TheParticleSystem)
{
    if(editMFActiveParticleSystems()->find(TheParticleSystem) ==
       editMFActiveParticleSystems()->end())
    {
        removeObjFromActiveParticleSystems(TheParticleSystem);
    }
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

void Project::produceSceneChanged(void)
{
    ProjectEventDetailsUnrecPtr details = ProjectEventDetails::create(this, getTimeStamp());
   
    Inherited::produceSceneChanged(details);
}

void Project::produceProjectStarted(void)
{
    ProjectEventDetailsUnrecPtr details = ProjectEventDetails::create(this, getTimeStamp());
   
    Inherited::produceProjectStarted(details);
}

void Project::produceProjectStopping(void)
{
    ProjectEventDetailsUnrecPtr details = ProjectEventDetails::create(this, getTimeStamp());
   
    Inherited::produceProjectStopping(details);
}

void Project::produceProjectStopped(void)
{
    ProjectEventDetailsUnrecPtr details = ProjectEventDetails::create(this, getTimeStamp());
   
    Inherited::produceProjectStopped(details);
}

void Project::produceProjectReset(void)
{
    ProjectEventDetailsUnrecPtr details = ProjectEventDetails::create(this, getTimeStamp());
   
    Inherited::produceProjectReset(details);
}

void Project::resolveLinks(void)
{
    Inherited::resolveLinks();
        
    _UpdateConnection.disconnect();
    _MouseClickedConnection.disconnect();
    _MouseEnteredConnection.disconnect();
    _MouseExitedConnection.disconnect();
    _MousePressedConnection.disconnect();
    _MouseReleasedConnection.disconnect();
    _MouseMovedConnection.disconnect();
    _MouseDraggedConnection.disconnect();
    _MouseWheelMovedConnection.disconnect();
    _KeyPressedConnection.disconnect();
    _KeyReleasedConnection.disconnect();
    _KeyTypedConnection.disconnect();
    _WindowOpenedConnection.disconnect();
    _WindowClosingConnection.disconnect();
    _WindowClosedConnection.disconnect();
    _WindowIconifiedConnection.disconnect();
    _WindowDeiconifiedConnection.disconnect();
    _WindowActivatedConnection.disconnect();
    _WindowDeactivatedConnection.disconnect();
    _WindowEnteredConnection.disconnect();
    _WindowExitedConnection.disconnect();

}

/*----------------------- constructors & destructors ----------------------*/

Project::Project(void) :
    Inherited(),
    _PauseActiveUpdates(false),
    _LastActiveScene(NULL),
    _BlockInput(false)
{
}

Project::Project(const Project &source) :
    Inherited(source),
    _PauseActiveUpdates(source._PauseActiveUpdates),
    _LastActiveScene(NULL),
    _BlockInput(source._BlockInput)
{
}

Project::~Project(void)
{
}

/*----------------------------- class specific ----------------------------*/

void Project::changed(ConstFieldMaskArg whichField, 
                      UInt32            origin,
                      BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void Project::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump Project NI" << std::endl;
}

OSG_END_NAMESPACE
