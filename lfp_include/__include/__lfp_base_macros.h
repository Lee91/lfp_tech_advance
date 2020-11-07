/***************************************************************************************
File name: __lfp_base_macros.h																	
Description: define the basic macro function structure(macros define).									
Author: wytaitaislee																	
Version: V1.0.0																			
Date: 2020-09-26																		
History: 1. create file. -- 2020.09.26
		 2. add the `assert` scenes -- 2020.11.06
****************************************************************************************/

#ifndef __LFP_BASE_MACROS_H__
#define __LFP_BASE_MACROS_H__

#include <assert.h>
#include <stdio.h>

#define LFP_MAX(x, y) 				((x > y) ? (x) : (y))
#define LFP_MIN(x, y) 				((x > y) ? (y) : (x))
#define LFP_BUFF_BEZERO(pStr, len) 	(memset(pStr , 0, len))
#define LFP_NELEMENTS(x)			(sizeof(x) / sizeof(*x))
#define LFP_MALLOC(size)			(malloc(size))

/* basic assert output format */
#define __LFP_ASSERT_FORMAT(c)														\
do																					\
{																					\
	printf("[%s][warn][%s][%s][%d] %s ,condition err!!\n", 							\
			__TIME__, __FILE__, __func__, __LINE__, #c);							\	
} while (0);

/* assert */
#define LFP_ASSERT( c )																\
do																					\
{																					\
	if( !(c) ){__LFP_ASSERT_FORMAT( c ); assert( c );}								\																			\
}while(0);

/* assert return NULL */
#define LFP_ASSERT_NULL_RET( c )													\
do																					\
{																					\
	if( !(c) ){__LFP_ASSERT_FORMAT( c ); return LFP_NULL;}							\ 																				\
}while(0);

/* assert return error */	
#define LFP_ASSERT_ERR_RET( c )														\
do																					\
{																					\
	if( !(c) ){__LFP_ASSERT_FORMAT( c ); return LFP_ERR;}							\																				\
}while(0);

/* assert return ok */
#define LFP_ASSERT_OK_RET( c )														\
do																					\
{																					\
	if( !(c) ){__LFP_ASSERT_FORMAT( c ); return LFP_OK;}							\	
}while(0);
	
/* assert safe free memory */
#define LFP_SAFE_FREE( p )															\
do																					\
{																					\
	if( p ) { free( p ); p = ( LFP_VOID* )LFP_NULL;}								\
}while(0);
	
/* assert safe close file */
#define LFP_SAFE_CLOSE( p )															\
do																					\
{																					\
	if( p ) { fclose( p ); p = ( LFP_VOID* )LFP_NULL;}								\
}while(0);

/* assert safe close socket connection */
#define LFP_SAFE_CLOSE_SOCKET( p )													\
do																					\
{																					\
	if( p ) { close( p ); p = ( LFP_VOID* )LFP_NULL;}								\
}while(0);

/* modules register sign. */
#define LFP_MODULES_REGISTER_SIGN(util, sign)										\
do 																					\
{																					\
	util("module %s !\n", sign);													\
}while(0);

#endif /* end of __LFP_BASE_MACROS_H__ */