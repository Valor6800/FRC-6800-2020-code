#include "commands/Autos/MotionProfileTest.h"

MotionProfileTest::MotionProfileTest() { 
  AddSequential(new DriveForward(15));

}