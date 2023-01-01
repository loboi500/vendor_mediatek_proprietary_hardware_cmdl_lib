/*------------------------------------------------------------------------------
 * MediaTek Inc. (C) 2019. All rights reserved.
 *
 * Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 *----------------------------------------------------------------------------*/
#ifndef __CMDL_H__
#define __CMDL_H__

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

#include <CL/cl.h>

#define CMDL_RESULT         CMDL_Result_e
#define CMDL_NODE           CMDL_Node_t
#define CMDL_HANDLE_NULL    0
#define CMDL_NODE_NULL      0

typedef struct CmdL_Handle_s* CMDL_HANDLE;
typedef void*  CMDL_Node_t;

// defined same as MKErrorType structure in ./src/MKType.h
typedef enum {
    CMDL_OK                         = 0,
    CMDL_OK_DISABLE                 = 1,
    CMDL_OK_HANDLE_FULL             = 2,
    CMDL_OK_NO_IMPLEMENTATION       = 3,
    CMDL_ERR                        = 16,
    CMDL_ERR_INVALID_PARAMS         = 17,
    CMDL_ERR_INVALID_HANDLE         = 18,
    CMDL_ERR_INVALID_NODE           = 19,
    CMDL_ERR_INVALID_RESULT         = 20,
    CMDL_ERR_BAD_RESOURCE_MAP       = 21,
    CMDL_ERR_BAD_BUFFER_MAP         = 22,
    CMDL_ERR_OUT_OF_MEMORY          = 23,
    CMDL_ERR_COMMAND_RECORD_FAIL    = 24,
    CMDL_ERR_COMMAND_RUN_FAIL       = 25,
    CMDL_ERR_CL_DEVICE_NOT_MATCHED  = 26,
    CMDL_ERR_NOT_FOUND              = 27,
    CMDL_ERR_DUMP_FILE              = 28,
    CMDL_ERR_SET_HOST_PTR_FAIL      = 29,
    CMDL_ERR_COMPARE_SIZE_NOT_MATCH = 30,
    CMDL_ERR_COMPARE_NOT_MATCH      = 31,
    CMDL_ERR_OPENCL_NOT_AVAILABLE   = 32,
} CMDL_Result_e;

typedef enum {
    E_CMDL_DEBUG_LEVEL_FATAL = 0,    ///< Fatal
    E_CMDL_DEBUG_LEVEL_ERROR,        ///< Error
    E_CMDL_DEBUG_LEVEL_WARN,         ///< Warn
    E_CMDL_DEBUG_LEVEL_DEBUG,        ///< Debug
    E_CMDL_DEBUG_LEVEL_INFO,         ///< Info
    E_CMDL_DEBUG_LEVEL_VERBOSE,      ///< Verbose
    E_CMDL_DEBUG_LEVEL_MAX,
} CMDL_DebugLevel_e;

typedef enum {
    E_CMDL_CTL_FLAGS_DEBUG_BIT_TRUE = 0,    ///< Check bit true. The flags value is bool value.
    E_CMDL_CTL_FLAGS_NEUROPILOT_CL_PROFILE, ///< Enable profiling log. The flags value is bool value.
    E_CMDL_CTL_FLAGS_NEUROPILOT_CL_FINISH,  ///< Enable clflush to clfinish. The flags value is bool value.
    E_CMDL_CTL_FLAGS_SYSTRACE,              ///< Enable systrace. The flags value is bool value.
    E_CMDL_CTL_FLAGS_MAX,
} CMDL_CtlFlags_e;

// defined same as MKProgramType structure in ./src/MKType.h
typedef enum {
    E_CMDL_RUN_TYPE_INIT    = 0x0001,
    E_CMDL_RUN_TYPE_EXECUTE = 0x0002,
    E_CMDL_RUN_TYPE_END     = 0x0004,
    E_CMDL_RUN_TYPE_ANY     = 0xFFFF,
} CMDL_RunType_e;

typedef enum {
    E_CMDL_HOST_SOURCE_INPUT = 1,   ///< Host input type
    E_CMDL_HOST_SOURCE_OUTPUT,      ///< Host output type
    E_CMDL_HOST_SOURCE_MAX,
} CMDL_HostSource_e;

typedef enum {
    E_CMDL_DATA_TYPE_NHWC = 0,
    E_CMDL_DATA_TYPE_NCHW,
    E_CMDL_DATA_TYPE_MAX,
} CMDL_DataType_e;

typedef enum {
    E_CMDL_CMDS_SET_RELEASE_COMMAND_QUEUE_AND_CONTEXT = 0,
    E_CMDL_CMDS_SET_ONLY_RUN_ONCE,
    E_CMDL_CMDS_SET_MAX,
} CMDL_CmdsSet_e;


typedef struct CMDL_DataInfo_s
{
    size_t copyLength;              ///< [in] Length
    size_t dstStride[4];            ///< [in] Destination data Stride
    size_t srcStride[4];            ///< [in] Source data stride
    size_t dimension[4];            ///< [in] Dimension
} CMDL_DataInfo_t;

//------------------------------------------------------------------------------
/// @brief Create.
/// @param[in] eType: Run type defined in enum type CMDL_RunType_e.
/// @param[out] ppNode: Tree node.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_INVALID_NODE: Node are invalied.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodeCreate(CMDL_RunType_e eType, CMDL_Node_t* ppNode);

//------------------------------------------------------------------------------
/// @brief Release.
/// @param[in] pNode: Tree node.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_INVALID_NODE: Node are invalied.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodeRelease(CMDL_Node_t pNode);

//------------------------------------------------------------------------------
/// @brief Attach node.
/// @param[in] pParentNode: Parent tree node.
/// @param[in] pChildNode: Child tree node.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodeAttachNode(CMDL_Node_t pParentNode, CMDL_Node_t pChildNode);

//------------------------------------------------------------------------------
/// @brief Attach host input/output data.
/// @param[in] pNode: Tree node.
/// @param[in] eSource: Source type defined in enum type CMDL_HostSource_e.
/// @param[in] id: Dimension.
/// @param[in] pData: Data pointer for every dimension.
/// @param[in] dataSize: Data size for every dimension.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodeAttachHostPtr(CMDL_Node_t pNode, CMDL_HostSource_e eSource, unsigned int id, void* pData, size_t dataSize);

//------------------------------------------------------------------------------
/// @brief Attach static data.
/// @param[in] pNode: Tree node.
/// @param[in] pData: Data pointer for every dimension.
/// @param[in] dataSize: Data size for every dimension.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodeAttachStaticData(CMDL_Node_t pNode, void* pData, size_t dataSize);

//------------------------------------------------------------------------------
/// @brief Attach data copy.
/// @param[in] pNode: Tree node.
/// @param[in] eDataType: Data type.
/// @param[in] pDst: A pointer to destination buffer.
/// @param[in] pSrc: A pointer to source buffer.
/// @param[in] pDataInfo: Data information.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodeAttachDataCopy(CMDL_Node_t pNode, CMDL_DataType_e eDataType, void *pDst, const void* pSrc, CMDL_DataInfo_t *pDataInfo);

//------------------------------------------------------------------------------
/// @brief Attach cmmands set.
/// @param[in] pNode: Tree node.
/// @param[in] eCmdsSet: Commands set.
/// @param[in] pData: Data.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
/// @return CMDL_ERR_NOT_FOUND: Not found.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodeAttachCommands(CMDL_Node_t pNode, CMDL_CmdsSet_e eCmdsSet, void* pData);

//------------------------------------------------------------------------------
/// @brief Deattach node.
/// @param[in] pParentNode: Parent tree node.
/// @param[in] pChildNode: Child tree node.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodeDeAttachNode(CMDL_Node_t pParentNode, CMDL_Node_t pChildNode);

//------------------------------------------------------------------------------
/// @brief Dump Json file.
/// @param[in] pNode: Tree node.
/// @param[in] pFilename: File name.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_INVALID_NODE: Node are invalied.
/// @return CMDL_ERR_DUMP_FILE: Save file failed.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodeDumpJsonFile(CMDL_Node_t pNode, const char* pszFilename);

//------------------------------------------------------------------------------
/// @brief Push node to top.
/// @param[in] pNode: Tree node.
/// @return CMDL_OK: Process success.
/// @return CMDL_OK_DISABLE: CmdL is disable.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodePushStack(CMDL_Node_t pNode);

//------------------------------------------------------------------------------
/// @brief Pop node from top one.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodePopStack(void);

//------------------------------------------------------------------------------
/// @brief Get node.
/// @param[out] ppNode: Tree node.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_TreeNodeGetTop(CMDL_Node_t* ppNode);

//------------------------------------------------------------------------------
/// @brief Create handle.
/// @param[out] phCmdL: A handle pointer to retrieve an instance of a created CmdL module.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_CreateHandle(CMDL_HANDLE *phCmdL);

//------------------------------------------------------------------------------
/// @brief Release handle.
/// @param[in] hCmdL: An instance of a created CmdL module.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_ReleaseHandle(CMDL_HANDLE hCmdL);

//------------------------------------------------------------------------------
/// @brief Insert tree node.
/// @param[in] hCmdL: Handle.
/// @param[in] pNode: Tree node.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_INVALID_NODE: Node are invalied.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_InsertTreeNode(CMDL_HANDLE hCmdL, CMDL_Node_t pNode);

//------------------------------------------------------------------------------
/// @brief Remove tree node.
/// @param[in] hCmdL: Handle.
/// @param[in] pNode: Tree node.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_INVALID_NODE: Node are invalied.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_RemoveTreeNode(CMDL_HANDLE hCmdL, CMDL_Node_t pNode);

//------------------------------------------------------------------------------
/// @brief Save to file.
/// @param[in] hCmdL: Handle.
/// @param[in] pFilename: File name.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_INVALID_NODE: Node are invalied.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_SaveToFile(CMDL_HANDLE hCmdL, const char* pszFilename);

//------------------------------------------------------------------------------
/// @brief Get buffer size.
/// @param[in] hCmdL: Handle.
/// @param[out] pSize: Buffer size.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_GetBufferSize(CMDL_HANDLE hCmdL, unsigned int* pSize);

//------------------------------------------------------------------------------
/// @brief Save to buffer.
/// @param[in] hCmdL: Handle.
/// @param[in] pBuffer: Buffer.
/// @param[in] size: Buffer size.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_INVALID_NODE: Node are invalied.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_SaveToBuffer(CMDL_HANDLE hCmdL, char* pBuffer, unsigned int size);

//------------------------------------------------------------------------------
/// @brief Get tree from file.
/// @param[in] hCmdL: Handle.
/// @param[in] pszFilename: File name.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_LoadByFile(CMDL_HANDLE hCmdL, const char* pszFilename);

//------------------------------------------------------------------------------
/// @brief Get tree load from buffer.
/// @param[in] hCmdL: Handle.
/// @param[in] pBuffer: Buffer.
/// @param[in] size: Buffer size.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_LoadByBuffer(CMDL_HANDLE hCmdL, const char* pBuffer, unsigned int size);

//------------------------------------------------------------------------------
/// @brief Get tree node count.
/// @param[in] hCmdL: Handle.
/// @param[out] pCount: Tree node count.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_GetTreeNodeCount(CMDL_HANDLE hCmdL, unsigned int *pCount);

//------------------------------------------------------------------------------
/// @brief Get tree node.
/// @param[in] hCmdL: Handle.
/// @param[in] i: Take the ith.
/// @param[out] ppNode: Tree node.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_GetTreeNode(CMDL_HANDLE hCmdL, unsigned int i, CMDL_Node_t *ppNode);

//------------------------------------------------------------------------------
/// @brief Set control.
/// @param[in] flags: Debug flag using DEBUG_FLAGS defined value.
/// @param[in] pValue: Flag value.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_SetControl(CMDL_HANDLE hCmdL, CMDL_CtlFlags_e flags, void* pValue);

//------------------------------------------------------------------------------
/// @brief Set host memory pointer.
/// @param[in] hCmdL: Handle.
/// @param[in] pNode: Tree node.
/// @param[in] eSource: Source type defined in enum type CMDL_HostSource_e.
/// @param[in] id: Dimension.
/// @param[in] pData: Data for every dimension.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_SetHostPtr(CMDL_HANDLE hCmdL, CMDL_Node_t pNode, CMDL_HostSource_e eSource, unsigned int id, void* pData);

//------------------------------------------------------------------------------
/// @brief Set fd pointer.
/// @param[in] hCmdL: Handle.
/// @param[in] pNode: Tree node.
/// @param[in] eSource: Source type defined in enum type CMDL_HostSource_e.
/// @param[in] id: Dimension.
/// @param[in] fd: externel memory FD.
/// @param[in] bProtected: is protected memory or not.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_SetFd(CMDL_HANDLE hCmdL, CMDL_Node_t pNode, CMDL_HostSource_e eSource, unsigned int id, int fd, bool bProtected=false);

//------------------------------------------------------------------------------
/// @brief Run.
/// @param[in] hCmdL: Handle.
/// @param[in] eType: Run type defined in enum type CMDL_RunType_e.
/// @param[in] pNode: Tree node.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_Run(CMDL_HANDLE hCmdL, CMDL_RunType_e eType, CMDL_Node_t pNode);

//------------------------------------------------------------------------------
/// @brief Reset.
/// @param[in] hCmdL: Handle.
/// @param[in] pNode: Tree node.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_Reset(CMDL_HANDLE hCmdL, CMDL_Node_t pNode);

//------------------------------------------------------------------------------
/// @brief Get enable.
/// @param[out] pEnable: enable cmdl feature or not.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_GetEnable(bool *pEnable);

//------------------------------------------------------------------------------
/// @brief Set enable.
/// @param[in] bEnable: enable cmdl feature or not.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_SetEnable(bool bEnable);

//------------------------------------------------------------------------------
/// @brief Set debug level.
/// @param[in] eLevel: Debug level defined in enum type CMDL_DebugLevel_e.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_SetDebugLevel(CMDL_DebugLevel_e eLevel);

//------------------------------------------------------------------------------
/// @brief Set extended properties for cl_context.
/// @param[in] hCmdL: Handle.
/// @param[in] prop: Extended properties.
/// @param[in] num_prop: The number of extended properties.
/// @param[in] pNodeSpecifiedOnly: Specified tree node.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_SetCLContextExtendedProp(
    CMDL_HANDLE hCmdL,
    cl_context_properties* prop,
    int num_prop,
    CMDL_Node_t pNodeSpecifiedOnly = nullptr);

//------------------------------------------------------------------------------
/// @brief Set function for TV fd.
/// @param[in] hCmdL: Handle.
/// @param[in] pfAllocFd: Function implemented by user to alloc fd.
/// @param[in] pfIsProtectedFd: Function implemented by user to get whether fd is protected.
/// @param[in] pfFreeFd: Function implemented by user to free fd.
/// @param[in] pPrivate: Private variable deined by user.
/// @param[in] pNodeSpecifiedOnly: Specified tree node.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
typedef int (*AllocFdFunc)(size_t size, void* pPrivate);
typedef bool (*IsProtectedFunc)(int fd, void* pPrivate);
typedef void (*FreeFdFunc)(int fd, void* pPrivate);
CMDL_RESULT CmdL_SetFunc4Fd(
    CMDL_HANDLE hCmdL,
    AllocFdFunc pfAllocFd,
    IsProtectedFunc pfIsProtectedFd,
    FreeFdFunc pfFreeFd,
    void* pPrivate,
    CMDL_Node_t pNodeSpecifiedOnly = nullptr);

//------------------------------------------------------------------------------
/// @brief Check driver compatibility.
/// @param[in] hCmdL: Handle.
/// @param[in] pNode: Tree node.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_CheckDriverCompatibility(CMDL_HANDLE hCmdL, CMDL_Node_t pNode);

//------------------------------------------------------------------------------
/// @brief Get Op profiling result.
/// @param[in] hCmdL: Handle.
/// @param[in] pNode: Tree node.
/// @param[out] rDataSize: Number of profiled OPs.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_GetProfiledOpSize(
    CMDL_HANDLE hCmdL,
    CMDL_Node_t pNode,
    size_t* rDataSize);

//------------------------------------------------------------------------------
/// @brief Get Op profiling result.
/// @param[in] hCmdL: Handle.
/// @param[in] pNode: Tree node.
/// @param[out] pNameSize: Length of each profiled OP name.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_GetProfiledOpNameSize(
    CMDL_HANDLE hCmdL,
    CMDL_Node_t pNode,
    size_t* pNameSize);

//------------------------------------------------------------------------------
/// @brief Get Op profiling result.
/// @param[in] hCmdL: Handle.
/// @param[in] pNode: Tree node.
/// @param[out] pProfiledOpName: Profiled OP name.
/// @param[out] pProfiledOpResult: Profiled OP result.
/// @return CMDL_OK: Process success.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_GetProfiledOpResult(
    CMDL_HANDLE hCmdL,
    CMDL_Node_t pNode,
    char** pProfiledOpName,
    double* pProfiledOpResult);

#ifdef __cplusplus
}
#endif

#endif///__CMDL_H__
