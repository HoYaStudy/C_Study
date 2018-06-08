/*******************************************************************************
 * @file			main.c
 * @brief			Main application
 * @author		llHoYall <hoya128@gmail.com>
 * @version		v0.0.5
 * @note
 * 	- 2018.05.14	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include "message.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Definitions ---------------------------------------------------------------*/
#define MAX_THREAD (3)

/* Private Function Prototypes -----------------------------------------------*/
static void *threadAccel(void *param);
static void *threadBrake(void *param);

/* Main Process --------------------------------------------------------------*/
int main(void) {
  // thread initial
  pthread_t thread[MAX_THREAD];
  pthread_create(&thread[0], NULL, threadAccel, NULL);
  pthread_create(&thread[1], NULL, threadBrake, NULL);

  msg_e msg;
  uint32_t param1;
  uint32_t param2;

  clearMessage();

  while (1) {
    if (dequeueMessage(&msg, &param1, &param2) == MSG_SUCCESS) {
      switch (msg) {
      case MSG_ACCEL_PEDAL:
        printf("Process accel\n");
        break;

      case MSG_BRAKE_PEDAL:
        printf("Process brake\n");
        break;

      default:
        break;
      }
    }
  }

  return 0;
}

/* Private Functions ---------------------------------------------------------*/
static void *threadAccel(void *param) {
  while (1) {
    printf("Accel\n");
    enqueueMessage(MSG_ACCEL_PEDAL, 0, 0);
    sleep(1);
  }
}

static void *threadBrake(void *param) {
  while (1) {
    printf("Brake\n");
    enqueueMessage(MSG_BRAKE_PEDAL, 0, 0);
    sleep(1);
  }
}
