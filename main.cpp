#include "mainwin.h" 

int main(int argc, char** argv){

	// build application 
	auto app = Gtk::Application::create(argc, argv, "smart.app"); 

	// instance window 
	Mainwin win; 

	return app->run(win); 
}
