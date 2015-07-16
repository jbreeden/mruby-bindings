
#ifndef NSPR_HEADER
#define NSPR_HEADER

/*
 * RClass Macros
 * -------------
 *
 * Macros for retrieving the RClass*'s defined by this gem.
 */

#define NSPR_module(mrb) mrb_module_get(mrb, "NSPR")
#define Prversiondescription_class(mrb) mrb_class_get_under(mrb, NSPR_module(mrb), "Prversiondescription")

/*
 * Class Bindings Options
 * ----------------------
 *
 * Use these macros to configure the generated bindings for classes & structs.
 *
 * Key:
 *
 * BIND_{type name}_TYPE                     : Should we bind the class at all?
 * BIND_{type name}_INITIALIZE               : If the class is bound, should we also bind initialize to malloc a new instance on `new`?
 * BIND_{type name}_{field name}_FIELD       : If the class is bound, should we also bind this field?
 * BIND_{type name}_{function name}_FUNCTION : If the class is bound, should we also bind this member function?
 *
 * Fields & method are disabled by default so that bindings may be added and
 * tested incrementally. The generated bindings are a good start, but they
 * will need to be verified and, sometimes, customized.
 */

#define BIND_Prversiondescription_TYPE TRUE
#define BIND_Prversiondescription_INITIALIZE FALSE
#define BIND_Prversiondescription_beta_FIELD FALSE
#define BIND_Prversiondescription_buildTime_FIELD FALSE
#define BIND_Prversiondescription_buildTimeString_FIELD FALSE
#define BIND_Prversiondescription_comment_FIELD FALSE
#define BIND_Prversiondescription_copyright_FIELD FALSE
#define BIND_Prversiondescription_debug_FIELD FALSE
#define BIND_Prversiondescription_description_FIELD FALSE
#define BIND_Prversiondescription_filename_FIELD FALSE
#define BIND_Prversiondescription_security_FIELD FALSE
#define BIND_Prversiondescription_special_FIELD FALSE
#define BIND_Prversiondescription_specialString_FIELD FALSE
#define BIND_Prversiondescription_vMajor_FIELD FALSE
#define BIND_Prversiondescription_vMinor_FIELD FALSE
#define BIND_Prversiondescription_vPatch_FIELD FALSE
#define BIND_Prversiondescription_version_FIELD FALSE


/*
 * Global Function Options
 * -----------------------
 *
 * Set these macros to TRUE to enable bindings for these functions.
 * They are disabled initially so that bindings may be added and tested
 * incrementally. The generated bindings are a good start, but they
 * will need to be verified and, sometimes, customized.
 */

#define BIND_LL_MaxInt_FUNCTION FALSE
#define BIND_LL_MaxUint_FUNCTION FALSE
#define BIND_LL_MinInt_FUNCTION FALSE
#define BIND_LL_Zero_FUNCTION FALSE
#define BIND_nspr_InitializePRErrorTable_FUNCTION FALSE
#define BIND_PL_Base64Decode_FUNCTION FALSE
#define BIND_PL_Base64Encode_FUNCTION FALSE
#define BIND_PL_CompareStrings_FUNCTION FALSE
#define BIND_PL_CompareValues_FUNCTION FALSE
#define BIND_PL_CreateLongOptState_FUNCTION FALSE
#define BIND_PL_CreateOptState_FUNCTION FALSE
#define BIND_PL_DestroyOptState_FUNCTION FALSE
#define BIND_PL_FPrintError_FUNCTION FALSE
#define BIND_PL_GetNextOpt_FUNCTION FALSE
#define BIND_PL_HashString_FUNCTION FALSE
#define BIND_PL_HashTableAdd_FUNCTION FALSE
#define BIND_PL_HashTableDestroy_FUNCTION FALSE
#define BIND_PL_HashTableDump_FUNCTION FALSE
#define BIND_PL_HashTableEnumerateEntries_FUNCTION FALSE
#define BIND_PL_HashTableLookup_FUNCTION FALSE
#define BIND_PL_HashTableLookupConst_FUNCTION FALSE
#define BIND_PL_HashTableRawAdd_FUNCTION FALSE
#define BIND_PL_HashTableRawLookup_FUNCTION FALSE
#define BIND_PL_HashTableRawLookupConst_FUNCTION FALSE
#define BIND_PL_HashTableRawRemove_FUNCTION FALSE
#define BIND_PL_HashTableRemove_FUNCTION FALSE
#define BIND_PL_NewHashTable_FUNCTION FALSE
#define BIND_PL_PrintError_FUNCTION FALSE
#define BIND_PL_strcasecmp_FUNCTION FALSE
#define BIND_PL_strcaserstr_FUNCTION FALSE
#define BIND_PL_strcasestr_FUNCTION FALSE
#define BIND_PL_strcat_FUNCTION FALSE
#define BIND_PL_strcatn_FUNCTION FALSE
#define BIND_PL_strchr_FUNCTION FALSE
#define BIND_PL_strcmp_FUNCTION FALSE
#define BIND_PL_strcpy_FUNCTION FALSE
#define BIND_PL_strdup_FUNCTION FALSE
#define BIND_PL_strfree_FUNCTION FALSE
#define BIND_PL_strlen_FUNCTION FALSE
#define BIND_PL_strncasecmp_FUNCTION FALSE
#define BIND_PL_strncaserstr_FUNCTION FALSE
#define BIND_PL_strncasestr_FUNCTION FALSE
#define BIND_PL_strncat_FUNCTION FALSE
#define BIND_PL_strnchr_FUNCTION FALSE
#define BIND_PL_strncmp_FUNCTION FALSE
#define BIND_PL_strncpy_FUNCTION FALSE
#define BIND_PL_strncpyz_FUNCTION FALSE
#define BIND_PL_strndup_FUNCTION FALSE
#define BIND_PL_strnlen_FUNCTION FALSE
#define BIND_PL_strnpbrk_FUNCTION FALSE
#define BIND_PL_strnprbrk_FUNCTION FALSE
#define BIND_PL_strnrchr_FUNCTION FALSE
#define BIND_PL_strnrstr_FUNCTION FALSE
#define BIND_PL_strnstr_FUNCTION FALSE
#define BIND_PL_strpbrk_FUNCTION FALSE
#define BIND_PL_strprbrk_FUNCTION FALSE
#define BIND_PL_strrchr_FUNCTION FALSE
#define BIND_PL_strrstr_FUNCTION FALSE
#define BIND_PL_strstr_FUNCTION FALSE
#define BIND_PL_strtok_r_FUNCTION FALSE
#define BIND_PR_Abort_FUNCTION FALSE
#define BIND_PR_Accept_FUNCTION FALSE
#define BIND_PR_AcceptRead_FUNCTION FALSE
#define BIND_PR_Access_FUNCTION FALSE
#define BIND_PR_AddToCounter_FUNCTION FALSE
#define BIND_PR_AddWaitFileDesc_FUNCTION FALSE
#define BIND_PR_Assert_FUNCTION FALSE
#define BIND_PR_AssertCurrentThreadInMonitor_FUNCTION FALSE
#define BIND_PR_AssertCurrentThreadOwnsLock_FUNCTION FALSE
#define BIND_PR_AtomicAdd_FUNCTION FALSE
#define BIND_PR_AtomicDecrement_FUNCTION FALSE
#define BIND_PR_AtomicIncrement_FUNCTION FALSE
#define BIND_PR_AtomicSet_FUNCTION FALSE
#define BIND_PR_AttachSharedMemory_FUNCTION FALSE
#define BIND_PR_Available_FUNCTION FALSE
#define BIND_PR_Available64_FUNCTION FALSE
#define BIND_PR_Bind_FUNCTION FALSE
#define BIND_PR_BlockClockInterrupts_FUNCTION FALSE
#define BIND_PR_BlockInterrupt_FUNCTION FALSE
#define BIND_PR_Calloc_FUNCTION FALSE
#define BIND_PR_CallOnce_FUNCTION FALSE
#define BIND_PR_CallOnceWithArg_FUNCTION FALSE
#define BIND_PR_CancelJob_FUNCTION FALSE
#define BIND_PR_CancelWaitFileDesc_FUNCTION FALSE
#define BIND_PR_CancelWaitGroup_FUNCTION FALSE
#define BIND_PR_CeilingLog2_FUNCTION FALSE
#define BIND_PR_CEnterMonitor_FUNCTION FALSE
#define BIND_PR_CExitMonitor_FUNCTION FALSE
#define BIND_PR_Cleanup_FUNCTION FALSE
#define BIND_PR_ClearInterrupt_FUNCTION FALSE
#define BIND_PR_Close_FUNCTION FALSE
#define BIND_PR_CloseDir_FUNCTION FALSE
#define BIND_PR_CloseFileMap_FUNCTION FALSE
#define BIND_PR_CloseSemaphore_FUNCTION FALSE
#define BIND_PR_CloseSharedMemory_FUNCTION FALSE
#define BIND_PR_CNotify_FUNCTION FALSE
#define BIND_PR_CNotifyAll_FUNCTION FALSE
#define BIND_PR_cnvtf_FUNCTION FALSE
#define BIND_PR_Connect_FUNCTION FALSE
#define BIND_PR_ConnectContinue_FUNCTION FALSE
#define BIND_PR_ConvertIPv4AddrToIPv6_FUNCTION FALSE
#define BIND_PR_CreateCounter_FUNCTION FALSE
#define BIND_PR_CreateFileMap_FUNCTION FALSE
#define BIND_PR_CreateIOLayer_FUNCTION FALSE
#define BIND_PR_CreateIOLayerStub_FUNCTION FALSE
#define BIND_PR_CreateMWaitEnumerator_FUNCTION FALSE
#define BIND_PR_CreateOrderedLock_FUNCTION FALSE
#define BIND_PR_CreatePipe_FUNCTION FALSE
#define BIND_PR_CreateProcess_FUNCTION FALSE
#define BIND_PR_CreateProcessDetached_FUNCTION FALSE
#define BIND_PR_CreateStack_FUNCTION FALSE
#define BIND_PR_CreateThread_FUNCTION FALSE
#define BIND_PR_CreateThreadPool_FUNCTION FALSE
#define BIND_PR_CreateTrace_FUNCTION FALSE
#define BIND_PR_CreateWaitGroup_FUNCTION FALSE
#define BIND_PR_CSetOnMonitorRecycle_FUNCTION FALSE
#define BIND_PR_CWait_FUNCTION FALSE
#define BIND_PR_DecrementCounter_FUNCTION FALSE
#define BIND_PR_Delete_FUNCTION FALSE
#define BIND_PR_DeleteSemaphore_FUNCTION FALSE
#define BIND_PR_DeleteSharedMemory_FUNCTION FALSE
#define BIND_PR_DestroyCondVar_FUNCTION FALSE
#define BIND_PR_DestroyCounter_FUNCTION FALSE
#define BIND_PR_DestroyLock_FUNCTION FALSE
#define BIND_PR_DestroyMonitor_FUNCTION FALSE
#define BIND_PR_DestroyMWaitEnumerator_FUNCTION FALSE
#define BIND_PR_DestroyOrderedLock_FUNCTION FALSE
#define BIND_PR_DestroyPollableEvent_FUNCTION FALSE
#define BIND_PR_DestroyProcessAttr_FUNCTION FALSE
#define BIND_PR_DestroyRWLock_FUNCTION FALSE
#define BIND_PR_DestroyStack_FUNCTION FALSE
#define BIND_PR_DestroyTrace_FUNCTION FALSE
#define BIND_PR_DestroyWaitGroup_FUNCTION FALSE
#define BIND_PR_DetachProcess_FUNCTION FALSE
#define BIND_PR_DetachSharedMemory_FUNCTION FALSE
#define BIND_PR_DisableClockInterrupts_FUNCTION FALSE
#define BIND_PR_dtoa_FUNCTION FALSE
#define BIND_PR_EnableClockInterrupts_FUNCTION FALSE
#define BIND_PR_EnterMonitor_FUNCTION FALSE
#define BIND_PR_EnumerateAddrInfo_FUNCTION FALSE
#define BIND_PR_EnumerateHostEnt_FUNCTION FALSE
#define BIND_PR_EnumerateWaitGroup_FUNCTION FALSE
#define BIND_PR_ErrorInstallCallback_FUNCTION FALSE
#define BIND_PR_ErrorInstallTable_FUNCTION FALSE
#define BIND_PR_ErrorLanguages_FUNCTION FALSE
#define BIND_PR_ErrorToName_FUNCTION FALSE
#define BIND_PR_ErrorToString_FUNCTION FALSE
#define BIND_PR_ExitMonitor_FUNCTION FALSE
#define BIND_PR_ExplodeTime_FUNCTION FALSE
#define BIND_PR_ExportFileMapAsString_FUNCTION FALSE
#define BIND_PR_FindFunctionSymbol_FUNCTION FALSE
#define BIND_PR_FindFunctionSymbolAndLibrary_FUNCTION FALSE
#define BIND_PR_FindNextCounterQname_FUNCTION FALSE
#define BIND_PR_FindNextCounterRname_FUNCTION FALSE
#define BIND_PR_FindNextTraceQname_FUNCTION FALSE
#define BIND_PR_FindNextTraceRname_FUNCTION FALSE
#define BIND_PR_FindSymbol_FUNCTION FALSE
#define BIND_PR_FindSymbolAndLibrary_FUNCTION FALSE
#define BIND_PR_FloorLog2_FUNCTION FALSE
#define BIND_PR_FormatTime_FUNCTION FALSE
#define BIND_PR_FormatTimeUSEnglish_FUNCTION FALSE
#define BIND_PR_fprintf_FUNCTION FALSE
#define BIND_PR_Free_FUNCTION FALSE
#define BIND_PR_FreeAddrInfo_FUNCTION FALSE
#define BIND_PR_FreeLibraryName_FUNCTION FALSE
#define BIND_PR_GetAddrInfoByName_FUNCTION FALSE
#define BIND_PR_GetCanonNameFromAddrInfo_FUNCTION FALSE
#define BIND_PR_GetConnectStatus_FUNCTION FALSE
#define BIND_PR_GetCounter_FUNCTION FALSE
#define BIND_PR_GetCounterHandleFromName_FUNCTION FALSE
#define BIND_PR_GetCounterNameFromHandle_FUNCTION FALSE
#define BIND_PR_GetCurrentThread_FUNCTION FALSE
#define BIND_PR_GetDefaultIOMethods_FUNCTION FALSE
#define BIND_PR_GetDescType_FUNCTION FALSE
#define BIND_PR_GetDirectorySeparator_FUNCTION FALSE
#define BIND_PR_GetDirectorySepartor_FUNCTION FALSE
#define BIND_PR_GetEnv_FUNCTION FALSE
#define BIND_PR_GetError_FUNCTION FALSE
#define BIND_PR_GetErrorText_FUNCTION FALSE
#define BIND_PR_GetErrorTextLength_FUNCTION FALSE
#define BIND_PR_GetFileInfo_FUNCTION FALSE
#define BIND_PR_GetFileInfo64_FUNCTION FALSE
#define BIND_PR_GetHostByAddr_FUNCTION FALSE
#define BIND_PR_GetHostByName_FUNCTION FALSE
#define BIND_PR_GetIdentitiesLayer_FUNCTION FALSE
#define BIND_PR_GetInheritedFD_FUNCTION FALSE
#define BIND_PR_GetInheritedFileMap_FUNCTION FALSE
#define BIND_PR_GetIPNodeByName_FUNCTION FALSE
#define BIND_PR_GetLayersIdentity_FUNCTION FALSE
#define BIND_PR_GetLibraryFilePathname_FUNCTION FALSE
#define BIND_PR_GetLibraryName_FUNCTION FALSE
#define BIND_PR_GetLibraryPath_FUNCTION FALSE
#define BIND_PR_GetMemMapAlignment_FUNCTION FALSE
#define BIND_PR_GetNameForIdentity_FUNCTION FALSE
#define BIND_PR_GetNumberOfProcessors_FUNCTION FALSE
#define BIND_PR_GetOpenFileInfo_FUNCTION FALSE
#define BIND_PR_GetOpenFileInfo64_FUNCTION FALSE
#define BIND_PR_GetOSError_FUNCTION FALSE
#define BIND_PR_GetPageShift_FUNCTION FALSE
#define BIND_PR_GetPageSize_FUNCTION FALSE
#define BIND_PR_GetPathSeparator_FUNCTION FALSE
#define BIND_PR_GetPeerName_FUNCTION FALSE
#define BIND_PR_GetPhysicalMemorySize_FUNCTION FALSE
#define BIND_PR_GetProtoByName_FUNCTION FALSE
#define BIND_PR_GetProtoByNumber_FUNCTION FALSE
#define BIND_PR_GetRandomNoise_FUNCTION FALSE
#define BIND_PR_GetSocketOption_FUNCTION FALSE
#define BIND_PR_GetSockName_FUNCTION FALSE
#define BIND_PR_GetSpecialFD_FUNCTION FALSE
#define BIND_PR_GetSystemInfo_FUNCTION FALSE
#define BIND_PR_GetThreadName_FUNCTION FALSE
#define BIND_PR_GetThreadPriority_FUNCTION FALSE
#define BIND_PR_GetThreadPrivate_FUNCTION FALSE
#define BIND_PR_GetThreadScope_FUNCTION FALSE
#define BIND_PR_GetThreadState_FUNCTION FALSE
#define BIND_PR_GetThreadType_FUNCTION FALSE
#define BIND_PR_GetTraceEntries_FUNCTION FALSE
#define BIND_PR_GetTraceHandleFromName_FUNCTION FALSE
#define BIND_PR_GetTraceNameFromHandle_FUNCTION FALSE
#define BIND_PR_GetTraceOption_FUNCTION FALSE
#define BIND_PR_GetUniqueIdentity_FUNCTION FALSE
#define BIND_PR_GetVersion_FUNCTION FALSE
#define BIND_PR_GMTParameters_FUNCTION FALSE
#define BIND_PR_htonl_FUNCTION FALSE
#define BIND_PR_htonll_FUNCTION FALSE
#define BIND_PR_htons_FUNCTION FALSE
#define BIND_PR_ImplodeTime_FUNCTION FALSE
#define BIND_PR_ImportFileMapFromString_FUNCTION FALSE
#define BIND_PR_IncrementCounter_FUNCTION FALSE
#define BIND_PR_Init_FUNCTION FALSE
#define BIND_PR_Initialize_FUNCTION FALSE
#define BIND_PR_Initialized_FUNCTION FALSE
#define BIND_PR_InitializeNetAddr_FUNCTION FALSE
#define BIND_PR_Interrupt_FUNCTION FALSE
#define BIND_PR_IntervalNow_FUNCTION FALSE
#define BIND_PR_IntervalToMicroseconds_FUNCTION FALSE
#define BIND_PR_IntervalToMilliseconds_FUNCTION FALSE
#define BIND_PR_IntervalToSeconds_FUNCTION FALSE
#define BIND_PR_IsNetAddrType_FUNCTION FALSE
#define BIND_PR_JoinJob_FUNCTION FALSE
#define BIND_PR_JoinThread_FUNCTION FALSE
#define BIND_PR_JoinThreadPool_FUNCTION FALSE
#define BIND_PR_KillProcess_FUNCTION FALSE
#define BIND_PR_Listen_FUNCTION FALSE
#define BIND_PR_LoadLibrary_FUNCTION FALSE
#define BIND_PR_LoadLibraryWithFlags_FUNCTION FALSE
#define BIND_PR_LoadStaticLibrary_FUNCTION FALSE
#define BIND_PR_LocalTimeParameters_FUNCTION FALSE
#define BIND_PR_Lock_FUNCTION FALSE
#define BIND_PR_LockOrderedLock_FUNCTION FALSE
#define BIND_PR_LogFlush_FUNCTION FALSE
#define BIND_PR_LogPrint_FUNCTION FALSE
#define BIND_PR_MakeDir_FUNCTION FALSE
#define BIND_PR_Malloc_FUNCTION FALSE
#define BIND_PR_MemMap_FUNCTION FALSE
#define BIND_PR_MemUnmap_FUNCTION FALSE
#define BIND_PR_MicrosecondsToInterval_FUNCTION FALSE
#define BIND_PR_MillisecondsToInterval_FUNCTION FALSE
#define BIND_PR_MkDir_FUNCTION FALSE
#define BIND_PR_NetAddrToString_FUNCTION FALSE
#define BIND_PR_NewCondVar_FUNCTION FALSE
#define BIND_PR_NewLock_FUNCTION FALSE
#define BIND_PR_NewLogModule_FUNCTION FALSE
#define BIND_PR_NewMonitor_FUNCTION FALSE
#define BIND_PR_NewPollableEvent_FUNCTION FALSE
#define BIND_PR_NewProcessAttr_FUNCTION FALSE
#define BIND_PR_NewRWLock_FUNCTION FALSE
#define BIND_PR_NewTCPSocket_FUNCTION FALSE
#define BIND_PR_NewTCPSocketPair_FUNCTION FALSE
#define BIND_PR_NewThreadPrivateIndex_FUNCTION FALSE
#define BIND_PR_NewUDPSocket_FUNCTION FALSE
#define BIND_PR_NormalizeTime_FUNCTION FALSE
#define BIND_PR_Notify_FUNCTION FALSE
#define BIND_PR_NotifyAll_FUNCTION FALSE
#define BIND_PR_NotifyAllCondVar_FUNCTION FALSE
#define BIND_PR_NotifyCondVar_FUNCTION FALSE
#define BIND_PR_Now_FUNCTION FALSE
#define BIND_PR_ntohl_FUNCTION FALSE
#define BIND_PR_ntohll_FUNCTION FALSE
#define BIND_PR_ntohs_FUNCTION FALSE
#define BIND_PR_Open_FUNCTION FALSE
#define BIND_PR_OpenAnonFileMap_FUNCTION FALSE
#define BIND_PR_OpenDir_FUNCTION FALSE
#define BIND_PR_OpenFile_FUNCTION FALSE
#define BIND_PR_OpenSemaphore_FUNCTION FALSE
#define BIND_PR_OpenSharedMemory_FUNCTION FALSE
#define BIND_PR_OpenTCPSocket_FUNCTION FALSE
#define BIND_PR_OpenUDPSocket_FUNCTION FALSE
#define BIND_PR_ParseTimeString_FUNCTION FALSE
#define BIND_PR_ParseTimeStringToExplodedTime_FUNCTION FALSE
#define BIND_PR_Poll_FUNCTION FALSE
#define BIND_PR_PopIOLayer_FUNCTION FALSE
#define BIND_PR_PostSemaphore_FUNCTION FALSE
#define BIND_PR_ProcessAttrSetCurrentDirectory_FUNCTION FALSE
#define BIND_PR_ProcessAttrSetInheritableFD_FUNCTION FALSE
#define BIND_PR_ProcessAttrSetInheritableFileMap_FUNCTION FALSE
#define BIND_PR_ProcessAttrSetStdioRedirect_FUNCTION FALSE
#define BIND_PR_ProcessExit_FUNCTION FALSE
#define BIND_PR_PushIOLayer_FUNCTION FALSE
#define BIND_PR_QueueJob_FUNCTION FALSE
#define BIND_PR_QueueJob_Accept_FUNCTION FALSE
#define BIND_PR_QueueJob_Connect_FUNCTION FALSE
#define BIND_PR_QueueJob_Read_FUNCTION FALSE
#define BIND_PR_QueueJob_Timer_FUNCTION FALSE
#define BIND_PR_QueueJob_Write_FUNCTION FALSE
#define BIND_PR_Read_FUNCTION FALSE
#define BIND_PR_ReadDir_FUNCTION FALSE
#define BIND_PR_Realloc_FUNCTION FALSE
#define BIND_PR_RecordTraceEntries_FUNCTION FALSE
#define BIND_PR_Recv_FUNCTION FALSE
#define BIND_PR_RecvFrom_FUNCTION FALSE
#define BIND_PR_Rename_FUNCTION FALSE
#define BIND_PR_ResetProcessAttr_FUNCTION FALSE
#define BIND_PR_RmDir_FUNCTION FALSE
#define BIND_PR_RWLock_Rlock_FUNCTION FALSE
#define BIND_PR_RWLock_Unlock_FUNCTION FALSE
#define BIND_PR_RWLock_Wlock_FUNCTION FALSE
#define BIND_PR_SecondsToInterval_FUNCTION FALSE
#define BIND_PR_Seek_FUNCTION FALSE
#define BIND_PR_Seek64_FUNCTION FALSE
#define BIND_PR_Send_FUNCTION FALSE
#define BIND_PR_SendFile_FUNCTION FALSE
#define BIND_PR_SendTo_FUNCTION FALSE
#define BIND_PR_SetConcurrency_FUNCTION FALSE
#define BIND_PR_SetCounter_FUNCTION FALSE
#define BIND_PR_SetCurrentThreadName_FUNCTION FALSE
#define BIND_PR_SetEnv_FUNCTION FALSE
#define BIND_PR_SetError_FUNCTION FALSE
#define BIND_PR_SetErrorText_FUNCTION FALSE
#define BIND_PR_SetFDCacheSize_FUNCTION FALSE
#define BIND_PR_SetFDInheritable_FUNCTION FALSE
#define BIND_PR_SetLibraryPath_FUNCTION FALSE
#define BIND_PR_SetLogBuffering_FUNCTION FALSE
#define BIND_PR_SetLogFile_FUNCTION FALSE
#define BIND_PR_SetNetAddr_FUNCTION FALSE
#define BIND_PR_SetPollableEvent_FUNCTION FALSE
#define BIND_PR_SetSocketOption_FUNCTION FALSE
#define BIND_PR_SetStdioRedirect_FUNCTION FALSE
#define BIND_PR_SetThreadPriority_FUNCTION FALSE
#define BIND_PR_SetThreadPrivate_FUNCTION FALSE
#define BIND_PR_SetTraceOption_FUNCTION FALSE
#define BIND_PR_Shutdown_FUNCTION FALSE
#define BIND_PR_ShutdownThreadPool_FUNCTION FALSE
#define BIND_PR_Sleep_FUNCTION FALSE
#define BIND_PR_smprintf_FUNCTION FALSE
#define BIND_PR_smprintf_free_FUNCTION FALSE
#define BIND_PR_snprintf_FUNCTION FALSE
#define BIND_PR_sprintf_append_FUNCTION FALSE
#define BIND_PR_sscanf_FUNCTION FALSE
#define BIND_PR_StackPop_FUNCTION FALSE
#define BIND_PR_StackPush_FUNCTION FALSE
#define BIND_PR_StringToNetAddr_FUNCTION FALSE
#define BIND_PR_strtod_FUNCTION FALSE
#define BIND_PR_SubtractFromCounter_FUNCTION FALSE
#define BIND_PR_sxprintf_FUNCTION FALSE
#define BIND_PR_Sync_FUNCTION FALSE
#define BIND_PR_SyncMemMap_FUNCTION FALSE
#define BIND_PR_TicksPerSecond_FUNCTION FALSE
#define BIND_PR_Trace_FUNCTION FALSE
#define BIND_PR_TransmitFile_FUNCTION FALSE
#define BIND_PR_UnblockClockInterrupts_FUNCTION FALSE
#define BIND_PR_UnblockInterrupt_FUNCTION FALSE
#define BIND_PR_UnloadLibrary_FUNCTION FALSE
#define BIND_PR_Unlock_FUNCTION FALSE
#define BIND_PR_UnlockOrderedLock_FUNCTION FALSE
#define BIND_PR_USPacificTimeParameters_FUNCTION FALSE
#define BIND_PR_VersionCheck_FUNCTION FALSE
#define BIND_PR_vfprintf_FUNCTION FALSE
#define BIND_PR_vsmprintf_FUNCTION FALSE
#define BIND_PR_vsnprintf_FUNCTION FALSE
#define BIND_PR_vsprintf_append_FUNCTION FALSE
#define BIND_PR_vsxprintf_FUNCTION FALSE
#define BIND_PR_Wait_FUNCTION FALSE
#define BIND_PR_WaitCondVar_FUNCTION FALSE
#define BIND_PR_WaitForPollableEvent_FUNCTION FALSE
#define BIND_PR_WaitProcess_FUNCTION FALSE
#define BIND_PR_WaitRecvReady_FUNCTION FALSE
#define BIND_PR_WaitSemaphore_FUNCTION FALSE
#define BIND_PR_Write_FUNCTION FALSE
#define BIND_PR_Writev_FUNCTION FALSE
#define BIND_PRP_DestroyNakedCondVar_FUNCTION FALSE
#define BIND_PRP_NakedBroadcast_FUNCTION FALSE
#define BIND_PRP_NakedNotify_FUNCTION FALSE
#define BIND_PRP_NakedWait_FUNCTION FALSE
#define BIND_PRP_NewNakedCondVar_FUNCTION FALSE
#define BIND_PRP_TryLock_FUNCTION FALSE

/*
 * Header Files
 * ------------
 *
 * These are the header files that defined the
 * classes and functions for which bindings have
 * been generated. If any of these are not needed
 * they should be commented out.
 */

#include <stdlib.h>
#include "mruby.h"
#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "mruby/value.h"
#include "mruby/variable.h"
#include "nspr.h"
#include "plarena.h"
#include "plarenas.h"
#include "plbase64.h"
#include "plerror.h"
#include "plgetopt.h"
#include "plhash.h"
#include "plstr.h"
#include "pratom.h"
#include "prbit.h"
#include "prclist.h"
#include "prcmon.h"
#include "prcountr.h"
#include "prcpucfg.h"
#include "prcvar.h"
#include "prdtoa.h"
#include "prenv.h"
#include "prerr.h"
#include "prerror.h"
#include "prinet.h"
#include "prinit.h"
#include "prinrval.h"
#include "prio.h"
#include "pripcsem.h"
#include "prlink.h"
#include "prlock.h"
#include "prlog.h"
#include "prlong.h"
#include "prmem.h"
#include "prmon.h"
#include "prmwait.h"
#include "prnetdb.h"
#include "prolock.h"
#include "prpdce.h"
#include "prprf.h"
#include "prproces.h"
#include "prrng.h"
#include "prrwlock.h"
#include "prshm.h"
#include "prshma.h"
#include "prsystem.h"
#include "prthread.h"
#include "prtime.h"
#include "prtpool.h"
#include "prtrace.h"
#include "prtypes.h"
#include "prvrsion.h"
#include "prwin16.h"

/*
 * Class initialization function declarations
 * ------------------------------------------
 *
 * These declarations are controlled by the macros in the
 * "Class Bindings Options" section above.
 */

#if BIND_Prversiondescription_TYPE
void mrb_NSPR_Prversiondescription_init(mrb_state* mrb);
#endif

/*
 * Boxing declarations
 * -------------------
 *
 * These declarations are controlled by the macros in the
 * "Class Bindings Options" section above.
 */

/*
* Extra wrapper over native pointer to indicate who owns this memory.
* (Either mruby, and it should be garage collected, or C, and it shouldn't be)
* Considered using the LSB of the pointer itself, but I don't think I can
* be assured that all memory is word-aligned (especially when C libraries
* implement their own memory management techniques like memory pools)
*/
typedef struct mruby_to_native_ref_ {
  /* If true, indicates that the object should be freed when
   * mruby GC's the ruby object containing this pointer. This
   * is set to true when an object is boxed via the `giftwrap`
   * or `gift_{type}_ptr_set` functions.
   */
  unsigned char belongs_to_ruby;

  /* A pointer to the native object */
  void* obj;

  /* For the convenience of the binding writer,
   * the data pointer can be used to associate arbitrary
   * data with a reference to a C object. This could
   * be a function pointer to invoke instead of `free` on GC,
   * a pointer back to the RObject, or even cast to an integer type
   * and used as a bit field. You get the idea...
   */
  void* data;
} mruby_to_native_ref;

#if BIND_Prversiondescription_TYPE
mrb_value
mruby_box_PRVersionDescription(mrb_state* mrb, PRVersionDescription *unboxed);

mrb_value
mruby_giftwrap_PRVersionDescription(mrb_state* mrb, PRVersionDescription *unboxed);

void
mruby_set_PRVersionDescription_data_ptr(mrb_value obj, PRVersionDescription *unboxed);

void
mruby_gift_PRVersionDescription_data_ptr(mrb_value obj, PRVersionDescription *unboxed);

PRVersionDescription *
mruby_unbox_PRVersionDescription(mrb_value boxed);
#endif


/*
 * Macro definition function declaration
 * -------------------------------------
 */
void mruby_NSPR_define_macro_constants(mrb_state* mrb);

#endif
