#include <TimedAction.h>
#include <ax12.h>
#include "handlers.h"
#include "serial_reader.h"

unsigned char data[256];
unsigned char ch;
unsigned char prev = 0;

// read all the AX12a registers
void read_actuator_status(){
  query_all_registers();
}

// read LIDAR
void read_LIDAR(){
  // TODO: Read LIDAR distance from I2C
}

// Set up the timed functions
TimedAction statusThread = TimedAction(48, read_actuator_status);
TimedAction lidarThread = TimedAction(101, read_LIDAR);

// Initialize everything before we begin the main loop
void setup(){
  pinMode(0,OUTPUT);

  // TODO: set up I2C for LIDAR

  // setup serial
  Serial.begin(115200);


  // Initialize the interface to AX12a Servos
  init_interface();

  // wait, then check the voltage (LiPO safety)
  delay (500);
  float voltage = (ax12GetRegister (1, AX_PRESENT_VOLTAGE, 1)) / 10.0;
  if (voltage < 10.0)
    while(1);
}

// The main loop for the ArbotiX-M Robocontroller
void loop(){
  // check on threads
  statusThread.check();
  lidarThread.check();

  // Read in next command
  if(Serial.available() > 0){
    ch = (unsigned char)Serial.read();
    process_char(ch);
  }
}
