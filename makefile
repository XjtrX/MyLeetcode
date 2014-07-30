HEADFILES = maxPathSum.h 

a.out : main.o 
	g++ -o main.out  main.o

main.o : main.cpp $(HEADFILES)
	gcc -c main.cpp
clean :
	rm *.o *.out
