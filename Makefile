CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: smart

debug: CXXFLAGS += -g
debug: clean
debug: smart

smart: mainwin.o parent.o student.o person.o  main.o course.o section.o subject.o semester.o teacher.o grade.o transcript.o 
	$(CXX) $(CXXFLAGS) mainwin.o parent.o student.o person.o  main.o course.o section.o subject.o semester.o teacher.o grade.o transcript.o $(GTKFLAGS) -o smart 

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp $(GTKFLAGS) -o parent.o

student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp $(GTKFLAGS) -o student.o

person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp $(GTKFLAGS) -o person.o

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

course.o: course.cpp *.h
	$(CXX) $(CXXFLAGS) -c course.cpp $(GTKFLAGS) -o course.o

section.o: section.cpp *.h
	$(CXX) $(CXXFLAGS) -c section.cpp $(GTKFLAGS) -o section.o

subject.o: subject.cpp *.h
	$(CXX) $(CXXFLAGS) -c subject.cpp $(GTKFLAGS) -o subject.o

semester.o: semester.cpp *.h
	$(CXX) $(CXXFLAGS) -c semester.cpp $(GTKFLAGS) -o semester.o

teacher.o: teacher.cpp *.h
	$(CXX) $(CXXFLAGS) -c teacher.cpp $(GTKFLAGS) -o teacher.o

grade.o: grade.cpp *.h
	$(CXX) $(CXXFLAGS) -c grade.cpp $(GTKFLAGS) -o grade.o

transcript.o: transcript.cpp *.h
	$(CXX) $(CXXFLAGS) -c transcript.cpp $(GTKFLAGS) -o transcript.o

clean:
	rm -f *.o *.gch *~ smart a.out


