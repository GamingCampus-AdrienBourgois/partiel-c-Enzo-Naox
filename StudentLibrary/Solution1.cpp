#include "Solution1.h"

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#include <stdexcept>
#include <iostream>
#ifdef COMPILE_EXERCICE_1

float Solution1::ConvertTemperature(float _value, TemperatureUnits _from, TemperatureUnits _to)
{
    if (_from == _to)
    {
        // If the source and target units are the same, no conversion is needed
        return _value;
    }

    switch (_from)
    {
    case TemperatureUnits::CELSIUS:
        return ConvertFromCelsius(_value, _to);

    case TemperatureUnits::FAHRENHEIT:
        return ConvertFromFahrenheit(_value, _to);

    case TemperatureUnits::KELVIN:
        return ConvertFromKelvin(_value, _to);

    default:
        // Handle invalid source unit
        throw std::invalid_argument("Invalid source temperature unit");
    }
}

float Solution1::ConvertFromCelsius(float _value, TemperatureUnits _to)
{
    {
        switch (_to)
        {
        case TemperatureUnits::FAHRENHEIT:
            return (_value * 9.0f / 5.0f) + 32.0f;

        case TemperatureUnits::KELVIN:
            return _value + 273.15f;

        default:
            // Handle invalid target unit
            throw std::invalid_argument("Invalid target temperature unit");
        }
    }
}

float Solution1::ConvertFromFahrenheit(float _value, TemperatureUnits _to)
{
    {
        switch (_to)
        {
        case TemperatureUnits::CELSIUS:
            return (_value - 32.0f) * 5.0f / 9.0f;

        case TemperatureUnits::KELVIN:
            return (_value - 32.0f) * 5.0f / 9.0f + 273.15f;

        default:
            // Handle invalid target unit
            throw std::invalid_argument("Invalid target temperature unit");
        }
    }
}

float Solution1::ConvertFromKelvin(float _value, TemperatureUnits _to)
{
    {
        switch (_to)
        {
        case TemperatureUnits::CELSIUS:
            return _value - 273.15f;

        case TemperatureUnits::FAHRENHEIT:
            return (_value - 273.15f) * 9.0f / 5.0f + 32.0f;

        default:
            // Handle invalid target unit
            throw std::invalid_argument("Invalid target temperature unit");
        }
    }
}

#endif
