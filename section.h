#ifndef __SECTION_H
#define __SECTION_H 
#include "course.h"  	// Course enum class and iostream 
#include "semester.h" 
#include "teacher.h"

class Section{
	public: 
		Section(Course course, Semester semester, int year, Teacher teacher); 
		Section(std::istream& ist); 
		void save(std::ostream& ost); 
		friend std::ostream& operator<<(std::ostream& ost, const Section& section); 

	private: 
		Course _course;
		Semester _semester; 
		int _year; 
		Teacher _teacher; 

}; 

#endif
