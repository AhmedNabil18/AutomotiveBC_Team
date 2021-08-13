/*
 * Sensing.h
 *
 * Created: 13/8/2021 11:16:10 AM
 *  Author: Ahmed Nabil
 */ 


#ifndef SENSING_H_
#define SENSING_H_

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- INCLUDES *-*-*-*-*-*/
//#include "../../../ECUAL/Ultrasonic Module/Ultrasonic.h"
#include "Rbt_Steering_Cfg.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- CONSTANTS -*-*-*-*-*-*/

/*******************************************************************************
 *                          Module Data Types                                  *
 *******************************************************************************/

/*
 * Data Type for Sensing module state
 */
typedef uint8_t Sensing_State_t;

/*
 * Data Type for Sensing Module configurations
 */
typedef struct  
{
	
}Sensing_Config_t;
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Function to initialize the module */
Std_ReturnType Sensing_init(void);

/* Function used to get distance between the sensor and the facing obstacle */
Std_ReturnType Sensing_getObstcleDistance(uint16_t *Sensing_distanceCM_pu16);


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const Sensing_Config_t Sensing_Configuratons;

#endif /* SENSING_H_ */