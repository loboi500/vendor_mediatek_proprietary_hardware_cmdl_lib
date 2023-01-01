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

#include "cmdl.h"
#include "CL/cl.h"
#include "CL/cl_ext.h"

#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
/// @brief Create an array of sub-devices that each reference a non-intersecting set of compute units within in_device.
/// @param[in] ppNode: Tree node.
/// @param[in] in_device: A device to be partitioned.
/// @param[in] properties: The way to partition in_device.
/// @param[in] num_devices: The number of the sub-devices.
/// @param[in] out_devices: The buffer where the OpenCL sub-devices will be returned.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateSubDevices(
    CMDL_Node_t ppNode,
    cl_device_id in_device,
    const cl_device_partition_property *properties,
    cl_uint num_devices,
    cl_device_id *out_devices);

//------------------------------------------------------------------------------
/// @brief Increment the devices reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] device: A device ID.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclRetainDevice(
    CMDL_Node_t ppNode,
    cl_device_id device);

//------------------------------------------------------------------------------
/// @brief Decrement the device reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] device: A device ID.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclReleaseDevice(
    CMDL_Node_t ppNode,
    cl_device_id device);

//------------------------------------------------------------------------------
/// @brief Create an OpenCL context.
/// @param[in] ppNode: Tree node.
/// @param[in] properties: A list of context property names and their corresponding values.
/// @param[in] num_devices: The number of devices.
/// @param[in] devices: A list of OpenCL devices.
/// @param[in] context: An OpenCL context.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateContext(
    CMDL_Node_t ppNode,
    const cl_context_properties *properties,
    cl_uint num_devices,
    const cl_device_id *devices,
    cl_context context);

//------------------------------------------------------------------------------
/// @brief Create an OpenCL context from a device type that identifies the specific device(s) to use.
/// @param[in] ppNode: Tree node.
/// @param[in] properties: A list of context property names and their corresponding values.
/// @param[in] device_type: The type of OpenCL device.
/// @param[in] context: An OpenCL context.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateContextFromType(
    CMDL_Node_t ppNode,
    const cl_context_properties *properties,
    cl_device_type device_type,
    cl_context context);

//------------------------------------------------------------------------------
/// @brief Increment the context reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclRetainContext(
    CMDL_Node_t ppNode,
    cl_context context);

//------------------------------------------------------------------------------
/// @brief Decrement the context reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclReleaseContext(
    CMDL_Node_t ppNode,
    cl_context context);

//------------------------------------------------------------------------------
/// @brief Create a command-queue on a specific device.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] device: A device associated with context.
/// @param[in] properties: A list of properties for the command-queue.
/// @param[in] command_queue: An OpenCL command-queue.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateCommandQueue(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_device_id device,
    cl_command_queue_properties properties,
    cl_command_queue command_queue);

//------------------------------------------------------------------------------
/// @brief Create a host or device command-queue on a specific device.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] device: A device associated with context.
/// @param[in] properties: A list of properties for the command-queue and their corresponding values.
/// @param[in] command_queue: An OpenCL command-queue.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateCommandQueueWithProperties(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_device_id device,
    const cl_queue_properties *properties,
    cl_command_queue command_queue);

//------------------------------------------------------------------------------
/// @brief Increment the command_queue reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclRetainCommandQueue(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue);

//------------------------------------------------------------------------------
/// @brief Decrement the command_queue reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclReleaseCommandQueue(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue);

//------------------------------------------------------------------------------
/// @brief Enable or disable the properties of a command-queue.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] properties: The new command-queue properties.
/// @param[in] enable: The values specified by properties are enabled or disabled.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclSetCommandQueueProperty(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_command_queue_properties properties,
    cl_bool enable);

//------------------------------------------------------------------------------
/// @brief Create a buffer object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] flags: A bit-field used to specify allocation and usage information about the buffer memory object.
/// @param[in] size: The size in bytes of the buffer memory object to be allocated.
/// @param[in] host_ptr: A pointer to the buffer data that may already be allocated by the application.
/// @param[in] buffer: An OpenCL buffer memory object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateBuffer(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_mem_flags flags,
    size_t size,
    void *host_ptr,
    cl_mem buffer);

//------------------------------------------------------------------------------
/// @brief Create a new buffer object (as a sub-buffer object) from an existing buffer object.
/// @param[in] ppNode: Tree node.
/// @param[in] buffer: An existing buffer object and cannot be a sub-buffer object.
/// @param[in] flags: A bit-field used to specify allocation and usage information about the sub-buffer memory object.
/// @param[in] buffer_create_type: The type of buffer object to be created.
/// @param[in] buffer_create_info: The offset and size in bytes in the buffer object.
/// @param[in] sub_buffer: An OpenCL buffer memory object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateSubBuffer(
    CMDL_Node_t ppNode,
    cl_mem buffer,
    cl_mem_flags flags,
    cl_buffer_create_type buffer_create_type,
    const void *buffer_create_info,
    cl_mem sub_buffer);

//------------------------------------------------------------------------------
/// @brief Create a 1D image, 1D image buffer, 1D image array, 2D image, 2D image array or 3D image object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] flags: A bit-field that is used to specify allocation and usage information about the image memory object.
/// @param[in] image_format: A pointer to a structure that describes format properties of the image to be allocated.
/// @param[in] image_desc: A pointer to a structure that describes type and dimensions of the image to be allocated.
/// @param[in] host_ptr: A pointer to the image data that may already be allocated by the application.
/// @param[in] image: An OpenCL image memory object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateImage(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format *image_format,
    const cl_image_desc *image_desc,
    void *host_ptr,
    cl_mem image);

//------------------------------------------------------------------------------
/// @brief Create a 2D image object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] flags: A bit-field that is used to specify allocation and usage information about the image memory object.
/// @param[in] image_format: A pointer to a structure that describes format properties of the image to be allocated.
/// @param[in] image_width: The width of the image in pixels.
/// @param[in] image_height: The height of the image in pixels.
/// @param[in] image_row_pitch: The scan-line pitch in bytes.
/// @param[in] host_ptr: A pointer to the image data that may already be allocated by the application.
/// @param[in] image2d: A 2D OpenCL image memory object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateImage2D(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format *image_format,
    size_t image_width,
    size_t image_height,
    size_t image_row_pitch,
    void *host_ptr,
    cl_mem image2d);

//------------------------------------------------------------------------------
/// @brief Create a 3D image object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] flags: A bit-field that is used to specify allocation and usage information about the image memory object.
/// @param[in] image_format: A pointer to a structure that describes format properties of the image to be allocated.
/// @param[in] image_width: The width of the image in pixels.
/// @param[in] image_height: The height of the image in pixels.
/// @param[in] image_depth: The depth of the image in pixels.
/// @param[in] image_row_pitch: The scan-line pitch in bytes.
/// @param[in] image_slice_pitch: The size in bytes of each 2D slice in the 3D image.
/// @param[in] host_ptr: A pointer to the image data that may already be allocated by the application.
/// @param[in] image3d: A 3D OpenCL image memory object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateImage3D(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format *image_format,
    size_t image_width,
    size_t image_height,
    size_t image_depth,
    size_t image_row_pitch,
    size_t image_slice_pitch,
    void *host_ptr,
    cl_mem image3d);

//------------------------------------------------------------------------------
/// @brief Create a pipe object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] flags: A bit-field used to specify allocation and usage information such as the memory arena that should be used to allocate the pipe object and how it will be used.
/// @param[in] pipe_packet_size: The size in bytes of a pipe packet.
/// @param[in] pipe_max_packets: The pipe capacity by specifying the maximum number of packets the pipe can hold.
/// @param[in] properties: A list of properties for the pipe and their corresponding values.
/// @param[in] pipe: An OpenCL pipe object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreatePipe(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_mem_flags flags,
    cl_uint pipe_packet_size,
    cl_uint pipe_max_packets,
    const cl_pipe_properties *properties,
    cl_mem pipe);

//------------------------------------------------------------------------------
/// @brief Map the memory into the device page tables after a suitable pointer to an external memory allocation <memory> is given.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] flags: A bit-field used to specify allocation and usage information about the buffer memory object.
/// @param[in] properties: A list of properties for the imported memory and their corresponding values.
/// @param[in] memory: An imported host memory pointer.
/// @param[in] size: The size in bytes.
/// @param[in] buffer: An OpenCL buffer memory object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclImportMemoryARM(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_mem_flags flags,
    const cl_import_properties_arm *properties,
    void *memory,
    size_t size,
    cl_mem buffer);

//------------------------------------------------------------------------------
/// @brief Increment the memory object reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] memobj: A memory object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclRetainMemObject(
    CMDL_Node_t ppNode,
    cl_mem memobj);

//------------------------------------------------------------------------------
/// @brief Decrement the memory object reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] memobj: A memory object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclReleaseMemObject(
    CMDL_Node_t ppNode,
    cl_mem memobj);

//------------------------------------------------------------------------------
/// @brief Allocate a shared virtual memory (SVM) buffer that can be shared by the host and all devices in an OpenCL context that support shared virtual memory.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] flags: A bit-field used to specify allocation and usage information.
/// @param[in] size: The size in bytes of the SVM buffer to be allocated.
/// @param[in] alignment: The minimum alignment in bytes that is required for the newly created buffer's memory region.
/// @param[in] svm: A shared virtual memory pointer.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclSVMAlloc(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_svm_mem_flags flags,
    size_t size,
    cl_uint alignment,
    void* svm_ptr);

//------------------------------------------------------------------------------
/// clSVMFree Free a shared virtual memory buffer allocated using clSVMAlloc.
/// @brief
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] svm_pointer: A svm pointer.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclSVMFree(
    CMDL_Node_t ppNode,
    cl_context context,
    void *svm_pointer);

//------------------------------------------------------------------------------
/// @brief Create a sampler object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] normalized_coords: The image coordinates are normalized or not.
/// @param[in] addressing_mode: The way to handle out-of-range image coordinates when reading from an image.
/// @param[in] filter_mode: The type of filter that must be applied when reading an image.
/// @param[in] sampler: An OpenCL sampler object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateSampler(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_bool normalized_coords,
    cl_addressing_mode addressing_mode,
    cl_filter_mode filter_mode,
    cl_sampler sampler);

//------------------------------------------------------------------------------
/// @brief Create a sampler object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] sampler_properties: A list of sampler property names and their corresponding values.
/// @param[in] sampler: An OpenCL sampler object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateSamplerWithProperties(
    CMDL_Node_t ppNode,
    cl_context context,
    const cl_sampler_properties *sampler_properties,
    cl_sampler sampler);

//------------------------------------------------------------------------------
/// @brief Increment the sampler reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] sampler: A sampler object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclRetainSampler(
    CMDL_Node_t ppNode,
    cl_sampler sampler);

//------------------------------------------------------------------------------
/// @brief Decrement the sampler reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] sampler: A sampler object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclReleaseSampler(
    CMDL_Node_t ppNode,
    cl_sampler sampler);

//------------------------------------------------------------------------------
/// @brief Create a program object for a context, and loads the source code specified by the text strings in the strings array into the program object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] count: The count of the string in the strings array.
/// @param[in] strings: An array of count pointers to optionally null-terminated character strings that make up the source code.
/// @param[in] lengths: An array with the number of chars in each string (the string length).
/// @param[in] program: An OpenCL program object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateProgramWithSource(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_uint count,
    const char **strings,
    const size_t *lengths,
    cl_program program);

//------------------------------------------------------------------------------
/// @brief Create a program object for a context, and loads specified binary data into the program object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] num_devices: The number of devices listed in device_list.
/// @param[in] device_list: A pointer to a list of devices in context.
/// @param[in] lengths: An array of the size in bytes of the program binaries to be loaded for devices specified by device_list.
/// @param[in] binaries: An array of pointers to program binaries to be loaded for devices specified by device_list.
/// @param[in] program: An OpenCL program object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateProgramWithBinary(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_uint num_devices,
    const cl_device_id *device_list,
    const size_t *lengths,
    const unsigned char **binaries,
    cl_program program);

//------------------------------------------------------------------------------
/// @brief Create a program object for a context, and loads the information related to the built-in kernels into a program object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] num_devices: The number of devices listed in device_list.
/// @param[in] device_list: A pointer to a list of devices in context.
/// @param[in] kernel_names: A semi-colon separated list of built-in kernel names.
/// @param[in] program: An OpenCL program object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateProgramWithBuiltInKernels(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_uint num_devices,
    const cl_device_id *device_list,
    const char *kernel_names,
    cl_program program);

//------------------------------------------------------------------------------
/// @brief Increment the program reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] program: A program object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclRetainProgram(
    CMDL_Node_t ppNode,
    cl_program program);

//------------------------------------------------------------------------------
/// @brief Decrement the program reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] program: A program object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclReleaseProgram(
    CMDL_Node_t ppNode,
    cl_program program);

//------------------------------------------------------------------------------
/// @brief Build (compiles and links) a program executable from the program source or binary.
/// @param[in] ppNode: Tree node.
/// @param[in] program: A program object.
/// @param[in] num_devices: The number of devices listed in device_list.
/// @param[in] device_list: A pointer to a list of devices associated with program..
/// @param[in] options: A pointer to a null-terminated string of characters that describes the build options to be used for building the program executable.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclBuildProgram(
    CMDL_Node_t ppNode,
    cl_program program,
    cl_uint num_devices,
    const cl_device_id *device_list,
    const char *options);

//------------------------------------------------------------------------------
/// @brief Compile a program's source for all the devices or a specific device(s) in the OpenCL context associated with program.
/// @param[in] ppNode: Tree node.
/// @param[in] program: A program object.
/// @param[in] num_devices: The number of devices listed in device_list.
/// @param[in] device_list: A pointer to a list of devices associated with program.
/// @param[in] options: A pointer to a null-terminated string of characters that describes the compilation options to be used for building the program executable.
/// @param[in] num_input_headers: The number of programs that describe headers in the array referenced by input_headers.
/// @param[in] input_headers: An array of program embedded headers created with clCreateProgramWithSource.
/// @param[in] header_include_names: An array that has a one to one correspondence with input_headers.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCompileProgram(
    CMDL_Node_t ppNode,
    cl_program program,
    cl_uint num_devices,
    const cl_device_id *device_list,
    const char *options,
    cl_uint num_input_headers,
    const cl_program *input_headers,
    const char **header_include_names);

//------------------------------------------------------------------------------
/// @brief Link a set of compiled program objects and libraries for all the devices or a specific device(s) in the OpenCL context and creates an executable.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] num_devices: The number of devices listed in device_list.
/// @param[in] device_list: A pointer to a list of devices in context.
/// @param[in] options: A pointer to a null-terminated string of characters that describes the link options to be used for building the program executable.
/// @param[in] num_input_programs: The number of programs in input_programs.
/// @param[in] input_programs: An array of program objects that are compiled binaries or libraries that are to be linked to create the program executable.
/// @param[in] program: A program object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclLinkProgram(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_uint num_devices,
    const cl_device_id *device_list,
    const char *options,
    cl_uint num_input_programs,
    const cl_program *input_programs,
    cl_program program);

//------------------------------------------------------------------------------
/// @brief Allow the implementation to release the resources allocated by the OpenCL compiler.
/// @param[in] ppNode: Tree node.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclUnloadCompiler(
    CMDL_Node_t ppNode);

//------------------------------------------------------------------------------
/// @brief Allow the implementation to release the resources allocated by the OpenCL compiler for platform.
/// @param[in] ppNode: Tree node.
/// @param[in] platform: A platform ID.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclUnloadPlatformCompiler(
    CMDL_Node_t ppNode,
    cl_platform_id platform);

//------------------------------------------------------------------------------
/// @brief Create a kernal object.
/// @param[in] ppNode: Tree node.
/// @param[in] program: A program object with a successfully built executable.
/// @param[in] kernel_name: A function name in the program declared with the __kernel qualifier.
/// @param[in] kernel: An OpenCL kernal object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateKernel(
    CMDL_Node_t ppNode,
    cl_program program,
    const char *kernel_name,
    cl_kernel kernel);

//------------------------------------------------------------------------------
/// @brief Create kernel objects for all kernel functions in a program object.
/// @param[in] ppNode: Tree node.
/// @param[in] program: A program object with a successfully built executable.
/// @param[in] num_kernels: The number of kernels in program.
/// @param[in] kernels: The buffer where the kernel objects for kernels in program will be returned.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateKernelsInProgram(
    CMDL_Node_t ppNode,
    cl_program program,
    cl_uint num_kernels,
    cl_kernel *kernels);

//------------------------------------------------------------------------------
/// @brief Increment the kernel reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] kernel: A kernel object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclRetainKernel(
    CMDL_Node_t ppNode,
    cl_kernel kernel);

//------------------------------------------------------------------------------
/// @brief Decrement the kernel reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] kernel: A kernel object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclReleaseKernel(
    CMDL_Node_t ppNode,
    cl_kernel kernel);

//------------------------------------------------------------------------------
/// @brief Set the argument value for a specific argument of a kernel.
/// @param[in] ppNode: Tree node.
/// @param[in] kernel: A kernel object.
/// @param[in] arg_index: The argument index.
/// @param[in] arg_size: The size of the argument value.
/// @param[in] arg_value: A pointer to data that should be used as the argument value for argument specified by arg_index.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclSetKernelArg(
    CMDL_Node_t ppNode,
    cl_kernel kernel,
    cl_uint arg_index,
    size_t arg_size,
    const void *arg_value);

//------------------------------------------------------------------------------
/// @brief Set a SVM pointer as the argument value for a specific argument of a kernel.
/// @param[in] ppNode: Tree node.
/// @param[in] kernel: A kernel object.
/// @param[in] arg_index: The argument index.
/// @param[in] arg_value: The SVM pointer that should be used as the argument value for argument specified by arg_index.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclSetKernelArgSVMPointer(
    CMDL_Node_t ppNode,
    cl_kernel kernel,
    cl_uint arg_index,
    const void *arg_value);

//------------------------------------------------------------------------------
/// @brief Pass additional information other than argument values to a kernel.
/// @param[in] ppNode: Tree node.
/// @param[in] kernel: A kernel object.
/// @param[in] param_name: The information to be passed to kernel.
/// @param[in] param_value_size: The size in bytes of the memory pointed to by param_value.
/// @param[in] param_value: A pointer to memory where the appropriate values determined by param_name.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclSetKernelExecInfo(
    CMDL_Node_t ppNode,
    cl_kernel kernel,
    cl_kernel_exec_info param_name,
    size_t param_value_size,
    const void *param_value);

//------------------------------------------------------------------------------
/// @brief Increment the event reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] event: An event object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclRetainEvent(
    CMDL_Node_t ppNode,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Decrement the event reference count.
/// @param[in] ppNode: Tree node.
/// @param[in] event: An event object.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclReleaseEvent(
    CMDL_Node_t ppNode,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Wait on the host thread for commands identified by event objects to complete.
/// @param[in] ppNode: Tree node.
/// @param[in] num_events: The number of events in event_list.
/// @param[in] event_list: The events specified in event_list act as synchronization points.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclWaitForEvents(
    CMDL_Node_t ppNode,
    cl_uint num_events,
    const cl_event *event_list);

//------------------------------------------------------------------------------
/// @brief Create a user event object.
/// @param[in] ppNode: Tree node.
/// @param[in] context: A context.
/// @param[in] user_event: An OpenCL user event object.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclCreateUserEvent(
    CMDL_Node_t ppNode,
    cl_context context,
    cl_event user_event);

//------------------------------------------------------------------------------
/// @brief Set the execution status of a user event object.
/// @param[in] ppNode: Tree node.
/// @param[in] event: A user event object.
/// @param[in] execution_status: The new execution status to be set and can be CL_COMPLETE or a negative integer value to indicate an error.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclSetUserEventStatus(
    CMDL_Node_t ppNode,
    cl_event event,
    cl_int execution_status);

//------------------------------------------------------------------------------
/// @brief Issue all previously queued OpenCL commands in a command-queue to the device associated with the command-queue.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclFlush(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue);

//------------------------------------------------------------------------------
/// @brief Block until all previously queued OpenCL commands in a command-queue are issued to the associated device and have completed.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclFinish(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to read from a buffer object to host memory.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] buffer: A buffer memory object.
/// @param[in] blocking_read: The read operations are blocking or non-blocking.
/// @param[in] offset: The offset in bytes in the buffer object to read from.
/// @param[in] size: The size in bytes of data being read.
/// @param[in] ptr: The pointer to buffer in host memory where data is to be read into.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueReadBuffer(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    size_t offset,
    size_t size,
    void *ptr,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to read from a 2D or 3D rectangular region from a buffer object to host memory.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] buffer: A buffer memory object.
/// @param[in] blocking_read: The read operations are blocking or non-blocking.
/// @param[in] buffer_origin: The (x, y, z) offset in the memory region associated with buffer.
/// @param[in] host_origin: The (x, y, z) offset in the memory region pointed to by ptr.
/// @param[in] region: The (width in bytes, height in rows, depth in slices) of the 2D or 3D rectangle being read or written.
/// @param[in] buffer_row_pitch: The length of each row in bytes to be used for the memory region associated with buffer.
/// @param[in] buffer_slice_pitch: The length of each 2D slice in bytes to be used for the memory region associated with buffer.
/// @param[in] host_row_pitch: The length of each row in bytes to be used for the memory region pointed to by ptr.
/// @param[in] host_slice_pitch: The length of each 2D slice in bytes to be used for the memory region pointed to by ptr.
/// @param[in] ptr: The pointer to buffer in host memory where data is to be read into.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueReadBufferRect(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    const size_t *buffer_origin,
    const size_t *host_origin,
    const size_t *region,
    size_t buffer_row_pitch,
    size_t buffer_slice_pitch,
    size_t host_row_pitch,
    size_t host_slice_pitch,
    void *ptr,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to write to a buffer object from host memory.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] buffer: A buffer memory object.
/// @param[in] blocking_write: The write operations are blocking or non-blocking.
/// @param[in] offset: The offset in bytes in the buffer object to write to.
/// @param[in] size: The size in bytes of data being written.
/// @param[in] ptr: The pointer to buffer in host memory where data is to be written from.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueWriteBuffer(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    size_t offset,
    size_t size,
    const void *ptr,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to write a 2D or 3D rectangular region to a buffer object from host memory.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] buffer: A buffer memory object.
/// @param[in] blocking_write: The write operations are blocking or non-blocking.
/// @param[in] buffer_origin: The (x, y, z) offset in the memory region associated with buffer.
/// @param[in] host_origin: The (x, y, z) offset in the memory region pointed to by ptr.
/// @param[in] region: The (width in bytes, height in rows, depth in slices) of the 2D or 3D rectangle being read or written.
/// @param[in] buffer_row_pitch: The length of each row in bytes to be used for the memory region associated with buffer.
/// @param[in] buffer_slice_pitch: The length of each 2D slice in bytes to be used for the memory region associated with buffer.
/// @param[in] host_row_pitch: The length of each row in bytes to be used for the memory region pointed to by ptr.
/// @param[in] host_slice_pitch: The length of each 2D slice in bytes to be used for the memory region pointed to by ptr.
/// @param[in] ptr: The pointer to buffer in host memory where data is to be written from.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueWriteBufferRect(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    const size_t *buffer_origin,
    const size_t *host_origin,
    const size_t *region,
    size_t buffer_row_pitch,
    size_t buffer_slice_pitch,
    size_t host_row_pitch,
    size_t host_slice_pitch,
    void *ptr,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to fill a buffer object with a pattern of a given pattern size.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] buffer: A buffer memory object.
/// @param[in] pattern: A pointer to the data pattern of size pattern_size in bytes.
/// @param[in] pattern_size: The size of the data pattern.
/// @param[in] offset: The location in bytes of the region being filled in buffer and must be a multiple of pattern_size.
/// @param[in] size: The size in bytes of region being filled in buffer and must be a multiple of pattern_size.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueFillBuffer(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem buffer,
    const void *pattern,
    size_t pattern_size,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to copy a buffer object to another buffer object.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] src_buffer: A buffer object from which to copy data.
/// @param[in] dst_buffer: A buffer object into which to copy data.
/// @param[in] src_offset: The offset where to begin copying data from src_buffer.
/// @param[in] dst_offset: The offset where to begin copying data into dst_buffer.
/// @param[in] size: The size in bytes to copy.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueCopyBuffer(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    size_t src_offset,
    size_t dst_offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to copy a rectangular region from a buffer object to another buffer object.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] src_buffer: A buffer object from which to copy data.
/// @param[in] dst_buffer: A buffer object into which to copy data.
/// @param[in] src_origin: The (x, y, z) offset in the memory region associated with src_buffer.
/// @param[in] dst_origin: The (x, y, z) offset in the memory region associated with dst_buffer.
/// @param[in] region: The (width, height, depth) in bytes of the 2D or 3D rectangle being copied.
/// @param[in] src_row_pitch: The length of each row in bytes to be used for the memory region associated with src_buffer.
/// @param[in] src_slice_pitch: The length of each 2D slice in bytes to be used for the memory region associated with src_buffer.
/// @param[in] dst_row_pitch: The length of each row in bytes to be used for the memory region associated with dst_buffer.
/// @param[in] dst_slice_pitch: The length of each 2D slice in bytes to be used for the memory region associated with dst_buffer.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueCopyBufferRect(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    const size_t *src_origin,
    const size_t *dst_origin,
    const size_t *region,
    size_t src_row_pitch,
    size_t src_slice_pitch,
    size_t dst_row_pitch,
    size_t dst_slice_pitch,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to read from a 2D or 3D image object to host memory.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] image: A 2D or 3D image object.
/// @param[in] blocking_read: The read operations are blocking or non-blocking.
/// @param[in] origin: The (x, y, z) offset in pixels in the image from where to read.
/// @param[in] region: The (width, height, depth) in pixels of the 2D or 3D rectangle being read.
/// @param[in] row_pitch: The length of each row in bytes.
/// @param[in] slice_pitch: The size in bytes of the 2D slice of the 3D region of a 3D image being read.
/// @param[in] ptr: The pointer to a buffer in host memory where image data is to be written to.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueReadImage(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_read,
    const size_t origin[3],
    const size_t region[3],
    size_t row_pitch,
    size_t slice_pitch,
    void *ptr,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to write from a 2D or 3D image object to host memory.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] image: A 2D or 3D image object.
/// @param[in] blocking_write: The write operations are blocking or non-blocking.
/// @param[in] origin: The (x, y, z) offset in pixels in the image from where to write.
/// @param[in] region: The (width, height, depth) in pixels of the 2D or 3D rectangle being written.
/// @param[in] input_row_pitch: The length of each row in bytes.
/// @param[in] input_slice_pitch: The size in bytes of the 2D slice of the 3D region of a 3D image being written.
/// @param[in] ptr: The pointer to a buffer in host memory where image data is to be read from.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueWriteImage(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_write,
    const size_t origin[3],
    const size_t region[3],
    size_t input_row_pitch,
    size_t input_slice_pitch,
    const void *ptr,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to fill an image object with a specified color.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] image: An image memory object.
/// @param[in] fill_color: The fill color converted to the appropriate image channel format and order associated with image.
/// @param[in] origin: The (x, y, z) offset in pixels in the 1D, 2D, or 3D image.
/// @param[in] region: The (width, height, depth) in pixels of the 1D, 2D or 3D rectangle.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueFillImage(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem image,
    const void *fill_color,
    const size_t *origin,
    const size_t *region,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to copy image objects.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] src_image: An image object from which to copy data.
/// @param[in] dst_image: An image object into which to copy data.
/// @param[in] src_origin: The starting (x, y, z) location in pixels in src_image from where to start the data copy.
/// @param[in] dst_origin: The starting (x, y, z) location in pixels in dst_image from where to start the data copy.
/// @param[in] region: The (width, height, depth) in pixels of the 2D or 3D rectangle to copy.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueCopyImage(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_image,
    const size_t src_origin[3],
    const size_t dst_origin[3],
    const size_t region[3],
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to copy a buffer object to an image object.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] src_buffer: A buffer memory object.
/// @param[in] dst_image: An image memory object.
/// @param[in] src_offset: The offset where to begin copying data from src_buffer.
/// @param[in] dst_origin: The (x, y, z) offset in pixels where to begin copying data to dst_image.
/// @param[in] region: The (width, height, depth) in pixels of the 2D or 3D rectangle to copy.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueCopyBufferToImage(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_image,
    size_t src_offset,
    const size_t dst_origin[3],
    const size_t region[3],
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to copy an image object to a buffer object.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] src_image: An image memory object.
/// @param[in] dst_buffer: A buffer memory object.
/// @param[in] src_origin: The (x, y, z) offset in pixels in the image from where to copy.
/// @param[in] region: The (width, height, depth) in pixels of the 2D or 3D rectangle to copy.
/// @param[in] dst_offset: The offset where to begin copying data into dst_buffer.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueCopyImageToBuffer(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_buffer,
    const size_t src_origin[3],
    const size_t region[3],
    size_t dst_offset,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to map a region of the buffer object given by buffer into the host address space and returns a pointer to this mapped region.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] buffer: A buffer memory object.
/// @param[in] blocking_map: The map operation is blocking or non-blocking.
/// @param[in] map_flags: A bit-field used to indicate the region specified by (offset, size) in the buffer object is being mapped for reading or writing.
/// @param[in] offset: The offset in bytes in the buffer object that is being mapped.
/// @param[in] size: The size of the region in the buffer object that is being mapped.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @param[in] mapped_ptr: A pointer to the mapped region.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueMapBuffer(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_map,
    cl_map_flags map_flags,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event,
    void* mapped_ptr);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to map a region of an image object into the host address space and returns a pointer to this mapped region.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] image: An image memory object.
/// @param[in] blocking_map: The map operation is blocking or non-blocking.
/// @param[in] map_flags: A bit-field used to indicate the region specified by (origin, region) in the image object is being mapped for reading or writing.
/// @param[in] origin: The (x, y, z) offset in pixels of the 2D or 3D rectangle region that is to be mapped.
/// @param[in] region: The (width, height, depth) in pixels of the 2D or 3D rectangle region that is to be mapped.
/// @param[in] image_row_pitch: The scan-line pitch in bytes for the mapped region.
/// @param[in] image_slice_pitch: The size in bytes of each 2D slice for the mapped region.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @param[in] mapped_ptr: A pointer to the mapped region.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueMapImage(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_map,
    cl_map_flags map_flags,
    const size_t origin[3],
    const size_t region[3],
    size_t image_row_pitch,
    size_t image_slice_pitch,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event,
    void* mapped_ptr);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to unmap a previously mapped region of a memory object.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] memobj: A memory object.
/// @param[in] mapped_ptr: The host address returned by a previous call to clEnqueueMapBuffer or clEnqueueMapImage for memobj.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueUnmapMemObject(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_mem memobj,
    void *mapped_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to indicate which device a set of memory objects should be associated with.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] num_mem_objects: The number of memory objects specified in mem_objects.
/// @param[in] mem_objects: A pointer to a list of memory objects.
/// @param[in] flags: A bit-field that is used to specify migration options.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueMigrateMemObjects(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_uint num_mem_objects,
    const cl_mem *mem_objects,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to execute a kernel on a device.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] kernel: A kernel object.
/// @param[in] work_dim: The number of dimensions used to specify the global work-items and work-items in the work-group.
/// @param[in] global_work_offset: Must currently be a NULL value.
/// @param[in] global_work_size: Points to an array of work_dim unsigned values that describe the number of global work-items in work_dim dimensions that will execute the kernel function.
/// @param[in] local_work_size: Points to an array of work_dim unsigned values that describe the number of work-items that make up a work-group (also referred to as the size of the work-group) that will execute the kernel specified by kernel.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueNDRangeKernel(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint work_dim,
    const size_t *global_work_offset,
    const size_t *global_work_size,
    const size_t *local_work_size,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to execute a kernel on a device.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] kernel: A kernel object.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueTask(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a marker command.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] event: An event returned by the marker command.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueMarker(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a marker command which waits for either a list of events to complete, or all previously enqueued commands to complete.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueMarkerWithWaitList(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a barrier operation as a synchronization point.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueBarrier(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue);

//------------------------------------------------------------------------------
/// @brief Enqueue a barrier operation as a synchronization point.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueBarrierWithWaitList(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a wait for a specific event or a list of events to complete before any future commands queued in the command-queue are executed.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] num_events: The number of events in event_list.
/// @param[in] event_list: The events specified in event_list act as synchronization points.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueWaitForEvents(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_uint num_events,
    const cl_event *event_list);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to free the SVM allocated using clSVMAlloc or a shared system memory pointer.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] num_svm_pointers: The number of svm pointers in svm_pointers.
/// @param[in] svm_pointers: The svm pointers to be freed.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueSVMFree(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    void *svm_pointers[],
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to fill a region in memory with a pattern of a given pattern size.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] svm_ptr: A svm pointer to a memory region that will be filled with pattern.
/// @param[in] pattern: A pointer to the data pattern of size pattern_size in bytes.
/// @param[in] pattern_size: The size of the data pattern.
/// @param[in] size: The size in bytes of region being filled starting with svm_ptr and must be a multiple of pattern_size.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueSVMMemFill(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    void *svm_ptr,
    const void *pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to do a memcpy operation.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] blocking_copy: The copy operation is blocking or non-blocking.
/// @param[in] dst_ptr: A svm pointer to a memory region where data is copied to.
/// @param[in] src_ptr: A svm pointer to a memory region where data is copied from.
/// @param[in] size: The size in bytes of data being copied.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK_NO_IMPLEMENTATION: No implementation for recording.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueSVMMemcpy(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_bool blocking_copy,
    void *dst_ptr,
    const void *src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command that will allow the host to update a region of a SVM buffer.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] blocking_map: The map operation is blocking or non-blocking.
/// @param[in] flags: A bit-field used to specify that the region being mapped in the memory object is being mapped for reading or writing.
/// @param[in] svm_ptr: A svm pointer to a memory region.
/// @param[in] size: The size in bytes.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueSVMMap(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    cl_bool blocking_map,
    cl_map_flags flags,
    void *svm_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);

//------------------------------------------------------------------------------
/// @brief Enqueue a command to indicate that the host has completed updating the region given by svm_ptr and which was specified in a previous call to clEnqueueSVMMap.
/// @param[in] ppNode: Tree node.
/// @param[in] command_queue: A command-queue.
/// @param[in] svm_ptr: A svm pointer.
/// @param[in] num_events_in_wait_list: The number of events in event_wait_list.
/// @param[in] event_wait_list: The events that need to complete before this command can be executed.
/// @param[in] event: An event object used to query the status or queue a wait for this command to complete.
/// @return CMDL_OK: Process success.
/// @return CMDL_ERR_INVALID_PARAMS: Parameters are invalid.
/// @return CMDL_ERR_OUT_OF_MEMORY: Out of memory.
//------------------------------------------------------------------------------
CMDL_RESULT CmdL_AttachclEnqueueSVMUnmap(
    CMDL_Node_t ppNode,
    cl_command_queue command_queue,
    void *svm_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event event);


#ifdef __cplusplus
}
#endif