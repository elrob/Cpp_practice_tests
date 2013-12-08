soundex: main.o soundex.o
	g++ -g -Wall main.o soundex.o -o soundex

main.o: main.cpp soundex.h
	g++ -c -g -Wall main.cpp

soundex.o: soundex.cpp soundex.h
	g++ -c -g -Wall soundex.cpp

clean:
	rm -rf *.o soundex
