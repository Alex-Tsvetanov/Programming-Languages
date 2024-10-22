#pragma once
#include "project_fwd_def.hpp"

class IEnumerable
{
	static unsigned int next_id;
	unsigned int id;

public:
	IEnumerable();
	inline unsigned int get_id() const;
	friend class AirSpaceManager;
};
