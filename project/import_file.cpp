#include "import_file.hpp"

ImportFile::ImportFile(const std::string& filename) { out.open(filename, std::ios::out); }
ImportFile::~ImportFile() { out.close(); }