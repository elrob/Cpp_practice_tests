correct: main.o correct.o
	g++ -g -Wall main.o correct.o -o correct

main.o: main.cpp correct.h
	g++ -c -g -Wall main.cpp

correct.o: correct.cpp correct.h
	g++ -c -g -Wall correct.cpp

clean:
	rm -rf *.o correct
