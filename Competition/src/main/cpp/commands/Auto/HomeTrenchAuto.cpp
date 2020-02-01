#include <commands/Auto/HomeTrenchAuto.h>

HomeTrenchAuto::HomeTrenchAuto(Drivetrain* drivetrain) {
    AddCommands(InitHomeTrench(drivetrain));
}