#ifndef __TRANSCRIPT_H
#define __TRANSCRIPT_H
#include "grade.h" 
#include "student.h"
#include "section.h" 
#include <iostream> 

class Transcript{
	public: 
		Transcript(Student& student, Section& section); 
		void assign_grade(Grade grade); 
		friend std::ostream& operator<<(std::ostream& ost, const Transcript& transcript); 
		Student& get_stu(); 
		Section& get_sec(); 
		Grade get_grade(); 

	private: 
		Section& _section; 
		Student& _student; 
		Grade _grade; 
}; 

#endif
