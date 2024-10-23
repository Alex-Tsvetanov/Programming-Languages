#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "date_time.hpp"
#include "airport.hpp"
#include "plane.hpp"
#include "flight.hpp"

class AirSpaceManager
{
	std::vector<Flight*> flights;
	std::vector<Plane*> planes;
	std::vector<Airport*> airports;

	Airport& create_airport(std::string city, std::string airport, std::string location, std::vector<double> lane_lengths, double fuel_cost_per_liter);

	Flight& create_flight(DateTime date_time, double path_length);

	Plane& create_plane(
		std::string manufacturer,
		std::string model,
		unsigned short seats,
		double min_lane_length,
		double staff_costs_per_hour,
		double liters_per_km,
		double tank_volume,
		double average_speed);

	void help();

	void search_for_plane();

public:
	AirSpaceManager();

	~AirSpaceManager();

	void input_airport();

	void input_plane();

	void input_flight();

	void run();
};
