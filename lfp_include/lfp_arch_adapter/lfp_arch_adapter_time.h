/***************************************************************************************
File name: lfp_arch_adapter_time.h
Description: System adaptation layer, matching different arch.
Author: wytaitaislee
Date: 2021-01-31
History: 1. create file. -- 2021-01-31
****************************************************************************************/

#ifndef __LFP_ARCH_ADAPTER_TIME_H__
#define __LFP_ARCH_ADAPTER_TIME_H__

#include "lfp_base.h"

/*@fn		  LFP_INT32 lfp_sleep_ms(LFP_UINT32 uiSleepMsSeconds);
* @brief 	  delay milliseconds
* @param[in]  LFP_UINT32 uiSleepMsSeconds - ms counts
* @param[out] LFP_NULL
* @return	  LFP_OK / LFP_ERR
*/	
LFP_INT32 lfp_sleep_ms(LFP_UINT32 uiSleepMsSeconds);

/*@fn		  LFP_INT32 lfp_sleep_s(LFP_UINT32 uiSleepSeconds);
* @brief 	  delay seconds
* @param[in]  LFP_UINT32 uiSleepSeconds - seconds counts
* @param[out] LFP_NULL
* @return	  LFP_OK / LFP_ERR
*/
LFP_INT32 lfp_sleep_s(LFP_UINT32 uiSleepSeconds);

/*@fn		  LFP_INT32 lfp_arch_adapter_time_register(LFP_VOID)
* @brief 	  the adapter layer register -- time cluster register
* @param[in]  LFP_NULL
* @param[out] LFP_NULL
* @return	  LFP_OK
*/
LFP_INT32 lfp_arch_adapter_time_register(LFP_VOID);
#endif	/*end of __LFP_ARCH_ADAPTER_TIME_H__ */