/* This is the CPP file for Lift Control 
 * Current Version:
 * B Button hold to lift. No reverse.
 * */

#include "StringPot.h"

static StringPot *stringpot = NULL;
StringPot *StringPot::getInstance() {
	if (stringpot == NULL) {
		stringpot = new StringPot();
	}
	return stringpot;
}

StringPot::StringPot(): stringPot(STRINGPOTCHANNEL), referenceVoltage(REFERENCEVOLTAGECHANNEL) {

	dsLCD = DriverStationLCD::GetInstance();

//	dsLCD->PrintfLine(DriverStationLCD::kUser_Line2, "StringPot 1.0");
	//dsLCD->UpdateLCD();
}

void StringPot::initialize() {

}

void StringPot::initializeAutonomous() {
}
/*
 * StringPot "angle" starts at 1 and goes down from there to zero. So. Yeah. 
 */
void StringPot::run(){
	float refVolt = referenceVoltage.GetAverageVoltage();
	float stringPotVolt = stringPot.GetAverageVoltage();
	float testAngle = 0.0;
	float inches;
	testAngle = (refVolt - stringPotVolt)/refVolt;
	inches = 12.5-testAngle*12.5;
	
	//dsLCD->PrintfLine(DriverStationLCD::kUser_Line5, "Pot. inches %f", inches);
//	dsLCD->PrintfLine(DriverStationLCD::kUser_Line4, "Pot.volt %f", stringPotVolt);
//	dsLCD->PrintfLine(DriverStationLCD::kUser_Line5, "\"Angle\" %f", testAngle);
	dsLCD->UpdateLCD();
}


