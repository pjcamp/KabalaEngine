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
 **     class MainWindow
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _KEMAINWINDOWBASE_H_
#define _KEMAINWINDOWBASE_H_
#ifdef __sgi
#pragma once
#endif



#include <OpenSG/OSGConfig.h>
#include "KEKabalaEngineDef.h"
#include "KEConfig.h"

//#include "OpenSG/OSGBaseTypes.h"


#include "Builder/UserInterface/KEInterface.h" // Parent

#include "Builder/UserInterface/MainWindow/MainMenu/KEMainMenuFields.h" // Menu type
#include "Builder/UserInterface/MainWindow/MainToolbar/KEMainToolbarFields.h" // Toolbar type
#include "Builder/UserInterface/MainWindow/StatusBar/KEStatusBarFields.h" // StatusBar type
#include "Builder/UserInterface/MainWindow/HelpPanel/KEHelpPanelFields.h" // HelpPanel type
#include "Builder/UserInterface/MainWindow/SceneComponentTree/KESceneComponentTreeFields.h" // SceneComponentTree type
#include "Builder/UserInterface/MainWindow/SceneNavigationPanel/KESceneNavigationPanelFields.h" // SceneNavigationPanel type
#include "Builder/UserInterface/MainWindow/SceneViewportPanel/KESceneViewportPanelFields.h" // SceneViewportPanel type
#include "Builder/UserInterface/MainWindow/SceneViewportToolbar/KESceneViewportToolbarFields.h" // SceneViewportToolbar type
#include "Builder/UserInterface/MainWindow/Editors/KEEditorInterfaceFields.h" // SceneEditor type

#include "KEMainWindowFields.h"

OSG_BEGIN_NAMESPACE

class MainWindow;

//! \brief MainWindow Base Class.

class KE_KABALAENGINE_DLLMAPPING MainWindowBase : public Interface
{
  public:

    typedef Interface Inherited;
    typedef Interface ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(MainWindow);
    
    

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        MenuFieldId = Inherited::NextFieldId,
        ToolbarFieldId = MenuFieldId + 1,
        StatusBarFieldId = ToolbarFieldId + 1,
        HelpPanelFieldId = StatusBarFieldId + 1,
        SceneComponentTreeFieldId = HelpPanelFieldId + 1,
        SceneNavigationPanelFieldId = SceneComponentTreeFieldId + 1,
        SceneViewportPanelFieldId = SceneNavigationPanelFieldId + 1,
        SceneViewportToolbarFieldId = SceneViewportPanelFieldId + 1,
        SceneEditorFieldId = SceneViewportToolbarFieldId + 1,
        BackgroundEditorFieldId = SceneEditorFieldId + 1,
        CameraEditorFieldId = BackgroundEditorFieldId + 1,
        ForegroundEditorFieldId = CameraEditorFieldId + 1,
        LightEditorFieldId = ForegroundEditorFieldId + 1,
        ParticleSystemEditorFieldId = LightEditorFieldId + 1,
        SceneObjectEditorFieldId = ParticleSystemEditorFieldId + 1,
        ViewportEditorFieldId = SceneObjectEditorFieldId + 1,
        NextFieldId = ViewportEditorFieldId + 1
    };

    static const OSG::BitVector MenuFieldMask =
        (TypeTraits<BitVector>::One << MenuFieldId);
    static const OSG::BitVector ToolbarFieldMask =
        (TypeTraits<BitVector>::One << ToolbarFieldId);
    static const OSG::BitVector StatusBarFieldMask =
        (TypeTraits<BitVector>::One << StatusBarFieldId);
    static const OSG::BitVector HelpPanelFieldMask =
        (TypeTraits<BitVector>::One << HelpPanelFieldId);
    static const OSG::BitVector SceneComponentTreeFieldMask =
        (TypeTraits<BitVector>::One << SceneComponentTreeFieldId);
    static const OSG::BitVector SceneNavigationPanelFieldMask =
        (TypeTraits<BitVector>::One << SceneNavigationPanelFieldId);
    static const OSG::BitVector SceneViewportPanelFieldMask =
        (TypeTraits<BitVector>::One << SceneViewportPanelFieldId);
    static const OSG::BitVector SceneViewportToolbarFieldMask =
        (TypeTraits<BitVector>::One << SceneViewportToolbarFieldId);
    static const OSG::BitVector SceneEditorFieldMask =
        (TypeTraits<BitVector>::One << SceneEditorFieldId);
    static const OSG::BitVector BackgroundEditorFieldMask =
        (TypeTraits<BitVector>::One << BackgroundEditorFieldId);
    static const OSG::BitVector CameraEditorFieldMask =
        (TypeTraits<BitVector>::One << CameraEditorFieldId);
    static const OSG::BitVector ForegroundEditorFieldMask =
        (TypeTraits<BitVector>::One << ForegroundEditorFieldId);
    static const OSG::BitVector LightEditorFieldMask =
        (TypeTraits<BitVector>::One << LightEditorFieldId);
    static const OSG::BitVector ParticleSystemEditorFieldMask =
        (TypeTraits<BitVector>::One << ParticleSystemEditorFieldId);
    static const OSG::BitVector SceneObjectEditorFieldMask =
        (TypeTraits<BitVector>::One << SceneObjectEditorFieldId);
    static const OSG::BitVector ViewportEditorFieldMask =
        (TypeTraits<BitVector>::One << ViewportEditorFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFUnrecMainMenuPtr SFMenuType;
    typedef SFUnrecMainToolbarPtr SFToolbarType;
    typedef SFUnrecStatusBarPtr SFStatusBarType;
    typedef SFUnrecHelpPanelPtr SFHelpPanelType;
    typedef SFUnrecSceneComponentTreePtr SFSceneComponentTreeType;
    typedef SFUnrecSceneNavigationPanelPtr SFSceneNavigationPanelType;
    typedef SFUnrecSceneViewportPanelPtr SFSceneViewportPanelType;
    typedef SFUnrecSceneViewportToolbarPtr SFSceneViewportToolbarType;
    typedef SFUnrecEditorInterfacePtr SFSceneEditorType;
    typedef SFUnrecEditorInterfacePtr SFBackgroundEditorType;
    typedef SFUnrecEditorInterfacePtr SFCameraEditorType;
    typedef SFUnrecEditorInterfacePtr SFForegroundEditorType;
    typedef SFUnrecEditorInterfacePtr SFLightEditorType;
    typedef SFUnrecEditorInterfacePtr SFParticleSystemEditorType;
    typedef SFUnrecEditorInterfacePtr SFSceneObjectEditorType;
    typedef SFUnrecEditorInterfacePtr SFViewportEditorType;

    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    static FieldContainerType &getClassType   (void);
    static UInt32              getClassTypeId (void);
    static UInt16              getClassGroupId(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                FieldContainer Get                            */
    /*! \{                                                                 */

    virtual       FieldContainerType &getType         (void);
    virtual const FieldContainerType &getType         (void) const;

    virtual       UInt32              getContainerSize(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

            const SFUnrecMainMenuPtr  *getSFMenu           (void) const;
            const SFUnrecMainToolbarPtr *getSFToolbar        (void) const;
            const SFUnrecStatusBarPtr *getSFStatusBar      (void) const;
            const SFUnrecHelpPanelPtr *getSFHelpPanel      (void) const;
            const SFUnrecSceneComponentTreePtr *getSFSceneComponentTree(void) const;
            const SFUnrecSceneNavigationPanelPtr *getSFSceneNavigationPanel(void) const;
            const SFUnrecSceneViewportPanelPtr *getSFSceneViewportPanel(void) const;
            const SFUnrecSceneViewportToolbarPtr *getSFSceneViewportToolbar(void) const;
            const SFUnrecEditorInterfacePtr *getSFSceneEditor    (void) const;
            const SFUnrecEditorInterfacePtr *getSFBackgroundEditor(void) const;
            const SFUnrecEditorInterfacePtr *getSFCameraEditor   (void) const;
            const SFUnrecEditorInterfacePtr *getSFForegroundEditor(void) const;
            const SFUnrecEditorInterfacePtr *getSFLightEditor    (void) const;
            const SFUnrecEditorInterfacePtr *getSFParticleSystemEditor(void) const;
            const SFUnrecEditorInterfacePtr *getSFSceneObjectEditor(void) const;
            const SFUnrecEditorInterfacePtr *getSFViewportEditor (void) const;


                  MainMenu * getMenu           (void) const;

                  MainToolbar * getToolbar        (void) const;

                  StatusBar * getStatusBar      (void) const;

                  HelpPanel * getHelpPanel      (void) const;

                  SceneComponentTree * getSceneComponentTree(void) const;

                  SceneNavigationPanel * getSceneNavigationPanel(void) const;

                  SceneViewportPanel * getSceneViewportPanel(void) const;

                  SceneViewportToolbar * getSceneViewportToolbar(void) const;

                  EditorInterface * getSceneEditor    (void) const;

                  EditorInterface * getBackgroundEditor(void) const;

                  EditorInterface * getCameraEditor   (void) const;

                  EditorInterface * getForegroundEditor(void) const;

                  EditorInterface * getLightEditor    (void) const;

                  EditorInterface * getParticleSystemEditor(void) const;

                  EditorInterface * getSceneObjectEditor(void) const;

                  EditorInterface * getViewportEditor (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr Field Set                                 */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Access                              */
    /*! \{                                                                 */

    virtual UInt32 getBinSize (ConstFieldMaskArg  whichField);
    virtual void   copyToBin  (BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);
    virtual void   copyFromBin(BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Construction                               */
    /*! \{                                                                 */

    static  MainWindowTransitPtr  create          (void);
    static  MainWindow           *createEmpty     (void);

    static  MainWindowTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  MainWindow            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  MainWindowTransitPtr  createDependent  (BitVector bFlags);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Copy                                   */
    /*! \{                                                                 */

    virtual FieldContainerTransitPtr shallowCopy     (void) const;
    virtual FieldContainerTransitPtr shallowCopyLocal(
                                       BitVector bFlags = FCLocal::All) const;
    virtual FieldContainerTransitPtr shallowCopyDependent(
                                                      BitVector bFlags) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    static TypeObject _type;

    static       void   classDescInserter(TypeObject &oType);
    static const Char8 *getClassname     (void             );

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFUnrecMainMenuPtr _sfMenu;
    SFUnrecMainToolbarPtr _sfToolbar;
    SFUnrecStatusBarPtr _sfStatusBar;
    SFUnrecHelpPanelPtr _sfHelpPanel;
    SFUnrecSceneComponentTreePtr _sfSceneComponentTree;
    SFUnrecSceneNavigationPanelPtr _sfSceneNavigationPanel;
    SFUnrecSceneViewportPanelPtr _sfSceneViewportPanel;
    SFUnrecSceneViewportToolbarPtr _sfSceneViewportToolbar;
    SFUnrecEditorInterfacePtr _sfSceneEditor;
    SFUnrecEditorInterfacePtr _sfBackgroundEditor;
    SFUnrecEditorInterfacePtr _sfCameraEditor;
    SFUnrecEditorInterfacePtr _sfForegroundEditor;
    SFUnrecEditorInterfacePtr _sfLightEditor;
    SFUnrecEditorInterfacePtr _sfParticleSystemEditor;
    SFUnrecEditorInterfacePtr _sfSceneObjectEditor;
    SFUnrecEditorInterfacePtr _sfViewportEditor;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    MainWindowBase(void);
    MainWindowBase(const MainWindowBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~MainWindowBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const MainWindow *source = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleMenu            (void) const;
    EditFieldHandlePtr editHandleMenu           (void);
    GetFieldHandlePtr  getHandleToolbar         (void) const;
    EditFieldHandlePtr editHandleToolbar        (void);
    GetFieldHandlePtr  getHandleStatusBar       (void) const;
    EditFieldHandlePtr editHandleStatusBar      (void);
    GetFieldHandlePtr  getHandleHelpPanel       (void) const;
    EditFieldHandlePtr editHandleHelpPanel      (void);
    GetFieldHandlePtr  getHandleSceneComponentTree (void) const;
    EditFieldHandlePtr editHandleSceneComponentTree(void);
    GetFieldHandlePtr  getHandleSceneNavigationPanel (void) const;
    EditFieldHandlePtr editHandleSceneNavigationPanel(void);
    GetFieldHandlePtr  getHandleSceneViewportPanel (void) const;
    EditFieldHandlePtr editHandleSceneViewportPanel(void);
    GetFieldHandlePtr  getHandleSceneViewportToolbar (void) const;
    EditFieldHandlePtr editHandleSceneViewportToolbar(void);
    GetFieldHandlePtr  getHandleSceneEditor     (void) const;
    EditFieldHandlePtr editHandleSceneEditor    (void);
    GetFieldHandlePtr  getHandleBackgroundEditor (void) const;
    EditFieldHandlePtr editHandleBackgroundEditor(void);
    GetFieldHandlePtr  getHandleCameraEditor    (void) const;
    EditFieldHandlePtr editHandleCameraEditor   (void);
    GetFieldHandlePtr  getHandleForegroundEditor (void) const;
    EditFieldHandlePtr editHandleForegroundEditor(void);
    GetFieldHandlePtr  getHandleLightEditor     (void) const;
    EditFieldHandlePtr editHandleLightEditor    (void);
    GetFieldHandlePtr  getHandleParticleSystemEditor (void) const;
    EditFieldHandlePtr editHandleParticleSystemEditor(void);
    GetFieldHandlePtr  getHandleSceneObjectEditor (void) const;
    EditFieldHandlePtr editHandleSceneObjectEditor(void);
    GetFieldHandlePtr  getHandleViewportEditor  (void) const;
    EditFieldHandlePtr editHandleViewportEditor (void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

                  SFUnrecMainMenuPtr  *editSFMenu           (void);
                  SFUnrecMainToolbarPtr *editSFToolbar        (void);
                  SFUnrecStatusBarPtr *editSFStatusBar      (void);
                  SFUnrecHelpPanelPtr *editSFHelpPanel      (void);
                  SFUnrecSceneComponentTreePtr *editSFSceneComponentTree(void);
                  SFUnrecSceneNavigationPanelPtr *editSFSceneNavigationPanel(void);
                  SFUnrecSceneViewportPanelPtr *editSFSceneViewportPanel(void);
                  SFUnrecSceneViewportToolbarPtr *editSFSceneViewportToolbar(void);
                  SFUnrecEditorInterfacePtr *editSFSceneEditor    (void);
                  SFUnrecEditorInterfacePtr *editSFBackgroundEditor(void);
                  SFUnrecEditorInterfacePtr *editSFCameraEditor   (void);
                  SFUnrecEditorInterfacePtr *editSFForegroundEditor(void);
                  SFUnrecEditorInterfacePtr *editSFLightEditor    (void);
                  SFUnrecEditorInterfacePtr *editSFParticleSystemEditor(void);
                  SFUnrecEditorInterfacePtr *editSFSceneObjectEditor(void);
                  SFUnrecEditorInterfacePtr *editSFViewportEditor (void);


















    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setMenu           (MainMenu * const value);
            void setToolbar        (MainToolbar * const value);
            void setStatusBar      (StatusBar * const value);
            void setHelpPanel      (HelpPanel * const value);
            void setSceneComponentTree(SceneComponentTree * const value);
            void setSceneNavigationPanel(SceneNavigationPanel * const value);
            void setSceneViewportPanel(SceneViewportPanel * const value);
            void setSceneViewportToolbar(SceneViewportToolbar * const value);
            void setSceneEditor    (EditorInterface * const value);
            void setBackgroundEditor(EditorInterface * const value);
            void setCameraEditor   (EditorInterface * const value);
            void setForegroundEditor(EditorInterface * const value);
            void setLightEditor    (EditorInterface * const value);
            void setParticleSystemEditor(EditorInterface * const value);
            void setSceneObjectEditor(EditorInterface * const value);
            void setViewportEditor (EditorInterface * const value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual void execSyncV(      FieldContainer    &oFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);

            void execSync (      MainWindowBase *pFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Aspect Create                            */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual FieldContainer *createAspectCopy(
                                    const FieldContainer *pRefAspect) const;
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:
    /*---------------------------------------------------------------------*/

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const MainWindowBase &source);
};

typedef MainWindowBase *MainWindowBaseP;

OSG_END_NAMESPACE

#endif /* _OSGMAINWINDOWBASE_H_ */
