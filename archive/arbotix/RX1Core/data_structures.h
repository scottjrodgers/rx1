#ifndef DATASTRUCTS
#define DATASTRUCTS

// Core data structures for RX1 API
#include "robot.h"

typedef enum{SUCCESS=1000, FAILURE=-65535} RC_t;

// Declare vector
typedef struct{
  fixed_t x;
  fixed_t y;
  fixed_t z;
} vector_t;

// Declare vector
typedef struct{
  fixed_t x;
  fixed_t y;
  fixed_t z;
  fixed_t dx;
  fixed_t dy;
  fixed_t dz;
} k_vector_t;

// Actuator State
typedef struct{
  int position[NUM_ACTUATORS + 1];
  int speed[NUM_ACTUATORS + 1];
  int load[NUM_ACTUATORS + 1];
  int voltage[NUM_ACTUATORS + 1];
  int temperature[NUM_ACTUATORS + 1];
  int moving[NUM_ACTUATORS + 1];
} actuator_state_t;

// Actuator Targets
typedef struct{
  int position[NUM_ACTUATORS + 1];
  int speed[NUM_ACTUATORS + 1];
} actuator_target_t;

// Kinematic State
typedef struct{
  k_vector_t position;
  vector_t up;
  vector_t fwd;
  k_vector_t legs[NUM_LEGS];
  char fixed[NUM_LEGS];
} kinematic_state_t;

#endif
