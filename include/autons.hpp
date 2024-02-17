#pragma once

#include "EZ-Template/drive/drive.hpp"

extern Drive chassis;
extern pros::MotorGroup motors;
extern bool leftwing;
extern bool rightwing;
extern bool intake;
extern pros::ADIDigitalOut leftWing;
extern pros::ADIDigitalOut rightWing;
extern pros::ADIDigitalOut transmission;
extern pros::ADIDigitalIn cataSw;

void defensive_side();
void offensive_side();
void skills();

void default_constants();