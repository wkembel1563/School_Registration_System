#ifndef __STUDENT_H
#define __STUDENT_H
#include "person.h" 
#include <iostream> 

class Parent;  

class Student : public Person {
	public: 
		Student(std::string name, std::string email, int grade); 
		Student(std::istream& ist); 
		std::string full_info() override; 
		void add_parent(Parent& parent);
		void save(std::ostream& ost);
		typedef std::vector<Parent*> Parents; 
		typedef Parents::iterator iterator; 
		typedef Parents::const_iterator const_iterator; 
		iterator begin() { return _parents.begin(); }
		iterator end() { return _parents.end(); }

	protected: 
		int _grade; 
		std::vector<Parent*> _parents; 
}; 


#endif 
