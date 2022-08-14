#include "semester.h"
#include <map> 

// OPERATOR << OVERLOAD
std::ostream& operator<<(std::ostream& ost, const Semester& semester){


	// map of semesters
	std::map<Semester, std::string> v = {{Semester::FALL, "fall"},{Semester::SPRING, "spring"},{Semester::SUMMER, "summer"}}; 

	// output string corresponding to semester
	ost << v[semester]; 

	return ost; 
		

} 

// LOAD SUBJECT FROM INPUT FILE STREAM 
Semester load_semester(std::istream& ist){

	std::string sub; 
	std::getline(ist, sub); 

	std::map<std::string, Semester> v = {{"fall", Semester::FALL},{"spring", Semester::SPRING},{"summer", Semester::SUMMER}}; 
	return v[sub]; 

} 
