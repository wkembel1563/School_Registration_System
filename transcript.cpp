#include "transcript.h" 

Transcript::Transcript(Student& student, Section& section) : _student{student}, _section{section}{} 

void Transcript::assign_grade(Grade grade) { _grade = grade; }

std::ostream& operator<<(std::ostream& ost, const Transcript& transcript){

	ost << transcript._section << " "; 	
	ost << transcript._student << " "; 	
	ost << transcript._grade; 	

	return ost; 

} 

Student& Transcript::get_stu(){ return _student; } 
Section& Transcript::get_sec(){ return _section; } 
Grade Transcript::get_grade(){ return _grade; } 
