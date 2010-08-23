/*---------------------------------------------------------------------------*\
 *                             Kabala Engine                                 *
 *                                                                           *
 *               Copyright (C) 2009-2010 by David Kabala                     *
 *                                                                           *
 *   authors:  Robert Goetz (rdgoetz@iastate.edu)                            *
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

#include "KEConcurrentEffectGroup.h"

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGConcurrentEffectGroupBase.cpp file.
// To modify it, please change the .fcd file (OSGConcurrentEffectGroup.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void ConcurrentEffectGroup::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

void ConcurrentEffectGroup::initEffect()
{
}

void ConcurrentEffectGroup::inheritedBegin()
{
    Inherited::inheritedBegin();

    //for all effects, begin and attach a listener.
    for(UInt32 i(0);i < getMFEffectList()->size(); ++i)
    {
        _EffectFinishedConnections.push_back(getEffectList(i)->connectEffectFinished(boost::bind(&ConcurrentEffectGroup::handleEffectFinished, this, _1)));
        getEffectList(i)->begin();
    }

    activeEffects = getMFEffectList()->size();
}

bool ConcurrentEffectGroup::inheritedIsPlaying()
{
    return isPlayingFlag;
}

bool ConcurrentEffectGroup::inheritedIsPaused()
{
    return isPausedFlag;
}

void ConcurrentEffectGroup::inheritedPause()
{
    //for all effects, pause them if they are playing
    for(UInt32 i(0);i < getMFEffectList()->size(); ++i)
    {
        if(getEffectList(i)->isPlaying())
        {
            getEffectList(i)->pause();
        }
    }
}

void ConcurrentEffectGroup::inheritedUnpause()
{
    //for all effects, unpause if they are paused
    for(UInt32 i(0);i < getMFEffectList()->size(); ++i)
    {
        if(getEffectList(i)->isPaused())
        {
            getEffectList(i)->unpause();
        }
    }
}

void ConcurrentEffectGroup::inheritedStop()
{
    //for all effects, stop if they are playing
    for(UInt32 i(0);i < getMFEffectList()->size(); ++i)
    {
        if(getEffectList(i)->isPlaying())
        {
            getEffectList(i)->stop();
        }
    }
}

void ConcurrentEffectGroup::finished()
{
    for(UInt32 i(0);i < _EffectFinishedConnections.size(); ++i)
    {
        _EffectFinishedConnections[i].disconnect();
    }
    _EffectFinishedConnections.clear();
    Inherited::finished();
}

void ConcurrentEffectGroup::handleEffectFinished(EffectEventDetails* const details)
{
    --activeEffects;
    if(activeEffects == 0)
    {
        finished();
    }
}

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

void ConcurrentEffectGroup::resolveLinks(void)
{
    Inherited::resolveLinks();

    for(UInt32 i(0);i < _EffectFinishedConnections.size(); ++i)
    {
        _EffectFinishedConnections[i].disconnect();
    }
    _EffectFinishedConnections.clear();
}

/*----------------------- constructors & destructors ----------------------*/

ConcurrentEffectGroup::ConcurrentEffectGroup(void) :
    Inherited()
{
}

ConcurrentEffectGroup::ConcurrentEffectGroup(const ConcurrentEffectGroup &source) :
    Inherited(source)
{
}

ConcurrentEffectGroup::~ConcurrentEffectGroup(void)
{
}

/*----------------------------- class specific ----------------------------*/

void ConcurrentEffectGroup::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void ConcurrentEffectGroup::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump ConcurrentEffectGroup NI" << std::endl;
}

OSG_END_NAMESPACE
