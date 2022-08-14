#include "course.h" 
#include <map> 

// DEFAULT
Course::Course(): _subject{Subject::MATH}, _grade{4}{}

// SUBJECT-GRADE CONSTRUCTOR: constructor from input of user at runtime  
Course::Course(Subject subject, int grade) : _subject{subject}, _grade{grade}{

	// check that grade is in range, if not throw error
	if(_grade < 1 || _grade > 12){
		std::cerr << " Invalid Grade" << std::endl; 
	}

} 

// INPUT STREAM CONSTRUCTOR: constructs from a file's input stream passed as parameters 
Course::Course(std::istream& ist){

	// get data
	_subject = load_subject(ist); 
	ist >> _grade; ist.ignore();  

} 

// SAVE - output subject to file
void Course::save(std::ostream& ost){ 

	ost << _subject << std::endl; 
	ost << _grade << std::endl; 

} 

// OPERATOR << OVERLOAD
std::ostream& operator<<(std::ostream& ost, const Course& course){

	ost << course._subject; 
	ost << " (grade " << course._grade << ")"; 

	return ost; 

} 

