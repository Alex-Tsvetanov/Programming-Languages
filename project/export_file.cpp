#include "export_file.hpp"

ExportFile::ExportFile(const std::string& filename) { out.open(filename, std::ios::out); }
ExportFile::~ExportFile() { out.close(); }