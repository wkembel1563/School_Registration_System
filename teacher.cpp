#include "teacher.h" 

Teacher::Teacher(std::string name, std::string email) : Person(name, email) {} 

Teacher::Teacher(std::istream& ist) : Person("", "") {

	getline(ist, _name); 
	ist >> _email; ist.ignore(); 

} 

void Teacher::save(std::ostream& ost){

	ost << _name << std::endl; 
	ost << _email << std::endl; 

} 

std::string Teacher::full_info(){

	std::string info = Person::full_info(); 

	return info; 

}  		
