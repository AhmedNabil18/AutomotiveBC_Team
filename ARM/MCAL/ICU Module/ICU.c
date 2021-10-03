/*****************************************************************************
* Module: SW_ICU Module
* File Name: ICU_Cfg.c
* Description: Source file for SW_ICU Module
* Author: Shady Mamdouh
* Date: 8/12/2021
******************************************************************************/

/**************************INCLUDES***************************************/
#include "ICU.h"
#include "..\Interrupt Driver\ISR.h"
#include "OS.h"

/************************************************************************/
/**********************States types************************************/
#define ICU_STOPPED				0
#define ICU_RISING			    1
#define ICU_FALLING			    2
#define ICU_RETURN_READY	    3
/***********************************************************************/

/**************************Global variables*******************************/
static uint8_t ICU_state[ICU_USED_CHANNELS] = {ICU_STOPPED} ;
static uint32_t ICU_Counts[ICU_USED_CHANNELS] = {0};

volatile  uint32_t RisingCurrentTime[ICU_USED_CHANNELS] ;
volatile  uint32_t FallingCurrentTime[ICU_USED_CHANNELS] ;
/*********************************************************************/
static void ICU_CH0CallBackFunction(void)
{
	
	if (ICU_state[ICU_CHANNEL_0] == ICU_RISING)
	{
		/* start  counter */


	    /*Get current system ticks */
	    OS_getCurrentSysTick(&RisingCurrentTime[ICU_CHANNEL_0]);

		/* ICU_state[ICU_0] function state */
		ICU_state[ICU_CHANNEL_0] =ICU_FALLING;
		
		
		/* Reverse the external interrupt polarity */

		ExtINT_Enable(EXT_INT_CHANNEL_0,FALLING_EDGE);
	}
	else if (ICU_state[ICU_CHANNEL_0]==ICU_FALLING)
	{
		
		/* Get the counter value */
		
	    OS_getCurrentSysTick(&FallingCurrentTime[ICU_CHANNEL_0]);

	    ICU_Counts[ICU_CHANNEL_0]=FallingCurrentTime[ICU_CHANNEL_0]-RisingCurrentTime[ICU_CHANNEL_0];

		/* Update function state */
		ICU_state[ICU_CHANNEL_0] = ICU_RETURN_READY;
		
		/* disable interrupt */

		ExtINT_Disable(EXT_INT_CHANNEL_0);

	}
}
Std_ReturnType ICU_Init(void)
{
	GptInit();
	uint8_t loopCounter_u8 = 0;
	for (loopCounter_u8=0; loopCounter_u8<ICU_USED_CHANNELS; loopCounter_u8++)
	{
		/* update function state */
		ICU_state[loopCounter_u8] =ICU_RISING;
		switch(ICU_Configurations[loopCounter_u8].Ext_InterruptChannel)
		{
			case EXT_INT0:
				//setExtINT0Callback(ICU_CH0CallBackFunction);
				//EnableExternalInterrupts_INT0(RISING_EDGE);
			    ExtINT_setCallback(EXT_INT_CHANNEL_0,ICU_CH0CallBackFunction);
			    ExtINT_Enable(EXT_INT_CHANNEL_0,RISING_EDGE);
				break;
			case EXT_INT1:
// 				setExtINT1Callback(ICU_CH1CallBackFunction);
// 				EnableExternalInterrupts_INT1(RISING_EDGE);
				break;
			case EXT_INT2:
		//		setExtINT2Callback(ICU_CH0CallBackFunction);
			//	EnableExternalInterrupts_INT2(RISING_EDGE);
				break;
			default:
				return E_NOT_OK;
		}
	}
	return E_OK;
}

Std_ReturnType ICU_GetONPeriod_Counts(ICU_channel_t ChannelId_u8 , ICU_Counts_t *Counts_pu32)
{
	/************** Error Handling **********************/
	if(ChannelId_u8 >= ICU_USED_CHANNELS)
	{
		return E_NOT_OK;
	}
	if (Counts_pu32 == NULL_PTR)  //NULL pointer
	{
		return E_NOT_OK;
	}
	/***************************************************/

	if (ICU_state[ChannelId_u8]==ICU_RETURN_READY)
	{
		*Counts_pu32 = ICU_Counts[ChannelId_u8];
				
		ICU_state[ChannelId_u8] =ICU_RISING;
		/* set call back function */
		//setExtINT2Callback(ICU_CH0CallBackFunction);
		ExtINT_setCallback(EXT_INT_CHANNEL_0,ICU_CH0CallBackFunction);
		/* Enable interrupt */
		//EnableExternalInterrupts_INT2(RISING_EDGE);
		ExtINT_Enable(EXT_INT_CHANNEL_0,RISING_EDGE);



		return E_OK;
	}
	
	return E_NOT_OK;
}





