/**Done**/
#ifndef I2C_CFG_H_
#define I2C_CFG_H_


#include "I2C.h"

/*Variables*/
#define Clk 100000                         /*I2C Clock Rate*/
#define I2Cs_NUM 1u                        /*Number of I2Cs you need*/

const I2C_Mod I2CMOD_Data[I2CS_NUMBER]=
{
  {(1)/*Port B ID*/,(3)/*SDA Pin*/,(2)/*SCK Pin*/,Clk,1/*Enable This I2C*/} /*****I2C 0*****/
 ,{(0)/*Port A ID*/,(7)/*SDA Pin*/,(6)/*SCK Pin*/,Clk,0/*Enable This I2C*/} /*****I2C 1*****/
 ,{(4)/*Port E ID*/,(5)/*SDA Pin*/,(4)/*SCK Pin*/,Clk,0/*Enable This I2C*/} /*****I2C 2*****/
 ,{(3)/*Port D ID*/,(1)/*SDA Pin*/,(0)/*SCK Pin*/,Clk,0/*Enable This I2C*/} /*****I2C 3*****/
};



#endif /* I2C_CFG_H_ */
