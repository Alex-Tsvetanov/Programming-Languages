/**
 * @file date_time.hpp
 * @brief Contains the declaration of the DateTime and Time classes and their methods for handling date and time information.
 */

#pragma once
#include "project_fwd_def.hpp"
#include <ostream>

/**
 * @class DateTime
 * @brief Represents a specific point in time with detailed components like year, month, day, hour, minute, and second.
 */
class DateTime
{
    unsigned short hour; ///< The hour of the time (0-23).
    unsigned short minute; ///< The minute of the time (0-59).
    unsigned short second; ///< The second of the time (0-59).
    unsigned short day; ///< The day of the date (1-31).
    unsigned short month; ///< The month of the date (1-12).
    unsigned short year; ///< The year of the date.

public:
    /**
     * @brief Default constructor initializing to an undefined date and time.
     */
    DateTime();

    /**
     * @brief Constructs a DateTime object with the specified date and time.
     * @param year The year of the date.
     * @param month The month of the date (1-12).
     * @param day The day of the date (1-31).
     * @param hour The hour of the time (0-23).
     * @param minute The minute of the time (0-59).
     * @param second The second of the time (0-59).
     */
    DateTime(unsigned short year, unsigned short month, unsigned short day, unsigned short hour, unsigned short minute, unsigned short second);

    /**
     * @brief Overloaded output stream operator for DateTime.
     * @param out The output stream.
     * @param time The DateTime object to be output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const DateTime& time);
};

/**
 * @class Time
 * @brief Represents a time duration or specific time of day without date information.
 */
class Time
{
    unsigned short hour; ///< The hour of the time duration or time of day (0-23).
    unsigned short minute; ///< The minute of the time duration or time of day (0-59).
    unsigned short second; ///< The second of the time duration or time of day (0-59).

public:
    /**
     * @brief Default constructor initializing to an undefined time.
     */
    Time();

    /**
     * @brief Constructs a Time object with the specified hours, minutes, and seconds.
     * @param hour The hour of the time (0-23).
     * @param minute The minute of the time (0-59).
     * @param second The second of the time (0-59).
     */
    Time(unsigned short hour, unsigned short minute, unsigned short second);

    /**
     * @brief Converts a time duration in hours (as a double) to a Time object.
     * @param hours The time duration in hours.
     * @return A Time object representing the duration.
     */
    static Time from(double hours);

    /**
     * @brief Overloaded output stream operator for Time.
     * @param out The output stream.
     * @param time The Time object to be output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Time& time);
};
