#ifndef __PERSON_H
#define __PERSON_H 
#include <iostream> 
#include <vector> 
#include <string> 

class Person {
	public: 
		Person(std::string name, std::string email); 
		std::string to_string(); 
		virtual std::string full_info(); 
		friend std::ostream& operator<<(std::ostream& ost, const Person& person); 

	protected: 
		std::string _name; 
		std::string _email; 

}; 


#endif 
