#pragma once

// Don't forget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#include <iostream>
#ifdef COMPILE_EXERCICE_1

enum class TemperatureUnits
{
	CELSIUS,
	FAHRENHEIT,
	KELVIN
};

class Solution1 // Temperature converter
{
public:
	static float ConvertTemperature(float _value, TemperatureUnits _from, TemperatureUnits _to);

private:
	static float ConvertFromCelsius(float _value, TemperatureUnits _to);
	static float ConvertFromFahrenheit(float _value, TemperatureUnits _to);
	static float ConvertFromKelvin(float _value, TemperatureUnits _to);
};


#endif
