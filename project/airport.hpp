#include "project_fwd_def.hpp"
#include "enumerable.hpp"
#include <iostream>
#include <string>
#include <vector>

class Airport : public IEnumerable
{
	std::string city;
	std::string airport;
	std::string location;
	std::vector<double> lane_lengths;
	double fuel_cost_per_liter;
	std::vector<Flight*> scheduled_flights;

	Airport(
		std::string city,
		std::string airport,
		std::string location,
		std::vector<double> lane_lengths,
		double fuel_cost_per_liter,
		const std::vector<Flight*>& scheduled_flights);

public:
	const std::string& get_city() const;
	const std::string& get_airport() const;
	const std::string& get_location() const;
	const std::vector<double>& get_lane_lengths() const;
	double get_fuel_cost_per_liter() const;
	const std::vector<Flight*>& get_scheduled_flights() const;

	friend class AirSpaceManager;
	friend std::ostream& operator<<(std::ostream& out, const Airport& airport);
};
