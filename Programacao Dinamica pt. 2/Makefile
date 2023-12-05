all:
	g++ -o exercise10 exercise10.cpp -g

clean:
	rm exercise10

run:
	./exercise10 < 1.in

test:
	valgrind -s --tool=memcheck --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./exercise10 < 1.in