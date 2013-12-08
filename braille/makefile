braille: main.o braille.o
	g++ -g -Wall main.o braille.o -o braille

main.o: main.cpp braille.h
	g++ -c -g -Wall main.cpp

braille.o: braille.cpp braille.h
	g++ -c -g -Wall braille.cpp

clean:
	rm -rf *.o braille
