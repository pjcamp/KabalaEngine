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

#include "KEApplicationPlayer.h"
#include <OpenSG/OSGNameAttachment.h>
#include <OpenSG/OSGDrawable.h>
#include <OpenSG/OSGPerspectiveCamera.h>
#include <OpenSG/OSGPassiveBackground.h>
#include <OpenSG/OSGViewport.h>
#include <OpenSG/OSGWindowEventProducer.h>
#include <OpenSG/OSGStringUtils.h>
#include <OpenSG/OSGChunkMaterial.h>
#include <OpenSG/OSGBlendChunk.h>
#include <OpenSG/OSGIntersectAction.h>
#include <OpenSG/OSGPolygonChunk.h>
#include <OpenSG/OSGMaterialGroup.h>
#include <OpenSG/OSGTypedGeoIntegralProperty.h>
#include <OpenSG/OSGTypedGeoVectorProperty.h>
#include <OpenSG/OSGPointLight.h>
#include <OpenSG/OSGVisitSubTree.h>
#include <OpenSG/OSGDirectionalLight.h>
#include <OpenSG/OSGSpotLight.h>
//#include <OpenSG/OSGOcclusionCullingTreeBuilder.h>
#include <OpenSG/OSGSimpleGeometryExt.h>
#include <OpenSG/OSGFieldContainerEditorDialog.h>
//#include <OpenSG/OSGGeometryUtils.h>
#include <OpenSG/OSGFCPtrFieldEditor.h>
#include <OpenSG/OSGFCPtrEditorRootedStore.h>

// the general scene file loading handler
#include <OpenSG/OSGSceneFileHandler.h>

//Input
#include <OpenSG/OSGWindowUtils.h>

#include "Application/KEMainApplication.h"
#include <OpenSG/OSGFlowLayout.h>
#include <OpenSG/OSGSceneGraphTreeModel.h>

#include "Player/HierarchyPanel/KEHierarchyPanel.h"
#include "Player/HelperPanel/KEHelperPanel.h"
#include "Player/ContentPanel/KEContentPanel.h"

#include "Player/Commands/KELoadProjectCommand.h"
#include "Player/Commands/KESaveProjectCommand.h"


#include <OpenSG/OSGGraphics2D.h>
#include <OpenSG/OSGComboBox.h>
#include <OpenSG/OSGDefaultMutableComboBoxModel.h>
#include <OpenSG/OSGUIForeground.h>
#include <OpenSG/OSGSimpleStatisticsForeground.h>
#include <OpenSG/OSGFieldAnimation.h>
#include <OpenSG/OSGKeyframeAnimator.h>
#include <OpenSG/OSGAnimationGroup.h>
#include <OpenSG/OSGLineChunk.h>
#include <OpenSG/OSGReplicateTransform.h>
#include <OpenSG/OSGBorderLayoutConstraints.h>
#include <OpenSG/OSGSplitPanel.h>
#include <OpenSG/OSGTree.h>
#include <OpenSG/OSGBorderLayout.h>
#include <OpenSG/OSGTextArea.h>


OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGApplicationPlayerBase.cpp file.
// To modify it, please change the .fcd file (OSGApplicationPlayer.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void ApplicationPlayer::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
        //Set the FCPtrFieldEditor to use the FCPtrEditorRootedStore by default
        FCPtrFieldEditor::setDefaultFindFCStorePrototype(FCPtrEditorRootedStore::create());
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void ApplicationPlayer::reset(void)
{
}

void ApplicationPlayer::attachApplication(void)
{
    Inherited::attachApplication();

    //Main Window Titlebar
    ProjectRefPtr TheProject(MainApplication::the()->getProject());
    updateWindowTitle();
    _PlayerKeyTypedConnection = MainApplication::the()->getMainWindow()->connectKeyTyped(boost::bind(&ApplicationPlayer::handlePlayerKeyTyped, this, _1));
    _HighlightNodeUpdateConnection = MainApplication::the()->getMainWindow()->connectUpdate(boost::bind(&ApplicationPlayer::handleHighlightNodeUpdate, this, _1));
}


void ApplicationPlayer::dettachApplication(void)
{
    _PlayerKeyTypedConnection.disconnect();
    _HighlightNodeUpdateConnection.disconnect();
    Inherited::dettachApplication();
}

void ApplicationPlayer::attachInterface(void)
{
}

void ApplicationPlayer::attachHandlers(void)
{
}

void ApplicationPlayer::start(void)
{
    if(MainApplication::the()->getProject() != NULL)
    {
        createDebugInterface();							// Allocate memory to the various pointers in the debug interface when the ApplicationPlayer is started

        createGotoSceneMenuItems(MainApplication::the()->getProject());

        MainApplication::the()->getProject()->start();

        enableDebug(false);
    }
}

void ApplicationPlayer::stop(void)
{
    if(MainApplication::the()->getProject() != NULL)
    {
        MainApplication::the()->getProject()->stop();
    }
}


void ApplicationPlayer::createDebugInterface(void)
{
    //Check if te Debug Interface has already been created
    if(DebuggerGraphics != NULL)
    {
        return;
    }

    // debug interface creation
    DebuggerGraphics = OSG::Graphics2D::create();

    /*************************************************** Menu creation *******************************************************************/
    // the menu items
    _LoadProjectItem = MenuItem::create();				
    _SaveProjectItem = MenuItem::create();				
    _SaveProjectAsItem = MenuItem::create();				

    _ResetItem = MenuItem::create();				
    _ForceQuitItem = MenuItem::create();			

    _UndoItem = MenuItem::create();				
    _RedoItem = MenuItem::create();			

    _NextItem = MenuItem::create();				
    _PrevItem = MenuItem::create();				
    _FirstItem = MenuItem::create();				
    _LastItem = MenuItem::create();				
    _SceneSubItem = Menu::create();				

    _FlyNavigatorItem = MenuItem::create();		
    _TrackballNavigatorItem = MenuItem::create();

    _BasicItem = MenuItem::create();				
    _RenderItem = MenuItem::create();			
    _PhysicsItem = MenuItem::create();
    _ParticleSystemItem = MenuItem::create();	
    _AnimationItem = MenuItem::create();
    _PauseActiveUpdatesItem = MenuItem::create();
    _DrawBoundingVolumesItem = MenuItem::create();
    _FrustrumCullingItem = MenuItem::create();
    _DrawPhysicsCharacteristicsItem = MenuItem::create();


    // setting the fields of the menu items
    _LoadProjectItem->setText("Open Project ...");
    _LoadProjectItem->setEnabled(false);
    _LoadProjectItem->setAcceleratorKey(KeyEventDetails::KEY_O);
    _LoadProjectItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _LoadProjectItem->setMnemonicKey(KeyEventDetails::KEY_O);

    _SaveProjectItem->setText("Save Project");
    _SaveProjectItem->setAcceleratorKey(KeyEventDetails::KEY_S);
    _SaveProjectItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _SaveProjectItem->setMnemonicKey(KeyEventDetails::KEY_S);

    _SaveProjectAsItem->setText("Save Project As ...");
    _SaveProjectAsItem->setAcceleratorKey(KeyEventDetails::KEY_S);
    _SaveProjectAsItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _SaveProjectAsItem->setMnemonicKey(KeyEventDetails::KEY_S);

    _ResetItem->setText("Reset");
    _ResetItem->setAcceleratorKey(KeyEventDetails::KEY_E);
    _ResetItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _ResetItem->setMnemonicKey(KeyEventDetails::KEY_E);

    _ForceQuitItem ->setText("Force Quit");
    _ForceQuitItem ->setAcceleratorKey(KeyEventDetails::KEY_Q);
    _ForceQuitItem ->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _ForceQuitItem ->setMnemonicKey(KeyEventDetails::KEY_Q);

    _UndoItem->setText("Undo");
    _UndoItem->setAcceleratorKey(KeyEventDetails::KEY_Z);
    _UndoItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _UndoItem->setMnemonicKey(KeyEventDetails::KEY_U);

    _RedoItem->setText("Redo");
    _RedoItem->setAcceleratorKey(KeyEventDetails::KEY_Z);
    _RedoItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND |
                                       KeyEventDetails::KEY_MODIFIER_SHIFT);
    _RedoItem->setMnemonicKey(KeyEventDetails::KEY_R);

    _NextItem ->setText("Next");
    _NextItem ->setAcceleratorKey(KeyEventDetails::KEY_TAB);
    //_NextItem ->setAcceleratorModifiers(!KeyEventDetails::KEY_MODIFIER_SHIFT);

    _PrevItem->setText("Previous");
    _PrevItem->setAcceleratorKey(KeyEventDetails::KEY_TAB);
    _PrevItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_SHIFT);

    _FirstItem->setText("First");
    _FirstItem->setAcceleratorKey(KeyEventDetails::KEY_F);
    _FirstItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _FirstItem->setMnemonicKey(KeyEventDetails::KEY_F);

    _LastItem->setText("Last");
    _LastItem->setAcceleratorKey(KeyEventDetails::KEY_L);
    _LastItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _LastItem->setMnemonicKey(KeyEventDetails::KEY_L);

    _SceneSubItem->setText("Scenes");

    _FlyNavigatorItem->setText("FlyNavigator");
    _FlyNavigatorItem->setAcceleratorKey(KeyEventDetails::KEY_N);
    _FlyNavigatorItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _FlyNavigatorItem->setMnemonicKey(KeyEventDetails::KEY_N);

    _TrackballNavigatorItem->setText("TrackballNavigator");
    _TrackballNavigatorItem->setAcceleratorKey(KeyEventDetails::KEY_T);
    _TrackballNavigatorItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _TrackballNavigatorItem->setMnemonicKey(KeyEventDetails::KEY_T);

    _BasicItem->setText("Basic");
    _BasicItem->setAcceleratorKey(KeyEventDetails::KEY_B);
    _BasicItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _BasicItem->setMnemonicKey(KeyEventDetails::KEY_B);

    _RenderItem->setText("Render");
    _RenderItem->setAcceleratorKey(KeyEventDetails::KEY_R);
    _RenderItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _RenderItem->setMnemonicKey(KeyEventDetails::KEY_R);

    _PhysicsItem->setText("Physics");
    _PhysicsItem->setMnemonicKey(KeyEventDetails::KEY_Y);

    _ParticleSystemItem->setText("ParticleSystem");
    _ParticleSystemItem->setMnemonicKey(KeyEventDetails::KEY_Z);

    _AnimationItem->setText("Animation");
    _AnimationItem->setMnemonicKey(KeyEventDetails::KEY_A);

    _PauseActiveUpdatesItem->setText("Pause Active Updates");
    _PauseActiveUpdatesItem->setAcceleratorKey(KeyEventDetails::KEY_SPACE);
    //_PauseActiveUpdatesItem->setMnemonicKey(KeyEventDetails::KEY_SPACE);

    _DrawBoundingVolumesItem->setText("Draw Bounding Volumes");
    _DrawBoundingVolumesItem->setAcceleratorKey(KeyEventDetails::KEY_V);
    _DrawBoundingVolumesItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND | KeyEventDetails::KEY_MODIFIER_SHIFT);
    _DrawBoundingVolumesItem->setMnemonicKey(KeyEventDetails::KEY_V);

    _FrustrumCullingItem->setText("Disable Frustrum Culling ");
    _FrustrumCullingItem->setAcceleratorKey(KeyEventDetails::KEY_F);
    _FrustrumCullingItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _FrustrumCullingItem->setMnemonicKey(KeyEventDetails::KEY_F);

    _DrawPhysicsCharacteristicsItem->setText("Draw Physics Characteristics ");
    _DrawPhysicsCharacteristicsItem->setAcceleratorKey(KeyEventDetails::KEY_P);
    _DrawPhysicsCharacteristicsItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    _DrawPhysicsCharacteristicsItem->setMnemonicKey(KeyEventDetails::KEY_P);


    /*
       HideItem->setText("Hide Item");
    // HideItem->setAcceleratorKey(KeyEventDetails::KEY_H);
    // HideItem->setAcceleratorModifiers(KeyEventDetails::KEY_MODIFIER_COMMAND);
    // HideItem->setMnemonicKey(KeyEventDetails::KEY_P);
    */	
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // creation of the Tree
    _HelperPanel = HelperPanel::create();
    setName(_HelperPanel,"__KABALA_ENGINE_DEBUGGER_HELPER_PANEL");
    _HelperPanel->setApplicationPlayer(this);

    _HelperPanel->setupInfoTabPanel();
    _HelperPanel->setupHistoryList();
    _HelperPanel->setupRest();


    _HierarchyPanel = HierarchyPanel::create();
    setName(_HierarchyPanel,"__KABALA_ENGINE_DEBUGGER_HIERARCHY_PANEL");
    _HierarchyPanel->setApplicationPlayer(ApplicationPlayerRefPtr(this));
    _HierarchyPanel->createDefaultHierarchyPanel();

    _ContentPanel = ContentPanel::create();
    setName(_ContentPanel,"__KABALA_ENGINE_DEBUGGER_CONTENT_PANEL");
    _ContentPanel->setApplicationPlayer(ApplicationPlayerRefPtr(this));

    BorderLayoutConstraintsRefPtr ContentConstraints = OSG::BorderLayoutConstraints::create();

    ContentConstraints->setRegion(BorderLayoutConstraints::BORDER_CENTER);

    _ContentPanel->setConstraints(ContentConstraints);
    _ContentPanel->init();

    _EditProjectButton = Button::create();
    _EditProjectButton->setText("Edit Project");
    _EditProjectButton->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));

    _OpenFileButton = Button::create();
    _OpenFileButton->setText("Open File");
    //_OpenFileButton->setPreferredSize(Vec2f(100,50));
    _OpenFileButton->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));

    _SaveFileButton = Button::create();
    _SaveFileButton->setText("Save File");
    //_SaveFileButton->setPreferredSize(Vec2f(100,50));
    _SaveFileButton->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));

    /*_CloseFileButton = Button::create();

      _CloseFileButton->setText("Close File");
      _CloseFileButton->setPreferredSize(Vec2f(100,50));

      _CloseFileButton->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
      */

    _ModeComboBox = ComboBox::create();

    BorderLayoutConstraintsRefPtr ToolbarConstraints = OSG::BorderLayoutConstraints::create();

    ToolbarConstraints->setRegion(BorderLayoutConstraints::BORDER_NORTH);

    _Toolbar = Panel::create();

    _Toolbar->setConstraints(ToolbarConstraints);
    _Toolbar->setPreferredSize(Vec2f(200,40));

    FlowLayoutRefPtr ToolbarLayout = OSG::FlowLayout::create();
    ToolbarLayout->setOrientation(FlowLayout::HORIZONTAL_ORIENTATION);
    ToolbarLayout->setMajorAxisAlignment(1.0);

    _Toolbar->pushToChildren(_EditProjectButton);
    _Toolbar->pushToChildren(_OpenFileButton);
    _Toolbar->pushToChildren(_SaveFileButton);
    _Toolbar->pushToChildren(_ModeComboBox);
    _Toolbar->setLayout(ToolbarLayout);


    // creation of menus and addition of menu items to them
    _ProjectMenu = Menu::create();
    _ProjectMenu->addItem(_LoadProjectItem);
    _ProjectMenu->addItem(_SaveProjectItem);
    _ProjectMenu->addItem(_SaveProjectAsItem);
    _ProjectMenu->addSeparator();
    _ProjectMenu->addItem(_ResetItem);
    _ProjectMenu->addSeparator();
    _ProjectMenu->addItem(_ForceQuitItem);

    _EditMenu = Menu::create();
    _EditMenu->addItem(_UndoItem);
    _EditMenu->addItem(_RedoItem);


    _SceneMenu = Menu::create();
    _SceneMenu->addItem(_NextItem);
    _SceneMenu->addItem(_PrevItem);
    _SceneMenu->addItem(_FirstItem);
    _SceneMenu->addItem(_LastItem);
    _SceneMenu->addSeparator();
    _SceneMenu->addItem(_SceneSubItem);


    _NavigatorMenu = Menu::create();
    _NavigatorMenu->addItem(_FlyNavigatorItem);
    _NavigatorMenu->addItem(_TrackballNavigatorItem);

    _StatisticsMenu = Menu::create();
    _StatisticsMenu->addItem(_BasicItem);
    _StatisticsMenu->addItem(_RenderItem);
    _StatisticsMenu->addItem(_PhysicsItem);
    _StatisticsMenu->addItem(_ParticleSystemItem);
    _StatisticsMenu->addItem(_AnimationItem);

    _ToggleMenu = Menu::create();
    _ToggleMenu->addItem(_PauseActiveUpdatesItem);
    _ToggleMenu->addItem(_DrawBoundingVolumesItem);
    _ToggleMenu->addItem(_FrustrumCullingItem);
    _ToggleMenu->addItem(_DrawPhysicsCharacteristicsItem);

    // setting the fields for the menus 
    _ProjectMenu->setText("Project");
    _ProjectMenu->setMnemonicKey(KeyEventDetails::KEY_P);

    _EditMenu->setText("Edit");
    _EditMenu->setMnemonicKey(KeyEventDetails::KEY_D);

    _SceneMenu->setText("Scene");
    _SceneMenu->setMnemonicKey(KeyEventDetails::KEY_C);

    _NavigatorMenu->setText("Navigator");
    _NavigatorMenu->setMnemonicKey(KeyEventDetails::KEY_N);

    _StatisticsMenu->setText("Statistics");
    _StatisticsMenu->setMnemonicKey(KeyEventDetails::KEY_T);

    _ToggleMenu->setText("Toggle");
    _ToggleMenu->setMnemonicKey(KeyEventDetails::KEY_G);

    // adding actionlisteners to each of the menuitems
    _LoadProjectItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _SaveProjectItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _SaveProjectAsItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _ResetItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _ForceQuitItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));

    _NextItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _PrevItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _FirstItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _LastItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _FlyNavigatorItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _TrackballNavigatorItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _BasicItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _RenderItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _PhysicsItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _ParticleSystemItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _AnimationItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _PauseActiveUpdatesItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _DrawBoundingVolumesItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _FrustrumCullingItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _DrawPhysicsCharacteristicsItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _ProjectMenu->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _EditMenu->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _SceneMenu->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));	
    _NavigatorMenu->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _StatisticsMenu->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));
    _ToggleMenu->connectActionPerformed(boost::bind(&ApplicationPlayer::handleBasicAction, this, _1));

    _UndoItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleUndoButtonAction, this, _1));
    _RedoItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleRedoButtonAction, this, _1));

    // Creation of the menubar and addition of the menus to it
    _MainMenuBar = MenuBar::create();
    _MainMenuBar->addMenu(_ProjectMenu);
    _MainMenuBar->addMenu(_EditMenu);
    _MainMenuBar->addMenu(_SceneMenu);
    _MainMenuBar->addMenu(_NavigatorMenu);
    _MainMenuBar->addMenu(_StatisticsMenu);
    _MainMenuBar->addMenu(_ToggleMenu);

    //ToolbarLayout2= OSG::BorderLayout::create();

    _HierarchyPanel->setPreferredSize(Vec2f(400,700));

    _ModeComboBoxModel = DefaultMutableComboBoxModel::create();
    _ModeComboBoxModel->addElement(boost::any(std::string("Scene Graph")));
    _ModeComboBoxModel->addElement(boost::any(std::string("Lua Graph")));

    _ModeComboBox->setMinSize(Vec2f(100.0,20));
    _ModeComboBox->setEditable(false);
    _ModeComboBox->setModel(_ModeComboBoxModel);

    _ModeComboBoxModel->connectSelectionChanged(boost::bind(&ApplicationPlayer::handleComboBoxSelectionChanged, this, _1));

    // Determine where the _ModeComboBox starts
    _ModeComboBox->setSelectedIndex(0);

    setupPopupMenu();

    /*************************************************** _DebugWindowSplitPanel creation **********************************************************************/

    BorderLayoutRefPtr ToolbarAndContentPanelLayout = BorderLayout::create();

    _ToolbarAndContentPanel = OSG::Panel::createEmpty();

    _ToolbarAndContentPanel->setLayout(ToolbarAndContentPanelLayout);
    _ToolbarAndContentPanel->pushToChildren(_Toolbar);
    _ToolbarAndContentPanel->pushToChildren(_ContentPanel);

    _TopHalfSplitPanel = OSG::SplitPanel::create();

    _TopHalfSplitPanel->setMinComponent(_HierarchyPanel);
    _TopHalfSplitPanel->setMaxComponent(_ToolbarAndContentPanel);
    _TopHalfSplitPanel->setOrientation(SplitPanel::HORIZONTAL_ORIENTATION);
    _TopHalfSplitPanel->setDividerPosition(350.0f); 
    // location from the left/top
    _TopHalfSplitPanel->setDividerSize(5);
    //_TopHalfSplitPanel->setExpandable(true);
    _TopHalfSplitPanel->setMaxDividerPosition(.85);
    _TopHalfSplitPanel->setMinDividerPosition(150.0f);

    _DebugWindowSplitPanelConstraints = OSG::BorderLayoutConstraints::create();

    _DebugWindowSplitPanelConstraints->setRegion(BorderLayoutConstraints::BORDER_CENTER);

    _DebugWindowSplitPanel = OSG::SplitPanel::create();

    _DebugWindowSplitPanel->setConstraints(_DebugWindowSplitPanelConstraints);
    _DebugWindowSplitPanel->setMaxComponent(_HelperPanel);//->SplitPanelPanel);
    _DebugWindowSplitPanel->setMinComponent(_TopHalfSplitPanel);
    _DebugWindowSplitPanel->setOrientation(SplitPanel::VERTICAL_ORIENTATION);
    _DebugWindowSplitPanel->setDividerPosition(.75); 
    // location from the left/top
    _DebugWindowSplitPanel->setDividerSize(5);
    // _DebugWindowSplitPanel->setExpandable(false);
    _DebugWindowSplitPanel->setMaxDividerPosition(.95);
    _DebugWindowSplitPanel->setMinDividerPosition(.15);
    /*************************************************** END _DebugWindowSplitPanel creation **********************************************************************/

    /*************************************************** MainInternalWindow creation*************************************************************/

    BorderLayoutRefPtr MainInternalWindowLayout = OSG::BorderLayout::create();

    // Nothing

    // Create The Main InternalWindow


    MainInternalWindow = OSG::InternalWindow::create();
    setName(MainInternalWindow,"__KABALA_ENGINE_DEBUGGER_MAIN_WINDOW");
    MainInternalWindow->pushToChildren(_DebugWindowSplitPanel);
    MainInternalWindow->setLayout(MainInternalWindowLayout);
    MainInternalWindow->setBackgrounds(NULL);
    MainInternalWindow->setBorders(NULL);
    MainInternalWindow->setAlignmentInDrawingSurface(Vec2f(0.5f,0.5f));
    MainInternalWindow->setMenuBar(_MainMenuBar);
    MainInternalWindow->setScalingInDrawingSurface(Vec2f(1.0f,1.0f));
    MainInternalWindow->setDrawTitlebar(false);
    MainInternalWindow->setResizable(false);

    MainInternalWindow->setFocusedComponent(_HelperPanel->_CodeTextArea);

    /*************************************************** END MainInternalWindow creation*************************************************************/


    // Create the DrawingSurface Object
    DebuggerDrawingSurface = UIDrawingSurface::create();
    DebuggerDrawingSurface->setGraphics(DebuggerGraphics);

    DebuggerDrawingSurface->openWindow(MainInternalWindow);

    // Create the UI Foreground Object
    DebuggerUIForeground = OSG::UIForeground::create();
    setName(DebuggerUIForeground,"__KABALA_ENGINE_DEBUGGER_UIFOREGROUND");

    DebuggerUIForeground->setDrawingSurface(DebuggerDrawingSurface);

    //Create the Viewport
    _DebugViewport = createDebugViewport();

    //Create the Debug Camera Animation Group
    createDebugCameraAnim();

    //Create the statistic foregrounds
	initDebugStatForegrounds();
}

void ApplicationPlayer::updateGotoSceneMenuItems(ProjectRefPtr TheProject)
{
    SceneRefPtr CurrentlyActiveScene = TheProject->getActiveScene();
    SceneRefPtr GotoItemScene;
    MenuItemRefPtr GotoItem;

    //Disable the Goto Menu Item for the currently active Scene
    for(UInt32 i(0) ; i<_SceneSubItem->getNumItems() ; ++i)
    {
        GotoItem = _SceneSubItem->getItem(i);
        GotoItemScene = TheProject->getSceneByName(GotoItem->getText());
        if(CurrentlyActiveScene == GotoItemScene
           && GotoItem->getEnabled())
        {
            GotoItem->setEnabled(false);
        }
        else if(CurrentlyActiveScene != GotoItemScene
                && !GotoItem->getEnabled())
        {
            GotoItem->setEnabled(true);
        }
    }
}

void ApplicationPlayer::createGotoSceneMenuItems(ProjectRefPtr TheProject)
{
    //Clear all of the previous Items
    _SceneSubItem->removeAllItems();

    //Make a Menu Item for each of the scenes
    const Char8* SceneCharName(NULL);
    std::string SceneName;
    MenuItemRefPtr NewSceneItem;
    for(UInt32 i(0) ; i<TheProject->getMFScenes()->size() ; ++i)
    {
        //Get the Name of the Scene
        SceneCharName = getName(TheProject->getScenes(i));

        if(SceneCharName == NULL)
        {
            SceneName = "UNTITLED SCENE";
        }
        else
        {
            SceneName = SceneCharName;
        }

        //Create the menu Item
        NewSceneItem = MenuItem::create();
        NewSceneItem->setText(SceneName);
        //Attach the Goto Listener
        NewSceneItem->connectActionPerformed(boost::bind(&ApplicationPlayer::handleGotoSceneItemAction, this, _1));

        //Add the Scene Menu Item to the SubMenu
        _SceneSubItem->addItem(NewSceneItem);
    }
}

void ApplicationPlayer::attachDebugInterface(void)
{
    if( MainApplication::the()->getProject()->getActiveScene()->getMFViewports()->size() == 0 ||
        MainApplication::the()->getProject()->getActiveScene()->getViewports(0) == NULL)
    {
        SWARNING << "ApplicationPlayer::attachDebugInterface(): No Viewports in current scene.  There should be at least one defined." << std::endl;
    }
    else
    {
        if(MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->getRoot() == NULL)
        {
            SWARNING << "ApplicationPlayer::attachDebugInterface(): No root for current viewport!" << std::endl;
        }
        else
        {
            if(_HierarchyPanel->getSceneGraphTreeModel()->getRootNode() != MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->getRoot())
            {
                SWARNING << "Setting Root of SceneGraph tree model" <<
                    std::endl;
                _HierarchyPanel->getSceneGraphTreeModel()->setRoot(MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->getRoot());
            }
        }

    }

    //Root the FCPtr
    FCPtrEditorStorePtr FCEditorStore = FCPtrFieldEditor::getDefaultFindFCStorePrototype();
    if(boost::dynamic_pointer_cast<FCPtrEditorRootedStore>(FCEditorStore))
    {
        FCPtrEditorRootedStore::FieldContianerVector Roots;
        Roots.push_back(MainApplication::the()->getProject());
        boost::dynamic_pointer_cast<FCPtrEditorRootedStore>(FCEditorStore)->setRoots(Roots);
    }

    updateHighlightNode();
    DebuggerDrawingSurface->setEventProducer(MainApplication::the()->getMainWindow());

    attachDebugViewport();

    //MainApplication::the()->getMainWindow()->getPort(0)->addForeground(DebuggerUIForeground);
}


void ApplicationPlayer::detachDebugInterface(void)
{

    DebuggerDrawingSurface->setEventProducer(NULL);

    detachDebugViewport();
}

void ApplicationPlayer::enableDebug(bool EnableDebug)
{
    if(EnableDebug && !_IsDebugActive)
    {
        //Attach the Interface
        attachDebugInterface();

        updateGotoSceneMenuItems(MainApplication::the()->getProject());

        //Attach Listeners to the project
        _ProjectSceneChangedConnection = MainApplication::the()->getProject()->connectSceneChanged(boost::bind(&ApplicationPlayer::handleProjectSceneChanged, this, _1));
        updateUndoRedoInterfaces(_TheUndoManager);

        //Update Title
        updateWindowTitle();

        //Turn on Input Blocking
        setSceneInputBlocking(MainApplication::the()->getSettings().get<bool>("player.debugger.block_scene_input"));

        _WasMouseHidden = !MainApplication::the()->getMainWindow()->getShowCursor();
        if(_WasMouseHidden)
        {
            MainApplication::the()->getMainWindow()->setShowCursor(true);
        }
        _WasMouseAttached = !MainApplication::the()->getMainWindow()->getAttachMouseToCursor();

        if(_WasMouseAttached)
        {
            MainApplication::the()->getMainWindow()->setAttachMouseToCursor(true);
        }
    }
    else if(!EnableDebug && _IsDebugActive)
    {
        detachDebugInterface();

        //dettach Listeners to the project
        _ProjectSceneChangedConnection.disconnect();

        //Turn off Input Blocking
        setSceneInputBlocking(false);

        //Update Title
        updateWindowTitle();

        if(_WasMouseHidden)
        {
            MainApplication::the()->getMainWindow()->setShowCursor(false);
        }
        if(_WasMouseAttached)
        {
            MainApplication::the()->getMainWindow()->setAttachMouseToCursor(false);
        }
    }
    _IsDebugActive = EnableDebug;
}

void ApplicationPlayer::updateWindowTitle(void)
{
    std::string MainWindowTitle(MainApplication::the()->getProject()->getMainWindowTitle());
    if(_IsDebugActive)
    {
        MainWindowTitle += "(Debug)";
    }
    if(MainApplication::the()->getProject()->isInputBlocked())
    {
        MainWindowTitle += "(Input Blocked)";
    }
    MainApplication::the()->getMainWindow()->setTitle(MainWindowTitle);
}

void ApplicationPlayer::handleBasicAction(ActionEventDetails* const details)
{
    if(details->getSource() == _ResetItem)
    {
        //Reset the Project
        MainApplication::the()->getProject()->reset();
        MainApplication::the()->getProject()->setActiveScene(MainApplication::the()->getProject()->getLastActiveScene());
    }
    else if(details->getSource() == _LoadProjectItem)
    {
        CommandPtr LoadProjectItemCommand = LoadProjectCommand::create();
        getCommandManager()->executeCommand(LoadProjectItemCommand);
    }
    else if(details->getSource() == _SaveProjectItem)
    {
        CommandPtr SaveProjectItemCommand = SaveProjectCommand::create(false);
        getCommandManager()->executeCommand(SaveProjectItemCommand);
    }
    else if(details->getSource() == _SaveProjectAsItem)
    {
        CommandPtr SaveProjectItemCommand = SaveProjectCommand::create(true);
        getCommandManager()->executeCommand(SaveProjectItemCommand);
    }
    else if(details->getSource() == _ForceQuitItem)
    {
        MainApplication::the()->exit();
    }

    else if(details->getSource() == _NextItem)
    {
        Int32 SceneIndex(MainApplication::the()->getProject()->getMFScenes()->findIndex(MainApplication::the()->getProject()->getActiveScene()));
        SceneIndex = (SceneIndex+1) % MainApplication::the()->getProject()->getMFScenes()->size();

        MainApplication::the()->getProject()->setActiveScene(MainApplication::the()->getProject()->getScenes(SceneIndex));
    }
    else if(details->getSource() == _PrevItem)
    {
        Int32 SceneIndex(MainApplication::the()->getProject()->getMFScenes()->findIndex(MainApplication::the()->getProject()->getActiveScene()));

        if(SceneIndex == 0)
        {
            SceneIndex = MainApplication::the()->getProject()->getMFScenes()->size();
        }
        --SceneIndex;

        MainApplication::the()->getProject()->setActiveScene(MainApplication::the()->getProject()->getScenes(SceneIndex));
    }
    else if(details->getSource() == _FirstItem)
    {
        MainApplication::the()->getProject()->setActiveScene(MainApplication::the()->getProject()->getScenes(0));
    }

    else if(details->getSource() == _LastItem)
    {
        UInt32 SceneNumber = MainApplication::the()->getProject()->getMFScenes()->size() - 1;
        MainApplication::the()->getProject()->setActiveScene(MainApplication::the()->getProject()->getScenes(SceneNumber));
    }
    else if(details->getSource() == _FlyNavigatorItem )
    {
        //TODO: Implement
    }
    else if(details->getSource() == _TrackballNavigatorItem )
    {
        //TODO: Implement
    }
    else if(details->getSource() == _BasicItem)
    {
        toggleStatForeground(_DebugBasicStatForeground);
    }
    else if(details->getSource() == _RenderItem)
    {
        toggleStatForeground(_DebugRenderStatForeground);
    }
    else if(details->getSource() == _PhysicsItem)
    {
        toggleStatForeground(_DebugPhysicsStatForeground);
    }
    else if(details->getSource() == _ParticleSystemItem)
    {
        toggleStatForeground(_DebugParticleSystemStatForeground);
    }
    else if(details->getSource() == _AnimationItem)
    {
        toggleStatForeground(_DebugAnimationStatForeground);
    }
    else if(details->getSource() == _PauseActiveUpdatesItem)
    {
        MainApplication::the()->getProject()->togglePauseActiveUpdates();

        //Update the Menu Item
        if(MainApplication::the()->getProject()->getPauseActiveUpdates())
        {
            _PauseActiveUpdatesItem->setText("Unpause Active Updates");
        }
        else
        {
            _PauseActiveUpdatesItem->setText("Pause Active Updates");
        }
    }
    else if(details->getSource() == _DrawBoundingVolumesItem)
    {
        toggleDrawBoundingVolumes();

        //Update the Menu Item
        if(MainApplication::the()->getMainWindow()->getRenderAction()->getVolumeDrawing())
        {
            _DrawBoundingVolumesItem->setText("Hide Bounding Volumes");
        }
        else
        {
            _DrawBoundingVolumesItem->setText("Draw Bounding Volumes");
        }
    }
    else if(details->getSource() == _FrustrumCullingItem)
    {
        toggleFrustumCulling();

        //Update the Menu Item
        if(MainApplication::the()->getMainWindow()->getRenderAction()->getFrustumCulling())
        {
            _FrustrumCullingItem->setText("Disable Frustrum Culling");
        }
        else
        {
            _FrustrumCullingItem->setText("Enable Frustrum Culling");
        }
    }
    else if(details->getSource() == _DrawPhysicsCharacteristicsItem)
    {
        toggleDrawPhysicsCharacteristics();

        //Update the Menu Item
        //Add the Physics Drawable Node to the project
        if(MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->getRoot()->findChild(getPhysicsDrawableNode()) < 0)
        {
            _DrawPhysicsCharacteristicsItem->setText("Draw Physics Characteristics");
        }
        else
        {
            _DrawPhysicsCharacteristicsItem->setText("Hide Physics Characteristics");
        }
    }
    else if(details->getSource() == _ModeComboBox)
    {
        int index = _ModeComboBox->getSelectedIndex();
        _HierarchyPanel->setView(index);
        _ContentPanel->setView(index);
    }
    else if(details->getSource() == _EditProjectButton)
    {
        openEditor(MainApplication::the()->getProject());
    }
    else if(details->getSource() == _OpenFileButton)
    {

        std::vector<WindowEventProducer::FileDialogFilter> Filters;
        Filters.push_back(WindowEventProducer::FileDialogFilter("Lua Files","lua"));
        Filters.push_back(WindowEventProducer::FileDialogFilter("All","*"));


        std::vector<BoostPath> FilesToOpen;
        FilesToOpen = MainApplication::the()->getMainWindow()->openFileDialog("Open File Window",
                                                                                           Filters,
                                                                                           BoostPath(".."),
                                                                                           true);

        for(std::vector<BoostPath>::iterator Itor(FilesToOpen.begin()) ; Itor != FilesToOpen.end(); ++Itor)
        {
            _ContentPanel->addTabWithText(*Itor);
        }
    }
    else if(details->getSource() == _SaveFileButton)
    {
        std::vector<WindowEventProducer::FileDialogFilter> Filters;
        Filters.push_back(WindowEventProducer::FileDialogFilter("Lua Files","lua"));
        Filters.push_back(WindowEventProducer::FileDialogFilter("All","*"));

        BoostPath SavePath = MainApplication::the()->getMainWindow()->saveFileDialog("Save File Window",
                                                                                                  Filters,
                                                                                                  std::string("NewLuaFile.lua"),
                                                                                                  BoostPath(".."),
                                                                                                  true);

        _ContentPanel->saveTextFile(SavePath);
    }
    else
    {
        //do nothing
    }
}



void ApplicationPlayer::handlePlayerKeyTyped(KeyEventDetails* const details)
{
    if(details->getKey() == KeyEventDetails::KEY_D && details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND && details->getModifiers() & KeyEventDetails::KEY_MODIFIER_SHIFT)
    {
        enableDebug(!_IsDebugActive);
        return;
    }

    if(_IsDebugActive)
    {


        if(isNumericKey(static_cast<KeyEventDetails::Key>(details->getKey())) && details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND && details->getModifiers() & KeyEventDetails::KEY_MODIFIER_SHIFT)
        {
            //Switch To scene #
            UInt32 SceneNumber(boost::lexical_cast<UInt32>(KeyEventDetails::getCharFromKey(details->getKey(),0)));
            if(SceneNumber < MainApplication::the()->getProject()->getMFScenes()->size())
            {
                MainApplication::the()->getProject()->setActiveScene(MainApplication::the()->getProject()->getScenes(SceneNumber));
            }
        }

        //if(details->getKey() == KeyEventDetails::KEY_1 && (details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND))
        //{
            //MainInternalWindow->setFocusedComponent(_HelperPanel->_CodeTextArea);
            //_HelperPanel->_InfoTabPanel->setSelectedIndex(0);

        //}

        if(details->getKey() == KeyEventDetails::KEY_T && (details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND))
        {
            _ContentPanel->setIsSplit(!_ContentPanel->getIsSplit());
        }

        //Pause Active Updates
        //else if(details->getKey() == KeyEventDetails::KEY_SPACE)
        //{
        //MainApplication::the()->getProject()->togglePauseActiveUpdates();
        //}

        ////Toggle Input Blocking
        else if(details->getKey() == KeyEventDetails::KEY_I && (details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND))
        {
            toggleSceneInputBlocking();
        }

        //Scene Activation
        if(details->getKey() == KeyEventDetails::KEY_E && (details->getModifiers() & KeyEventDetails::KEY_MODIFIER_COMMAND))
        {
            //Reset the Project
            MainApplication::the()->getProject()->reset();
            MainApplication::the()->getProject()->setActiveScene(MainApplication::the()->getProject()->getLastActiveScene());
        }
    }
}

void ApplicationPlayer::toggleSceneInputBlocking(void)
{
    setSceneInputBlocking(!MainApplication::the()->getProject()->isInputBlocked());
}

void ApplicationPlayer::setSceneInputBlocking(bool block)
{
    MainApplication::the()->getProject()->blockInput(block);
    for(UInt32 i(0) ; i<MainApplication::the()->getProject()->getMFScenes()->size(); ++i)
    {
        MainApplication::the()->getProject()->getScenes(i)->blockInput(block);
    }
    updateWindowTitle();
}

void ApplicationPlayer::toggleDrawBoundingVolumes(void)
{
    MainApplication::the()->getMainWindow()->getRenderAction()->setVolumeDrawing(!MainApplication::the()->getMainWindow()->getRenderAction()->getVolumeDrawing());
}

void ApplicationPlayer::toggleDrawPhysicsCharacteristics(void)
{
    NodeRefPtr CurrentRoot(MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->getRoot());
    NodeRefPtr PhysNode(getPhysicsDrawableNode());

    //Get the Root Node of the Project
    _PhysDrawable->setRoot(CurrentRoot);

    //Add the Physics Drawable Node to the project
    if(CurrentRoot->findChild(PhysNode) < 0)
    {
        CurrentRoot->addChild(PhysNode);
    }
    else
    {
        CurrentRoot->subChild(PhysNode);
    }
}


Node* ApplicationPlayer::getPhysicsDrawableNode(void)
{
    if(_PhysDrawable == NULL)
    {
        //Make The Physics Characteristics Core
        _PhysDrawable = PhysicsCharacteristicsDrawable::create();
    }
    if(_PhysDrawableNode == NULL)
    {
        //Make The Physics Characteristics Node
        _PhysDrawableNode = Node::create();
        _PhysDrawableNode->setCore(_PhysDrawable);
    }
    return _PhysDrawableNode;
}

void ApplicationPlayer::gotoScene(SceneRefPtr TheScene)
{
    MainApplication::the()->getProject()->setActiveScene(TheScene);
}

void ApplicationPlayer::toggleFrustumCulling(void)
{
    MainApplication::the()->getMainWindow()->getRenderAction()->setFrustumCulling(!MainApplication::the()->getMainWindow()->getRenderAction()->getFrustumCulling());
}

void ApplicationPlayer::toggleStatForeground(StatisticsForeground* const TheForeground)
{
    Int32 Index(MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->getMFForegrounds()->findIndex(TheForeground));
    if(Index != -1)
    {
        //If the Stat foreground is present then switch it off
        MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->removeFromForegrounds(Index);
    }
    else
    {
        //If not present then switch all other stat foregrounds off
        hideAllStatForegrounds();

        //and switch it on
        MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->addForeground(TheForeground);

        MainApplication::the()->getMainWindow()->getRenderAction()->setStatCollector(TheForeground->getCollector());
    }
}

void ApplicationPlayer::hideAllStatForegrounds(void)
{

    //Hide Basic Stat Foreground if present
    MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->removeObjFromForegrounds(_DebugBasicStatForeground);

    //Hide Render Stat Foreground if present
    MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->removeObjFromForegrounds(_DebugRenderStatForeground);

    //Hide Physics Stat Foreground if present
    MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->removeObjFromForegrounds(_DebugPhysicsStatForeground);

    //Hide Particle System Stat Foreground if present
    MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->removeObjFromForegrounds(_DebugParticleSystemStatForeground);

    //Hide Animation Stat Foreground if present
    MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->removeObjFromForegrounds(_DebugAnimationStatForeground);
}

void ApplicationPlayer::initDebugStatForegrounds(void)
{
    Color4f StatColor(0.9f,0.9f,0.9f,0.8f),
            StatShadowColor(0.0f,0.0f,0.0f,0.8f),
            StatBorderColor(0.9f,0.9f,0.9f,0.8f),
            StatBackgroundColor(0.0f,0.0f,0.0f,0.7f);

    UInt32 StatFontSize(25);

    //Basic Statistics
    _DebugBasicStatForeground = SimpleStatisticsForeground::create();
    _DebugBasicStatForeground->setHorizontalAlign(SimpleStatisticsForeground::Right);
    _DebugBasicStatForeground->setVerticalAlign(SimpleStatisticsForeground::Middle);
    _DebugBasicStatForeground->setSize(StatFontSize);
    _DebugBasicStatForeground->setColor(StatColor);
    _DebugBasicStatForeground->setShadowColor(StatShadowColor);
    _DebugBasicStatForeground->setBgColor(StatBackgroundColor);
    _DebugBasicStatForeground->setBorderColor(StatBorderColor);
    _DebugBasicStatForeground->addElement(RenderAction::statDrawTime, "Draw FPS: %r.3f");
    _DebugBasicStatForeground->addElement(RenderAction::statNGeometries, "%d Nodes drawn");
    _DebugBasicStatForeground->addElement(RenderAction::statNTriangles, "%d triangles drawn");

    //Rendering Statistics
    _DebugRenderStatForeground = SimpleStatisticsForeground::create();
    _DebugRenderStatForeground->setHorizontalAlign(SimpleStatisticsForeground::Right);
    _DebugRenderStatForeground->setVerticalAlign(SimpleStatisticsForeground::Middle);
    _DebugRenderStatForeground->setSize(StatFontSize);
    _DebugRenderStatForeground->setColor(StatColor);
    _DebugRenderStatForeground->setShadowColor(StatShadowColor);
    _DebugRenderStatForeground->setBgColor(StatBackgroundColor);
    _DebugRenderStatForeground->setBorderColor(StatBorderColor);
    //Drawing Statistics
    _DebugRenderStatForeground->addElement(RenderAction::statDrawTime, "Draw FPS: %r.3f");
    _DebugRenderStatForeground->addElement(RenderAction::statTravTime, "Trav FPS: %r.3f");
    _DebugRenderStatForeground->addElement(RenderAction::statNGeometries, "%d Nodes drawn");
    _DebugRenderStatForeground->addElement(RenderAction::statDrawTime, "DrawTime: %.3f s");
    _DebugRenderStatForeground->addElement(RenderAction::statTravTime, "TravTime: %.3f s");

    //Nodes
    _DebugRenderStatForeground->addElement(RenderPartition::statCullTestedNodes, "%d Nodes culltested");
    _DebugRenderStatForeground->addElement(RenderPartition::statCulledNodes, "%d Nodes culled");
    _DebugRenderStatForeground->addElement(RenderAction::statNMatrices, "%d matrix changes");
    _DebugRenderStatForeground->addElement(RenderAction::statNGeometries, "%d Nodes drawn");
    //_DebugRenderStatForeground->addElement(RenderAction::statNTransGeometries, "%d transparent Nodes drawn");

    //Materials
    //_DebugRenderStatForeground->addElement(RenderAction::statNMaterials, "%d material changes");
    _DebugRenderStatForeground->addElement(RenderAction::statNShaders, "%d shader changes");
    _DebugRenderStatForeground->addElement(RenderAction::statNShaderParams, "%d shader param changes");

    //Drawn primities
    _DebugRenderStatForeground->addElement(RenderAction::statNTriangles, "%d triangles drawn");
    _DebugRenderStatForeground->addElement(Drawable::statNLines, "%d lines drawn");
    _DebugRenderStatForeground->addElement(Drawable::statNPoints, "%d points drawn");
    _DebugRenderStatForeground->addElement(Drawable::statNPrimitives,"%d primitive groups drawn");
    _DebugRenderStatForeground->addElement(Drawable::statNVertices, "%d vertices transformed");
    _DebugRenderStatForeground->addElement(Drawable::statNGeoBytes, "%d bytes of geometry used");

    //Textures
    _DebugRenderStatForeground->addElement(TextureObjChunk::statNTextures, "%d textures used");
    _DebugRenderStatForeground->addElement(TextureObjChunk::statNTexBytes, "%MB MB of texture used");

    //Lights
    _DebugRenderStatForeground->addElement(PointLight::statNPointLights,
                                           "%d point lights");
    _DebugRenderStatForeground->addElement(DirectionalLight::statNDirectionalLights,
                                           "%d directional lights");
    _DebugRenderStatForeground->addElement(SpotLight::statNSpotLights,
                                           "%d spot lights");

    //Occlusion
    //_DebugRenderStatForeground->addElement(OcclusionTestingTreeBuilder::statNOccNodes,
                                           //"%d nodes occlusion tested");
    //_DebugRenderStatForeground->addElement(OcclusionTestingTreeBuilder::statNOccTests,
                                           //"%d occlusion tests");
    //_DebugRenderStatForeground->addElement(OcclusionTestingTreeBuilder::statNOccInvisible,
                                           //"%d nodes found invisible from occ");
    //_DebugRenderStatForeground->addElement(OcclusionTestingTreeBuilder::statNOccSuccessTestPer,
                                           //"%r successful occlusion tests");
    //_DebugRenderStatForeground->addElement(OcclusionTestingTreeBuilder::statNOccTriangles,
                                           //"%d tris culled");

    //Physics Statistics
    _DebugPhysicsStatForeground = SimpleStatisticsForeground::create();
    _DebugPhysicsStatForeground->setHorizontalAlign(SimpleStatisticsForeground::Right);
    _DebugPhysicsStatForeground->setVerticalAlign(SimpleStatisticsForeground::Middle);
    _DebugPhysicsStatForeground->setSize(StatFontSize);
    _DebugPhysicsStatForeground->setColor(StatColor);
    _DebugPhysicsStatForeground->setShadowColor(StatShadowColor);
    _DebugPhysicsStatForeground->setBgColor(StatBackgroundColor);
    _DebugPhysicsStatForeground->setBorderColor(StatBorderColor);
    _DebugPhysicsStatForeground->addElement(RenderAction::statDrawTime, "Draw FPS: %r.3f");

    //Particle System Statistics
    _DebugParticleSystemStatForeground = SimpleStatisticsForeground::create();
    _DebugParticleSystemStatForeground->setHorizontalAlign(SimpleStatisticsForeground::Right);
    _DebugParticleSystemStatForeground->setVerticalAlign(SimpleStatisticsForeground::Middle);
    _DebugParticleSystemStatForeground->setSize(StatFontSize);
    _DebugParticleSystemStatForeground->setColor(StatColor);
    _DebugParticleSystemStatForeground->setShadowColor(StatShadowColor);
    _DebugParticleSystemStatForeground->setBgColor(StatBackgroundColor);
    _DebugParticleSystemStatForeground->setBorderColor(StatBorderColor);
    _DebugParticleSystemStatForeground->addElement(RenderAction::statDrawTime, "Draw FPS: %r.3f");

    //Animation Statistics
    _DebugAnimationStatForeground = SimpleStatisticsForeground::create();
    _DebugAnimationStatForeground->setHorizontalAlign(SimpleStatisticsForeground::Right);
    _DebugAnimationStatForeground->setVerticalAlign(SimpleStatisticsForeground::Middle);
    _DebugAnimationStatForeground->setSize(StatFontSize);
    _DebugAnimationStatForeground->setColor(StatColor);
    _DebugAnimationStatForeground->setShadowColor(StatShadowColor);
    _DebugAnimationStatForeground->setBgColor(StatBackgroundColor);
    _DebugAnimationStatForeground->setBorderColor(StatBorderColor);
    _DebugAnimationStatForeground->addElement(RenderAction::statDrawTime, "Draw FPS: %r.3f");
}

void ApplicationPlayer::updateDebugUI(void)
{
    updateGotoSceneMenuItems(MainApplication::the()->getProject());
    //TODO: Update the Scene Node Tree
    if(_HierarchyPanel->getSceneGraphTreeModel()->getRootNode() != MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->getRoot())
    {
        _HierarchyPanel->getSceneGraphTreeModel()->setRoot(MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->getRoot());
    }

    updateHighlightNode();

}

void ApplicationPlayer::updateDebugSceneChange(void)
{
    //Update the UI for the debug interface
    updateDebugUI();

    _WasMouseHidden = !MainApplication::the()->getMainWindow()->getShowCursor();
    if(_WasMouseHidden)
    {
        MainApplication::the()->getMainWindow()->setShowCursor(true);
    }
    _WasMouseAttached = !MainApplication::the()->getMainWindow()->getAttachMouseToCursor();

    if(_WasMouseAttached)
    {
        MainApplication::the()->getMainWindow()->setAttachMouseToCursor(true);
    }

    if(_IsDebugActive)
    {
        setSceneInputBlocking(true);
    }

    updateDebugViewport();

}

void ApplicationPlayer::detachDebugViewport(void)
{
    //Make sure the Debug Viewport is on top
    MainApplication::the()->getMainWindow()->subPortByObj(_DebugViewport);

    //Put the original Camera back on the Scene's Viewport
    MainApplication::the()->getMainWindow()->getPort(0)->setCamera(_SceneViewportCamera);
}

void ApplicationPlayer::updateDebugViewport(void)
{
    //Update The Camera
    _SceneViewportCamera = MainApplication::the()->getMainWindow()->getPort(0)->getCamera();

    _DebugCamera = dynamic_pointer_cast<Camera>(_SceneViewportCamera->shallowCopy());
    _DebugCamera->setBeacon(_DebugCameraBeacon);

    //Put the Camera Beacon to the beacon of the scene's camera
    _DebugSceneNavigator.set(_SceneViewportCamera->getBeacon()->getToWorld());

    //Put the Debug Camera on the Scene's Viewport
    MainApplication::the()->getMainWindow()->getPort(0)->setCamera(_DebugCamera);

    _DebugViewport->setCamera(_DebugCamera);

    //Make sure the Debug Viewport is on top
    MainApplication::the()->getMainWindow()->subPortByObj(_DebugViewport);
    MainApplication::the()->getMainWindow()->addPort(_DebugViewport);
}

void ApplicationPlayer::attachDebugViewport(void)
{
    updateDebugViewport();
}

ViewportRefPtr ApplicationPlayer::createDebugViewport(void)
{
    _WorkspaceGridLineChunk = LineChunk::create();
    _WorkspaceGridLineChunk->setWidth(1.0f);
    _WorkspaceGridLineChunk->setSmooth(true);

    BlendChunkRefPtr TheBlendChunk = BlendChunk::create();
    TheBlendChunk->setSrcFactor(GL_SRC_ALPHA);
    TheBlendChunk->setDestFactor(GL_ONE_MINUS_SRC_ALPHA);

    ChunkMaterialRefPtr WorkspaceGridMaterial = ChunkMaterial::create();
    WorkspaceGridMaterial->addChunk (TheBlendChunk);
    WorkspaceGridMaterial->addChunk (_WorkspaceGridLineChunk);

    MaterialGroupRefPtr GridMatGroup = MaterialGroup::create();
    GridMatGroup->setMaterial(WorkspaceGridMaterial);

    //Create the Workspace Grid
    _WorkspaceGrid = Node::create();

    _WorkspaceGrid->setCore(GridMatGroup);
    _WorkspaceGrid->addChild(makeGrid(100.0f, 100.0f, 1.0, Color3f(0.7f,0.7f,0.7f)));

    //Create the Highlight Node
    createHighlightNode();

    //Create the XFormManipulator Node
    createXFormManipulator();

    //Camera Transformation Node	
    _DebugBeaconTransform = Transform::create();

    _DebugCameraBeacon = OSG::Node::create();
    _DebugCameraBeacon->setCore(_DebugBeaconTransform);

    //Debug Root Node
    NodeRefPtr DefaultRootNode = OSG::Node::create();
    DefaultRootNode->setCore(OSG::DirectionalLight::create());
    DefaultRootNode->addChild(_DebugCameraBeacon);
    DefaultRootNode->addChild(_HighlightNode);
    DefaultRootNode->addChild(_XFormManipNode);
    DefaultRootNode->addChild(_WorkspaceGrid);

    //Background
    PassiveBackgroundRefPtr DefaultBackground = PassiveBackground::create();

    ViewportRefPtr DebugViewport = Viewport::create();
    setName(DebugViewport,"__KABALA_ENGINE_DEBUGGER_VIEWPORT");

    DebugViewport->setRoot      (DefaultRootNode);
    DebugViewport->setSize      (0.0f,0.0f, 1.0f,1.0f);
    DebugViewport->setBackground(DefaultBackground);
    DebugViewport->addForeground(DebuggerUIForeground);
    DebugViewport->setTravMask  (DEBUG_GRAPH_DRAWN);

    //Setup the XForm Manipulation Manager
    _XFormManipMgr.setTarget(NULL);
    _XFormManipMgr.setViewport(DebugViewport);

    //Setup the Navigator
    _DebugSceneNavigator.setMode(Navigator::TRACKBALL);
    _DebugSceneNavigator.setViewport(DebugViewport);
    _DebugSceneNavigator.setCameraTransformation(_DebugCameraBeacon);

    return DebugViewport;
}

void ApplicationPlayer::moveDebugCamera(const Matrix& Transform)
{
    if(_DebugCamera!=NULL)
    {
        _DebugCameraAnimationGroup->stop();

        //Update The Camera Animation Values
        _DebugCameraTransformationKeyframes->clear();
        _DebugCameraTransformationKeyframes->addKeyframe(_DebugBeaconTransform->getMatrix(),0.0f);
        _DebugCameraTransformationKeyframes->addKeyframe(Transform,1.0f);

        //_DebugCameraFovKeyframes->clear();
        //_DebugCameraFovKeyframes->addKeyframe(dynamic_pointer_cast<PerspectiveCamera>(_SceneViewportCamera)->getFov(),0.0f);
        //_DebugCameraFovKeyframes->addKeyframe(dynamic_pointer_cast<PerspectiveCamera>(_SceneViewportCamera)->getFov()
        //* 1.5f,0.5f);
        //_DebugCameraFovKeyframes->addKeyframe(dynamic_pointer_cast<PerspectiveCamera>(_SceneViewportCamera)->getFov(),1.0f);

        //Attach the Debug Camera Animation
        _DebugCameraTransAnimation->setAnimatedField(_DebugBeaconTransform,
                                                     Transform::MatrixFieldId);

        //_DebugCameraFovAnimation->setAnimatedField(_DebugCamera,
        //PerspectiveCamera::FovFieldId);

        _DebugCameraAnimationGroup->attachUpdateProducer(MainApplication::the()->getMainWindow());

        //Start the Animation
        _DebugCameraAnimationGroup->start();

        //Set The Navigator
        _DebugSceneNavigator.set(Transform);
    }
    else
    {
        if(_DebugCamera==NULL)
        {
            SWARNING << "Debug Camera is NULL." << std::endl;
        }
    }
}

void ApplicationPlayer::createDebugCameraAnim(void)
{
    //Transformation Animation
    _DebugCameraTransformationKeyframes = KeyframeTransformationSequenceMatrix4f::create();

    KeyframeAnimatorRefPtr DebugCameraTransformationAnimator = KeyframeAnimator::create();
    DebugCameraTransformationAnimator->setKeyframeSequence(_DebugCameraTransformationKeyframes);

    _DebugCameraTransAnimation = FieldAnimation::create();
    _DebugCameraTransAnimation->setAnimator(DebugCameraTransformationAnimator);
    _DebugCameraTransAnimation->setInterpolationType(Animator::LINEAR_INTERPOLATION);
    _DebugCameraTransAnimation->setCycling(1);

    //Fov Animation
    //_DebugCameraFovKeyframes = KeyframeNumbersSequenceReal32::create();

    //KeyframeAnimatorRefPtr DebugCameraFovAnimator = KeyframeAnimator::create();
    //DebugCameraFovAnimator->setKeyframeSequence(_DebugCameraFovKeyframes);

    //_DebugCameraFovAnimation = FieldAnimation::create();
    //_DebugCameraFovAnimation->setAnimator(DebugCameraFovAnimator);
    //_DebugCameraFovAnimation->setInterpolationType(LINEAR_INTERPOLATION);
    //_DebugCameraFovAnimation->setCycling(1);

    //Animation Group
    _DebugCameraAnimationGroup = AnimationGroup::create();
    _DebugCameraAnimationGroup->pushToAnimations(_DebugCameraTransAnimation);
    //_DebugCameraAnimationGroup->pushToAnimations(_DebugCameraFovAnimation);
}

void ApplicationPlayer::resetDebugCamera(void)
{
    //Put the Camera Beacon to the beacon of the scene's camera
    _DebugSceneNavigator.set(_SceneViewportCamera->getBeacon()->getToWorld());
}

void ApplicationPlayer::updateUndoRedoInterfaces(UndoManagerPtr TheUndoManager)
{

    _UndoItem->setEnabled(_TheUndoManager->canUndo());
    if(_TheUndoManager->canUndo())
    {
        _UndoItem->setText(TheUndoManager->getUndoPresentationName());
    }
    else
    {
        _UndoItem->setText("Undo");
    }

    _RedoItem->setEnabled(TheUndoManager->canRedo());
    if(_TheUndoManager->canRedo())
    {
        _RedoItem->setText(_TheUndoManager->getRedoPresentationName());
    }
    else
    {
        _RedoItem->setText("Redo");
    }
}


void ApplicationPlayer::setDebugView(UInt32 Index)
{
    _HierarchyPanel->setView(Index);
    _ContentPanel->setView(Index);
}

void ApplicationPlayer::updateFromSettings(void)
{
    //Undo History
    if(MainApplication::the()->getSettings().get<bool>("player.debugger.undo_history.enable"))
    {
        _TheUndoManager->setLimit(MainApplication::the()->getSettings().get<Int32>("player.debugger.undo_history.max_length"));
    }
    else
    {
        _TheUndoManager->discardAllEdits();
        _TheUndoManager->setLimit(0);
    }

    //Grid
    if(MainApplication::the()->getSettings().get<bool>("player.debugger.grid.draw"))
    {
        _WorkspaceGrid->setTravMask(DEBUG_GRAPH_DRAWN);
    }
    else
    {
        _WorkspaceGrid->setTravMask(DEBUG_GRAPH_NONE);
    }
    Vec2f GridSize(MainApplication::the()->getSettings().get<Vec2f>("player.debugger.grid.dimensions"));
    NodeRefPtr GridGeoNode = makeGrid(GridSize.x(),
                                      GridSize.y(), 
                                      MainApplication::the()->getSettings().get<Real32>("player.debugger.grid.segment_length"), 
                                      MainApplication::the()->getSettings().get<Color3f>("player.debugger.grid.color"));
    _WorkspaceGrid->replaceChild(0, GridGeoNode);

    _WorkspaceGridLineChunk->setWidth(MainApplication::the()->getSettings().get<Real32>("player.debugger.grid.line_thickness"));

    //Selected Node
        //Volume Box
        if(MainApplication::the()->getSettings().get<bool>("player.debugger.selected_node.volume_box.draw"))
        {
            _HighlightVolumeBoxNode->setTravMask(DEBUG_GRAPH_DRAWN);
        }
        else
        {
            _HighlightVolumeBoxNode->setTravMask(DEBUG_GRAPH_NONE);
        }
        Color4f bbColor(MainApplication::the()->getSettings().get<Color4f>("player.debugger.selected_node.volume_box.color"));
        GeoVec4fPropertyRefPtr bbColors =
            static_cast<GeoVec4fProperty*>(_HighlightVolumeBoxGeo->getColors());
        for(UInt32 i(0) ; i<bbColors->size() ; ++i)
        {
            bbColors->setValue(bbColor,i);
        }
        _HighlightBoundBoxMatLineChunk->setWidth(MainApplication::the()->getSettings().get<Real32>("player.debugger.selected_node.volume_box.line_thickness"));

        //Local Axis
        if(MainApplication::the()->getSettings().get<bool>("player.debugger.selected_node.axis.draw"))
        {
            _HighlightAxisNode->setTravMask(DEBUG_GRAPH_DRAWN);
        }
        else
        {
            _HighlightAxisNode->setTravMask(DEBUG_GRAPH_NONE);
        }
        Color4f xAxisColor(MainApplication::the()->getSettings().get<Color4f>("player.debugger.selected_node.axis.x_axis_color"));
        Color4f yAxisColor(MainApplication::the()->getSettings().get<Color4f>("player.debugger.selected_node.axis.y_axis_color"));
        Color4f zAxisColor(MainApplication::the()->getSettings().get<Color4f>("player.debugger.selected_node.axis.z_axis_color"));
        GeoVec4fPropertyRefPtr axisColors = static_cast<GeoVec4fProperty*>(_HighlightAxisGeo->getColors());
        axisColors->setValue(xAxisColor,0);
        axisColors->setValue(xAxisColor,1);
        axisColors->setValue(yAxisColor,2);
        axisColors->setValue(yAxisColor,3);
        axisColors->setValue(zAxisColor,4);
        axisColors->setValue(zAxisColor,5);
        _HighlightAxisLineChunk->setWidth(MainApplication::the()->getSettings().get<Real32>("player.debugger.selected_node.axis.line_thickness"));

        //Tri Mesh
        if(MainApplication::the()->getSettings().get<bool>("player.debugger.selected_node.mesh.draw"))
        {
            _WireframeNode->setTravMask(DEBUG_GRAPH_DRAWN);
        }
        else
        {
            _WireframeNode->setTravMask(DEBUG_GRAPH_NONE);
        }
        _WireframeMatMaterialChunk->setEmission(MainApplication::the()->getSettings().get<Color4f>("player.debugger.selected_node.mesh.color"));
        _WireframeMatLineChunk->setWidth(MainApplication::the()->getSettings().get<Real32>("player.debugger.selected_node.mesh.line_thickness"));

}

void ApplicationPlayer::openEditor(FieldContainer* FCToEdit)
{
    openDefaultFCTreeEditorDialog(FCToEdit, _TheCommandManager, DebuggerDrawingSurface);
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

ApplicationPlayer::ApplicationPlayer(void) :
    Inherited(),
    _IsDebugActive(false),
    _PhysDrawable(NULL),
    _PhysDrawableNode(NULL),
    _WasMouseHidden(false),
    _WasMouseAttached(false)
{
	_TheUndoManager = UndoManager::create();
	_TheCommandManager = CommandManager::create(_TheUndoManager);
}

ApplicationPlayer::ApplicationPlayer(const ApplicationPlayer &source) :
    Inherited(source),
    _IsDebugActive(false),
    _DebugBasicStatForeground(source._DebugBasicStatForeground),
    _DebugRenderStatForeground(source._DebugRenderStatForeground),
    _DebugPhysicsStatForeground(source._DebugPhysicsStatForeground),
    _DebugParticleSystemStatForeground(source._DebugParticleSystemStatForeground),
    _DebugAnimationStatForeground(source._DebugAnimationStatForeground),
    _PhysDrawable(NULL),
    _PhysDrawableNode(NULL),
    _WasMouseHidden(false),
    _WasMouseAttached(false)
{
	_TheUndoManager = UndoManager::create();
	_TheCommandManager = CommandManager::create(_TheUndoManager);
}

ApplicationPlayer::~ApplicationPlayer(void)
{
}

/*----------------------------- class specific ----------------------------*/

void ApplicationPlayer::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void ApplicationPlayer::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump ApplicationPlayer NI" << std::endl;
}

void ApplicationPlayer::handleCommandManagerStateChanged(ChangeEventDetails* const details)
{
    updateUndoRedoInterfaces(_TheUndoManager);
}

void ApplicationPlayer::handleGotoSceneItemAction(ActionEventDetails* const details)
{
    SceneRefPtr TheScene(MainApplication::the()->getProject()->getSceneByName(dynamic_cast<MenuItem*>(details->getSource())->getText()));

    if(TheScene != NULL)
    {
        gotoScene(TheScene);
    }
}

void ApplicationPlayer::handleProjectSceneChanged(ProjectEventDetails* const details)
{
    updateDebugSceneChange();
}

void ApplicationPlayer::handleHighlightNodeUpdate(UpdateEventDetails* const details)
{
    updateHighlightNode();
}

void ApplicationPlayer::updateXFormManipulator(void)
{
    Node* XFormTargetNode(NULL);
    if(_SelectedNode != NULL)
    {
        if(_SelectedNode->getCore()->getType().isDerivedFrom(Transform::getClassType()))
        {
            XFormTargetNode = _SelectedNode;
        }
        else if(_SelectedNode->getParent() != NULL &&
                _SelectedNode->getParent()->getNChildren() == 1 &&
                _SelectedNode->getParent()->getCore()->getType().isDerivedFrom(Transform::getClassType()))
        {
            XFormTargetNode = _SelectedNode->getParent();
        }
    }

    if(XFormTargetNode &&
       XFormTargetNode != _XFormManipMgr.getTarget())
    {
        // calc the world bbox of the highlight object
        BoxVolume      vol;
        XFormTargetNode->getWorldVolume(vol);

        Pnt3f min,max;
        vol.getBounds(min, max);

        //If the Volume is Zero, use a volume of size 1.0
        if(min == max)
        {
            min = Pnt3f(-0.5f,-0.5f,-0.5f);
            max = Pnt3f(0.5f,0.5f,0.5f);
        }

        //Get the side lengths of the volume
        Vec3f  Sides(max - min);
        Real32 AxisScaling(Sides.maxValue() *
                           MainApplication::the()->getSettings().get<Real32>("player.debugger.transform_manip.axis.relative_length"));

        _XFormManipMgr.setTarget(XFormTargetNode);
        _XFormManipMgr.setLength(Vec3f(AxisScaling,AxisScaling,AxisScaling));
        _XFormManipNodeCore->setTarget(XFormTargetNode);
        _XFormManipNode->setTravMask(DEBUG_GRAPH_DRAWN | DEBUG_GRAPH_INTERSECTABLE);
        if(MainApplication::the()->getSettings().get<bool>("player.debugger.selected_node.axis.draw"))
        {
            _HighlightAxisNode->setTravMask(DEBUG_GRAPH_NONE);
        }
    }
    else
    {
        _XFormManipMgr.setTarget(NULL);
        _XFormManipNodeCore->setTarget(NULL);
        _XFormManipNode->setTravMask(DEBUG_GRAPH_NONE);
        if(MainApplication::the()->getSettings().get<bool>("player.debugger.selected_node.axis.draw"))
        {
            _HighlightAxisNode->setTravMask(DEBUG_GRAPH_DRAWN);
        }
    }
}

void ApplicationPlayer::focusSelectedNode(void)
{
	showAll(MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->getCamera(),
            getSelectedNode(),
            MainApplication::the()->getProject()->getActiveScene()->getViewports(0));
}

void ApplicationPlayer::showAll(CameraRefPtr TheCameraOrig,
                             NodeRefPtr Scene,
                             ViewportRefPtr LocalViewport)
{
    NodeRefPtr FocusNode(Scene);
	if(FocusNode==NULL)
	{
        FocusNode = MainApplication::the()->getProject()->getActiveScene()->getViewports(0)->getRoot();
    }

	if(TheCameraOrig!=NULL)
	{
        PerspectiveCameraRefPtr TheCamera;
        if(TheCameraOrig->getType() == PerspectiveCamera::getClassType())
        {
            TheCamera = dynamic_pointer_cast<PerspectiveCamera>(TheCameraOrig);
        }

        //Make sure the volume is up to date for the FocusNode
        FocusNode->updateVolume();

        //Get the Minimum and Maximum bounds of the volume
        Vec3f min,max;
        BoxVolume TheVol;
        FocusNode->getWorldVolume(TheVol);
        TheVol.getBounds( min, max );

        Vec3f d = max - min;
        if(d.length() < Eps) //The volume is 0
        {
            Pnt3f NodeOrigin(0.0f,0.0f,0.0f);
            FocusNode->getToWorld().mult(NodeOrigin, NodeOrigin);
            //Default to a 1x1x1 box volume
            min = Vec3f(NodeOrigin) - Vec3f(1.0f,1.0f,1.0f);
            max = Vec3f(NodeOrigin) + Vec3f(1.0f,1.0f,1.0f);
            d = max - min;
        }

        // try to be nice to people giving degrees...
        Real32 VertFov(TheCamera->getFov());
        if(VertFov > Pi)
        {
            VertFov = osgDegree2Rad(VertFov);
        }

        //Get the horizontal feild of view
        Real32 HorFov = 2.0f * osgATan(static_cast<Real32>(LocalViewport->getPixelWidth())
                                       /(static_cast<Real32>(LocalViewport->getPixelHeight())/osgTan(VertFov*0.5f)));

        Pnt3f at((min[0] + max[0]) * .5f,(min[1] + max[1]) * .5f,(min[2] + max[2]) * .5f);

        //Get the camera world transformation
        Matrix CameraToWorld(TheCamera->getBeacon()->getToWorld());
        Matrix WorldToCamera(CameraToWorld);
        WorldToCamera.invert();

        //Get the 8 points of the bounding box in camera space
        Pnt3f p1(min),
              p2(max.x(), min.y(), min.z()),
              p3(max.x(), max.y(), min.z()),
              p4(max.x(), min.y(), max.z()),
              p5(min.x(), max.y(), min.z()),
              p6(min.x(), max.y(), max.z()),
              p7(min.x(), min.y(), max.z()),
              p8(max);

        p1 = WorldToCamera * p1;
        p2 = WorldToCamera * p2;
        p3 = WorldToCamera * p3;
        p4 = WorldToCamera * p4;
        p5 = WorldToCamera * p5;
        p6 = WorldToCamera * p6;
        p7 = WorldToCamera * p7;
        p8 = WorldToCamera * p8;

        //Get the min and max of the bounding volume relative camera space
        Vec3f BBMinCamera;
        Vec3f BBMaxCamera;
        BBMinCamera[0] = osgMin(p1.x(),
                         osgMin(p2.x(),
                         osgMin(p3.x(),
                         osgMin(p4.x(),
                         osgMin(p5.x(),
                         osgMin(p6.x(),
                         osgMin(p7.x(),p8.x())))))));

        BBMinCamera[1] = osgMin(p1.y(),
                         osgMin(p2.y(),
                         osgMin(p3.y(),
                         osgMin(p4.y(),
                         osgMin(p5.y(),
                         osgMin(p6.y(),
                         osgMin(p7.y(),p8.y())))))));

        BBMinCamera[2] = osgMin(p1.z(),
                         osgMin(p2.z(),
                         osgMin(p3.z(),
                         osgMin(p4.z(),
                         osgMin(p5.z(),
                         osgMin(p6.z(),
                         osgMin(p7.z(),p8.z())))))));

        BBMaxCamera[0] = osgMax(p1.x(),
                         osgMax(p2.x(),
                         osgMax(p3.x(),
                         osgMax(p4.x(),
                         osgMax(p5.x(),
                         osgMax(p6.x(),
                         osgMax(p7.x(),p8.x())))))));

        BBMaxCamera[1] = osgMax(p1.y(),
                         osgMax(p2.y(),
                         osgMax(p3.y(),
                         osgMax(p4.y(),
                         osgMax(p5.y(),
                         osgMax(p6.y(),
                         osgMax(p7.y(),p8.y())))))));

        BBMaxCamera[2] = osgMax(p1.z(),
                         osgMax(p2.z(),
                         osgMax(p3.z(),
                         osgMax(p4.z(),
                         osgMax(p5.z(),
                         osgMax(p6.z(),
                         osgMax(p7.z(),p8.z())))))));

        Pnt3f CamerAt(WorldToCamera * at);

        //Calculate the distance to move the camera back to make sure the bound
        //box is visible
        Real32 dist = 1.05f * ((BBMaxCamera.z()-CamerAt.z()) +
                              osgMax(((BBMaxCamera.y()-BBMinCamera.y()) / (2.0f * osgTan(VertFov *0.5f))),
                                     ((BBMaxCamera.x()-BBMinCamera.x()) / (2.0f * osgTan(HorFov  *0.5f)))));

        //Get the cameras current orientation
        Vec3f OrigY(0.0f,1.0f,0.0f),
              OrigZ(0.0f,0.0f,1.0f);
        CameraToWorld.mult(OrigY, OrigY);
        CameraToWorld.mult(OrigZ, OrigZ);

        //Keep the same camera heading
        Pnt3f  from = at + (OrigZ * dist); 

        Matrix m;
        if(!MatrixLookAt(m, from, at, OrigY))
        {
            moveDebugCamera(m);
        }

        //Scale the Motion Factor of the Navigator
        getDebugSceneNavigator().setMotionFactor((d[0] + d[1] + d[2]) / 100.f);
	}
	else
	{
		SWARNING << "Camera is NULL!" <<std::endl;
	}
}

void ApplicationPlayer::updateWireframeNode(void)
{
    //visit the sub-tree rooted at the selected node
    if(_SelectedNode != NULL)
    {
        dynamic_cast<VisitSubTree*>(_WireframeMatGroupNode->getChild(0)->getCore())->setSubTreeRoot(_SelectedNode);

    }

    //Update the transformation for the wireframe node
    if(_SelectedNode != NULL &&
       _SelectedNode->getParent() != NULL)
    {
        _WireframeTransform->setTarget(_SelectedNode->getParent());
    }
    else
    {
        _WireframeTransform->setTarget(NULL);
    }
}

void ApplicationPlayer::updateHighlightNode(void)
{
    getDebugSceneNavigator().updateCameraTransformation();

    // attach the hightlight node to the root if the highlight is active
    if(_SelectedNode == NULL)
    {
        _HighlightNode->setTravMask(DEBUG_GRAPH_NONE);
    }
    else
    {
        _HighlightNode->setTravMask(DEBUG_GRAPH_DRAWN);
    }

    if(_SelectedNode != NULL)		// selected node is the node that is being selected.
    {													// highlight node is the pointer to the bounding box for the selected node

        // calc the world bbox of the highlight object
        BoxVolume      vol;
        _SelectedNode->getWorldVolume(vol);

        Pnt3f min,max;
        vol.getBounds(min, max);

        //Get The Local Coordinate System
        Matrix NodeMatrix = _SelectedNode->getToWorld();
        Pnt3f NodeOrigin(NodeMatrix * Pnt3f(0.0f,0.0f,0.0f));
        Vec3f NodeXDir(NodeMatrix * Vec3f(1.0f,0.0f,0.0f)),
              NodeYDir(NodeMatrix * Vec3f(0.0f,1.0f,0.0f)),
              NodeZDir(NodeMatrix * Vec3f(0.0f,0.0f,1.0f));

        //If the Volume is Zero, use a volume of size 1.0
        if(min == max)
        {
            min = NodeOrigin - Vec3f(0.5f,0.5f,0.5f);
            max = NodeOrigin + Vec3f(0.5f,0.5f,0.5f);
        }

        //Get the side lengths of the volume
        Vec3f  Sides(max - min);

        GeoPnt3fPropertyRecPtr temphighlightPoints =
            static_cast<GeoPnt3fProperty*>(_HighlightVolumeBoxGeo->getPositions());

        //Update Bounding Box
        temphighlightPoints->setValue(Pnt3f(min[0], min[1], min[2]), 0);
        temphighlightPoints->setValue(Pnt3f(max[0], min[1], min[2]), 1);
        temphighlightPoints->setValue(Pnt3f(min[0], max[1], min[2]), 2);
        temphighlightPoints->setValue(Pnt3f(max[0], max[1], min[2]), 3);
        temphighlightPoints->setValue(Pnt3f(min[0], min[1], max[2]), 4);
        temphighlightPoints->setValue(Pnt3f(max[0], min[1], max[2]), 5);
        temphighlightPoints->setValue(Pnt3f(min[0], max[1], max[2]), 6);
        temphighlightPoints->setValue(Pnt3f(max[0], max[1], max[2]), 7);
        
        temphighlightPoints =
            static_cast<GeoPnt3fProperty*>(_HighlightAxisGeo->getPositions());

        //Update Local Coordinate Axis
        Real32 AxisScaling(Sides.maxValue() * MainApplication::the()->getSettings().get<Real32>("player.debugger.selected_node.axis.relative_length"));
        temphighlightPoints->setValue(NodeOrigin, 0);
        temphighlightPoints->setValue(NodeOrigin + (NodeXDir* AxisScaling), 1);
        temphighlightPoints->setValue(NodeOrigin, 2);
        temphighlightPoints->setValue(NodeOrigin + (NodeYDir* AxisScaling), 3);
        temphighlightPoints->setValue(NodeOrigin, 4);
        temphighlightPoints->setValue(NodeOrigin + (NodeZDir* AxisScaling), 5);
    }
}

void ApplicationPlayer::createXFormManipulator(void)
{
    _XFormManipMgr.setUniformScale(true);
    _XFormManipNodeCore = ReplicateTransform::create();

    _XFormManipNode = Node::create();
    _XFormManipNode->setCore(_XFormManipNodeCore);
    _XFormManipNode->addChild(_XFormManipMgr.createManipulator(OSG::ManipulatorManager::TRANSLATE));

    _XFormManipNode->setTravMask(DEBUG_GRAPH_NONE);
}

void ApplicationPlayer::createHighlightNode(void)
{
    createHighlightBoundBoxNode();
    createHighlightAxisNode();
    createHighlightTriMeshNode();

    //Highlight Node
    _HighlightNode = Node::create();
    setName(_HighlightNode,"DEBUG_MODE_HIGHLIGHT_NODE");

    GroupRecPtr HighlightCore = Group::create();
    _HighlightNode->setCore(HighlightCore);
    _HighlightNode->addChild(_HighlightVolumeBoxNode);
    _HighlightNode->addChild(_HighlightAxisNode);
    _HighlightNode->addChild(_WireframeNode);

    //Update from settings
    updateFromSettings();
}

void ApplicationPlayer::createHighlightBoundBoxNode(void)
{
    //Create the Material for the Highlight
    _HighlightBoundBoxMatLineChunk = LineChunk::create();
    _HighlightBoundBoxMatLineChunk->setWidth(2.0f);
    _HighlightBoundBoxMatLineChunk->setSmooth(true);

    BlendChunkRefPtr TheBlendChunk = BlendChunk::create();
    TheBlendChunk->setSrcFactor(GL_SRC_ALPHA);
    TheBlendChunk->setDestFactor(GL_ONE_MINUS_SRC_ALPHA);

    ChunkMaterialRefPtr HighlightMaterial = ChunkMaterial::create();
    HighlightMaterial->addChunk (TheBlendChunk);
    HighlightMaterial->addChunk (_HighlightBoundBoxMatLineChunk);

    //Create the Geometry for the highlight
    GeoUInt8PropertyRecPtr type = GeoUInt8Property::create();
    //Volume bound box
    type->push_back(GL_LINE_STRIP);
    type->push_back(GL_LINES);

    GeoUInt32PropertyRefPtr lens = GeoUInt32Property::create();
    //Volume bound box
    lens->push_back(10);
    lens->push_back(6);

    GeoUInt32PropertyRefPtr index = GeoUInt32Property::create();

    //Volume bound box
    index->push_back(0);
    index->push_back(1);
    index->push_back(3);
    index->push_back(2);
    index->push_back(0);
    index->push_back(4);
    index->push_back(5);
    index->push_back(7);
    index->push_back(6);
    index->push_back(4);

    index->push_back(1);
    index->push_back(5);
    index->push_back(2);
    index->push_back(6);
    index->push_back(3);
    index->push_back(7);

    GeoPnt3fPropertyRefPtr highlightPoints = GeoPnt3fProperty::create();
    //Volume bound box
    highlightPoints->push_back(Pnt3f(-1, -1, -1));
    highlightPoints->push_back(Pnt3f( 1, -1, -1));
    highlightPoints->push_back(Pnt3f(-1,  1, -1));
    highlightPoints->push_back(Pnt3f( 1,  1, -1));
    highlightPoints->push_back(Pnt3f(-1, -1,  1));
    highlightPoints->push_back(Pnt3f( 1, -1,  1));
    highlightPoints->push_back(Pnt3f(-1,  1,  1));
    highlightPoints->push_back(Pnt3f( 1,  1,  1));

    //Colors
    Color4f BoundBoxColor(0.0f,1.0f,1.0,1.0f);

    GeoVec4fPropertyRefPtr highlightColors = GeoVec4fProperty::create();
    //Volume bound box
    highlightColors->push_back(BoundBoxColor);
    highlightColors->push_back(BoundBoxColor);
    highlightColors->push_back(BoundBoxColor);
    highlightColors->push_back(BoundBoxColor);
    highlightColors->push_back(BoundBoxColor);
    highlightColors->push_back(BoundBoxColor);
    highlightColors->push_back(BoundBoxColor);
    highlightColors->push_back(BoundBoxColor);

    _HighlightVolumeBoxGeo =Geometry::create();
    _HighlightVolumeBoxGeo->setTypes     (type);
    _HighlightVolumeBoxGeo->setLengths   (lens);
    _HighlightVolumeBoxGeo->setIndices   (index);
    _HighlightVolumeBoxGeo->setPositions (highlightPoints);
    _HighlightVolumeBoxGeo->setColors    (highlightColors);
    _HighlightVolumeBoxGeo->setMaterial  (HighlightMaterial);

    //Highlight Bound Box Node
    _HighlightVolumeBoxNode = Node::create();
    setName(_HighlightVolumeBoxNode,"DEBUG_MODE_HIGHLIGHT_BOUND_BOX_NODE");

    _HighlightVolumeBoxNode->setCore(_HighlightVolumeBoxGeo);
}

void ApplicationPlayer::createHighlightAxisNode(void)
{
    //Create the Material for the Highlight
    _HighlightAxisLineChunk = LineChunk::create();
    _HighlightAxisLineChunk->setWidth(2.0f);
    _HighlightAxisLineChunk->setSmooth(true);

    BlendChunkRefPtr TheBlendChunk = BlendChunk::create();
    TheBlendChunk->setSrcFactor(GL_SRC_ALPHA);
    TheBlendChunk->setDestFactor(GL_ONE_MINUS_SRC_ALPHA);

    ChunkMaterialRefPtr HighlightMaterial = ChunkMaterial::create();
    HighlightMaterial->addChunk (TheBlendChunk);
    HighlightMaterial->addChunk (_HighlightAxisLineChunk);

    //Create the Geometry for the highlight
    GeoUInt8PropertyRecPtr type = GeoUInt8Property::create();
    //Local Coordinage axis
    type->push_back(GL_LINES);

    GeoUInt32PropertyRefPtr lens = GeoUInt32Property::create();
    //Local Coordinage axis
    lens->push_back(6);

    GeoUInt32PropertyRefPtr index = GeoUInt32Property::create();

    //Local Coordinage axis
    index->push_back(0);
    index->push_back(1);
    index->push_back(2);
    index->push_back(3);
    index->push_back(4);
    index->push_back(5);

    GeoPnt3fPropertyRefPtr highlightPoints = GeoPnt3fProperty::create();

    //Local Coordinage axis
    highlightPoints->push_back(Pnt3f( 0,  0,  0));
    highlightPoints->push_back(Pnt3f( 1,  0,  0));
    highlightPoints->push_back(Pnt3f( 0,  0,  0));
    highlightPoints->push_back(Pnt3f( 0,  1,  0));
    highlightPoints->push_back(Pnt3f( 0,  0,  0));
    highlightPoints->push_back(Pnt3f( 0,  0,  1));

    //Colors
    Color4f XAxisColor   (1.0f,0.0f,0.0,1.0f);
    Color4f YAxisColor   (0.0f,1.0f,0.0,1.0f);
    Color4f ZAxisColor   (0.0f,0.0f,1.0,1.0f);

    GeoVec4fPropertyRefPtr highlightColors = GeoVec4fProperty::create();

    //Local Coordinage axis
    highlightColors->push_back(XAxisColor);
    highlightColors->push_back(XAxisColor);
    highlightColors->push_back(YAxisColor);
    highlightColors->push_back(YAxisColor);
    highlightColors->push_back(ZAxisColor);
    highlightColors->push_back(ZAxisColor);

    _HighlightAxisGeo =Geometry::create();
    _HighlightAxisGeo->setTypes     (type);
    _HighlightAxisGeo->setLengths   (lens);
    _HighlightAxisGeo->setIndices   (index);
    _HighlightAxisGeo->setPositions (highlightPoints);
    _HighlightAxisGeo->setColors    (highlightColors);
    _HighlightAxisGeo->setMaterial  (HighlightMaterial);

    //Highlight Bound Box Node
    _HighlightAxisNode = Node::create();
    setName(_HighlightAxisNode,"DEBUG_MODE_HIGHLIGHT_AXIS_NODE");

    _HighlightAxisNode->setCore(_HighlightAxisGeo);
}

void ApplicationPlayer::createHighlightTriMeshNode(void)
{

    //Create the VisitSubTree Node to use to render the wireframe of the
    //selected node
    VisitSubTreeRefPtr SelectedSubTree = VisitSubTree::create();

    NodeRefPtr SelectedSubTreeNode = Node::create();
    SelectedSubTreeNode->setCore(SelectedSubTree);
    

    //Create the Material for the Mesh Highlight
    _WireframeMatLineChunk = LineChunk::create();
    _WireframeMatLineChunk->setWidth(1.0f);
    _WireframeMatLineChunk->setSmooth(true);

    BlendChunkRefPtr TheBlendChunk = BlendChunk::create();
    TheBlendChunk->setSrcFactor(GL_SRC_ALPHA);
    TheBlendChunk->setDestFactor(GL_ONE_MINUS_SRC_ALPHA);

    PolygonChunkRefPtr WireframeMatPolygonChunk = PolygonChunk::create();
    WireframeMatPolygonChunk->setCullFace(GL_NONE);
    WireframeMatPolygonChunk->setFrontMode(GL_LINE);
    WireframeMatPolygonChunk->setBackMode(GL_LINE);
    WireframeMatPolygonChunk->setOffsetFactor(1.0f);
    WireframeMatPolygonChunk->setOffsetBias(0.01f);
    WireframeMatPolygonChunk->setOffsetFill(true);

    Color4f WireframeColor(1.0f,0.0f,1.0f,1.0f);
    _WireframeMatMaterialChunk = MaterialChunk::create();
    _WireframeMatMaterialChunk->setAmbient (Color4f(0.0f,0.0f,0.0f,1.0f));
    _WireframeMatMaterialChunk->setDiffuse (Color4f(0.0f,0.0f,0.0f,1.0f));
    _WireframeMatMaterialChunk->setSpecular(Color4f(0.0f,0.0f,0.0f,1.0f));
    _WireframeMatMaterialChunk->setEmission(WireframeColor);
    _WireframeMatMaterialChunk->setLit(true);

    ChunkMaterialRefPtr WireframeMaterial = ChunkMaterial::create();
    WireframeMaterial->addChunk (TheBlendChunk);
    WireframeMaterial->addChunk (WireframeMatPolygonChunk);
    WireframeMaterial->addChunk (_WireframeMatMaterialChunk);
    WireframeMaterial->addChunk (_WireframeMatLineChunk);

    //MaterialGroup
    MaterialGroupRefPtr WireframeMaterialGroup = MaterialGroup::create(); 
    WireframeMaterialGroup->setMaterial(WireframeMaterial);

    //Mesh Highlight Node
    _WireframeMatGroupNode = Node::create();
    setName(_WireframeMatGroupNode,"DEBUG_MODE_MESH_HIGHLIGHT_MATGROUP_NODE");
    _WireframeMatGroupNode->setCore(WireframeMaterialGroup);

    _WireframeMatGroupNode->addChild(SelectedSubTreeNode);

    //Mesh Highlight Transformation Node
    _WireframeTransform = ReplicateTransform::create();

    _WireframeNode = Node::create();
    setName(_WireframeNode,"DEBUG_MODE_MESH_HIGHLIGHT_NODE");
    _WireframeNode->setCore(_WireframeTransform);
    _WireframeNode->addChild(_WireframeMatGroupNode);
}

void ApplicationPlayer::selectNode(const Pnt2f& ViewportPoint)
{
    Line ViewRay;
    ViewportRefPtr TheViewport(MainApplication::the()->getProject()->getActiveScene()->getViewports(0));
    TheViewport->getCamera()->calcViewRay( ViewRay, ViewportPoint.x(), ViewportPoint.y(), *TheViewport);

    IntersectAction *CastRayAction = IntersectAction::create();

    CastRayAction->setLine( ViewRay );
    CastRayAction->apply( TheViewport->getRoot() );             

    //Get the Tree Model
    SceneGraphTreeModelRefPtr SceneModel(_HierarchyPanel->getSceneGraphTreeModel());
    TreeRefPtr SceneTree(_HierarchyPanel->getSceneGraphTree());
    if ( CastRayAction->didHit() )
    {
        TreePath ThePath(SceneModel->getPathForNode(CastRayAction->getHitObject()));
        SceneTree->expandPath(ThePath);
        SceneTree->scrollPathToVisible(ThePath);
        SceneTree->setSelectionPath(ThePath);
    }
    else
    {
        SceneTree->clearSelection();
    }
}

void ApplicationPlayer::setupPopupMenu()
{
}

void ApplicationPlayer::handleComboBoxSelectionChanged(ComboBoxSelectionEventDetails* const details)
{
    setDebugView(details->getCurrentIndex());
}

void ApplicationPlayer::handleUndoButtonAction(ActionEventDetails* const details)
{
	getUndoManager()->undo();
}

void ApplicationPlayer::handleRedoButtonAction(ActionEventDetails* const details)
{
	getUndoManager()->redo();
}

OSG_END_NAMESPACE
