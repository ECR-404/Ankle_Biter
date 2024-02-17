#include "main.h"

/////
// For installation, upgrading, documentations and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;  
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(3, 0, 20);
  chassis.pid_drive_constants_set(10, 0, 100);
  chassis.pid_turn_constants_set(3, 0, 20);
  chassis.pid_swing_constants_set(5, 0, 30);

  chassis.pid_turn_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_swing_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_drive_exit_condition_set(300_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassis.slew_drive_constants_set(7_in, 80);
}

///
// Set Wings
///
void setwings(bool left, bool right) {
  leftwing = left;
  rightwing = right;
  leftWing.set_value(leftwing);
  rightWing.set_value(rightwing);
}

///
// Offensive Side
///
void offensive_side() {

  motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
  motors.move_velocity(100);
  
  chassis.pid_swing_set(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.pid_wait();

  if (cataSw.get_value()) {
    motors.move_velocity(0);
  }

  setwings(false, true);

  if (cataSw.get_value()) {
    motors.move_velocity(0);
  }

  chassis.pid_drive_set(70_in, DRIVE_SPEED);
  chassis.pid_wait();

  while (!cataSw.get_value()) {
    motors.move_velocity(100);
  }
  motors.move_velocity(0);

  setwings(false, false);

  chassis.pid_drive_set(15_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(60_in, 127);
  chassis.pid_wait();

  chassis.pid_drive_set(-30_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(50_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-25_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-180_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, -135_deg, SWING_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(100_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  setwings(false, true);

  chassis.pid_drive_set(76_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-95_deg, TURN_SPEED);
  chassis.pid_wait();

}



///
// Defensive Side
///
void defensive_side() {

  motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
  
  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(80_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(5_in, 127);
  chassis.pid_wait();

  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(25_in, 127);
  chassis.pid_wait();

  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-180_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-225_deg, TURN_SPEED);
  chassis.pid_wait();

  setwings(false, true);

  chassis.pid_drive_set(70_in, DRIVE_SPEED);
  chassis.pid_wait();

  setwings(false, false);

  chassis.pid_drive_set(60_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-270_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(20_in, DRIVE_SPEED);
  chassis.pid_wait();

  setwings(true, false);

  chassis.pid_drive_set(45_in, DRIVE_SPEED);
  chassis.pid_wait();


}



///
// Skills
///
void skills() {

  motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);

  motors.move_velocity(100);
  pros::delay(6000);
  motors.move_velocity(0);

  chassis.pid_drive_set(200_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-45_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(50_in, DRIVE_SPEED);
  chassis.pid_wait();

  setwings(true, true);

  chassis.pid_drive_set(200_in, DRIVE_SPEED);
  chassis.pid_wait();

}


///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches

  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 30
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(30);  // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 30 speed
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 30
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(30);  // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 30 speed
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

// . . .
// Make your own autonomous functions here!
// . . .