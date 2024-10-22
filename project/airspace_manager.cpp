#include "airspace_manager.hpp"

Airport& AirSpaceManager::create_airport(
	std::string city, std::string airport, std::string location, std::vector<double> lane_lengths, double fuel_cost_per_liter)
{
	Airport* new_airport = new Airport(city, airport, location, lane_lengths, fuel_cost_per_liter, {});
	airports.push_back(new_airport);
	new_airport->id = airports.size();
	return *new_airport;
}

Flight& AirSpaceManager::create_flight(DateTime date_time, double path_length)
{
	Flight* new_flight = new Flight(date_time, path_length);
	flights.push_back(new_flight);
	new_flight->id = airports.size();
	return *new_flight;
}

Plane& AirSpaceManager::create_plane()
{
	Plane* new_plane = new Plane();
	planes.push_back(new_plane);
	return *new_plane;
}

AirSpaceManager::AirSpaceManager()
{
}

AirSpaceManager::~AirSpaceManager()
{
	for (auto* flight : flights)
	{
		delete flight;
	}
	for (auto* plane : planes)
	{
		delete plane;
	}
	for (auto* airport : airports)
	{
		delete airport;
	}
}

void AirSpaceManager::run()
{
	std::string command;
	do
	{
		std::cin >> command;
		if (command == "new")
		{
			std::cin >> command;
			if (command == "airport")
			{
				input_airport();
			}
			else if (command == "plane")
			{
				input_plane();
			}
		}
		else if (command == "assign")
		{
		}
	} while (command != "end");
}

void AirSpaceManager::input_plane()
{
	std::string city;
	std::string airport;
	std::string location;
	std::string lanes;
	double fuel_cost_per_liter;
	std::vector<double> lane_lengths;
	std::cout << "Enter city: " << std::flush;
	std::getline(std::cin, city);
	std::cout << "Enter airport: " << std::flush;
	std::getline(std::cin, airport);
	std::cout << "Enter location: " << std::flush;
	std::getline(std::cin, location);
	std::cout << "Enter lanes: (on 1 line) " << std::flush;
	std::getline(std::cin, lanes);
	std::stringstream ss;
	ss << lanes;
	while (!ss.eof())
	{
		double lane;
		ss >> lane;
		lane_lengths.push_back(lane);
	}
	std::cout << "Enter the cost of 1 liter fuel: " << std::flush;
	std::cin >> fuel_cost_per_liter;
	const Airport& obj = create_airport(city, airport, location, lane_lengths, fuel_cost_per_liter);
	std::cout << "The airport " << obj << " was created." << std::endl;
}

void AirSpaceManager::input_airport()
{
	std::string city;
	std::string airport;
	std::string location;
	std::string lanes;
	double fuel_cost_per_liter;
	std::vector<double> lane_lengths;
	std::cout << "Enter city: " << std::flush;
	std::getline(std::cin, city);
	std::cout << "Enter airport: " << std::flush;
	std::getline(std::cin, airport);
	std::cout << "Enter location: " << std::flush;
	std::getline(std::cin, location);
	std::cout << "Enter lanes: (on 1 line) " << std::flush;
	std::getline(std::cin, lanes);
	std::stringstream ss;
	ss << lanes;
	while (!ss.eof())
	{
		double lane;
		ss >> lane;
		lane_lengths.push_back(lane);
	}
	std::cout << "Enter the cost of 1 liter fuel: " << std::flush;
	std::cin >> fuel_cost_per_liter;
	const Airport& obj = create_airport(city, airport, location, lane_lengths, fuel_cost_per_liter);
	std::cout << "The airport " << obj << " was created." << std::endl;
}
