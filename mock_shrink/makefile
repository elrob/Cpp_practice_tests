shrink: shrink.o main.o
	g++ -g -Wall shrink.o main.o -o shrink

main.o: main.cpp shrink.h
	g++ -c -g -Wall main.cpp

shrink.o: shrink.cpp shrink.h
	g++ -c -g -Wall shrink.cpp

clean:
	rm -rf *.o shrink