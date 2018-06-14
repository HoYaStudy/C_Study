#include <stdint.h>
#include "temp_sensor.h"
#include "i2c.h"

float TempSensor_GetTemperature(void) {
  uint16_t raw_value = I2C_ReadRegister(0x03);
  return -100.0f + (0.2f * (float)raw_value);
}