#include "mainwin.h"
#include <string> 
#include <fstream> 
#include <sstream>

Mainwin::Mainwin() : file_name{"untitled.smart"} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(1000, 500);
    set_title("SMART System");
    

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //    F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //    N E W 
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

    //    S A V E
    // Append Save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //    S A V E A S
    // Append Saveas to the File menu
    Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_saveas);

    //    O P E N 
    // Append Saveas to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

    //    Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //    I N S E R T
    // Create a Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //    S T U D E N T
    // Append Student to the Insert menu
    Gtk::MenuItem *menuitem_student = Gtk::manage(new Gtk::MenuItem("_Student", true));
    menuitem_student->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_student);

    //    P A R E N T 
    // Append Parent to the Insert menu
    Gtk::MenuItem *menuitem_parent = Gtk::manage(new Gtk::MenuItem("_Parent", true));
    menuitem_parent->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_parent);

    //    T E A C H E R
    // Appen Teacher to Insert menu 
    Gtk::MenuItem * menuitem_teacher = Gtk::manage(new Gtk::MenuItem{"_Teacher", true}); 
    menuitem_teacher->signal_activate().connect([this]{this->on_new_teacher_click();}); 
    insertmenu->append(*menuitem_teacher); 

    //    C O U R S E
    // Append Course to Insert menu
    Gtk::MenuItem * menuitem_course = Gtk::manage(new Gtk::MenuItem("_Course", true)); 
    menuitem_course->signal_activate().connect([this] {this->on_new_course_click();});
    insertmenu->append(*menuitem_course); 

    //    S E C T I O N  
    // Append Section to Insert menu
    Gtk::MenuItem * menuitem_section = Gtk::manage(new Gtk::MenuItem("Section", false)); 
    menuitem_section->signal_activate().connect([this] {this->on_new_section_click();});
    insertmenu->append(*menuitem_section); 

    //    T R A N S C R I P T  
    // Append Transcript to Insert menu 
    Gtk::MenuItem * menuitem_transcript = Gtk::manage(new Gtk::MenuItem{"Transcript", false}); 
    menuitem_transcript->signal_activate().connect([this]{this->on_new_transcript_click();}); 
    insertmenu->append(*menuitem_transcript); 

    //    R E L A T E 
    // Create a Relate menu and add to the menu bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    //    S T U D E N T  T O  P A R E N T 
    // Append 'Student to Parent' to the Relate menu
    Gtk::MenuItem *menuitem_s2p = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
    menuitem_s2p->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_s2p);

    //    H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);


    //    A B O U T
    // Append About to Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    //    V I E W
    // Create View menu and add to menu bar
    Gtk::MenuItem * menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true)); 
    menubar->append(*menuitem_view); 
    Gtk::Menu * viewmenu = Gtk::manage(new Gtk::Menu()); 
    menuitem_view->set_submenu(*viewmenu); 

    //    C O U R S E S
    // Append Courses to View menu
    Gtk::MenuItem * menuitem_courses = Gtk::manage(new Gtk::MenuItem("_Courses", true)); 
    menuitem_courses->signal_activate().connect([this]{this->show_data(2);}); 
    viewmenu->append(*menuitem_courses); 

    //    S E C T I O N S
    //    Append Sections to View menu 
    Gtk::MenuItem * menuitem_sections = Gtk::manage(new Gtk::MenuItem("_Sections", true)); 
    menuitem_sections->signal_activate().connect([this]{this->show_data(3);}); 
    viewmenu->append(*menuitem_sections); 

    //    T R A N S C R I P T 
    //    Append Transcript to View menu 
    Gtk::MenuItem * menuitem_transcripts = Gtk::manage(new Gtk::MenuItem("_Transcript", true)); 
    menuitem_transcripts->signal_activate().connect([this]{this->show_data(5);}); 
    viewmenu->append(*menuitem_transcripts); 

    //    S T U D E N T S  A N D  P A R E N T S
    //    Append 'Students and Parents' to View menu 
    Gtk::MenuItem * menuitem_s_n_p = Gtk::manage(new Gtk::MenuItem("Students and _Parents", true)); 
    menuitem_s_n_p->signal_activate().connect([this]{this->show_data();}); 
    viewmenu->append(*menuitem_s_n_p); 

    //    T E A C H E R S
    //    Append Teacher to View menu 
    Gtk::MenuItem * menuitem_teachers = Gtk::manage(new Gtk::MenuItem("_Teacher", true)); 
    menuitem_teachers->signal_activate().connect([this]{this->show_data(4);}); 
    viewmenu->append(*menuitem_teachers); 
  

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

    // New School 
    Gtk::ToolButton * new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_school_button->set_tooltip_markup("Create New School Data");
    new_school_button->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(*new_school_button);

    // Open School 
    Gtk::ToolButton * open_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    open_school_button->set_tooltip_markup("Open School Data File");
    open_school_button->signal_clicked().connect([this] {this->on_open_click();}); 

    // Save School
    Gtk::ToolButton * save_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    save_button->set_tooltip_markup("Save");
    save_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_button);

    // Save As School
    Gtk::ToolButton * save_as_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    save_as_button->set_tooltip_markup("Save As");
    save_as_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*save_as_button);

    // Spacer Between File/Data Manipulator Buttons
    Gtk::SeparatorToolItem * sep = Gtk::manage(new Gtk::SeparatorToolItem()); 
    toolbar->append(*sep); 

    // Insert Student
    Gtk::Image * student_image = Gtk::manage(new Gtk::Image("student.png")); 
    Gtk::ToolButton * student_button = Gtk::manage(new Gtk::ToolButton(*student_image));
    student_button->set_tooltip_markup("Insert Student in Database");
    student_button->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(*student_button);

    // Insert Parent
    Gtk::Image * parent_image = Gtk::manage(new Gtk::Image("parent.png")); 
    Gtk::ToolButton * parent_button = Gtk::manage(new Gtk::ToolButton(*parent_image));
    parent_button->set_tooltip_markup("Insert Parent in Database");
    parent_button->signal_clicked().connect([this] {this->on_new_parent_click();});
    toolbar->append(*parent_button);

    // Relate Student to Parent
    Gtk::Image * relate_image = Gtk::manage(new Gtk::Image("relate.png")); 
    Gtk::ToolButton * relate_button = Gtk::manage(new Gtk::ToolButton(*relate_image));
    relate_button->set_tooltip_markup("Relate a Student to a Parent");
    relate_button->signal_clicked().connect([this] {this->on_student_parent_click();});
    toolbar->append(*relate_button);

    // Teacher Section 
    Gtk::Image * teacher_image = Gtk::manage(new Gtk::Image("Teacher.png")); 
    Gtk::ToolButton * teacher_button = Gtk::manage(new Gtk::ToolButton{*teacher_image}); 
    teacher_button->set_tooltip_markup("Insert Teacher in Database"); 
    teacher_button->signal_clicked().connect([this]{this->on_new_teacher_click();}); 
    toolbar->append(*teacher_button); 

    // Spacer Between People/Course Buttons
    Gtk::SeparatorToolItem * sep2 = Gtk::manage(new Gtk::SeparatorToolItem()); 
    toolbar->append(*sep2); 

    // Insert Course
    Gtk::Image * course_image = Gtk::manage(new Gtk::Image("course.png")); 
    Gtk::ToolButton * course_button = Gtk::manage(new Gtk::ToolButton{*course_image}); 
    course_button->set_tooltip_markup("Insert Course in Database"); 
    course_button->signal_clicked().connect([this]{this->on_new_course_click();}); 
    toolbar->append(*course_button); 

    // Insert Section 
    Gtk::Image * section_image = Gtk::manage(new Gtk::Image("section.png")); 
    Gtk::ToolButton * section_button = Gtk::manage(new Gtk::ToolButton{*section_image}); 
    section_button->set_tooltip_markup("Insert Section in Database"); 
    section_button->signal_clicked().connect([this]{this->on_new_section_click();}); 
    toolbar->append(*section_button); 

    // Insert Transcript
    Gtk::Image * transcript_image = Gtk::manage(new Gtk::Image("Transcript.png")); 
    Gtk::ToolButton * transcript_button = Gtk::manage(new Gtk::ToolButton{*transcript_image}); 
    transcript_button->set_tooltip_markup("Insert Transcript in Database"); 
    transcript_button->signal_clicked().connect([this]{this->on_new_transcript_click();}); 
    toolbar->append(*transcript_button); 

    // Change Grade Section 
    Gtk::Image * grade_image = Gtk::manage(new Gtk::Image("Grade.png")); 
    Gtk::ToolButton * grade_button = Gtk::manage(new Gtk::ToolButton{*grade_image}); 
    grade_button->set_tooltip_markup("Change Transcript Grade"); 
    grade_button->signal_clicked().connect([this]{this->on_set_grade_click();}); 
    toolbar->append(*grade_button); 

    // /////////////////////////// ////////////////////////////////////////////
    // S M A R T   D I S P L A Y
    // Provides a text display for parent/student info 
    Gtk::Box *hbox = Gtk::manage(new Gtk::HBox); 
    display = Gtk::manage(new Gtk::Label());
    display2 = Gtk::manage(new Gtk::Label());
    hbox->add(*display); 
    hbox->add(*display2); 
    vbox->add(*hbox);
    
    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
//    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

    // Make the box and everything in it visible
    vbox->show_all();

    // Inialize display
    show_data(); 
}

Mainwin::~Mainwin() { 

	for(auto &s : _students){
		delete s; 
		s = NULL; 
	}
	for(auto &p : _parents){
		delete p; 
		p = NULL; 
	}
	for(auto &c : _courses){
		delete c; 
		c = NULL; 
	}
	for(auto &s : _sections){
		delete s; 
		s = NULL; 
	}
	for(auto &s : _transcripts){
		delete s; 
		s = NULL; 
	}
	for(auto &s : _teachers){
		delete s; 
		s = NULL; 
	}

}

// /////////////////
// C A L L B A C K S
// /////////////////

// INSERT > STUDENT 
void Mainwin::on_new_student_click(){
	
	// deploy dialog to get name, email and grade 
	Gtk::Dialog dialog{"New Student", *this}; 
//	dialog.set_default_size(800, 400); 

	// grid to format the space
	Gtk::Grid grid; 

	// entry for name
	Gtk::Label l_name{"Name"};	// Name entry label
	Gtk::Entry e_name; 	
	grid.attach(l_name, 0, 0, 1, 1); 
	grid.attach(e_name, 1, 0, 2, 1); 

	// entry for email 
	Gtk::Label l_email{"Email"};	// Email entry label
	Gtk::Entry e_email; 	
	grid.attach(l_email, 0, 1, 1, 1); 
	grid.attach(e_email, 1, 1, 2, 1); 

	// spinner for grade 
	Gtk::Label l_grade{"Grade"};		// Grade entry label
	Gtk::SpinButton s_grade; 	
	s_grade.set_range(1, 12); 		// set range of spin button 
	s_grade.set_increments(1, 5); 		// increment button press
	s_grade.set_value(1); 			// default grade is 1
	grid.attach(l_grade, 0, 2, 1, 1); 
	grid.attach(s_grade, 1, 2, 2, 1); 

	// add grid with entries to dialog
	dialog.get_content_area()->add(grid); 

	// add okay and cancel buttons to dialogue
	dialog.add_button("Create Student", Gtk::RESPONSE_OK); 
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL); 

	// show dialog
	dialog.show_all(); 

	// validate data after user Creates 
	int result = dialog.run();
	int incorrect; 
	std::string name 	= e_name.get_text(); 	
	std::string email 	= e_email.get_text(); 
	int grade 		= s_grade.get_value(); 
	// prompt user for correct inputs if incorrect
	do{
		// exit if cancel was pressed on first run 
		if(result != Gtk::RESPONSE_OK) break; 

		// assume input is correct, then verify
		incorrect = 0; 	

		// check name
		name = e_name.get_text(); 	
		if(name.compare("") == 0) incorrect++; 
		
		// check email
		email = e_email.get_text(); 
		if(email.compare("") == 0) incorrect++; 

		// update grade
		grade = s_grade.get_value(); 
		if(grade < 1 || grade > 12) incorrect++; 

		// display error dialog
		if(incorrect > 0) 
			Gtk::MessageDialog{*this, "Please enter name, email, and valid grade 1-12"}.run(); 

	}
	while(incorrect && (result = dialog.run()) == Gtk::RESPONSE_OK); 

	if(result == Gtk::RESPONSE_OK){

		// add new Student to vector 
		Student *new_s = new Student{name, email, grade}; 
		_students.push_back( new_s ); 

	}

	// update display
	show_data(); 	

}

// INSERT > PARENT
void Mainwin::on_new_parent_click(){
	
	// deploy dialog to get name, email and grade 
	Gtk::Dialog dialog{"New Parent", *this}; 
//	dialog.set_default_size(800, 400); 

	// grid to format the space
	Gtk::Grid grid; 

	// entry for name
	Gtk::Label l_name{"Name"};	// Name entry label
	Gtk::Entry e_name; 	
	grid.attach(l_name, 0, 0, 1, 1); 
	grid.attach(e_name, 1, 0, 2, 1); 

	// entry for email 
	Gtk::Label l_email{"Email"};	// Email entry label
	Gtk::Entry e_email; 	
	grid.attach(l_email, 0, 1, 1, 1); 
	grid.attach(e_email, 1, 1, 2, 1); 

	// add grid with entries to dialog
	dialog.get_content_area()->add(grid); 

	// add okay and cancel buttons to dialogue
	dialog.add_button("Create Parent", Gtk::RESPONSE_OK); 
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL); 

	// show dialog
	dialog.show_all(); 

	// validate data after user Creates 
	int result = dialog.run(); 
	int incorrect; 
	std::string name 	= e_name.get_text(); 	
	std::string email 	= e_email.get_text(); 
	// prompt user for correct inputs if incorrect
	do{
		// exit if cancel was pressed on first run 
		if(result != Gtk::RESPONSE_OK) break; 

		// assume input is correct, then verify
		incorrect = 0; 	

		// check name
		name = e_name.get_text(); 	
		if(name.compare("") == 0) incorrect++; 
		
		// check email
		email = e_email.get_text(); 
		if(email.compare("") == 0) incorrect++; 

		// display error dialog
		if(incorrect > 0) 
			Gtk::MessageDialog{*this, "Please enter both name and email"}.run(); 

	}
	while(incorrect && (result = dialog.run()) == Gtk::RESPONSE_OK); 

	if(result == Gtk::RESPONSE_OK){

		// add new Student to vector 
		Parent *new_p = new Parent{name, email}; 
		_parents.push_back( new_p ); 

	}

	// update display
	show_data(); 	

}

// INSERT > TEACHER
void Mainwin::on_new_teacher_click(){

	// deploy dialog to get name, email and grade 
	Gtk::Dialog dialog{"New Teacher", *this}; 
//	dialog.set_default_size(800, 400); 

	// grid to format the space
	Gtk::Grid grid; 

	// entry for name
	Gtk::Label l_name{"Name"};	// Name entry label
	Gtk::Entry e_name; 	
	grid.attach(l_name, 0, 0, 1, 1); 
	grid.attach(e_name, 1, 0, 2, 1); 

	// entry for email 
	Gtk::Label l_email{"Email"};	// Email entry label
	Gtk::Entry e_email; 	
	grid.attach(l_email, 0, 1, 1, 1); 
	grid.attach(e_email, 1, 1, 2, 1); 

	// add grid with entries to dialog
	dialog.get_content_area()->add(grid); 

	// add okay and cancel buttons to dialogue
	dialog.add_button("Create Teacher", Gtk::RESPONSE_OK); 
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL); 

	// show dialog
	dialog.show_all(); 

	// validate data after user Creates 
	int result = dialog.run(); 
	int incorrect; 
	std::string name 	= e_name.get_text(); 	
	std::string email 	= e_email.get_text(); 
	// prompt user for correct inputs if incorrect
	do{
		// exit if cancel was pressed on first run 
		if(result != Gtk::RESPONSE_OK) break; 

		// assume input is correct, then verify
		incorrect = 0; 	

		// check name
		name = e_name.get_text(); 	
		if(name.compare("") == 0) incorrect++; 
		
		// check email
		email = e_email.get_text(); 
		if(email.compare("") == 0) incorrect++; 

		// display error dialog
		if(incorrect > 0) 
			Gtk::MessageDialog{*this, "Please enter both name and email"}.run(); 

	}
	while(incorrect && (result = dialog.run()) == Gtk::RESPONSE_OK); 

	if(result == Gtk::RESPONSE_OK){

		// add new Student to vector 
		Teacher * new_t = new Teacher{name, email}; 
		_teachers.push_back( new_t ); 

	}

	// update display
	show_data(4); 	
}

// INSERT > Transcript
void Mainwin::on_new_transcript_click(){

	// deploy dialog to get name, email and grade 
	Gtk::Dialog dialog{"New Transcript", *this}; 

	// grid to format the space
	Gtk::Grid grid; 

	// Section 
	Gtk::Label s_name{"Section"};	// Name entry label
	Gtk::ComboBoxText section_combobox{true}; 
	std::ostringstream oss; 
	for(auto& stu : _sections){
		
		oss << *stu; 
		section_combobox.append(oss.str()); 
		oss.str(std::string()); 

	}
	section_combobox.set_active(0); 
	grid.attach(s_name, 0, 0, 1, 1); 
	grid.attach(section_combobox, 1, 0, 2, 1); 

	// Student
	Gtk::Label stu_name{"Student"};	// Name entry label
	Gtk::ComboBoxText stu_combobox{true}; 
	for(auto& stu : _students){
		
		oss << *stu; 
		stu_combobox.append(oss.str()); 
		oss.str(std::string()); 

	}
	stu_combobox.set_active(0); 
	grid.attach(stu_name, 0, 1, 1, 1); 
	grid.attach(stu_combobox, 1, 1, 2, 1); 

	// Grade
	Gtk::Label g_course{"Grade"};	
	Gtk::ComboBoxText grade_combobox{true}; 
	grade_combobox.append("A"); 	
	grade_combobox.append("B"); 	
	grade_combobox.append("C"); 	
	grade_combobox.append("D"); 	
	grade_combobox.append("F"); 	
	grade_combobox.append("I"); 	
	grade_combobox.append("X"); 	
	grade_combobox.set_active(0); 
	grid.attach(g_course, 0, 2, 1, 1); 
	grid.attach(grade_combobox, 1, 2, 2, 1); 

	// add grid with entries to dialog
	dialog.get_content_area()->add(grid); 

	// add okay and cancel buttons to dialogue
	dialog.add_button("Create Transcript", Gtk::RESPONSE_OK); 
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL); 

	// show dialog
	dialog.show_all(); 

	// validate data after user Creates 
	int result = dialog.run(); 
	int incorrect; 
	int section; 
	int student; 
	int grade;	
	// prompt user for correct inputs if incorrect
	do{
		// exit if cancel was pressed on first run 
		if(result != Gtk::RESPONSE_OK) break; 

		// assume input is correct, then verify
		incorrect = 0; 	

		// check section
		section = section_combobox.get_active_row_number(); 
		if(section < 0) incorrect++; 

		// student section
		student = stu_combobox.get_active_row_number(); 
		if(student < 0) incorrect++; 

		// check grade 
		grade = grade_combobox.get_active_row_number(); 
		if(grade < 0) incorrect++; 

		// display error dialog
		if(incorrect > 0) 
			Gtk::MessageDialog{*this, "Please choose from dropdown."}.run(); 

	}
	while(incorrect && (result = dialog.run()) == Gtk::RESPONSE_OK); 

	if(result == Gtk::RESPONSE_OK){

		// Create new transcript 
		Section * s = _sections[section]; 
		Student * stu = _students[student]; 
		Transcript * t = new Transcript{*stu, *s};  

		// Grade
		switch(grade){
			case 0: t->assign_grade(Grade::A); break;  
			case 1: t->assign_grade(Grade::B); break;  
			case 2: t->assign_grade(Grade::C); break;  
			case 3: t->assign_grade(Grade::D); break;  
			case 4: t->assign_grade(Grade::F); break;  
			case 5: t->assign_grade(Grade::I); break;  
			case 6: t->assign_grade(Grade::X); break;  
		}; 

		// Place in vector
		_transcripts.push_back(t); 


	}

	// update display
	show_data(5); 	
}

// RELATE > STUDENT TO PARENT 
void Mainwin::on_student_parent_click(){

	// deploy dialog to get name, email and grade 
	Gtk::Dialog dialog{"Relate a Student to a Parent", *this}; 
//	dialog.set_default_size(800, 400); 

	// grid to format the space
	Gtk::Grid grid; 

	// create combobox for Students 
	Gtk::Label l_stu{"Student"};	
	ComboBoxContainer<Student> stu_combobox(_students); 	
	stu_combobox.set_active(0); 

	// attach Student combobox to grid
	grid.attach(l_stu, 0, 0, 1, 1); 
	grid.attach(stu_combobox, 1, 0, 2, 1); 

	// create combobox for Parents 
	Gtk::Label l_par{"Parent"};
	ComboBoxContainer<Parent> par_combobox(_parents); 	
	par_combobox.set_active(0); 

	// attach Parent combobox to grid 
	grid.attach(l_par, 0, 1, 1, 1); 
	grid.attach(par_combobox, 1, 1, 2, 1); 

	// add grid with entries to dialog
	dialog.get_content_area()->add(grid); 

	// add okay and cancel buttons to dialogue
	dialog.add_button("Relate", Gtk::RESPONSE_OK); 
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL); 

	// show dialog
	dialog.show_all(); 

	// verify user has chosen from given options
	int result = dialog.run(); 
	int incorrect;	// 0 for correct response  
	int student_choice;  
	int parent_choice; 
	do{
		// exit if cancel was pressed on first run 
		if(result != Gtk::RESPONSE_OK) break; 
	
		// set incorrect to false by default
		incorrect = 0; 

		// check student choice
		student_choice =  stu_combobox.get_active_row_number(); 
		if(student_choice < 0){
			incorrect++; 
		}

		// check parent choice 
		parent_choice =  par_combobox.get_active_row_number(); 
		if(parent_choice < 0){
			incorrect++; 
		}

		// display error dialog
		if(incorrect > 0) 
			Gtk::MessageDialog{*this, "Please choose from dropdown"}.run(); 

	}
	while(incorrect && (result = dialog.run()) == Gtk::RESPONSE_OK); 

	if(result == Gtk::RESPONSE_OK){

		// Add chosen student to chosen parent
		Student *newstu = _students[student_choice]; 
		_parents[parent_choice]->add_student(*newstu); 
		
		// vice versa
		Parent *newpar = _parents[parent_choice]; 
		_students[student_choice]->add_parent(*newpar); 

	}


	// update display
	show_data(); 

}

// FILE > NEW 
void Mainwin::on_new_school_click() {

	// offer to save the current file 

	// reset file name to default
	file_name = "untitled.smart"; 

	// clear parent, student vectors
	int parent_size = _parents.size(); 
	int student_size = _students.size(); 
	int course_size = _courses.size(); 
	int section_size = _sections.size(); 
	for(auto &s : _students){
		delete s; 
		s = NULL; 
	}
	for(auto &p : _parents){
		delete p; 
		p = NULL; 
	}
	for(auto &c : _courses){
		delete c; 
		c = NULL; 
	}
	for(auto &s : _sections){
		delete s; 
		s = NULL; 
	}
	_parents.erase(_parents.begin(), _parents.begin() + parent_size); 
	_students.erase(_students.begin(), _students.begin() + student_size); 
	_courses.erase(_courses.begin(), _courses.begin() + course_size); 
	_sections.erase(_sections.begin(), _sections.begin() + section_size); 

	// update display
	show_data(); 
}

// ABOUT
void Mainwin::on_about_click(){

	// set up about dialog 
	Gtk::AboutDialog dialog; 

	// avoid transient warning
	dialog.set_transient_for(*this); 

	// add title and version number
	dialog.set_program_name("SMART School Management and Reporting Tool"); 
	dialog.set_version("Version 1.3.0"); 

	// add logo
	auto logo = Gdk::Pixbuf::create_from_file("school_photo.png"); 
	dialog.set_logo(logo); 

	// set copyright 
	dialog.set_copyright("Copyright 2021"); 
	dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0); 
	std::vector<Glib::ustring> authors = {"Robert Kembel"}; 
	dialog.set_authors(authors); 

	// credit artwork 
	std::vector<Glib::ustring> artists = {
		"Logo by David R. Tribble under CC BY-SA 3.0\nhttps://en.wikipedia.org/wiki/Martin_High_School_(Arlington,_Texas)#/media/File:MartinHighSchool-3971.jpg", 
		"New Student icon by ХЕРАЛДИКА СССС under CC A-SA 4.0\nhttps://commons.wikimedia.org/wiki/File:Student_(example).svg", 
		"New Parent icon by John Gelling under CC A-SA 4.0\nhttps://commons.wikimedia.org/wiki/File:Man_silhouette_symbol.png",
		"Relate Student to Parent icon by MrALCA95 under CC A-SA 4.0\nhttps://commons.wikimedia.org/wiki/File:Child_with_parent_by_User-MrALCA95.png"
	}; 
	dialog.set_artists(artists);   
	
	dialog.run(); 


}

// FILE > QUIT
void Mainwin::on_quit_click() {
    	close();
}

// FILE > SAVE
void Mainwin::on_save_click(){

	try{

		// save to current file_name
		std::ofstream ost{file_name}; 
		if(!ost) throw std::runtime_error("Could not write to file" + file_name); 

		// write student vector size then data
		ost << std::to_string(_students.size()) << std::endl; 
		for(auto s : _students) s->save(ost); 
		
		// write parent vector size then data
		ost << std::to_string(_parents.size()) << std::endl; 
		for(auto s : _parents) s->save(ost);  

		// write course vector size then data
		ost << std::to_string(_courses.size()) << std::endl; 
		for(auto s : _courses) s->save(ost);  

		// write sections vector size then data
		ost << std::to_string(_sections.size()) << std::endl; 
		for(auto s : _sections) s->save(ost);  

		// write teachers vector size then data
		ost << std::to_string(_teachers.size()) << std::endl; 
		for(auto s : _teachers) s->save(ost);  

		// write transcript vector size then data
		ost << std::to_string(_transcripts.size()) << std::endl; 
		for(auto s : _transcripts){
			s->get_stu().save(ost); 
			s->get_sec().save(ost); 
			ost << s->get_grade() << std::endl; 	
		}	  

	}
	catch(std::exception e){

		Gtk::MessageDialog{*this, "Error while writing file"}.run(); 

	}


}

// FILE > SAVE AS
void Mainwin::on_save_as_click(){

	// open file chooser dialog 
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE); 	
	dialog.set_transient_for(*this);

	// create file filter choices
	auto filter_smart = Gtk::FileFilter::create(); 
	filter_smart->set_name("SMART"); 
	filter_smart->add_pattern("*.smart"); 
	dialog.add_filter(filter_smart); 

	auto filter_any = Gtk::FileFilter::create(); 
	filter_any->set_name("Any");
	filter_any->add_pattern("*"); 
	dialog.add_filter(filter_any); 

	// add buttons
	dialog.add_button("_Cancel", 0); 
	dialog.add_button("_Save", 1);

	// set default file name
	dialog.set_filename("untitled.smart"); 

	// if save is clicked, update current file_name and save
	int result = dialog.run(); 
	if(result == 1){
		
		// get new filename
		file_name = dialog.get_filename(); 		

		// save data to the file 
		on_save_click(); 

	}
	

}

// FILE > OPEN
void Mainwin::on_open_click(){

	// Open file chooser dialog 
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN); 
	dialog.set_transient_for(*this); 

	// create file filters
	auto filter_smart = Gtk::FileFilter::create(); 
	filter_smart->set_name("SMART"); 
	filter_smart->add_pattern("*.smart"); 
	dialog.add_filter(filter_smart); 

	auto filter_any = Gtk::FileFilter::create(); 
	filter_any->set_name("ANY"); 
	filter_any->add_pattern("*"); 
	dialog.add_filter(filter_any); 

	// set buttons
	dialog.add_button("_Cancel", 0); 
	dialog.add_button("_Open", 1); 

	// set default file name
	dialog.set_filename("untitled.smart"); 

	// open file if directed
	int result = dialog.run(); 
	if(result == 1){
	
		try{
			
			// open file to read and clear old data 	
			std::ifstream ist{dialog.get_filename()}; 
			if(!ist) throw std::runtime_error("Could not open file"); 
			on_new_school_click();				

			// update current file name in Mainwin
			file_name = dialog.get_filename(); 

			// read data into mainwin vectors 
			std::string name, email; 
			int size, grade; 
			Student * stu = NULL;
			Parent * par = NULL; 

			// get student data, build out _students vector 
			ist >> size; 
			ist.ignore(); 
			for(int i = 0; i < size; ++i) _students.push_back(new Student{ist});

			// get parent data, build out _parents vector
			ist >> size; 
			ist.ignore(); 
			for(int i = 0; i < size; ++i) _parents.push_back(new Parent{ist});

			// get course data, build out _courses vector
			ist >> size; 
			ist.ignore(); 
			for(int i = 0; i < size; ++i) _courses.push_back(new Course{ist});

			// get section data, build out _sections vector
			ist >> size; 
			ist.ignore(); 
			for(int i = 0; i < size; ++i) _sections.push_back(new Section{ist});

			// get teacher data, build out _teacher vector
			ist >> size;
			ist.ignore(); 
			for(int i = 0; i < size; ++i) _teachers.push_back(new Teacher{ist});

			// get transcript data, build out _transcripts vector
			ist >> size; 
			ist.ignore(); 
			for(int i = 0; i < size; ++i){
				Student stu{ist}; 
				Section sec{ist}; 
				Grade g = load_grade(ist); 
				Transcript t{stu, sec}; 
				t.assign_grade(g); 
				_transcripts.push_back(new Transcript{t});
			}
				
		}
		catch(std::exception e){
			Gtk::MessageDialog{*this, "Unable to open file " + dialog.get_filename()}.run();  
		}

	}

	// update display
	show_data(); 
	
}

// Get new course from user - called from Insert and Toolbar
void Mainwin::on_new_course_click(){

	// deploy dialog to get name, email and grade 
	Gtk::Dialog dialog{"Create a New Course", *this}; 

	// grid to format the space
	Gtk::Grid grid; 

	// create combobox for Students 
	Gtk::Label l_sub{"Subject"};	
	Gtk::ComboBoxText sub_combobox{true}; 
	std::ostringstream oss; 

	// Reading Choice
	oss << Subject::READING; 
	sub_combobox.append(oss.str()); 
	oss.str(std::string()); 

	// Writing 
	oss << Subject::WRITING; 
	sub_combobox.append(oss.str()); 
	oss.str(std::string()); 
	
	// Math
	oss << Subject::MATH; 
	sub_combobox.append(oss.str()); 
	oss.str(std::string()); 

	// Science
	oss << Subject::SCIENCE; 
	sub_combobox.append(oss.str()); 
	oss.str(std::string()); 

	// History 	
	oss << Subject::HISTORY; 
	sub_combobox.append(oss.str()); 
	oss.str(std::string()); 

	// Art
	oss << Subject::ART; 
	sub_combobox.append(oss.str()); 
	oss.str(std::string()); 

	// Music 
	oss << Subject::MUSIC; 
	sub_combobox.append(oss.str()); 
	oss.str(std::string()); 

	// Sports	
	oss << Subject::SPORTS; 
	sub_combobox.append(oss.str()); 
	oss.str(std::string()); 

	sub_combobox.set_active(0); 

	// attach Subject to grid
	grid.attach(l_sub, 0, 0, 1, 1); 
	grid.attach(sub_combobox, 1, 0, 2, 1); 

	// create Spinner for Grade
	Gtk::Label l_gd{"Grade"};
	Gtk::SpinButton s_grade; 	
	s_grade.set_range(1, 12); 		// set range of spin button 
	s_grade.set_increments(1, 5); 		// increment button press
	s_grade.set_value(1); 			// default grade is 1

	// attach Grade to grid 
	grid.attach(l_gd, 0, 1, 1, 1); 
	grid.attach(s_grade, 1, 1, 2, 1); 

	// add grid with entries to dialog
	dialog.get_content_area()->add(grid); 

	// add okay and cancel buttons to dialogue
	dialog.add_button("Create Course", Gtk::RESPONSE_OK); 
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL); 

	// show dialog
	dialog.show_all(); 

	// verify user has chosen from given options
	int result = dialog.run(); 
	int incorrect;	// 0 for correct response  
	int subject_choice;  
	int grade; 
	do{
		// exit if cancel was pressed on first run 
		if(result != Gtk::RESPONSE_OK) break; 
	
		// set incorrect to false by default
		incorrect = 0; 

		// check subject choice
		subject_choice =  sub_combobox.get_active_row_number(); 
		if(subject_choice < 0){
			incorrect++; 
		}

		// check parent choice 
		grade = s_grade.get_value(); 
		if(grade < 1 || grade > 12){
			incorrect++; 
		}

		// display error dialog
		if(incorrect > 0) 
			Gtk::MessageDialog{*this, "Please choose from dropdown and enter valid grade [1,12]"}.run(); 

	}
	while(incorrect && (result = dialog.run()) == Gtk::RESPONSE_OK); 

	if(result == Gtk::RESPONSE_OK){

		// Find chosen subject 
		Subject subject; 
		switch(subject_choice){

			case 0: subject = Subject::READING; break;  
			case 1: subject = Subject::WRITING; break;
			case 2: subject = Subject::MATH;    break;
			case 3: subject = Subject::SCIENCE; break;
			case 4: subject = Subject::HISTORY; break;
			case 5: subject = Subject::ART;     break;
			case 6: subject = Subject::MUSIC;   break;
			case 7: subject = Subject::SPORTS;  

		}

		// Add chosen student to chosen parent
		Course * newcourse = new Course{subject, grade}; 
		_courses.push_back(newcourse); 
		
	}


	// update display
	show_data(2); 
} 

// Get new section from user - called from Insert and Toolbar
void Mainwin::on_new_section_click(){

	// deploy dialog to get name, email and year 
	Gtk::Dialog dialog{"Create a New Section", *this}; 

	// grid to format the space
	Gtk::Grid grid; 

	// create combobox for Courses
	Gtk::Label l_course{"Course"};	
	Gtk::ComboBoxText course_combobox{true}; 
	std::ostringstream oss; 
	for(auto& stu : _courses){
		
		oss << *stu; 
		course_combobox.append(oss.str()); 
		oss.str(std::string()); 

	}
	course_combobox.set_active(0); 

	// attach Course combobox to grid
	grid.attach(l_course, 0, 0, 1, 1); 
	grid.attach(course_combobox, 1, 0, 2, 1); 

	// create combobox for Semester 
	Gtk::Label l_sem{"Semester"};
	Gtk::ComboBoxText sem_combobox{true}; 

	// Append Fall
	oss << Semester::FALL; 
	sem_combobox.append(oss.str()); 
	oss.str(std::string()); 

	// Append Spring 
	oss << Semester::SPRING; 
	sem_combobox.append(oss.str()); 
	oss.str(std::string()); 
		
	// Append Summer 
	oss << Semester::SUMMER; 
	sem_combobox.append(oss.str()); 
	oss.str(std::string()); 

	sem_combobox.set_active(0); 

	// attach Semester combobox to grid 
	grid.attach(l_sem, 0, 1, 1, 1); 
	grid.attach(sem_combobox, 1, 1, 2, 1); 

	// create Spinner for Year
	Gtk::Label l_year{"Year"};
	Gtk::SpinButton s_year; 	
	s_year.set_range(1000, 2030); 		// set range of spin button 
	s_year.set_increments(1, 10); 		// increment button press
	s_year.set_value(2021);		// default year is 2021

	// attach spinner
	grid.attach(l_year, 0, 2, 1, 1); 
	grid.attach(s_year, 1, 2, 2, 1); 

	// create teacher combobox 
	Gtk::Label t_course{"Teacher"};	
	Gtk::ComboBoxText teacher_combobox{true}; 
	for(auto& stu : _teachers){
		
		oss << *stu; 
		teacher_combobox.append(oss.str()); 
		oss.str(std::string()); 

	}
	teacher_combobox.set_active(0); 
	grid.attach(t_course, 0, 3, 1, 1); 
	grid.attach(teacher_combobox, 1, 3, 2, 1); 

	// add grid with entries to dialog
	dialog.get_content_area()->add(grid); 

	// add okay and cancel buttons to dialogue
	dialog.add_button("Create Section", Gtk::RESPONSE_OK); 
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL); 

	// show dialog
	dialog.show_all(); 

	// verify user has chosen from given options
	int result = dialog.run(); 
	int incorrect;	// 0 for correct response  
	int course_choice;  
	int sem_choice; 
	int year; 
	int teacher; 
	do{
		// exit if cancel was pressed on first run 
		if(result != Gtk::RESPONSE_OK) break; 
	
		// set incorrect to false by default
		incorrect = 0; 

		// check Course choice
		course_choice =  course_combobox.get_active_row_number(); 
		if(course_choice < 0){
			incorrect++; 
		}

		// check semester choice 
		sem_choice = sem_combobox.get_active_row_number(); 
		if(sem_choice < 0)
			incorrect++; 

		year = s_year.get_value(); 

		// check teacher
		teacher = teacher_combobox.get_active_row_number(); 
		if(teacher < 0)
			incorrect++; 

		// display error dialog
		if(incorrect > 0) 
			Gtk::MessageDialog{*this, "Please choose from dropdown and enter valid year [1000,2030]"}.run(); 

	}
	while(incorrect && (result = dialog.run()) == Gtk::RESPONSE_OK); 

	if(result == Gtk::RESPONSE_OK){
		// Finder chosen course	
		Course * course = _courses[course_choice]; 

		// Find chosen semester 
		Semester semester; 
		switch(sem_choice){

			case 0: semester = Semester::FALL; 	break;  
			case 1: semester = Semester::SPRING; 	break;
			case 2: semester = Semester::SUMMER;    break;

		}

		// Find teahcer
		Teacher * teach = _teachers[teacher]; 

		// Add section to vector 
		Section * newsection = new Section{*course, semester, year, *teach}; 
		_sections.push_back(newsection); 
		
	}


	// update display
	show_data(3); 

} 

void Mainwin::on_set_grade_click(){

	// deploy dialog to get name, email and year 
	Gtk::Dialog dialog{"Set Grade", *this}; 

	// grid to format the space
	Gtk::Grid grid; 

	// create combobox for transcript
	Gtk::Label t_course{"Transcript"};	
	Gtk::ComboBoxText transcript_combobox{true}; 
	std::ostringstream ost; 
	for(auto t : _transcripts){

		ost << *t; 
		transcript_combobox.append(ost.str()); 
		ost.str(std::string()); 	

	}
	transcript_combobox.set_active(0); 

	// create combobox for Courses
	Gtk::Label l_course{"Grade"};	
	Gtk::ComboBoxText course_combobox{true}; 
	course_combobox.append("A"); 	
	course_combobox.append("B"); 	
	course_combobox.append("C"); 	
	course_combobox.append("D"); 	
	course_combobox.append("F"); 	
	course_combobox.append("I"); 	
	course_combobox.append("X"); 	
	course_combobox.set_active(0); 

	// attach transcript choice
	grid.attach(t_course, 0, 0, 1, 1); 
	grid.attach(transcript_combobox, 1, 0, 2, 1); 

	// attach Course combobox to grid
	grid.attach(l_course, 0, 1, 1, 1); 
	grid.attach(course_combobox, 1, 1, 2, 1); 

	// add grid with entries to dialog
	dialog.get_content_area()->add(grid); 

	// add okay and cancel buttons to dialogue
	dialog.add_button("Set Grade", Gtk::RESPONSE_OK); 
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL); 

	// show dialog
	dialog.show_all(); 

	// verify user has chosen from given options
	int result = dialog.run(); 
	int incorrect;	// 0 for correct response  
	int course_choice;  
	int t_choice;  
	do{
		// exit if cancel was pressed on first run 
		if(result != Gtk::RESPONSE_OK) break; 
	
		// set incorrect to false by default
		incorrect = 0; 

		// check Transcript choice
		t_choice =  transcript_combobox.get_active_row_number(); 
		if(t_choice < 0){
			incorrect++; 
		}

		// check Course choice
		course_choice =  course_combobox.get_active_row_number(); 
		if(course_choice < 0){
			incorrect++; 
		}

		// display error dialog
		if(incorrect > 0) 
			Gtk::MessageDialog{*this, "Please choose from dropdowns"}.run(); 

	}
	while(incorrect && (result = dialog.run()) == Gtk::RESPONSE_OK); 

	if(result == Gtk::RESPONSE_OK){

		// Find chosen semester 
		Grade semester; 
		switch(course_choice){

			case 0: semester = Grade::A; 	break;  
			case 1: semester = Grade::B; 	break;
			case 2: semester = Grade::C;    break;
			case 3: semester = Grade::D;    break;
			case 4: semester = Grade::F;    break;
			case 5: semester = Grade::I;    break;
			case 6: semester = Grade::X;    break;

		}

		// Finder chosen course	
		Transcript * transcript = _transcripts[t_choice]; 
		
		// Fix grade
		transcript->assign_grade(semester); 
		
	}


	// update display
	show_data(5); 

} 


//// /////////////////
//// U T I L I T I E S
//// /////////////////

// update display area 
// display_setting
// 1 = Students and Parents, 2 = Courses, 3 = Sections
void Mainwin::show_data(int display_setting){
	
	// 1: Display students and parents 
	if(display_setting == 1){

		std::ostringstream stu_ost; 
		std::ostringstream par_ost; 
		
		// Add Student Data
		stu_ost << "Students:\n"; 
		for(auto &st : _students){
			 // output name and grade
			 stu_ost << st->full_info(); 
			 stu_ost << "Parents: "; 

			 // output all parent info 
			 for(Parent * p : *st) stu_ost << *p << ", "; 
			 stu_ost << std::endl; 
		}
	
		// Add Parent Data
		par_ost << "Parents:\n"; 
		for(auto &pr : _parents){
			 // name email 
			 par_ost << pr->full_info(); 
			 par_ost << " Students: "; 

			 // student info
			 for(Student * s : *pr) par_ost << *s << ", "; 
			 par_ost << std::endl; 
		}
		
		display->set_markup(stu_ost.str()); 
		display2->set_markup(par_ost.str()); 
	}
	// 2: Display Courses
	else if(display_setting == 2){
		
		Glib::ustring c = ""; 
		Glib::ustring dummy = ""; 

		// Add Course data
		c += "Courses:\n"; 
		std::ostringstream oss; 
		for(auto &cs : _courses){
			oss << *cs << std::endl; 
		}
		c += oss.str(); 

		display->set_markup(c); 
		display2->set_markup(dummy); // turn off display 2
	}
	// 3: Display Sections 
	else if(display_setting == 3){

		Glib::ustring s = ""; 
		Glib::ustring dummy = ""; 

		// Add Section data
		s += "Sections:\n"; 
		std::ostringstream oss; 
		for(auto &st : _sections){
			oss << *st << std::endl; 
		}
		s += oss.str(); 
		
		display->set_markup(s); 
		display2->set_markup(dummy); 
	}
	// 4: Display Teachers 
	else if(display_setting == 4){

		Glib::ustring s = ""; 
		Glib::ustring dummy = ""; 

		// Add Section data
		s += "Teachers:\n"; 
		std::ostringstream oss; 
		for(auto &st : _teachers){
			oss << st->full_info() << std::endl; 
		}
		s += oss.str(); 
		
		display->set_markup(s); 
		display2->set_markup(dummy); 
	}
	// 5: Display Transcript
	else if(display_setting == 5){


		Glib::ustring s = ""; 
		Glib::ustring dummy = ""; 

		// Add Section data
		s += "Transcripts:\n"; 
		std::ostringstream oss; 
		for(auto &st : _transcripts){
			oss << *st << std::endl; 
		}
		s += oss.str(); 
		
		display->set_markup(s); 
		display2->set_markup(dummy); 
	}

}
