#ifndef __MAINWIN_H
#define __MAINWIN_H
#include <vector> 	 // parent and student vector
#include <gtkmm.h>	 // gtkmm.h 
#include "student.h"	 // Student class, iostream
#include "parent.h" 	 // Parent class
#include "course.h" 
#include "section.h" 
#include "comboboxcontainer.h" 
#include "transcript.h" 

class Mainwin : public Gtk::Window{
	public: 
		Mainwin(); 
		virtual ~Mainwin(); 

	protected: 
		void on_new_school_click(); 
		void on_new_student_click(); 
		void on_new_parent_click(); 
		void on_new_teacher_click(); 
		void on_new_transcript_click(); 
		void on_student_parent_click(); 
		void on_about_click(); 
		void on_quit_click(); 
		void on_save_click(); 
		void on_save_as_click(); 
		void on_set_grade_click(); 
		void on_open_click(); 
		void on_new_course_click(); 
		void on_new_section_click(); 

	private: 
		Gtk::Label *display; 
		Gtk::Label *display2; 
		Gtk::Label *msg; 
		std::vector<Student*> _students; 
		std::vector<Parent*> _parents; 
		std::vector<Teacher*> _teachers; 
		void show_data(int display_setting = 1); 
		std::string file_name; 
		std::vector<Course*> _courses; 
		std::vector<Section*> _sections; 
		std::vector<Transcript*> _transcripts; 

}; 

#endif
