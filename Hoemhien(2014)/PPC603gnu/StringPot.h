/* This is the Header File for Xbox Controller*/
#ifndef STRINGPOT_H
#define STRINGPOT_H



#include "WPILib.h"
#include <cmath>


#define STRINGPOTCHANNEL 1
#define REFERENCEVOLTAGECHANNEL 7


class StringPot {
public:
	~StringPot() {
	}
	StringPot();
	static StringPot *getInstance();
	void initialize();
	void initializeAutonomous();
	void run();

private:
	
	DriverStationLCD *dsLCD;
	AnalogChannel stringPot;
	AnalogChannel referenceVoltage;
};

#endif 
