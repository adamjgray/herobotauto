#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START IQ MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END IQ MACROS

// Robot configuration code.
inertial BrainInertial = inertial();
motor ArmMoverMotorA = motor(PORT6, true);
motor ArmMoverMotorB = motor(PORT12, false);
motor_group ArmMover = motor_group(ArmMoverMotorA, ArmMoverMotorB);

motor ConveyorSpinnerMotorA = motor(PORT5, true);
motor ConveyorSpinnerMotorB = motor(PORT11, false);
motor_group ConveyorSpinner = motor_group(ConveyorSpinnerMotorA, ConveyorSpinnerMotorB);

touchled Lighty = touchled(PORT10);
bumper Bumpy = bumper(PORT3);
optical AlmostUselessOpt = optical(PORT4);
distance Nameless = distance(PORT9);
optical LeftOptical = optical(PORT2);
optical RightOptical = optical(PORT8);
motor LeftDrive = motor(PORT1, false);
motor RightDrive = motor(PORT7, true);

#pragma endregion VEXcode Generated Robot Configuration

// Include the IQ Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

// User defined function
void myblockfunction_CalculateBrightness();

float AvgBrightness, Darkest, Brightest, CurrentBrightness;

void myblockfunction_CalculateBrightness() {
  CurrentBrightness = LeftOptical.brightness();
  if (CurrentBrightness < Darkest) {
    Darkest = CurrentBrightness;
  }
  if (CurrentBrightness > Brightest) {
    Brightest = CurrentBrightness;
  }
  AvgBrightness = (Darkest + Brightest) / 2.0;
}

// "when started" hat block
int whenStarted1() {
  ArmMover.setStopping(hold);
  ConveyorSpinner.setStopping(hold);
  LeftDrive.setVelocity(50.0, percent);
  RightDrive.setVelocity(50.0, percent);
  ArmMover.setVelocity(50.0, percent);
  ConveyorSpinner.setVelocity(50.0, percent);
  LeftDrive.setStopping(hold);
  RightDrive.setStopping(coast);
  LeftOptical.setLight(ledState::on);
  RightOptical.setLight(ledState::on);
  Lighty.setColor(green);
  Brain.playSound(tada);
  Darkest = 100.0;
  Brightest = 0.0;
  CurrentBrightness = 50.0;
  while (true) {
    myblockfunction_CalculateBrightness();
  }
  return 0;
}

float in_to_deg(float inches) {
  return inches * 25.4 * (360 / 200.0);
}

// "when buttonLeft pressed" hat block
void onevent_buttonLeft_pressed_0()  {
 RightDrive.spinFor(forward, in_to_deg(1), degrees, false);
 LeftDrive.spinFor(forward, in_to_deg(1), degrees, true);

 ConveyorSpinner.spin(forward);
 wait(2, seconds);

 ConveyorSpinner.stop();
}



void onevent_buttonCheck_pressed_0() {
  ArmMover.spinFor(forward, 90, degrees);
  LeftDrive.spin(forward);
  RightDrive.spin(forward);

  while (LeftOptical.brightness() > AvgBrightness && RightOptical.brightness() > AvgBrightness){
    wait(20, msec);  
  }

  LeftDrive.stop();
  RightDrive.stop();

  LeftDrive.spin(forward);
  RightDrive.spin(reverse);

  while (BrainInertial.rotation(degrees) > -89) {
    LeftDrive.setVelocity(-5 + -abs(-90 - BrainInertial.rotation(degrees)),percent);
    RightDrive.setVelocity(5 + abs(-90 - BrainInertial.rotation(degrees)),percent);

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    Brain.Screen.print("GYRO: %f", BrainInertial.rotation(degrees));
    wait(16,msec);
  }

  LeftDrive.stop();
  RightDrive.stop();

  LeftDrive.spin(reverse);
  RightDrive.spin(forward);
  
  while (BrainInertial.rotation(degrees)<-1) {
    LeftDrive.setVelocity(5 + abs(0 - BrainInertial.rotation(degrees)),percent);
    RightDrive.setVelocity(-5 + -abs(0 - BrainInertial.rotation(degrees)),percent);
  }

  LeftDrive.setVelocity(50, percent);
  RightDrive.setVelocity(50, percent);

  LeftDrive.spinFor(forward, in_to_deg(13.0), degrees, false);
  RightDrive.spinFor(forward, in_to_deg(13.0), degrees, true);

  LeftDrive.spin(forward);
  RightDrive.spin(forward);

  while (LeftOptical.brightness() > AvgBrightness && RightOptical.brightness() > AvgBrightness){
    wait(20, msec);  
  }

  LeftDrive.stop();
  RightDrive.stop();

  LeftDrive.spinFor(forward, in_to_deg(3), degrees, false);
  RightDrive.spinFor(forward, in_to_deg(3), degrees, true);

  LeftDrive.spin(reverse);
  RightDrive.spin(forward);

  while (BrainInertial.rotation(degrees) > -64) {
    LeftDrive.setVelocity(-5 + -abs(-65 - BrainInertial.rotation(degrees)),percent);
    RightDrive.setVelocity(5 + abs(-65 - BrainInertial.rotation(degrees)),percent);
  }

  LeftDrive.stop();
  RightDrive.stop();

  LeftDrive.setVelocity(50, percent);
  RightDrive.setVelocity(50, percent);

  LeftDrive.spinFor(forward, in_to_deg(12), degrees, false);
  RightDrive.spinFor(forward, in_to_deg(12), degrees, true);

  LeftDrive.spinFor(reverse, in_to_deg(24), degrees, false);
  RightDrive.spinFor(reverse, in_to_deg(24), degrees, true);

  LeftDrive.spin(forward);
  RightDrive.spin(reverse);

  while (BrainInertial.rotation(degrees) < 54) {
    LeftDrive.setVelocity(5 + abs(54 - BrainInertial.rotation(degrees)),percent);
    RightDrive.setVelocity(-5 + -abs(54 - BrainInertial.rotation(degrees)),percent);
  }
  
  RightDrive.stop();
  LeftDrive.stop();

  RightDrive.setVelocity(50, percent);
  LeftDrive.setVelocity(50,percent);

  RightDrive.spinFor(forward, in_to_deg(20), degrees, false);
  LeftDrive.spinFor(forward, in_to_deg(20), degrees, true);
}

void on_release_lighty() {
  Brain.playSound(soundType::wrongWay);
  Lighty.setColor(color::red);
}

float gyro_cur_deg = BrainInertial.rotation(degrees);

int main() {  
  BrainInertial.calibrate();
  wait(2, seconds);
  
  Brain.playSound(tada);

  // register event handlers
  Brain.buttonLeft.pressed(onevent_buttonLeft_pressed_0);
  Brain.buttonCheck.pressed(onevent_buttonCheck_pressed_0);
  Lighty.released(on_release_lighty);
    
  wait(15, msec);
  whenStarted1();
} 
