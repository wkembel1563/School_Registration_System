#ifndef __SUBJECT_H
#define __SUBJECT_H
#include <iostream> 

enum class Subject{READING, WRITING, MATH, SCIENCE, HISTORY, ART, MUSIC, SPORTS}; 

std::ostream& operator<<(std::ostream& ost, const Subject& subject); 

Subject load_subject(std::istream& ist); 

#endif
