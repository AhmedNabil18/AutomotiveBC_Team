#include "GPIO.h"
#include "GPIO_Cfg.h"

const GPIO_CfgType GPIO_ConfigParam [GPIO_GROUPS_NUMBER] =
        {
            {               // Blue LED
                0x05,       //port ID
                1<<2,       //port mask
                0x00,       //AFSEL
                0,          //UseDMATrig
                0,          //UseACDTrig
                0xff,       //Direction
                0x00,       //UsePullUp
                0x00,       //UsePullDown
                0x00,       //UseOpenDrain
                0xff,       //Use2mACrt
                0x00,       //Use4mACrt
                0x00,       //Use8mACrt
                0xff,       //Digital EN
                0
            },
            {               // Camera
                0x00,       //port ID
                1<<5,       //port mask
                0x00,       //AFSEL
                0,          //UseDMATrig
                0,          //UseACDTrig
                0xff,       //Direction
                0x00,       //UsePullUp
                0x00,       //UsePullDown
                0x00,       //UseOpenDrain
                0xff,       //Use2mACrt
                0x00,       //Use4mACrt
                0x00,       //Use8mACrt
                0xff,       //Digital EN
                0
            },
            {               // RED LED
                0x05,       //port ID
                1<<1,       //port mask
                0x00,       //AFSEL
                0,          //UseDMATrig
                0,          //UseACDTrig
                0xff,       //Direction
                0x00,       //UsePullUp
                0x00,       //UsePullDown
                0x00,       //UseOpenDrain
                0xff,       //Use2mACrt
                0x00,       //Use4mACrt
                0x00,       //Use8mACrt
                0xff,       //Digital EN
                0
            },
            {               // Green LED
                0x05,       //port ID
                1<<3,       //port mask
                0x00,       //AFSEL
                0,          //UseDMATrig
                0,          //UseACDTrig
                0xff,       //Direction
                0x00,       //UsePullUp
                0x00,       //UsePullDown
                0x00,       //UseOpenDrain
                0xff,       //Use2mACrt
                0x00,       //Use4mACrt
                0x00,       //Use8mACrt
                0xff,       //Digital EN
                0
            },
            {               // SW1
                0x05,       //port ID
                1<<4,       //port mask
                0x00,       //AFSEL
                0,          //UseDMATrig
                0,          //UseACDTrig
                0x00,       //Direction
                0xff,       //UsePullUp
                0x00,       //UsePullDown
                0x00,       //UseOpenDrain
                0xff,       //Use2mACrt
                0x00,       //Use4mACrt
                0x00,       //Use8mACrt
                0xff,       //Digital EN
                0
            },
            {               // SW2
                0x05,       //port ID
                1<<0,       //port mask
                0x00,       //AFSEL
                0,          //UseDMATrig
                0,          //UseACDTrig
                0x00,       //Direction
                0xff,       //UsePullUp
                0x00,       //UsePullDown
                0x00,       //UseOpenDrain
                0xff,       //Use2mACrt
                0x00,       //Use4mACrt
                0x00,       //Use8mACrt
                0xff,       //Digital EN
                0
            },

            {               // Screen
                0x00,       //port ID
                1<<6,       //port mask
                0x00,       //AFSEL
                0,          //UseDMATrig
                0,          //UseACDTrig
                0xff,       //Direction
                0x00,       //UsePullUp
                0x00,       //UsePullDown
                0x00,       //UseOpenDrain
                0xff,       //Use2mACrt
                0x00,       //Use4mACrt
                0x00,       //Use8mACrt
                0xff,       //Digital EN
                0
            },
            {               // SW3  PD0
                0x03,       //port ID
                1<<0,       //port mask
                0x00,       //AFSEL
                0,          //UseDMATrig
                0,          //UseACDTrig
                0x00,       //Direction
                0xff,       //UsePullUp
                0x00,       //UsePullDown
                0x00,       //UseOpenDrain
                0xff,       //Use2mACrt
                0x00,       //Use4mACrt
                0x00,       //Use8mACrt
                0xff,       //Digital EN
                0
            },
            {               // SW4  PD1
                0x03,       //port ID
                1<<1,       //port mask
                0x00,       //AFSEL
                0,          //UseDMATrig
                0,          //UseACDTrig
                0x00,       //Direction
                0xff,       //UsePullUp
                0x00,       //UsePullDown
                0x00,       //UseOpenDrain
                0xff,       //Use2mACrt
                0x00,       //Use4mACrt
                0x00,       //Use8mACrt
                0xff,       //Digital EN
                0
            },

            {               // Screen
                0x03,       //port ID
                1<<2,       //port mask
                0x00,       //AFSEL
                0,          //UseDMATrig
                0,          //UseACDTrig
                0xff,       //Direction
                0x00,       //UsePullUp
                0x00,       //UsePullDown
                0x00,       //UseOpenDrain
                0xff,       //Use2mACrt
                0x00,       //Use4mACrt
                0x00,       //Use8mACrt
                0xff,       //Digital EN
                0
            }
        };
