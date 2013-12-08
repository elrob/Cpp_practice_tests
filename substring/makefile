substring: main.o substring.o
	g++ -g -Wall main.o substring.o -o substring

main.o: main.cpp substring.h
	g++ -c -g -Wall main.cpp

substring.o: substring.cpp substring.h
	g++ -c -g -Wall substring.cpp

clean:
	rm -rf *.o substring