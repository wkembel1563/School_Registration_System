#include "subject.h" 
#include <map> 


// OPERATOR << OVERLOAD
std::ostream& operator<<(std::ostream& ost, const Subject& subject){


	// map of subjects
	std::map<Subject, std::string> v = {{Subject::READING, "reading"}, {Subject::WRITING, "writing"}, {Subject::MATH, "math"}, 
	                                    {Subject::SCIENCE, "science"}, {Subject::HISTORY, "history"}, {Subject::ART, "art"}, 
                                            {Subject::MUSIC, "music"}, {Subject::SPORTS, "sports"}}; 

	// output string corresponding to subject
	ost << v[subject]; 

	return ost; 
		

} 

// LOAD SUBJECT FROM INPUT FILE STREAM 
Subject load_subject(std::istream& ist){

	std::string sub; 
	std::getline(ist, sub); 

	std::map<std::string, Subject> v = {{"reading", Subject::READING}, {"writing", Subject::WRITING}, {"math", Subject::MATH}, 
					    {"science", Subject::SCIENCE}, {"history", Subject::HISTORY}, {"art", Subject::ART}, 
					    {"music", Subject::MUSIC}, {"sports", Subject::SPORTS}}; 
	return v[sub]; 
	
} 
