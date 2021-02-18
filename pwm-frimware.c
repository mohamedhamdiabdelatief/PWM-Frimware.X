/*
* File: PWM - DC Motor Speed Control
* Author: Mohamed Hamdi
* please visit my youtube channel:https://www.youtube.com/channel/UCzt_0MFbJiT93KSR74pW6Jw
*
*/
#include <xc.h>
#include <stdint.h>
#include "config.h"
#define _XTAL_FREQ 4000000
//================================
//--[ Function Declarations ]--
void PWM1_Set_Duty(uint16_t);
void main(void)
{
  //--[ Configure The CCP Module For PWM Mode ]--
  CCP1M3 = 1;
  CCP1M2 = 1;
  TRISC2 = 0; // The CCP1 Output Pin (PWM)
  // Set The PWM Frequency (2kHz)
  PR2 = 124;
  // Set The PS For Timer2 (1:4 Ratio)
  T2CKPS0 = 1;
  T2CKPS1 = 0;
  // Start CCP1 PWM !
  TMR2ON = 1;
  // The Main Loop (Routine)
  while(1)
  {
  //DO What you want
  }
  return;
}
// Definition For PWM1_Set_Duty Function
void PWM1_Set_Duty(uint16_t DC)
{
  // Check The DC Value To Make Sure it's Within 10-Bit Range
  if(DC<1024)
  {
    CCP1Y = DC & 1;
    CCP1X = DC & 2;
    CCPR1L = DC >> 2;
  }
}