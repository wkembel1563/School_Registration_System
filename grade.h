#ifndef __GRADE_H
#define __GRADE_H
#include <iostream> 
#include <map> 

enum class Grade{A, B, C, D, F, I, X}; 

std::ostream& operator<<(std::ostream& ost, const Grade& grade); 

Grade load_grade(std::istream& ist); 

#endif
