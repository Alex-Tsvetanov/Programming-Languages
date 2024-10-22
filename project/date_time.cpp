#include "date_time.hpp"
#include <iomanip>

DateTime::DateTime() : DateTime(0, 0, 0, 0, 0, 0)
{
}

DateTime::DateTime(unsigned short year, unsigned short month, unsigned short day, unsigned short hour, unsigned short minute, unsigned short second)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

std::ostream& operator<<(std::ostream& out, const DateTime& time)
{
	out << std::setw(2) << std::setfill('0') << time.day << "." << std::setw(2) << std::setfill('0') << time.month << "." << time.year << " " << std::setw(2)
		<< std::setfill('0') << time.hour << ":" << std::setw(2) << std::setfill('0') << time.minute << ":" << std::setw(2) << std::setfill('0') << time.second;
	return out;
}

Time::Time()
{
}

Time::Time(unsigned short hour, unsigned short minute, unsigned short second)
{
}

Time Time::from(double hours)
{
	unsigned short h, m, s;
	h = (unsigned short)hours;
	hours -= h;
	hours *= 60;
	m = (unsigned short)hours;
	hours -= m;
	hours *= 60;
	s = (unsigned short)hours;
	return Time(h, m, s);
}

std::ostream& operator<<(std::ostream& out, const Time& time)
{
	out << time.hour << ":" << time.minute << ":" << time.second;
	return out;
}
