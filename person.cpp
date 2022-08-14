#include "person.h" 


// PERSON::PERSON CONSTRUCTOR
Person::Person(std::string name, std::string email) : _name{name}, _email{email}  {} 

// PERSON::TO_STRING - returns person's name
std::string Person::to_string(){ return _name; } 

// PERSON::FULL_INFO - returns "name (email)"
std::string Person::full_info(){ return _name + " (" + _email + ")"; } 

// PERSON COUT OPERATOR - returns name
std::ostream& operator<<(std::ostream& ost, const Person& person){
	ost << person._name; 
	return ost; 
} 
