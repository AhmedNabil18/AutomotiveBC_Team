
#ifndef I2C_H_
#define I2C_H_
#include <stdint.h>


/*Constants*/
#define PORTS_NUMBER 6u                    /*Total Number of PORTs*/
#define I2CS_NUMBER  4u                     /*Total Number of I2Cs*/
#define I2C_PCTL_VAL 3u                    /*Alternate Function Value of the I2C*/

typedef struct
{
    uint8_t PortID;
    uint8_t SDA_Pin;
    uint8_t SCK_Pin;
    uint32_t Clock;
    uint8_t Enable;
}I2C_Mod;

void I2C_Init(void);
uint8_t I2C_Send(uint8_t I2CID, uint8_t Slave_address, uint8_t* Data);
uint8_t I2C_Single_Send(uint8_t I2CID, uint8_t Slave_address, uint8_t Data);
uint8_t I2C_Send_To_Memory(uint8_t I2CID, uint8_t Slave_address, uint8_t Memory_Loc, uint8_t* Data);
uint8_t BQI2C_Send_To_Memory(uint8_t I2CID, uint8_t Slave_address, uint8_t Memory_Loc, uint8_t Data);
/*****/
uint8_t I2C_Receive(uint8_t I2CID, uint8_t Slave_address, uint8_t Datacount, uint8_t* Data);
uint8_t I2C_Receive_from_Memory(uint8_t I2CID, uint8_t Slave_address, uint8_t Memory_Loc, uint8_t Datacount, uint8_t* Data);
uint8_t TPR_Calculator(uint32_t Clock);

#endif /* I2C_H_ */
