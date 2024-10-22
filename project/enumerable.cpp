#include "enumerable.hpp"

IEnumerable::IEnumerable()
{
	id = next_id++;
}

inline unsigned int IEnumerable::get_id() const
{
	return id;
}

unsigned int IEnumerable::next_id = 0;
