/***************************************************************************************
File name: __lfp_arch_abstract.h
Description: System adaptation layer. Abstract different underlying implementations.
Author: wytaitaislee
Version: V1.0.0
Date: 2020-03-12
History: 1. create file. -- 2020-03-12
****************************************************************************************/
#ifndef __LFP_ARCH_ABSTRACT_H__
#define __LFP_ARCH_ABSTRACT_H__

#define ARCH_NAME LFP_
#define __OS_NAME_UPPER LINUX_
#define __OS_NAME_LOWER linux_
#include "lfp_base.h"
/* X86, 32. */
#if defined (linux) || defined(unix) || defined(__unix__) || defined(__linux__)
#include "linux/linux.h"
/* win32, wins64 */
#elif defined(__WIN32__) || defined(__WIN64__)
#include "windows/windows.h"
#else
/*someother platforms */
#endif

/* os arch typesdef to lfp arch typesdef adapter macros definition */
#define __DEFINE_ARCH_TYPESDEF_ADAPTER(os, arch, item) typedef os##item arch##item
#define __DEFINE_ARCH_TYPESDEF_ADAPTER_CONVERT(os, arch, item)  __DEFINE_ARCH_TYPESDEF_ADAPTER(os, arch, item) 
#define DEFINE_ARCH_TYPESDEF_ADAPTER(BASE_NAME) __DEFINE_ARCH_TYPESDEF_ADAPTER_CONVERT(__OS_NAME_UPPER, ARCH_NAME, BASE_NAME)

/* os arch MACROS to lfp arch MACROS adapter macros definition */
#define __DEFINE_ARCH_MACROS_ADAPTER(os, arch, item) arch##item os##item
#define DEFINE_ARCH_MACROS_ADAPTER(BASE_NAME) __DEFINE_ARCH_MACROS_ADAPTER(__OS_NAME_UPPER, ARCH_NAME, BASE_NAME)

/* os arch function to lfp arch function adapter macros definition */
#define __DEFINE_ARCH_ADAPTER(osname, basename)    (osname##basename)
#define DEFINE_ARCH_ADAPTER(BASE_FUNC_NAME)    __DEFINE_ARCH_ADAPTER(__OS_NAME_LOWER, BASE_FUNC_NAME)

/* socket relevant typesdef */
DEFINE_ARCH_TYPESDEF_ADAPTER(SOCK_ADDR_T);
DEFINE_ARCH_TYPESDEF_ADAPTER(SOCK_ADDRIN_T);
DEFINE_ARCH_TYPESDEF_ADAPTER(SOCKLEN_T);
DEFINE_ARCH_TYPESDEF_ADAPTER(MSGHDR_T);
DEFINE_ARCH_TYPESDEF_ADAPTER(SOCK);
#define DEFINE_ARCH_MACROS_ADAPTER(AF_INET)
#define DEFINE_ARCH_MACROS_ADAPTER(SOCK_STREAM)
#define DEFINE_ARCH_MACROS_ADAPTER(IPPROTO_TCP)

/* mutex relevant typesdef */
DEFINE_ARCH_TYPESDEF_ADAPTER(MUTEX_T);
DEFINE_ARCH_TYPESDEF_ADAPTER(MUTEX_ATTR_T);

/* pthread relevant typesdef */
DEFINE_ARCH_TYPESDEF_ADAPTER(PTHREAD_HADLE_T);
DEFINE_ARCH_TYPESDEF_ADAPTER(PTHREAD_ATTR_T);
//DEFINE_ARCH_MACROS_CONVERT(ESRCH)

/* semaphore relevant typesdef */
DEFINE_ARCH_TYPESDEF_ADAPTER(SEM_T);

/* comm datatypes typesdef */
DEFINE_ARCH_TYPESDEF_ADAPTER(OFF_T);
DEFINE_ARCH_TYPESDEF_ADAPTER(SIZE_T);
DEFINE_ARCH_TYPESDEF_ADAPTER(SSIZE_T);
DEFINE_ARCH_TYPESDEF_ADAPTER(FILE);

/* Thread function cluster */
typedef struct lfp_arch_adapter_pthread_t
{
    /* data */
    LFP_INT32 (*pthread_create)(LFP_PTHREAD_HADLE_T *pThreadHandle, LFP_INT32 iPrority, LFP_UINT32 uiStackSize, LFP_VOID* pStartTask, LFP_VOID* pParams);
    LFP_INT32 (*pthread_cancel)(LFP_PTHREAD_HADLE_T hThreadHandle);
    LFP_INT32 (*pthread_kill)(LFP_PTHREAD_HADLE_T hThreadHandle, LFP_INT32 iSig);
}LFP_ARCH_ADAPTER_PTHREAD_T;

/* Mutex function cluster */
typedef struct lfp_arch_adapter_mutex_t
{
    LFP_INT32 (*mutex_create)(LFP_MUTEX_T* mutex, LFP_MUTEX_ATTR_T* pAttr);
    LFP_INT32 (*mutex_lock)(LFP_MUTEX_T* mutex);
    LFP_INT32 (*mutex_unlock)(LFP_MUTEX_T* mutex);
    LFP_INT32 (*mutex_destroy)(LFP_MUTEX_T* mutex);
}LFP_ARCH_ADAPTER_MUTEX_T;

/* Semaphore function cluster */
typedef struct lfp_arch_adapter_semaphore_t
{
    LFP_INT32 (*semaphore_init)(LFP_SEM_T* sem, LFP_INT32 iShared, LFP_UINT32 uiInitVal);
    LFP_INT32 (*semaphore_wait)(LFP_SEM_T* sem, LFP_INT32 iWaitTime);
    LFP_INT32 (*semaphore_post)(LFP_SEM_T* sem);
    LFP_INT32 (*semaphore_destroy)(LFP_SEM_T* sem);
}LFP_ARCH_ADAPTER_SEMAPHORE_T;

/* Lock function cluster */
typedef struct lfp_arch_adapter_lock_t
{
    LFP_INT32 (*lock_create)();
    LFP_INT32 (*lock)();
    LFP_INT32 (*unlock)();
}LFP_ARCH_ADAPTER_LOCK_T;

/* file io function cluster */
typedef struct lfp_arch_adapter_fileio_t
{
    LFP_INT32 (*fileio_open)(LFP_CONST LFP_INT8* pPath, LFP_INT32 iFlags, LFP_INT32 iMode);
    LFP_OFF_T (*fileio_seek)(LFP_INT32 iFd, LFP_OFF_T iOffset, LFP_INT32 iWhence);
	LFP_INT32 (*fileio_fcntl)(LFP_INT32 iFd, LFP_INT32 iStyle);
	LFP_INT32 (*fileio_read)(LFP_INT32 iFd, LFP_VOID* pBuf, LFP_SIZE_T bytes);
    LFP_INT32 (*fileio_write)(LFP_INT32 iFd, LFP_CONST LFP_VOID* pBuf, LFP_SIZE_T bytes);
	LFP_INT32 (*fileio_close)(LFP_INT32 iFd);
}LFP_ARCH_ADAPTER_FILEIO_T;

/* standard io function cluster */
typedef struct lfp_arch_adapter_stdio_t
{
	LFP_FILE *(*stdio_open)(LFP_CONST LFP_INT8 *LFP_RESTRICT pPath, LFP_CONST LFP_INT8 *LFP_RESTRICT pMode);
	LFP_INT32 (*stdio_seek)(LFP_FILE* pFp, LFP_LONG iOffset, LFP_INT32 iWhence);
	LFP_SIZE_T (*stdio_read)(LFP_VOID *LFP_RESTRICT pBuf, LFP_SIZE_T size, LFP_SIZE_T nobjs, LFP_FILE *LFP_RESTRICT pFp);
	LFP_SIZE_T (*stdio_write)(LFP_CONST LFP_VOID *LFP_RESTRICT pBuf, LFP_SIZE_T size, LFP_SIZE_T nobjs, LFP_FILE *LFP_RESTRICT pFp);
	LFP_INT32 (*stdio_close)(LFP_FILE* pFp);
}LFP_ARCH_ADAPTER_STDIO_T;

typedef struct lfp_arch_adapter_socket_t
{
    LFP_INT32 (*socket_create)(LFP_INT32, LFP_INT32, LFP_INT32);
    LFP_INT32 (*socket_bind)(LFP_INT32, LFP_CONST LFP_SOCK_ADDR_T*, LFP_SOCKLEN_T);
    LFP_INT32 (*socket_listen)(LFP_INT32, LFP_INT32);
    LFP_INT32 (*socket_accept)(LFP_INT32, LFP_SOCK_ADDR_T*, LFP_SOCKLEN_T*);
    LFP_INT32 (*socket_connect)(LFP_INT32, LFP_CONST LFP_SOCK_ADDR_T*, LFP_SOCKLEN_T);
    LFP_INT32 (*socket_close)(LFP_INT32);
    LFP_SSIZE_T (*socket_write)(LFP_INT32, LFP_CONST LFP_VOID*, LFP_SIZE_T);
    LFP_INT32 (*socket_fcntl)(LFP_INT32, LFP_INT32);
    LFP_SSIZE_T (*socket_send)(LFP_INT32, LFP_CONST LFP_VOID*, LFP_SIZE_T, LFP_INT32);
    LFP_SSIZE_T (*socket_sendto)(LFP_INT32, LFP_CONST LFP_VOID*, LFP_SIZE_T, LFP_INT32, LFP_CONST LFP_SOCK_ADDR_T*, LFP_SOCKLEN_T);
    LFP_SSIZE_T (*socket_sendmsg)(LFP_INT32, LFP_CONST LFP_MSGHDR_T*, LFP_INT32);
    LFP_SSIZE_T (*socket_read)(LFP_INT32, LFP_VOID*, LFP_SIZE_T);
    LFP_SSIZE_T (*socket_recv)(LFP_INT32, LFP_VOID*, LFP_SIZE_T, LFP_INT32);
    LFP_SSIZE_T (*socket_recvfrom)(LFP_INT32, LFP_VOID*, LFP_SIZE_T, LFP_INT32, LFP_SOCK_ADDR_T*, LFP_SOCKLEN_T*);
    LFP_SSIZE_T (*socket_recvmsg)(LFP_INT32, LFP_MSGHDR_T*, LFP_INT32);
}LFP_ARCH_ADAPTER_SOCKET_T;

/* The abstruct of the os function cluster */
typedef struct lfp_arch_adapter_os_t
{
    /* data */
    LFP_ARCH_ADAPTER_PTHREAD_T      struArchAdapterPthread;
    LFP_ARCH_ADAPTER_MUTEX_T        struArchAdapterMutex;
    LFP_ARCH_ADAPTER_SEMAPHORE_T    struArchAdapterSem;
    LFP_ARCH_ADAPTER_LOCK_T         struArchAdapterLock;
	LFP_ARCH_ADAPTER_FILEIO_T		struArchAdapterFileio;
	LFP_ARCH_ADAPTER_STDIO_T		struArchAdapterStdio;
    LFP_ARCH_ADAPTER_SOCKET_T       struArchAdapterSocket;
}LFP_ARCH_ADAPTER_OS_T;

#endif /*end of __LFP_ARCH_ABSTRACT_H__ */
