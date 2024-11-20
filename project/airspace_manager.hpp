/**
 * @file airspace_manager.hpp
 * @brief Contains the declaration of the AirSpaceManager class and its methods for managing airports, planes, and
 * flights.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "date_time.hpp"
#include "airport.hpp"
#include "plane.hpp"
#include "flight.hpp"
#include "export_file.hpp"
#include "import_file.hpp"

/**
 * @class AirSpaceManager
 * @brief A class to manage airports, planes, and flights for optimizing airline resources.
 */
class AirSpaceManager
{
	/**
	 * @brief A list of all flights managed by the application.
	 */
	std::vector<Flight*> flights;

	/**
	 * @brief A list of all planes managed by the application.
	 */
	std::vector<Plane*> planes;

	/**
	 * @brief A list of all airports managed by the application.
	 */
	std::vector<Airport*> airports;

	/**
	 * @brief Creates a new airport and adds it to the managed list.
	 * @param city The city where the airport is located.
	 * @param airport The name of the airport.
	 * @param location The location of the airport.
	 * @param lane_lengths The lengths of the runways available at the airport.
	 * @param fuel_cost_per_liter The cost of fuel per liter at the airport.
	 * @return Reference to the newly created airport.
	 */
	Airport& create_airport(std::string city, std::string airport, std::string location,
	                        std::vector<double> lane_lengths, double fuel_cost_per_liter);

	/**
	 * @brief Creates a new flight and adds it to the managed list.
	 * @param date_time The departure date and time of the flight.
	 * @param path_length The length of the flight path in kilometers.
	 * @return Reference to the newly created flight.
	 */
	Flight& create_flight(DateTime date_time, double path_length);

	/**
	 * @brief Creates a new plane and adds it to the managed list.
	 * @param manufacturer The manufacturer of the plane.
	 * @param model The model of the plane.
	 * @param seats The number of seats available on the plane.
	 * @param min_lane_length The minimum runway length required for the plane.
	 * @param staff_costs_per_hour The hourly cost of the plane's staff.
	 * @param liters_per_km Fuel consumption in liters per kilometer per seat.
	 * @param tank_volume The fuel tank volume in liters.
	 * @param average_speed The average speed of the plane in km/h.
	 * @return Reference to the newly created plane.
	 */
	Plane& create_plane(std::string manufacturer, std::string model, unsigned short seats, double min_lane_length,
	                    double staff_costs_per_hour, double liters_per_km, double tank_volume, double average_speed);

	/**
	 * @brief Displays help information about using the application.
	 */
	void help();

	/**
	 * @brief Searches for planes compatible with a specific destination.
	 */
	void search_for_plane();

	/**
	 * @brief Assigns a plane to a given flight.
	 */
	void assign_plane();

	/**
	 * @brief Reads all the information about the airspace from an inputed file
	 *
	 */
	void read();

	/**
	 * @brief Writes all the information about the airspace to an inputed file
	 *
	 */
	void write();

public:
	/**
	 * @brief Default constructor for AirSpaceManager.
	 */
	AirSpaceManager();

	/**
	 * @brief Destructor for AirSpaceManager. Frees allocated memory.
	 */
	~AirSpaceManager();

	/**
	 * @brief Prompts the user to input details for a new airport.
	 */
	void input_airport();

	/**
	 * @brief Prompts the user to input details for a new plane.
	 */
	void input_plane();

	/**
	 * @brief Prompts the user to input details for a new flight.
	 */
	void input_flight();

	/**
	 * @brief Main entry point to run the AirSpaceManager application.
	 */
	void run();
};
