#pragma once
#include "project_fwd_def.hpp"
#include "date_time.hpp"
#include "enumerable.hpp"
#include <iostream>

class Flight : public IEnumerable
{
	// дата на полета
	DateTime takeoff_datetime;
	// дължина на маршрута
	double path_length;
	// Начална точка
	const Airport* from;
	// Крайна дестинация
	const Airport* to;
	// Самолет, който ще осъществи полета
	const Plane* plane;

	Flight(DateTime date_time, double _path_length);

public:
	bool assign_plane(const Plane& candidate);

	bool set_from(const Airport& from);

	bool set_to(const Airport& to);

	// натовареността на пилотите
	double exhaust_rate() const;
	double exhaust_rate(const Plane* _plane) const;

	// продължителността на полетите
	double flight_duration() const;

	friend class AirSpaceManager;
	friend std::ostream& operator<<(std::ostream& out, const Flight& flight);
};
