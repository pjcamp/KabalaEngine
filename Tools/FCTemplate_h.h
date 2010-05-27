/* This is a template file for fcdEdit.
 * To create it from sample source,  cut'n'paste the source and apply the following
 * substitutions:
 * s|\|\\|g 
 * s|"|\"|g 
 * s|^|"| 
 * s|$|",|
 */

const char *FCTemplate_h[]={
"/*---------------------------------------------------------------------------*\\",
" *                             Kabala Engine                                 *",
" *                                                                           *",
" *                                                                           *",
" *   contact: djkabala@gmail.com                                             *",
" *                                                                           *",
"\\*---------------------------------------------------------------------------*/",
"/*---------------------------------------------------------------------------*\\",
" *                                License                                    *",
" *                                                                           *",
" * This library is free software; you can redistribute it and/or modify it   *",
" * under the terms of the GNU General Public License as published            *",
" * by the Free Software Foundation, version 3.                               *",
" *                                                                           *",
" * This library is distributed in the hope that it will be useful, but       *",
" * WITHOUT ANY WARRANTY; without even the implied warranty of                *",
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *",
" * Library General Public License for more details.                          *",
" *                                                                           *",
" * You should have received a copy of the GNU General Public                 *",
" * License along with this library; if not, write to the Free Software       *",
" * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *",
" *                                                                           *",
"\\*---------------------------------------------------------------------------*/",
"/*---------------------------------------------------------------------------*\\",
" *                                Changes                                    *",
" *                                                                           *",
" *                                                                           *",
" *                                                                           *",
" *                                                                           *",
" *                                                                           *",
" *                                                                           *",
"\\*---------------------------------------------------------------------------*/",
"",
"#ifndef _KE@!CLASSNAME!@_H_",
"#define _KE@!CLASSNAME!@_H_",
"#ifdef __sgi",
"#pragma once",
"#endif",
"",
"#include <@!HeaderPrefix!@OSGConfig.h>",
"",
"@@if useLocalIncludes",
"#include \"KE@!Classname!@Base.h\"",
"@@else",
"#include <KE@!Classname!@Base.h>",
"@@endif",
"",
"OSG_BEGIN_NAMESPACE",
"",
"@@if Library",
"/*! \\brief @!Classname!@ class. See \\ref ",
"           Page@!Libname!@@!Classname!@ for a description.",
"*/",
"",
"class KE_@!LIBNAME!@LIB_DLLMAPPING @!Classname!@ : public @!Classname!@Base",
"@@else",
"class @!Classname!@ : public @!Classname!@Base",
"@@endif",
"{",
"  private:",
"",
"    typedef @!Classname!@Base Inherited;",
"",
"    /*==========================  PUBLIC  =================================*/",
"  public:",
"",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                      Sync                                    */",
"    /*! \\{                                                                 */",
"",
"    virtual void changed(BitVector  whichField, ",
"                         UInt32     origin    );",
"",
"    /*! \\}                                                                 */",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                     Output                                   */",
"    /*! \\{                                                                 */",
"",
"    virtual void dump(      UInt32     uiIndent = 0, ",
"                      const BitVector  bvFlags  = 0) const;",
"",
"    /*! \\}                                                                 */",
"    /*=========================  PROTECTED  ===============================*/",
"  protected:",
"",
"    // Variables should all be in @!Classname!@Base.",
"",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                  Constructors                                */",
"    /*! \\{                                                                 */",
"",
"    @!Classname!@(void);",
"    @!Classname!@(const @!Classname!@ &source);",
"",
"    /*! \\}                                                                 */",
"    /*---------------------------------------------------------------------*/",
"    /*! \\name                   Destructors                                */",
"    /*! \\{                                                                 */",
"",
"    virtual ~@!Classname!@(void); ",
"",
"    /*! \\}                                                                 */",
"    ",
"    /*==========================  PRIVATE  ================================*/",
"  private:",
"",
"    friend class FieldContainer;",
"    friend class @!Classname!@Base;",
"",
"    static void initMethod(void);",
"",
"    // prohibit default functions (move to 'public' if you need one)",
"",
"    void operator =(const @!Classname!@ &source);",
"};",
"",
"typedef @!Classname!@ *@!Classname!@P;",
"",
"OSG_END_NAMESPACE",
"",
"@@if useLocalIncludes",
"#include \"KE@!Classname!@Base.inl\"",
"#include \"KE@!Classname!@.inl\"",
"@@else",
"#include <KE@!Classname!@Base.inl>",
"#include <KE@!Classname!@.inl>",
"@@endif",
"",
"#endif /* _KE@!CLASSNAME!@_H_ */",
NULL };
