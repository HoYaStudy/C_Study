#include "unity.h"
#include "temp_sensor.h"
#include "mock_i2c.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_temp_sensor_ReadMinValue(void) {
  uint8_t temp_register_address = 0x03;
  float expected_temperature = -100.0f;
  float tolerance = 0.1f;

  I2C_ReadRegister_ExpectAndReturn(temp_register_address, 0x0);

  float actual_temperature = TempSensor_GetTemperature();
  TEST_ASSERT_FLOAT_WITHIN(tolerance, expected_temperature, actual_temperature);
}

void test_temp_sensor_ReadMaxValue(void)
{
  uint8_t temp_register_address = 0x03;
  float expected_temperature = 104.6f;
  float tolerance = 0.1f;

  I2C_ReadRegister_ExpectAndReturn(temp_register_address, 0x3ff);

  float actual_temperature = TempSensor_GetTemperature();
  TEST_ASSERT_FLOAT_WITHIN(tolerance, expected_temperature, actual_temperature);
}
