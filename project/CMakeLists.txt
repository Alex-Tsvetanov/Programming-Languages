cmake_minimum_required(VERSION 3.15...3.30)

project(
  ProgrammingLanguageCourseProject
  VERSION 1.0
  LANGUAGES CXX
)

set(Enumerable enumerable.cpp enumerable.hpp)

set(DateTime date_time.cpp date_time.hpp)

set(Airport airport.cpp airport.hpp)

set(Flight flight.cpp flight.hpp)

set(Plane plane.cpp plane.hpp)

set(AirspaceManager airspace_manager.cpp airspace_manager.hpp)

# Adding something we can run - Output name matches target name
add_executable(project main.cpp ${AirspaceManager} ${Enumerable} ${DateTime} ${Airport} ${Flight} ${Plane})
