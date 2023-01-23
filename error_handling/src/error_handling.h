#ifndef __ERROR_HANDLING_H__
#define __ERROR_HANDLING_H__

//--- Include Headers --------------------------------------------------------//
#include <stdint.h>


//--- Definitions ------------------------------------------------------------//
#define MAX_ERROR_MESSAGE   32


//--- Enumerations -----------------------------------------------------------//
typedef enum _eERRORCODE {
  eEC_OK,
  eEC_FAILURE
} eERRORCODE;


//--- Structures -------------------------------------------------------------//
typedef struct _tERROR {
  eERRORCODE errorcode;
  void* error;
} tERROR, *ptERROR;

typedef struct _tERROR_FAILURE {
  char errormsg[MAX_ERROR_MESSAGE];
} tERROR_FAILURE, *ptERROR_FAILURE;

#endif  // __ERROR_HANDLING_H__
