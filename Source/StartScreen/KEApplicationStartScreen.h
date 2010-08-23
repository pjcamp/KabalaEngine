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

#ifndef _KEAPPLICATIONSTARTSCREEN_H_
#define _KEAPPLICATIONSTARTSCREEN_H_
#ifdef __sgi
#pragma once
#endif

#include "KEApplicationStartScreenBase.h"
#include <OpenSG/OSGForegroundFields.h>
#include <OpenSG/OSGAnimatorFields.h>
#include <OpenSG/OSGUIDrawingSurfaceFields.h>
#include <OpenSG/OSGFieldAnimationFields.h>
#include <OpenSG/OSGKeyEventDetailsFields.h>
#include <OpenSG/OSGActionEventDetailsFields.h>

OSG_BEGIN_NAMESPACE

/*! \brief ApplicationStartScreen class. See \ref
           PageKabalaEngineApplicationStartScreen for a description.
*/

class KE_KABALAENGINE_DLLMAPPING ApplicationStartScreen : public ApplicationStartScreenBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef ApplicationStartScreenBase Inherited;
    typedef ApplicationStartScreen     Self;

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
	virtual void attachApplication(void);
	virtual void dettachApplication(void);
	ForegroundRefPtr createInterface(void);
	virtual void start(void);
	virtual void stop(void);
    virtual void reset(void);
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in ApplicationStartScreenBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    ApplicationStartScreen(void);
    ApplicationStartScreen(const ApplicationStartScreen &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~ApplicationStartScreen(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    void handleKeyTyped(KeyEventDetails* const details);
    void handleBuilderButtonAction(ActionEventDetails* const details);
    void handlePlayerButtonAction(ActionEventDetails* const details);
    void handleExitButtonAction(ActionEventDetails* const details);

    boost::signals2::connection _KeyTypedConnection,
                                _BuilderButtonActionConnection,
                                _PlayerButtonActionConnection,
                                _ExitButtonActionConnection;

    UIDrawingSurfaceRefPtr _TheUIDrawingSurface;
    FieldAnimationRefPtr _TorusAnimation;
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class ApplicationStartScreenBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const ApplicationStartScreen &source);
};

typedef ApplicationStartScreen *ApplicationStartScreenP;

OSG_END_NAMESPACE

#include "KEApplicationStartScreenBase.inl"
#include "KEApplicationStartScreen.inl"

#endif /* _KEAPPLICATIONSTARTSCREEN_H_ */
