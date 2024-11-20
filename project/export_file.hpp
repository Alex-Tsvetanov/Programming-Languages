/**
 * @file export_file.hpp
 * @brief Contains a wrapper for export file.
 */

#include <fstream>
#include <string>
#include <sstream>
#include "date_time.hpp"
#include "airport.hpp"
#include "plane.hpp"
#include "flight.hpp"

class ExportFile
{
	std::ofstream out;

public:
	ExportFile(const std::string&);
	~ExportFile();
};