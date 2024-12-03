/**
 * @file airport.hpp
 * @brief Contains the declaration of the Airport class and its methods.
 */

#include "project_fwd_def.hpp"
#include "enumerable.hpp"
#include <iostream>
#include <string>
#include <vector>

/**
 * @class Airport
 * @brief Represents an airport with details such as city, name, location, lane lengths, fuel cost, and scheduled flights.
 * 
 * This class provides methods to access airport-related information and handles its associated data.
 */
class Airport : public IEnumerable
{
    /**
     * @brief The city where the airport is located.
     */
    std::string city;

    /**
     * @brief The name of the airport.
     */
    std::string airport;

    /**
     * @brief The geographical location of the airport.
     */
    std::string location;

    /**
     * @brief The lengths of the lanes available at the airport.
     */
    std::vector<double> lane_lengths;

    /**
     * @brief The cost of fuel per liter at the airport.
     */
    double fuel_cost_per_liter;

    /**
     * @brief The list of scheduled flights at the airport.
     */
    std::vector<Flight*> scheduled_flights;

    /**
     * @brief Constructs an Airport object with detailed information.
     * 
     * @param city The city where the airport is located.
     * @param airport The name of the airport.
     * @param location The geographical location of the airport.
     * @param lane_lengths The lengths of the lanes available at the airport.
     * @param fuel_cost_per_liter The cost of fuel per liter at the airport.
     * @param scheduled_flights The list of scheduled flights.
     */
    Airport(
        std::string city,
        std::string airport,
        std::string location,
        std::vector<double> lane_lengths,
        double fuel_cost_per_liter,
        const std::vector<Flight*>& scheduled_flights);

public:
    /**
     * @brief Gets the city where the airport is located.
     * @return A constant reference to the city name.
     */
    const std::string& get_city() const;

    /**
     * @brief Gets the name of the airport.
     * @return A constant reference to the airport name.
     */
    const std::string& get_airport() const;

    /**
     * @brief Gets the geographical location of the airport.
     * @return A constant reference to the location.
     */
    const std::string& get_location() const;

    /**
     * @brief Gets the lengths of the lanes at the airport.
     * @return A constant reference to a vector containing the lane lengths.
     */
    const std::vector<double>& get_lane_lengths() const;

    /**
     * @brief Gets the cost of fuel per liter at the airport.
     * @return The fuel cost per liter.
     */
    double get_fuel_cost_per_liter() const;

    /**
     * @brief Gets the list of scheduled flights at the airport.
     * @return A constant reference to a vector of pointers to Flight objects.
     */
    const std::vector<Flight*>& get_scheduled_flights() const;

    /**
     * @brief Allows AirSpaceManager to access private members of the Airport class.
     */
    friend class AirSpaceManager;

    /**
     * @brief Outputs the details of the Airport object to an output stream.
     * 
     * @param out The output stream to write to.
     * @param airport The Airport object to output.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Airport& airport);
};
