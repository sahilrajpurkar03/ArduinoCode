#include <SparkFunMPU9250-DMP.h>

#define SerialPort SerialUSB  // Define serial port for debug output

MPU9250_DMP imu;  // Create MPU9250 object

void setup() 
{
  SerialPort.begin(115200);  // Initialize debug serial port
  Serial1.begin(115200);     // Initialize secondary serial port (e.g., for communication)

  // Initialize the IMU sensor and check connection
  if (imu.begin() != INV_SUCCESS)
  {
    while (1)
    {
      SerialPort.println("Unable to communicate with MPU-9250");
      SerialPort.println("Check connections, and try again.");
      SerialPort.println();
      delay(5000);
    }
  }
  
  // Enable DMP features:
  // 6-axis low-power quaternion + gyro calibration
  imu.dmpBegin(DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_GYRO_CAL, 10); 
  // 10 Hz FIFO update rate
}

void loop() 
{
  // Check if new data available from FIFO buffer
  if (imu.fifoAvailable())
  {
    // Update sensor data from FIFO
    if (imu.dmpUpdateFifo() == INV_SUCCESS)
    {
      // Compute Euler angles from quaternion data
      imu.computeEulerAngles();

      // Send yaw over Serial1 as ASCII float (recommended)
      Serial1.print("Yaw: ");
      Serial1.println(imu.yaw);
      
      // Alternatively, send raw bytes (not human-readable):
      // Serial1.write((uint8_t*)&imu.yaw, sizeof(imu.yaw));
    }
  }
}