#include "grade.h" 

std::ostream& operator<<(std::ostream& ost, const Grade& grade){

	std::map<Grade, std::string> m = {{Grade::A, "A"},{Grade::B, "B"},{Grade::C, "C"},{Grade::D, "D"},{Grade::F, "F"},{Grade::I, "I"},{Grade::X, "X"}};  

	ost << m[grade]; 	
	return ost; 

} 

Grade load_grade(std::istream& ist){

	std::string sub; 
	std::getline(ist, sub); 

	std::map<std::string, Grade> v = {{"A", Grade::A},{"B", Grade::B},{"C", Grade::C}, {"D", Grade::D}, {"F", Grade::F}, {"I", Grade::I}, {"X", Grade::X}}; 
	
	return v[sub]; 

} 
