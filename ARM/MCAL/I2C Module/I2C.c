#include <stdint.h>
#include "I2C.h"
#include "I2C_Cfg.h"

typedef volatile uint32_t* const I2C_RegAddType;
typedef volatile uint32_t* const GPIO_RegAddType;

/*Register GPIO memory map*/
#define PORTA_BASE_ADDRESS 0x40004000
#define PORTB_BASE_ADDRESS 0x40005000
#define PORTC_BASE_ADDRESS 0x40006000
#define PORTD_BASE_ADDRESS 0x40007000
#define PORTE_BASE_ADDRESS 0x40024000
#define PORTF_BASE_ADDRESS 0x40025000

#define RCGC_BASE_ADDRESS  0x400FE000

/*Base Address of Ports*/
static const uint32_t PortsBaseAddressLut[PORTS_NUMBER] =
{
    PORTA_BASE_ADDRESS,
    PORTB_BASE_ADDRESS,
    PORTC_BASE_ADDRESS,
    PORTD_BASE_ADDRESS,
    PORTE_BASE_ADDRESS,
    PORTF_BASE_ADDRESS
};

/*Needed GPIO Registers*/
#define GPIO_REG_ADDRESS(CHANNEL_ID,REG_OFFSET)\
(PortsBaseAddressLut[CHANNEL_ID] + REG_OFFSET)

#define GPIOAFSEL_REG(PORT_ID)          *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x420))
#define GPIOPCTL_REG(PORT_ID)           *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x52C))
#define GPIODR2R_REG(PORT_ID)           *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x500))
#define GPIODR4R_REG(PORT_ID)           *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x504))
#define GPIODR8R_REG(PORT_ID)           *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x508))
#define GPIOLOCK_REG(PORT_ID)           *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x520))
#define GPIOCR_REG(PORT_ID)             *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x524))
#define GPIODIR_REG(PORT_ID)            *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x400))
#define GPIODEN_REG(PORT_ID)            *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x51C))
#define GPIOODR_REG(PORT_ID)            *((GPIO_RegAddType)GPIO_REG_ADDRESS(PORT_ID,0x50C))
#define RCGC_GPIO                       *((volatile uint32_t *)0x400FE608)
#define GPIO_PORT_UNLOCK_VALUE 0x4C4F434B

/*Register I2C memory map*/
#define I2C0_BASE_ADDRESS 0x40020000
#define I2C1_BASE_ADDRESS 0x40021000
#define I2C2_BASE_ADDRESS 0x40022000
#define I2C3_BASE_ADDRESS 0x40023000

/*Base Address of Ports*/
static const uint32_t I2CSBaseAddressLut[I2CS_NUMBER] =
{
     I2C0_BASE_ADDRESS,
     I2C1_BASE_ADDRESS,
     I2C2_BASE_ADDRESS,
     I2C3_BASE_ADDRESS,
};


/*Register Address Calculator*/
#define I2C_REG_ADDRESS(I2C_ID,REG_OFFSET)\
(I2CSBaseAddressLut[I2C_ID] + REG_OFFSET)

/*Registers with offsets*/
#define I2C_MSA_R(I2C_ID)              *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x000))
#define I2C_MCS_R(I2C_ID)              *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x004))
#define I2C_MDR_R(I2C_ID)              *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x008))
#define I2C_MTPR_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x00C))
#define I2C_MIMR_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x010))
#define I2C_MRIS_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x014))
#define I2C_MMIS_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x018))
#define I2C_MICR_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x01C))
#define I2C_MCR_R(I2C_ID)              *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x020))
#define I2C_MCLKOCNT_R(I2C_ID)         *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x024))
#define I2C_MBMON_R(I2C_ID)            *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x02C))
#define I2C_MCR2_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x038))
#define I2C_SOAR_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x800))
#define I2C_SCSR_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x804))
#define I2C_SDR_R(I2C_ID)              *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x808))
#define I2C_SIMR_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x80C))
#define I2C_SRIS_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x810))
#define I2C_SMIS_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x814))
#define I2C_SICR_R(I2C_ID)             *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x818))
#define I2C_SOAR2_R(I2C_ID)            *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x81C))
#define I2C_SACKCTL_R(I2C_ID)          *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0x820))
#define I2C_PP_R(I2C_ID)               *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0xFC0))
#define I2C_PC_R(I2C_ID)               *((I2C_RegAddType)I2C_REG_ADDRESS(I2C_ID,0xFC4))
#define RCGC_I2C                       *((volatile uint32_t *)0x400FE620)

#define READ 1
#define WRITE 0
#define SINGLE_SEND                        0x00000007
#define SINGLE_RECEIVE                     0x00000007
#define BURST_SEND_START                   0x00000003
#define BURST_SEND_CONT                    0x00000001
#define BURST_SEND_FINISH                  0x00000005
#define BURST_SEND_ERROR_STOP              0x00000004
#define BURST_RECEIVE_START                0x0000000b
#define BURST_RECEIVE_CONT                 0x00000009
#define BURST_RECEIVE_FINISH               0x00000005
#define BURST_RECEIVE_ERROR_STOP           0x00000004

#define I2C_SLVADDRESS(I2C_ID,SlvAdd,RW)    (I2C_MSA_R(I2C_ID) = RW << 0);\
                                            (I2C_MSA_R(I2C_ID) |= SlvAdd << 1)
#define I2C_WRITE_DATA(I2C_ID,Data)         (I2C_MDR_R(I2C_ID) = Data)
#define I2C_READ_DATA (I2C_ID,Data)         (*Data++ = I2C_MDR_R(I2C_ID))
#define I2C_MSTR_CONTROL(I2C_ID, Command)   (I2C_MCS_R(I2C_ID) = Command)

#define Start(I2C_ID)   I2C_MSTR_CONTROL(I2C_ID, 0x02)
#define Run(I2C_ID)   I2C_MSTR_CONTROL(I2C_ID, 0x01)
#define Stop(I2C_ID)   I2C_MSTR_CONTROL(I2C_ID, 0x04)
#define Ack(I2C_ID)   I2C_MSTR_CONTROL(I2C_ID, 0x08)

/************************************************/
/*******************Functions********************/
/************************************************/
void I2C_Init(void)
{
    uint8_t I2CID;
    const I2C_Mod *Mod_data_ptr;
    for(I2CID=0 ; I2CID<I2CS_NUMBER ; I2CID++)
    {
        Mod_data_ptr = &I2CMOD_Data[I2CID];
        if(Mod_data_ptr->Enable == 1)
        {
            RCGC_GPIO |= 1<<(Mod_data_ptr->PortID);
            GPIODEN_REG  (Mod_data_ptr->PortID) |= (1<<(Mod_data_ptr->SDA_Pin)) + (1<<(Mod_data_ptr->SCK_Pin)); /*Digital Enable for the SDA and SCK pins of I2C*/
            GPIOAFSEL_REG(Mod_data_ptr->PortID) |= 1<<(Mod_data_ptr->SDA_Pin);                   /*SET the AFSEL of the pins*/
            GPIOAFSEL_REG(Mod_data_ptr->PortID) |= 1<<(Mod_data_ptr->SCK_Pin);                   /*SET the AFSEL of the pins*/
			GPIOPCTL_REG (Mod_data_ptr->PortID) |= I2C_PCTL_VAL << 4*(Mod_data_ptr->SDA_Pin);	 /*Configuring SDA pin to work as an I2C pin*/
            GPIOPCTL_REG (Mod_data_ptr->PortID) |= I2C_PCTL_VAL << 4*(Mod_data_ptr->SCK_Pin);    /*Configuring SCK pin to work as an I2C pin*/
            GPIOODR_REG  (Mod_data_ptr->PortID) |= 1<<(Mod_data_ptr->SDA_Pin);					 /*Configuring SDA pin to OPEN DRAIN*/

            RCGC_I2C |= 1<<I2CID;					   /*Enable I2C Clock*/
            I2C_MCR_R(I2CID) |= 0x10;                  /*I2C work as a Master*/
            I2C_MTPR_R(I2CID) |= TPR_Calculator(Clk);  /*Clock*/
        }else
        {
         /*Nothing to be done yet*/
        }
    }
}
/************************************************/
/************************************************/
/*Sending Bytes of Data*/
uint8_t I2C_Send(uint8_t I2CID, uint8_t Slave_address, uint8_t* Data)
{
    int st;
    int datacount=0;
    int w=0;
    for(st=0;;st++)
        {
            datacount=w+1;
            w++;
            if(*(Data+st+1)=='\0')
            {
                break;
            }
        }

    if(datacount == 1)
        {
            volatile char error=0;
            I2C_SLVADDRESS(I2CID,Slave_address,WRITE);
            I2C_WRITE_DATA(I2CID,*(Data));
            //I2C_MSTR_CONTROL(I2CID, SINGLE_SEND);
            Start(I2CID);Run(I2CID);Stop(I2CID);
            while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
            error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
            while(I2C_MCS_R(I2CID) & 0x40); /*Check on the bus busy flag*/
            error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/

            if (error) return error;
        }else
        {
            volatile char error=0;
            int i,k=0;

            I2C_SLVADDRESS(I2CID,Slave_address,WRITE);
            I2C_WRITE_DATA(I2CID,*(Data));
            //I2C_MSTR_CONTROL(I2CID,BURST_SEND_START);
            Start(I2CID);Run(I2CID);
            while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
            error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/

            for(i=0;i<datacount-1;i++)
            {
                k=i+1;
                I2C_WRITE_DATA(I2CID,*(Data+k));
                if(k != datacount-1)
                {
                    //I2C_MSTR_CONTROL(I2CID,BURST_SEND_CONT);
                    Run(I2CID);
                    while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
                    error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
                    if (error) return error;
                }else
                {
                    //I2C_MSTR_CONTROL(I2CID,BURST_SEND_FINISH);
                    Run(I2CID);Stop(I2CID);
                    while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
                    error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
                    if (error) return error;
                }
            }
        }
    return 0;
}
/************************************************/
/************************************************/
uint8_t I2C_Single_Send(uint8_t I2CID, uint8_t Slave_address, uint8_t Data)
{

    volatile char error=0;
    I2C_SLVADDRESS(I2CID,Slave_address,WRITE);
    I2C_WRITE_DATA(I2CID,Data);
    //I2C_MSTR_CONTROL(I2CID, SINGLE_SEND);
    Start(I2CID);Run(I2CID);Stop(I2CID);

    while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
    error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
    while(I2C_MCS_R(I2CID) & 0x40); /*Check on the bus busy flag*/
    error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/

    if (error) return error;
    return 0;
}
/************************************************/
/************************************************/
/*Sending Bytes of Data to a certain memory location*/
uint8_t I2C_Send_To_Memory(uint8_t I2CID, uint8_t Slave_address, uint8_t Memory_Loc, uint8_t* Data)
{
    int st,i;
    int datacount=0;
    int w=0;
    for(st=0;;st++)
    {
         datacount=w+1;
         w++;
         if(*(Data+st+1)=='\0')
         {
            break;
         }
    }
    volatile char error=0;
    I2C_SLVADDRESS(I2CID,Slave_address,WRITE);
    I2C_WRITE_DATA(I2CID,Memory_Loc);
    //I2C_MSTR_CONTROL(I2CID, BURST_SEND_START);
    Start(I2CID);Run(I2CID);

    while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
    error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/

    if(datacount == 1)
    {
        volatile char error=0;
        I2C_SLVADDRESS(I2CID,Slave_address,WRITE);
        I2C_WRITE_DATA(I2CID,*(Data+0));
        //I2C_MSTR_CONTROL(I2CID, BURST_SEND_FINISH);
        Run(I2CID);Stop(I2CID);

        while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
        error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
        while(I2C_MCS_R(I2CID) & 0x40); /*Check on the bus busy flag*/
        error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/

        if (error) return error;
    }
    for(i=0;i<datacount;i++)
    {
       I2C_WRITE_DATA(I2CID,*(Data+i));
       if(i != datacount-1)
       {
           //I2C_MSTR_CONTROL(I2CID,BURST_SEND_CONT);
           Run(I2CID);
           while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
           error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
           if (error) return error;
       }else
       {
           //I2C_MSTR_CONTROL(I2CID,BURST_SEND_FINISH);
           Run(I2CID);Stop(I2CID);
           while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
           error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
           if (error) return error;
       }
    }
    return 0;
}
/************************************************/
/************************************************/
uint8_t BQI2C_Send_To_Memory(uint8_t I2CID, uint8_t Slave_address, uint8_t Memory_Loc, uint8_t Data)
{

    volatile char error=0;
    I2C_SLVADDRESS(I2CID,Slave_address,WRITE);
    I2C_WRITE_DATA(I2CID,Memory_Loc);
    //I2C_MSTR_CONTROL(I2CID, BURST_SEND_START);
    Start(I2CID);Run(I2CID);

    while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
    error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
	
	I2C_SLVADDRESS(I2CID,Slave_address,WRITE);
	I2C_WRITE_DATA(I2CID,Data);
	//I2C_MSTR_CONTROL(I2CID, BURST_SEND_FINISH);
	Run(I2CID);Stop(I2CID);

	while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
	error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
	while(I2C_MCS_R(I2CID) & 0x40); /*Check on the bus busy flag*/
	error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/

	if (error) return error;
	return 0;
}
/************************************************/
/************************************************/
/*Receiving Bytes of Data*/
uint8_t I2C_Receive(uint8_t I2CID, uint8_t Slave_address, uint8_t Datacount, uint8_t* Data)
{
    volatile char error=0;

    I2C_SLVADDRESS(I2CID,Slave_address,READ); /* set slave address and read mode */

    if (Datacount == 1) /* if last byte, don't ack */
    {
        I2C_MSTR_CONTROL(I2CID,SINGLE_RECEIVE);
    }
    else /* else ack */
    {
        I2C_MSTR_CONTROL(I2CID,BURST_RECEIVE_START);
    }

    while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
    error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
    if (error) return error;

    I2C_READ_DATA(I2CID,Data); /* store the Data received */


    if (--Datacount == 0) /* if single byte read, done */
    {
    while(I2C_MCS_R(I2CID) & 0x40); /* wait until bus is not busy */
    return 0; /* no error */
    }

    /* read the rest of the bytes */
    while (Datacount > 1)
    {
        I2C_MSTR_CONTROL(I2CID,BURST_RECEIVE_CONT); /* -Data-ACK- */

        while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
        error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
        if (error) return error;

        Datacount--;

        I2C_READ_DATA(I2CID,Data); /* store the Data received */
    }

    I2C_MSTR_CONTROL(I2CID,BURST_RECEIVE_FINISH); /* -Data-NACK-P */

    while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/


    //I2C_READ_DATA(I2CID,Data); /* store the Data received */
    I2C_READ_DATA(I2CID,Data); /* store the Data received */

    while(I2C_MCS_R(I2CID) & 0x40); /*Check on the bus busy flag*/

    return 0; /* no error */

}
/************************************************/
/************************************************/
/*Receiving Bytes of Data from a certain memory location*/
uint8_t I2C_Receive_from_Memory(uint8_t I2CID, uint8_t Slave_address, uint8_t Memory_Loc, uint8_t Datacount, uint8_t* Data)
{
    volatile char error=0;
	I2C_SLVADDRESS(I2CID,Slave_address,WRITE);
    I2C_WRITE_DATA(I2CID,Memory_Loc);
    I2C_MSTR_CONTROL(I2CID, BURST_SEND_START);

    while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
    error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/

    I2C_SLVADDRESS(I2CID,Slave_address,READ); /* set slave address and read mode */
w
    if (Datacount == 1) /* if last byte, don't ack */
    {
        I2C_MSTR_CONTROL(I2CID,SINGLE_RECEIVE);
    }
    else /* else ack */
    {
        I2C_MSTR_CONTROL(I2CID,BURST_RECEIVE_START);
    }

    while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
    error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
    if (error) return error;

    I2C_READ_DATA(I2CID,Data); /* store the Data received */


    if (--Datacount == 0) /* if single byte read, done */
    {
    while(I2C_MCS_R(I2CID) & 0x40); /* wait until bus is not busy */
    return 0; /* no error */
    }

    /* read the rest of the bytes */
    while (Datacount > 1)
    {
        I2C_MSTR_CONTROL(I2CID,BURST_RECEIVE_CONT); /* -Data-ACK- */

        while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/
        error = I2C_MCS_R(I2CID) & 0xE; /*returns 1 if any of these bits are equal 1 (Error || DataAcknowledge || ADress Acknowledge)*/
        if (error) return error;

        Datacount--;

        I2C_READ_DATA(I2CID,Data); /* store the Data received */
    }

    I2C_MSTR_CONTROL(I2CID,BURST_RECEIVE_FINISH); /* -Data-NACK-P */

    while(I2C_MCS_R(I2CID) & 1);    /*Checks if the I2C Master still busy*/


    //I2C_READ_DATA(I2CID,Data); /* store the Data received */
    I2C_READ_DATA(I2CID,Data); /* store the Data received */

    while(I2C_MCS_R(I2CID) & 0x40); /*Check on the bus busy flag*/

    return 0; /* no error */

}
/************************************************/
/************************************************/
uint8_t TPR_Calculator(uint32_t Clock)
{
    char tpr=0;
    tpr=((16000000)/(20*Clock)) - 1;
    return tpr;
}
