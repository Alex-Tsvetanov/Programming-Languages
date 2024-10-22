#include "airport.hpp"
#include "date_time.hpp"
#include "flight.hpp"
#include "plane.hpp"
#include <ostream>

Airport::Airport(
	std::string city,
	std::string airport,
	std::string location,
	std::vector<double> lane_lengths,
	double fuel_cost_per_liter,
	const std::vector<Flight*>& scheduled_flights)
	: IEnumerable()
{
	this->city = city;
	this->airport = airport;
	this->location = location;
	this->lane_lengths = lane_lengths;
	this->fuel_cost_per_liter = fuel_cost_per_liter;
	this->scheduled_flights = scheduled_flights;
}

const std::string& Airport::get_city() const
{
	return city;
}

const std::string& Airport::get_airport() const
{
	return airport;
}

const std::string& Airport::get_location() const
{
	return location;
}

const std::vector<double>& Airport::get_lane_lengths() const
{
	return lane_lengths;
}

double Airport::get_fuel_cost_per_liter() const
{
	return fuel_cost_per_liter;
}

const std::vector<Flight*>& Airport::get_scheduled_flights() const
{
	return scheduled_flights;
}

std::ostream& operator<<(std::ostream& out, const Airport& airport)
{
	out << "("
		<< "id: " << airport.get_id() << ", city: " << airport.get_city() << ", airport: " << airport.get_airport() << ", location: " << airport.get_location()
		<< ", scheduled flights: " << airport.get_scheduled_flights().size() << ", cost of fuel per liter: " << airport.get_fuel_cost_per_liter() << ")";
	return out;
}
