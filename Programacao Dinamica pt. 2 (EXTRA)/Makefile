all:
	g++ -o exercise11 exercise11.cpp -g -Wall

clean:
	rm exercise11

run:
	./exercise11 < 1.in

test:
	valgrind -s --tool=memcheck --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./exercise11 < 1.in