#pragma once
#include "project_fwd_def.hpp"

class IEnumerable
{
	static unsigned int next_id;
	unsigned int id;

public:
	IEnumerable()
	{
		id = next_id++;
	}
	virtual inline unsigned int get_id() const final
	{
		return id;
	}
	friend class AirSpaceManager;
};
