/**
 * @file flight.hpp
 * @brief Contains the declaration of the Flight class, representing a flight with associated data and operations.
 */

#pragma once
#include "project_fwd_def.hpp"
#include "date_time.hpp"
#include "enumerable.hpp"
#include <iostream>

/**
 * @class Flight
 * @brief Represents a flight, including its schedule, route, and assigned plane.
 * 
 * The Flight class encapsulates details about a specific flight, such as the takeoff time,
 * route length, origin and destination airports, and the plane assigned to the flight.
 * It also provides methods to calculate workload and flight duration.
 */
class Flight : public IEnumerable
{
    DateTime takeoff_datetime; ///< The scheduled takeoff date and time.
    double path_length; ///< The length of the flight route in kilometers.
    const Airport* from; ///< The origin airport of the flight.
    const Airport* to; ///< The destination airport of the flight.
    const Plane* plane; ///< The plane assigned to execute the flight.

    /**
     * @brief Constructs a Flight object with the given date/time and route length.
     * @param date_time The takeoff date and time.
     * @param _path_length The length of the flight route in kilometers.
     */
    Flight(DateTime date_time, double _path_length);

public:
    /**
     * @brief Assigns a plane to the flight if it meets the necessary criteria.
     * @param candidate The plane to be considered for assignment.
     * @return True if the plane was successfully assigned, false otherwise.
     */
    bool assign_plane(const Plane& candidate);

    /**
     * @brief Sets the origin airport for the flight.
     * @param from The airport object representing the flight's origin.
     * @return True if the origin was set successfully, false otherwise.
     */
    bool set_from(const Airport& from);

    /**
     * @brief Sets the destination airport for the flight.
     * @param to The airport object representing the flight's destination.
     * @return True if the destination was set successfully, false otherwise.
     */
    bool set_to(const Airport& to);

    /**
     * @brief Calculates the workload for the pilot(s) during this flight.
     * @return The workload as a percentage.
     */
    double exhaust_rate() const;

    /**
     * @brief Calculates the workload for a given plane during this flight.
     * @param _plane The plane to evaluate.
     * @return The workload as a percentage for the specified plane.
     */
    double exhaust_rate(const Plane* _plane) const;

    /**
     * @brief Calculates the flight duration based on the route length and plane speed.
     * @return The flight duration in hours.
     */
    double flight_duration() const;

    /**
     * @brief Overloaded output stream operator for Flight.
     * @param out The output stream.
     * @param flight The Flight object to be output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Flight& flight);

    /**
     * @brief Declares AirSpaceManager as a friend class to access private members.
     */
    friend class AirSpaceManager;
};
