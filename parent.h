#ifndef __PARENT_H
#define __PARENT_H
#include "person.h" 

class Student;  

class Parent : public Person {
	public: 
		Parent(std::string name, std::string email); 
		Parent(std::istream& ist); 
		std::string full_info() override; 
		void add_student(Student& student);
		void save(std::ostream& ost); 
		typedef std::vector<Student*> Students; 
		typedef Students::iterator iterator; 
		typedef Students::const_iterator const_iterator; 
		iterator begin() { return _students.begin(); }
		iterator end() { return _students.end(); }

	protected: 
		std::vector<Student*> _students; 
}; 


#endif 
