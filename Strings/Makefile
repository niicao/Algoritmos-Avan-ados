all:
	g++ -o exercise15 exercise15.cpp -g

clean:
	rm exercise15

run:
	./exercise15 < 1.in

test:
	valgrind -s --tool=memcheck --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./exercise15 < 1.in