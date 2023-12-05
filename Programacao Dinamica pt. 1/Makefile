all:
	g++ -o exercise9 exercise9.cpp -g

clean:
	rm exercise9

run:
	./exercise9 < 1.in

test:
	valgrind -s --tool=memcheck --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./exercise9 < 1.in