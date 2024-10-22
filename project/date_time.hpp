#pragma once
#include "project_fwd_def.hpp"
#include <ostream>

class DateTime
{
	unsigned short hour, minute, second, day, month, year;

public:
	DateTime();
	DateTime(unsigned short year, unsigned short month, unsigned short day, unsigned short hour, unsigned short minute, unsigned short second);

	friend class AirSpaceManager;
	friend std::ostream& operator<<(std::ostream& out, const DateTime& time);
};

class Time
{
	unsigned short hour, minute, second;

public:
	Time();
	Time(unsigned short hour, unsigned short minute, unsigned short second);

	static Time from(double hours);

	friend class AirSpaceManager;
	friend std::ostream& operator<<(std::ostream& out, const Time& time);
};
