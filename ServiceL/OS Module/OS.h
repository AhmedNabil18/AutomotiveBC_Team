/*****************************************************************************
* Module: OS Module
* File Name: OS.h
* Description: Header file for OS Module
* Author: Mohamed Magdy
* Date: 28-Aug-2021
******************************************************************************/ 


#ifndef OS_H_
#define OS_H_

#include "Std_Types.h"
#include "Common_Macros.h"
#include "Gpt.h"
#include "OS_Cfg.h"
/*- Primitive Types
-------------------------------*/
/* void pointer to parameters to be passed to the task */
typedef void*    TaskParameters_t;
/* task unique id */
typedef uint8_t  TaskId_t;
/* task unique priority */
typedef uint8_t  TaskPriority_t;
/* task periodicity in sys ticks */
typedef uint16_t TaskPeriodicityTicks_t;
/* master sys tick monitor like a clock */
typedef volatile uint32_t OS_SysTicks_t;
/* index for tasks array */
typedef uint8_t TaskIndex_t;
/* pointer to function representing the task which can take input parameter */
typedef Std_ReturnType (*ptrTask_t) (TaskParameters_t);
/* current number of tasks created in system */
typedef uint8_t CreatedTasksCount_t;
/* OS tick flag */
typedef volatile boolean OS_NewTickFlag_t;

/* task will run flag */
typedef boolean OS_TaskWillRunFlag_t;

/* task is running flag */
typedef boolean OS_TaskIsRunningFlag_t;

/* OS is initialized flag */
typedef boolean OS_InitializedFlag_t;

/*  cpu load */
typedef uint8_t OS_CpuLoad_t;

/* idle task duration */
typedef OS_SysTicks_t OS_IdleTaskDuration_t;

 /*- Constants
 -------------------------------*/
 /* input used in OS_setTaskState function */
 #define ALL_TASKS			(0xFF)
 
  /* return used to indicate that Id not found used in OS_GetTaskIndex function */
 #define INDEX_NOT_FOUND	(0xFF)
 
  /*- Structs
 -------------------------------*/
typedef struct
{
	ptrTask_t TaskPointer;
	TaskParameters_t Parameters;
	TaskPeriodicityTicks_t Periodicity;
	
}strTasksCreationData_t;

  /*- Structs
 -------------------------------*/
typedef enum
{
	BLOCKED,
	RUNNING,
	READY,
	SUSPENDED
}TaskState_t;

/*- Function Declarations
-------------------------------*/
/* task creation */
Std_ReturnType OS_TaskCreate(TaskId_t* Id, TaskPriority_t Priority, TaskPeriodicityTicks_t Periodicity, 
							 ptrTask_t TaskPointer, TaskParameters_t Parameters);
/* task lock */							 
Std_ReturnType OS_TaskSuspend(TaskId_t Id);
/* task resume */
Std_ReturnType OS_TaskResume(TaskId_t Id);
/* set task's prio */
Std_ReturnType OS_SetPriority(TaskId_t Id, TaskPriority_t Priority);
/*set task's periodicity */
Std_ReturnType OS_SetPeriodicity(TaskId_t Id, TaskPeriodicityTicks_t Periodicity);
/* start system */
Std_ReturnType OS_Start(void);
/* OS init */
Std_ReturnType OS_Init(void);
/* get current sys tick */
Std_ReturnType OS_getCurrentSysTick(OS_SysTicks_t* Sys_CurrentTime);
/* check if any task is currently running */
boolean OS_checkIfTaskRunning(void);
/* get cpu load */
Std_ReturnType OS_getCpuLoad(OS_CpuLoad_t* CpuLoad);
/*- Extern Variables
-------------------------------*/

#endif /* OS_H_ */