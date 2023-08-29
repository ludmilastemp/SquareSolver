a.exe:  draw_cats.o infile.o io.o main.o print_equation.o solve.o tests.o
	g++ draw_cats.o infile.o io.o main.o print_equation.o solve.o tests.o

draw_cats.o:      draw_cats.cpp         draw_cats.h      struct.h
	g++ 	   -c draw_cats.cpp      -o draw_cats.o

infile.o:         infile.cpp            infile.h         struct.h
	g++		   -c infile.cpp         -o infile.o

io.o:             io.cpp                io.h             struct.h      print_equation.h     draw_cats.h
	g++ 	   -c io.cpp             -o io.o

main.o:           main.cpp              solve.h			 tests.h 		draw_cats.h
	g++        -c main.cpp           -o main.o

print_equation.o: print_equation.cpp    print_equation.h struct.h
	g++        -c print_equation.cpp -o print_equation.o

solve.o:          solve.cpp             solve.h          struct.h
	g++        -c solve.cpp          -o solve.o

tests.o:          tests.cpp             tests.h          struct.h draw_cats.h infile.h print_equation.h solve.h
	g++ 	   -c tests.cpp          -o tests.o
