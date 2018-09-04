CXXFLAGS = -DNDEBUG

main.exe: main.o
	g++ main.o -o main.exe

main.o: main.cpp stack.h
	g++ $(CXXFLAGS) -c main.cpp -o main.o

.PHONY: clean

doc:
	doxygen

clean:
	rm *.exe *.o

cleanall:
	rm -r *.exe *.o html