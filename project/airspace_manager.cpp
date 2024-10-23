#include "airspace_manager.hpp"
#include "plane.hpp"

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

Plane& AirSpaceManager::create_plane(
	std::string manufacturer,
	std::string model,
	unsigned short seats,
	double min_lane_length,
	double staff_costs_per_hour,
	double liters_per_km,
	double tank_volume,
	double average_speed)
{
	Plane* new_plane = new Plane();
	planes.push_back(new_plane);
	new_plane->manufacturer = manufacturer;
	new_plane->model = model;
	new_plane->seats = seats;
	new_plane->min_lane_length = min_lane_length;
	new_plane->staff_costs_per_hour = staff_costs_per_hour;
	new_plane->liters_per_km = liters_per_km;
	new_plane->tank_volume = tank_volume;
	new_plane->average_speed = average_speed;
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

void AirSpaceManager::help()
{
	std::cout <<
		R"(Valid commands:
new airport<Enter>      - to add new airport
new plane<Enter>        - to add new plane
new flight<Enter>       - to add new flight
search_for_plane<Enter> - to find planes able to do a given flight
)";
}

void AirSpaceManager::run()
{
	std::string command;
	do
	{
		help();
		std::cin >> command;
		if (command == "new")
		{
			std::cin >> command;
			std::string x;
			std::getline(std::cin, x);
			if (command == "airport")
			{
				input_airport();
			}
			else if (command == "plane")
			{
				input_plane();
			}
			else if (command == "flight")
			{
				input_flight();
			}
		}
		else if (command == "search_for_plane")
		{
			search_for_plane();
		}
	} while (command != "end");
}

void AirSpaceManager::input_plane()
{
	std::string manufacturer;
	std::string model;
	unsigned short seats;
	double min_lane_length;
	double staff_costs_per_hour;
	double liters_per_km;
	double tank_volume;
	double average_speed;
	std::cout << "Enter plane's manufacturer: " << std::flush;
	std::cin >> manufacturer;
	std::cout << "Enter plane's model: " << std::flush;
	std::cin >> model;
	std::cout << "Enter plane's seats: " << std::flush;
	std::cin >> seats;
	std::cout << "Enter plane's minimum lane length required: " << std::flush;
	std::cin >> min_lane_length;
	std::cout << "Enter plane's costs for staff per hour: " << std::flush;
	std::cin >> staff_costs_per_hour;
	std::cout << "Enter plane's liters fuel per km required: " << std::flush;
	std::cin >> liters_per_km;
	std::cout << "Enter plane's tank volume: " << std::flush;
	std::cin >> tank_volume;
	std::cout << "Enter plane's average speed: " << std::flush;
	std::cin >> average_speed;
	const Plane& plane = create_plane(manufacturer, model, seats, min_lane_length, staff_costs_per_hour, liters_per_km, tank_volume, average_speed);
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
	if (lane_lengths.size() == 0)
	{
		std::cout << "You cannot have airport with no lanes. The creation of this airport is cancelled." << std::endl;
		return;
	}
	std::cout << "Enter the cost of 1 liter fuel: " << std::flush;
	std::cin >> fuel_cost_per_liter;
	const Airport& obj = create_airport(city, airport, location, lane_lengths, fuel_cost_per_liter);
	std::cout << "The airport " << obj << " was created." << std::endl;
}

void AirSpaceManager::input_flight()
{
	// дата на полета
	DateTime takeoff_datetime;
	std::cout << "Enter takeoff date and time (DD.MM.YYYY HH:MM:SS): " << std::flush;
	scanf(
		"%hu.%hu.%hu %hu:%hu:%hu",
		&takeoff_datetime.day,
		&takeoff_datetime.month,
		&takeoff_datetime.year,
		&takeoff_datetime.hour,
		&takeoff_datetime.minute,
		&takeoff_datetime.second);

	// дължина на маршрута
	double path_length;
	std::cout << "Enter flight's path length: " << std::flush;
	std::cin >> path_length;
	auto& new_flight = create_flight(takeoff_datetime, path_length);

	if (airports.size() < 2)
	{
		std::cout << "Not enough airports added. Please add new airports and assigned them to flight #" << new_flight.get_id() << std::endl;
	}

	for (int i = 0; i < airports.size(); i++)
	{
		std::cout << i + 1 << ") " << *airports[i] << std::endl;
	}
	std::cout << "Choose airports between will be the flight by entering their numbers: " << std::endl;
	// Начална точка
	size_t from;
	std::cin >> from;
	// Крайна дестинация
	size_t to;
	std::cin >> to;
	new_flight.from = airports[from - 1];
	new_flight.to = airports[to - 1];
}

void AirSpaceManager::search_for_plane()
{
	for (int i = 0; i < flights.size(); i++)
	{
		std::cout << i + 1 << ") " << *flights[i] << std::endl;
	}
	if (flights.size() == 0)
	{
		std::cout << "No flights added. Create new flight first." << std::endl;
		return;
	}
	std::cout << "Which flight are you interested in? (enter their number)" << std::endl;
	size_t flight_ind;
	std::cin >> flight_ind;
	const auto& flight = flights[flight_ind - 1];

	std::vector<size_t> planes_able_to_execute_the_flight;
	for (int i = 0; i < planes.size(); i++)
	{
		if (planes[i]->can_land_on(*(flight->from)) && planes[i]->can_land_on(*(flight->to)) && planes[i]->max_flight_distance() >= flight->path_length)
		{
			planes_able_to_execute_the_flight.push_back(i);
		}
	}

	if (planes_able_to_execute_the_flight.size() == 0)
	{
		std::cout << "No planes added. There are no planes to execute the flight." << std::endl;
		return;
	}

	std::cout << "Here are the plane able to execute this flight:" << std::endl;
	for (size_t i : planes_able_to_execute_the_flight)
	{
		std::cout << i + 1 << ") " << *planes[i] << " with exhaust rate of " << flight->exhaust_rate(planes[i]) << " and costs of "
				  << flight->flight_duration() * planes[i]->staff_costs_per_hour << std::endl;
	}
}
