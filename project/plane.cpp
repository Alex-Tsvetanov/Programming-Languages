#include "airport.hpp"
#include "enumerable.hpp"
#include "plane.hpp"

Plane::Plane() : IEnumerable() {}

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

double Plane::max_flight_distance() const { return tank_volume / liters_per_km; }

double Plane::get_average_speed() const { return average_speed; }

std::ostream& operator<<(std::ostream& out, const Plane& plane)
{
	out << "Plane (" << plane.manufacturer << ", " << plane.model << ", " << plane.seats << ", "
	    << plane.min_lane_length << ", "

	    << plane.staff_costs_per_hour << ", " << plane.liters_per_km << ", "

	    << plane.tank_volume << ", "

	    << plane.average_speed << ")";
	return out;
}
