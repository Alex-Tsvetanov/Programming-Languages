#pragma once
#include "project_fwd_def.hpp"
#include "enumerable.hpp"
#include <string>

// Класът на самолета
class Plane : public IEnumerable
{
	// производителя, модела, броя места и минималната дължина на пистата за кацане/излитане
	std::string manufacturer;
	std::string model;
	unsigned short seats;
	double min_lane_length;

	// разходите за необходимия персонал, разход на гориво за 1 километър на едно място
	double staff_costs_per_hour;
	double liters_per_km;

	// данни за обем на резервоара в литри
	double tank_volume;

	// средната скорост на самолетите от класа
	double average_speed;

	Plane();

public:
	bool can_land_on(const Airport& airport) const;

	// За оценка на максималната далечина на полета
	double max_flight_distance() const;

	double get_average_speed() const;

	friend class AirSpaceManager;
	friend std::ostream operator<<(std::ostream& out, const Plane& flight);
	friend std::istream operator>>(std::istream& out, Plane& flight);
};
