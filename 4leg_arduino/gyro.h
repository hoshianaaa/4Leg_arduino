#ifndef gyro_h
#define gyro_h

#include <Wire.h>
#include <Adafruit_L3GD20.h>

const int GYRO_CS = 49;
const int GYRO_DO = 50;
const int GYRO_DI = 51;
const int GYRO_CLK = 52;

Adafruit_L3GD20 gyro(GYRO_CS, GYRO_DO, GYRO_DI, GYRO_CLK);

void gyro_init() {
  gyro.begin(gyro.L3DS20_RANGE_250DPS);
}

gyro_read(double* data) {
  gyro.read();
  data[0] = gyro.data.x;
  data[1] = gyro.data.y;
  data[2] = gyro.data.z;
}

#endif
