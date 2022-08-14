#ifndef __CCC_H
#define __CCC_H
#include <vector> 
#include <sstream> 

template <class T>
class ComboBoxContainer : public Gtk::ComboBoxText{
	public: 
		ComboBoxContainer(std::vector<T*> t){
			// iterate over t, place each element in combobox
			std::ostringstream ost; 
			for(auto& i : t) {

				// add to combobox dropdown 
				ost << *i; 
				append(ost.str()); 	

				// erase stream
				ost.str(std::string()); 

			}
		
		}
}; 

#endif
