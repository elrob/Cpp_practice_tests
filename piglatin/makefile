piglatin: main.o piglatin.o
	g++ -g -Wall main.o piglatin.o -o piglatin

main.o: main.cpp piglatin.h
	g++ -c -g -Wall main.cpp

piglatin.o: piglatin.cpp piglatin.h
	g++ -c -g -Wall piglatin.cpp

clean:
	rm -rf *.o piglatin
