#ifndef gyro_h
#define gyro_h

#include <Wire.h>
#include <Adafruit_L3GD20.h>

const int GYRO_CS = 49;  // mega CS
const int GYRO_DO = 50;  // mega MISO
const int GYRO_DI = 51;  // mega MOSI
const int GYRO_CLK = 52; // mega SCK

const double DRIFT[3] = { -0.0163681, 4.55715, -0.6529};
const double DRIFT_2[3] = { -0.016952, 0.373748, -0.057698};
const double DRIFT_3[3] = { -0.00729, 0.01722, 0.02919};

double GyroDeg[3];


Adafruit_L3GD20 gyro(GYRO_CS, GYRO_DO, GYRO_DI, GYRO_CLK);

void GyroInit() {
  gyro.begin(gyro.L3DS20_RANGE_250DPS);
}

void GyroRead(int DeltaTime) {
  
  gyro.read();
  GyroDeg[0] += (gyro.data.x - DRIFT[0] - DRIFT_2[0] - DRIFT_3[0]) * DeltaTime / 1000;
  GyroDeg[1] += (gyro.data.y - DRIFT[1] - DRIFT_2[1] - DRIFT_3[1]) * DeltaTime / 1000;
  GyroDeg[2] += (gyro.data.z - DRIFT[2] - DRIFT_2[2] - DRIFT_3[2]) * DeltaTime / 1000;

}

#endif
