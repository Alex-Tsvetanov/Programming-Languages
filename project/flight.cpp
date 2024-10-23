#include "airport.hpp"
#include "date_time.hpp"
#include "flight.hpp"
#include "plane.hpp"

Flight::Flight(DateTime date_time, double _path_length) : IEnumerable(), takeoff_datetime(date_time), path_length(_path_length)
{
}

bool Flight::assign_plane(const Plane& candidate)
{
	if (from != nullptr && !candidate.can_land_on(*from))
	{
		return false;
	}
	if (to != nullptr && !candidate.can_land_on(*to))
	{
		return false;
	}
	plane = &candidate;
	return true;
}

bool Flight::set_from(const Airport& from)
{
	if (plane != nullptr && !plane->can_land_on(from))
	{
		return false;
	}
	this->from = &from;
	return true;
}

bool Flight::set_to(const Airport& to)
{
	if (plane != nullptr && !plane->can_land_on(to))
	{
		return false;
	}
	this->to = &to;
	return true;
}

// натовареността на пилотите
double Flight::exhaust_rate() const
{
	return exhaust_rate(this->plane);
}

double Flight::exhaust_rate(const Plane* _plane) const
{
	if (_plane == nullptr)
	{
		return std::numeric_limits<double>::quiet_NaN();
	}
	return _plane->get_average_speed() * path_length;
}

// продължителността на полетите
double Flight::flight_duration() const
{
	if (plane == nullptr)
	{
		return std::numeric_limits<double>::quiet_NaN();
	}
	return path_length / plane->get_average_speed();
}

std::ostream& operator<<(std::ostream& out, const Flight& flight)
{
	out << "Flight " << flight.get_id() << " from " << flight.from->get_location() << ", " << flight.from->get_city() << " to " << flight.to->get_location()
		<< ", " << flight.to->get_city() << " with length of " << flight.path_length << " will take off at " << flight.takeoff_datetime << " local time"
		<< " by " << *flight.plane << " and will take " << Time::from(flight.flight_duration());
	return out;
}
