#include "airport.hpp"
#include "enumerable.hpp"
#include "plane.hpp"

Plane::Plane() : IEnumerable()
{
}

// Класът на самолета
bool Plane::can_land_on(const Airport& airport) const
{
	for (auto lane : airport.get_lane_lengths())
	{
		if (lane >= min_lane_length)
		{
			return true;
		}
	}
	return false;
}

// За оценка на максималната далечина на полета
double Plane::max_flight_distance() const
{
	return tank_volume / liters_per_km;
}

double Plane::get_average_speed() const
{
	return average_speed;
}
