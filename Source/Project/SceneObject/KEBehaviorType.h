/*---------------------------------------------------------------------------*\
 *                        OpenSG ToolBox Toolbox                             *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                         www.vrac.iastate.edu                              *
 *                                                                           *
 *            Authors: David Kabala,Eric Langkamp,Robert Goetz               *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU Library General Public License as published    *
 * by the Free Software Foundation, version 2.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU Library General Public         *
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

#ifndef _KEBEHAVIORTYPE_H_
#define _KEBEHAVIORTYPE_H_

#include <OpenSG/OSGConfig.h>
#include "KEKabalaEngineDef.h"

#include "Project/Scene/KESceneFields.h"

#include <OpenSG/OSGBaseTypes.h>

#include <map>
#include <boost/function.hpp>
#include <OpenSG/OSGTypeBase.h>

#include <OpenSG/OSGFilePathAttachment.h>
#include <OpenSG/OSGContainerUtils.h>
#include <fstream>
#include <sstream>


OSG_BEGIN_NAMESPACE

/*! \ingroup GrpSystemFieldContainerFuncs
 */

//typedef void              (*InitContainerF)  (void);

/*! \ingroup GrpSystemFieldContainerFuncs
 */

//typedef FieldContainerPtr (*PrototypeCreateF)(void);

/*! \ingroup GrpSystemFieldContainer
 */

class KE_KABALAENGINE_DLLMAPPING BehaviorType : public TypeBase
{
    /*==========================  PUBLIC  =================================*/

  public :
    typedef TypeBase Inherited;
	
	void registerWithScene(Scene* scene);

	UInt32 findEventID(std::string eventName);
    std::string findEventName(UInt32 id);


	FieldContainerType * getFieldContainerType();

    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */



    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructor                                 */
    /*! \{                                                                 */

    virtual ~BehaviorType(void); 

	/*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name						Get	                                   */
    /*! \{                                                                 */

    const std::vector<std::string>      getSourceContainers();
    const std::vector<std::string>      getEvents();
    const std::vector<std::string>      getEventLinks();
    const std::vector<BehaviorType*>	getDependencies();
          Scene*                        getAttachedScene();

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name						Has	                                   */
    /*! \{                                                                 */
	bool hasEvent(std::string e);
	bool hasEventLink(std::string e);
	bool hasDependent(BehaviorType* d);
	bool hasDependency(BehaviorType* d);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                  Type Information                            */
    /*! \{                                                                 */

    BehaviorType *getParent (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Description                                  */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Prototype                                    */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Query Properties                              */
    /*! \{                                                                 */

    bool isInitialized(void) const;

    bool isAbstract(void) const;
  

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                        Dump                                  */
    /*! \{                                                                 */

    virtual void dump(UInt32 uiIndent = 0, const BitVector bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

	  BehaviorType(const std::string &szName,
			 FieldContainerType * bBehaviorFieldContainerType,
			 std::vector<std::string> eventSourceNames = std::vector<std::string>(),
			 std::vector<std::string> bEvents = std::vector<std::string>(),
			 std::vector<std::string> bEventLinks = std::vector<std::string>());

      BehaviorType(const BehaviorType &source);

    /*---------------------------------------------------------------------*/
    /*! \name                      Member                                  */
    /*! \{                                                                 */

    bool _bInitialized;
	std::string TheCode;

    std::vector<UInt32>         _bActiveEventIDs;
	std::vector<BehaviorType*>	_bDependencies;
	std::vector<BehaviorType*>	_bDependents;

    std::vector<std::string>    _bSourceContainers;
	std::vector<std::string>	_bEvents;
	std::vector<std::string>	_bEventLinks;
    std::vector<std::string>    luaFunctionNames;  

    BehaviorType *_pParent;

	Scene * attachedScene;
	
	FieldContainerType * behaviorFieldContainerType;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Register                                  */
    /*! \{                                                                 */

    void registerType();

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name             Intialization / Termination                      */
    /*! \{                                                                 */

    bool initialize(void);
    void terminate(void);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:
   // typedef TypeBase Inherited;

    friend class BehaviorFactoryBase;
	friend class Behavior;

    /*!\brief prohibit default function (move to 'public' if needed) */
    void operator =(const BehaviorType &source);
};

OSG_END_NAMESPACE

#include "KEBehaviorType.inl"

#endif /* _KEBEHAVIORTYPE_H_ */
