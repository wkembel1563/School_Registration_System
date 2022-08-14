#include "student.h" 
#include "parent.h"

// STUDENT::STUDENT CONSTRUCTOR
Student::Student(std::string name, std::string email, int grade) : Person(name, email), _grade{grade} {
	// check that grade is in range, if not throw error
	if(_grade < 1 || _grade > 12){
		std::cerr << to_string() << " Invalid Grade" << std::endl; 
	}
}

// STUDENT::STUDENT CONSTRUCTOR - reading from file 
Student::Student(std::istream &ist) : Person("", ""), _grade{0}{

	getline(ist, _name);  
	ist >> _email; ist.ignore(); 
	ist >> _grade; ist.ignore(); 

}

// STUDENT::ADD_PARENT - adds ptr to new parent of student 
void Student::add_parent(Parent& parent){

	// add address of new Parent to vector	
	_parents.push_back(&parent); 

} 

// STUDENT::FULL_INFO - adds grades and parents names to output
std::string Student::full_info(){ 

	int SIZE = _parents.size(); 	

	// get person output
	std::string person_info = Person::full_info(); 

	// get student output
	std::string grade = " grade " +  std::to_string(_grade) + " "; 

	return (person_info + grade);  
} 


// STUDENT::SAVE - saves all the students info to an output stream argument
void Student::save(std::ostream& ost){

	// save name, email, grade, in that order
	ost << _name << std::endl; 
	ost << _email << std::endl; 
	ost << _grade << std::endl;

}


