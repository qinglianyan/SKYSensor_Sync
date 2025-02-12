/**
 * <name>CmpTemplate.c</name>
 * <description> 
 *  Example for an empty runtime component frame that can be used as a starting point to develop own components.
 *
 *  MANDATORY FUNCTIONS:
 *  - ComponentEntry()
 *  - ExportFunctions()
 *  - ImportFunctions()
 *  - CmpGetVersion()
 *  - HookFunction()
 * </description>
 *
 * <copyright>Copyright CODESYS Development GmbH</copyright>
 */

#include "CmpStd.h"
#include "CmpTemplateEmptyDep.h"

USE_STMT

DLL_DECL int CDECL ComponentEntry(INIT_STRUCT *pInitStruct)
/*	Used to exchange function pointers between component manager and components.
	Called at startup for each component.
	pInitStruct:			IN	Pointer to structure with:
		pfExportFunctions	OUT Pointer to function that exports component functions
		pfImportFunctions	OUT Pointer to function that imports functions from other components
		pfGetVersion		OUT Pointer to function to get component version
		pfRegisterAPI		IN	Pointer to component manager function to register a API function
		pfGetAPI			IN	Pointer to component manager function to get a API function
		pfCallHook			IN	Pointer to component manager function to call a hook function
	Return					ERR_OK if library could be initialized, else error code
*/
{
	pInitStruct->CmpId = COMPONENT_ID;
	pInitStruct->pfExportFunctions = ExportFunctions;
	pInitStruct->pfImportFunctions = ImportFunctions;
	pInitStruct->pfGetVersion = CmpGetVersion;
	pInitStruct->pfHookFunction = HookFunction;
	pInitStruct->pfCreateInstance = NULL;
	pInitStruct->pfDeleteInstance = NULL;

	s_pfCMRegisterAPI = pInitStruct->pfCMRegisterAPI;
	s_pfCMRegisterAPI2 = pInitStruct->pfCMRegisterAPI2;
	s_pfCMGetAPI = pInitStruct->pfCMGetAPI;
	s_pfCMGetAPI2 = pInitStruct->pfCMGetAPI2;
	s_pfCMCallHook = pInitStruct->pfCMCallHook;
	s_pfCMRegisterClass = pInitStruct->pfCMRegisterClass;
	s_pfCMCreateInstance = pInitStruct->pfCMCreateInstance;
	return ERR_OK;
}

/**
 * <description>Publish exported functions to the component manager, to make them available for other components.
 * Use generated macro EXPORT_STMT.</description>
 * <result>ERR_OK or error code in case of error</result>
 */
static int CDECL ExportFunctions(void)
{
	/* Macro to export functions */
	EXPORT_STMT;
	return ERR_OK;
}

/**
 * <description>Import function pointers from other components. Use generated macro IMPORT_STMT.</description>
 * <result>ERR_OK or error code if function name could not be resolved</result>
 */
static int CDECL ImportFunctions(void)
{
	/* Macro to import functions */
	IMPORT_STMT;
	return ERR_OK;
}

/**
 * <description>Return the version of our component.</description>
 * <result>Version as defined in dep file</result>
 */
static RTS_UI32 CDECL CmpGetVersion(void)
{
	return CMP_VERSION;
}

/**
 * <description>Hook function to get all broadcast hooks of the component manager. All init and exit stuff must be implemented here!</description>
 * <param name="ulHook" type="IN">Kind of hook. See CH_ definitions in CmpItf.h for details.</param> 
 * <param name="ulParam1" type="IN">Hook specific first parameter. See definitions in CmpItf.h for details.</param> 
 * <param name="ulParam2" type="IN">Hook specific second parameter. See definitions in CmpItf.h for details.</param>  
 * <result>Error code</result>
 */
static RTS_RESULT CDECL HookFunction(RTS_UI32 ulHook, RTS_UINTPTR ulParam1, RTS_UINTPTR ulParam2)
{
	switch (ulHook)
	{
		case CH_INIT:
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_INIT");
			break;
		case CH_INIT2:
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_INIT2");
			break;
		case CH_INIT3:
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_INIT3");
			break;
		case CH_INIT_TASKS:
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_INIT_TASKS");
			break;
		case CH_INIT_COMM:
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_INIT_COMM");
			break;
		case CH_INIT_FINISHED:
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_INIT_FINISHED");
			break;

		/* Cyclic */
		case CH_COMM_CYCLE:
			break;

		case CH_EXIT_COMM:
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_EXIT_COMM");
			break;
		case CH_EXIT_TASKS:
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_EXIT_TASKS");
			break;
		case CH_EXIT3:
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_EXIT3");
			break;
		case CH_EXIT2:
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_EXIT2");
			break;
		case CH_EXIT:
		{
			if (CHK_LogAdd)
				CAL_LogAdd(STD_LOGGER, COMPONENT_ID, LOG_INFO, ERR_OK, 0, "CH_EXIT");
			EXIT_STMT;
			break;
		}
		default:
			break;
	}
	return ERR_OK;
}
