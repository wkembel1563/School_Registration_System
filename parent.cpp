#include "parent.h" 
#include "student.h" 

// PARENT::PARENT CONSTRUCTOR
Parent::Parent(std::string name, std::string email) : Person(name, email){}

// STUDENT::STUDENT CONSTRUCTOR - reading from file 
Parent::Parent(std::istream &ist) : Person("", ""){

	getline(ist, _name); 
	ist >> _email; ist.ignore(); 

}

// PARENT::ADD_STUDENT - adds ptr to new student 
void Parent::add_student(Student& student){

	// add address of new Parent to vector	
	_students.push_back(&student); 

} 

// PARENT::FULL_INFO - adds students names to output
std::string Parent::full_info(){ 

	int SIZE = _students.size(); 

	// get person output
	std::string person_info = Person::full_info(); 

	return person_info;  
} 

// PARENT::SAVE - saves all the parents info to an output stream argument
void Parent::save(std::ostream& ost){

	// save name, email in that order
	ost << _name << std::endl; 
	ost << _email << std::endl; 

}
