#include "section.h" 

// COURSE-SEMESTER-YEAR CONSTRUCTOR: constructor from input of user at runtime  
Section::Section(Course course, Semester semester, int year, Teacher teacher): _course{course}, _semester{semester}, _year{year}, _teacher{teacher}{} 

// INPUT STREAM CONSTRUCTOR: constructs from a file's input stream passed as parameter 
Section::Section(std::istream& ist) : _teacher{"", ""}{

	// Have course load itself
	_course = Course{ist}; 		

	// Have semester load itself 
	_semester = load_semester(ist); 	

	// Get year
	ist >> _year; ist.ignore();

	// Have teacher load itself
	_teacher = Teacher{ist}; 
	
} 

// SAVE - output !!!! to file, assume calling function will place newline after
void Section::save(std::ostream& ost){ 

	// Save course - includes newline
	_course.save(ost); 	
	
	// Save semester
	ost << _semester << std::endl; 

	// Save year
	ost << _year << std::endl; 

	// Save teacher
	_teacher.save(ost); 

} 

// OPERATOR << OVERLOAD
std::ostream& operator<<(std::ostream& ost, const Section& section){

	ost << section._course << " " << section._semester << " " << section._year << " " << section._teacher; 

	return ost; 

} 
