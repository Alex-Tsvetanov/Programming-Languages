/**
 * @file plane.hpp
 * @brief Contains the declaration of the Plane class and its methods.
 */

#pragma once
#include "project_fwd_def.hpp"
#include "enumerable.hpp"
#include <string>

/**
 * @class Plane
 * @brief Represents an aircraft with details for efficient airline management.
 *
 * The Plane class encapsulates data about the manufacturer, model, seating capacity,
 * minimum runway length, operational costs, fuel consumption, tank volume, and average speed.
 */
class Plane : public IEnumerable
{
    /**
     * @brief Manufacturer of the plane.
     */
    std::string manufacturer;

    /**
     * @brief Model of the plane.
     */
    std::string model;

    /**
     * @brief Number of seats in the plane.
     */
    unsigned short seats;

    /**
     * @brief Minimum runway length required for takeoff and landing.
     */
    double min_lane_length;

    /**
     * @brief Staff costs per hour for operating the plane.
     */
    double staff_costs_per_hour;

    /**
     * @brief Fuel consumption in liters per kilometer per seat.
     */
    double liters_per_km;

    /**
     * @brief Maximum fuel tank volume in liters.
     */
    double tank_volume;

    /**
     * @brief Average speed of the plane in kilometers per hour.
     */
    double average_speed;

    /**
     * @brief Private default constructor.
     * Used internally for specific purposes.
     */
    Plane();

public:
    /**
     * @brief Checks if the plane can land on a given airport.
     * @param airport The airport to check compatibility with.
     * @return True if the plane can land, false otherwise.
     */
    bool can_land_on(const Airport& airport) const;

    /**
     * @brief Calculates the maximum flight distance for the plane.
     * @return The maximum distance the plane can travel in kilometers.
     */
    double max_flight_distance() const;

    /**
     * @brief Retrieves the average speed of the plane.
     * @return The average speed in kilometers per hour.
     */
    double get_average_speed() const;

    /**
     * @brief Overloaded output stream operator for Plane.
     * Outputs the details of the plane to the provided stream.
     * @param out The output stream.
     * @param plane The plane object to be output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Plane& plane);

    /**
     * @brief Declares AirSpaceManager as a friend class.
     * Allows access to the private and protected members of Plane.
     */
    friend class AirSpaceManager;
};
