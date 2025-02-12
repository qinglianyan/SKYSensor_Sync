/**
 *  <name>Component Template</name>
 *  <description> 
 *  An example on how to implement a component.
 *  This component does no usefull work and it exports no functions
 *  which are intended to be used for anything. Use at your own risk.
 *  </description>
 *  <copyright>
 *  Copyright CODESYS Development GmbH
 *  </copyright>
 */
SET_COMPONENT_NAME(`CmpTemplateEmpty')
COMPONENT_SOURCES(`CmpTemplateEmpty.c')

COMPONENT_VERSION(`0x03051200')

/* NOTE: REPLACE 0x0001 BY YOUR VENDORID */
COMPONENT_VENDORID(`0x0001')				

#define CMPID_CmpTemplateEmpty		0x2000								/* NOTE: START HERE WITH YOUR COMPONENTIDS (see CmpItf.h */
#define CLASSID_CCmpTemplateEmpty	ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR CLASSIDS (see CmpItf.h */
#define ITFID_ICmpTemplateEmpty		ADDVENDORID(CMP_VENDORID, 0x2000)	/* NOTE: START HERE WITH YOUR INTERFACEIDS (see CmpItf.h */

CATEGORY(`Templates')

USE_ITF(`CMUtilsItf.m4')
USE_ITF(`SysFileItf.m4')

IMPLEMENT_ITF(`CmpTemplateEmptyItf.m4')

REQUIRED_IMPORTS(
CMUtlSafeStrCpy)

OPTIONAL_IMPORTS(
SysFileOpen,
SysFileClose,
SysFileRead,
SysFileWrite)
