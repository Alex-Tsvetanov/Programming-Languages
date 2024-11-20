#include "airspace_manager.hpp"
#include "plane.hpp"

Airport& AirSpaceManager::create_airport(std::string city, std::string airport, std::string location,
                                         std::vector<double> lane_lengths, double fuel_cost_per_liter)
{
	Airport* new_airport = new Airport(city, airport, location, lane_lengths, fuel_cost_per_liter, {});
	airports.push_back(new_airport);
	return *new_airport;
}

Flight& AirSpaceManager::create_flight(DateTime date_time, double path_length)
{
	Flight* new_flight = new Flight(date_time, path_length);
	flights.push_back(new_flight);
	return *new_flight;
}

Plane& AirSpaceManager::create_plane(std::string manufacturer, std::string model, unsigned short seats,
                                     double min_lane_length, double staff_costs_per_hour, double liters_per_km,
                                     double tank_volume, double average_speed)
{
	Plane* new_plane = new Plane();
	new_plane->manufacturer = manufacturer;
	new_plane->model = model;
	new_plane->seats = seats;
	new_plane->min_lane_length = min_lane_length;
	new_plane->staff_costs_per_hour = staff_costs_per_hour;
	new_plane->liters_per_km = liters_per_km;
	new_plane->tank_volume = tank_volume;
	new_plane->average_speed = average_speed;
	planes.push_back(new_plane);
	return *new_plane;
}

AirSpaceManager::AirSpaceManager() {}

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
assign_plane<Enter>     - to assign a plane to execute a given flight
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
		else if (command == "assign_plane")
		{
			assign_plane();
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
	const Plane& plane = create_plane(manufacturer, model, seats, min_lane_length, staff_costs_per_hour, liters_per_km,
	                                  tank_volume, average_speed);
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
	DateTime takeoff_datetime;
	std::cout << "Enter takeoff date and time (DD.MM.YYYY HH:MM:SS): " << std::flush;
	scanf("%hu.%hu.%hu %hu:%hu:%hu", &takeoff_datetime.day, &takeoff_datetime.month, &takeoff_datetime.year,
	      &takeoff_datetime.hour, &takeoff_datetime.minute, &takeoff_datetime.second);

	double path_length;
	std::cout << "Enter flight's path length: " << std::flush;
	std::cin >> path_length;
	auto& new_flight = create_flight(takeoff_datetime, path_length);

	if (airports.size() < 2)
	{
		std::cout << "Not enough airports added. Please add new airports and assigned them to flight #"
		          << new_flight.get_id() << std::endl;
	}

	for (int i = 0; i < airports.size(); i++)
	{
		std::cout << i + 1 << ") " << *airports[i] << std::endl;
	}
	std::cout << "Choose airports between will be the flight by entering their numbers: " << std::endl;
	size_t from;
	std::cin >> from;
	size_t to;
	std::cin >> to;
	new_flight.from = airports[from - 1];
	new_flight.to = airports[to - 1];
}

void AirSpaceManager::search_for_plane()
{
	if (flights.size() == 0)
	{
		std::cout << "No flights added. Create new flight first." << std::endl;
		return;
	}
	for (int i = 0; i < flights.size(); i++)
	{
		std::cout << i + 1 << ") " << *flights[i] << std::endl;
	}
	std::cout << "Which flight are you interested in? (enter their number)" << std::endl;
	size_t flight_ind;
	std::cin >> flight_ind;
	const auto& flight = flights[flight_ind - 1];

	std::vector<size_t> planes_able_to_execute_the_flight;
	for (int i = 0; i < planes.size(); i++)
	{
		if (planes[i]->can_land_on(*(flight->from)))
		{
			if (planes[i]->can_land_on(*(flight->to)))
			{
				if (planes[i]->max_flight_distance() >= flight->path_length)
				{
					planes_able_to_execute_the_flight.push_back(i);
				}
				else
				{
					std::cout << planes[i] << " cannot execute the flight, due to not having enough fuel in the tank. ("
					          << planes[i]->max_flight_distance() << " < " << flight->path_length << ")\n";
				}
			}
			else
			{
				std::cout << planes[i] << " cannot execute the flight, due to not being able to land in " << *flight->to
				          << ".\n";
			}
		}
		else
		{
			std::cout << planes[i] << " cannot execute the flight, due to not being able to take off from "
			          << *flight->from << ".\n";
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
		std::cout << i + 1 << ") " << *planes[i] << " with exhaust rate of " << flight->exhaust_rate(planes[i])
		          << " and costs of " << flight->flight_duration() * planes[i]->staff_costs_per_hour << std::endl;
	}
}

void AirSpaceManager::assign_plane()
{
	if (flights.size() == 0)
	{
		std::cout << "No flights to assign plane to. Create new flight first." << std::endl;
		return;
	}
	for (int i = 0; i < flights.size(); i++)
	{
		std::cout << i + 1 << ") " << *flights[i] << std::endl;
	}
	std::cout << "Which flight are you interested in? (enter their number)" << std::endl;
	size_t flight_ind;
	std::cin >> flight_ind;
	const auto& flight = flights[flight_ind - 1];

	std::vector<size_t> planes_able_to_execute_the_flight;
	for (int i = 0; i < planes.size(); i++)
	{
		if (planes[i]->can_land_on(*(flight->from)))
		{
			if (planes[i]->can_land_on(*(flight->to)))
			{
				if (planes[i]->max_flight_distance() >= flight->path_length)
				{
					planes_able_to_execute_the_flight.push_back(i);
				}
				else
				{
					std::cout << planes[i] << " cannot execute the flight, due to not having enough fuel in the tank. ("
					          << planes[i]->max_flight_distance() << " < " << flight->path_length << ")\n";
				}
			}
			else
			{
				std::cout << planes[i] << " cannot execute the flight, due to not being able to land in " << *flight->to
				          << ".\n";
			}
		}
		else
		{
			std::cout << planes[i] << " cannot execute the flight, due to not being able to take off from "
			          << *flight->from << ".\n";
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
		std::cout << i + 1 << ") " << *planes[i] << " with exhaust rate of " << flight->exhaust_rate(planes[i])
		          << " and costs of " << flight->flight_duration() * planes[i]->staff_costs_per_hour << std::endl;
	}

	std::cout << "Which plane do you want to assign? (enter their number)" << std::endl;
	size_t assigned_plane_index;
	std::cin >> assigned_plane_index;

	flight->assign_plane(*planes[planes_able_to_execute_the_flight[assigned_plane_index - 1]]);
	std::cout << "Done" << std::endl;
}

void AirSpaceManager::read()
{
	std::string file_locaiton;
	std::cout << "Enter full path to the previously exported file:" << std::flush;
	std::cin >> file_locaiton;
	std::ifstream in(file_locaiton);
	size_t planes_number;
	in >> planes_number;
	for (auto*& plane : planes)
	{
		delete plane;
		plane = nullptr;
	}
	planes.resize(planes_number);
	for (size_t i = 0; i < planes_number; i++)
	{
		Plane* plane = planes[i] = new Plane();
		in >> plane->id;
		in >> plane->manufacturer;
		in >> plane->model;
		in >> plane->seats;
		in >> plane->min_lane_length;
		in >> plane->staff_costs_per_hour;
		in >> plane->liters_per_km;
		in >> plane->tank_volume;
		in >> plane->average_speed;
	}
	size_t airports_number;
	in >> airports_number;
	for (auto*& airport : airports)
	{
		delete airport;
		airport = nullptr;
	}
	airports.resize(airports_number);
	for (auto* airport : airports)
	{
		in >> airport->city;
		in >> airport->airport;
		in >> airport->location;
		size_t lane_lengths_number;
		double x;
		for (size_t i = 0; i < lane_lengths_number; i++)
		{
			in >> x;
			airport->lane_lengths.push_back(x);
		}
		in >> airport->fuel_cost_per_liter;
		// out << airport->scheduled_flights << std::endl;
	}
}
void AirSpaceManager::write()
{
	std::string file_locaiton;
	std::cout << "Enter full path to the file where the export data should be saved:" << std::flush;
	std::cin >> file_locaiton;
	std::ofstream out(file_locaiton);
	out << planes.size() << std::endl;
	for (auto* plane : planes)
	{
		out << plane->get_id() << std::endl;
		out << plane->manufacturer << std::endl;
		out << plane->model << std::endl;
		out << plane->seats << std::endl;
		out << plane->min_lane_length << std::endl;
		out << plane->staff_costs_per_hour << std::endl;
		out << plane->liters_per_km << std::endl;
		out << plane->tank_volume << std::endl;
		out << plane->average_speed << std::endl;
	}
	out << airports.size() << std::endl;
	for (auto* airport : airports)
	{
		out << airport->city << std::endl;
		out << airport->airport << std::endl;
		out << airport->location << std::endl;
		out << airport->lane_lengths.size() << std::endl;
		for (auto x : airport->lane_lengths) out << x << std::endl;
		out << airport->fuel_cost_per_liter << std::endl;
		// out << airport->scheduled_flights << std::endl;
	}
	out << flights.size() << std::endl;
	for (auto* flight : flights)
	{
	}
}