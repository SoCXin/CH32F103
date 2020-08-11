/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2019/10/15
* Description        : Main program body.
*******************************************************************************/ 
#include "debug.h"
#include "usb_lib.h"
#include "hw_config.h"
#include "usb_pwr.h"

/* Global define */


/* Global Variable */    


/*******************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Return         : None
*******************************************************************************/
int main(void)
{   
	u8 usbstatus=0;	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Delay_Init(); 
	USART_Printf_Init(115200); 
	printf("SystemClk:%d\r\n",SystemCoreClock);
	 
	printf("USBD Device Test\r\n");
	Set_USBConfig(); 
    USB_Init();	    
   
	USB_Port_Set(DISABLE, DISABLE);	
	Delay_Ms(700);
	USB_Port_Set(ENABLE, ENABLE);
 	USB_Interrupts_Config();    
 	
    
	while(1)
	{
		if(usbstatus!=bDeviceState)
		{
			usbstatus=bDeviceState;
			
			if(usbstatus==CONFIGURED)
			{
				printf("USB Connected\r\n");
			}else
			{
				printf("USB disConnected\r\n");				
			}
		}
	}
}







