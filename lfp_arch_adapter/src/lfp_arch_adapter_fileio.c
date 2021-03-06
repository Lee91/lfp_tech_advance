/*
 * @fileName: lfp_arch_adapter_fileio.h
 * @Description: System adaptation layer. Adapter to different fileio on different OS.
 * @Author: wytaitaislee
 * @Date: 2020-08-16 16:05:58
 * @LastEditors: wytaitaislee
 * @LastEditTime: 2021-04-04 16:02:11
*/
#include "lfp_arch_adapter_typesdef.h"
#include "lfp_arch_abstract.h"
#include "lfp_arch_adapter.h"

#define LFP_GET_FILEIO_ENTRY()             (*(LFP_ARCH_ADAPTER_FILEIO_T*)LFP_GET_CLASS_ENTRY(fileio))
#define LFP_ADAPTER_FILEIO_INIT(FUNC)      LFP_ADAPTER_INIT(LFP_GET_FILEIO_ENTRY(), FUNC)

/* the definition of file io cluster */
LFP_ARCH_ADAPTER3(LFP_GET_FILEIO_ENTRY(), fileio_open, LFP_INT32, LFP_CONST LFP_INT8*, LFP_INT32, LFP_INT32);
LFP_ARCH_ADAPTER3(LFP_GET_FILEIO_ENTRY(), fileio_seek, LFP_OFF_T, LFP_INT32, LFP_OFF_T, LFP_INT32);
LFP_ARCH_ADAPTER2(LFP_GET_FILEIO_ENTRY(), fileio_fcntl, LFP_INT32, LFP_INT32, LFP_INT32);
LFP_ARCH_ADAPTER3(LFP_GET_FILEIO_ENTRY(), fileio_read, LFP_INT32, LFP_INT32, LFP_VOID*, LFP_SIZE_T);
LFP_ARCH_ADAPTER3(LFP_GET_FILEIO_ENTRY(), fileio_write, LFP_INT32, LFP_INT32, LFP_CONST LFP_VOID*, LFP_SIZE_T);
LFP_ARCH_ADAPTER1(LFP_GET_FILEIO_ENTRY(), fileio_close, LFP_INT32, LFP_INT32);

/*@fn		  LFP_INT32 lfp_arch_adapter_fileio_register(LFP_VOID)
* @brief 	  the adapter layer register -- fileio cluster register
* @param[in]  LFP_NULL
* @param[out] LFP_NULL
* @return	  LFP_OK
*/
LFP_INT32 lfp_arch_adapter_fileio_register(LFP_VOID)
{
//    LFP_ADAPTER_FILEIO_INIT(fileio_open);
//    LFP_ADAPTER_FILEIO_INIT(fileio_seek);
    LFP_ADAPTER_FILEIO_INIT(fileio_fcntl);

//    LFP_ADAPTER_FILEIO_INIT(fileio_read);
//    LFP_ADAPTER_FILEIO_INIT(fileio_write);
//    LFP_ADAPTER_FILEIO_INIT(fileio_close);
    return LFP_OK;
}

