/**
 * @file import_file.hpp
 * @brief Contains a wrapper for import file.
 */

#include <fstream>
#include <string>
#include <sstream>
#include "date_time.hpp"
#include "airport.hpp"
#include "plane.hpp"
#include "flight.hpp"

class ImportFile
{
	std::ofstream out;

public:
	ImportFile(const std::string&);
	~ImportFile();
};