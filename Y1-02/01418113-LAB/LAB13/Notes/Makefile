CXX = clang++

run : make
	./main

make :
	$(CXX)	-c	person.cpp
	$(CXX)	-c	teacher.cpp
	$(CXX)	-c	student.cpp
	$(CXX)	-g	person.o teacher.o student.o	main.cpp	-o main