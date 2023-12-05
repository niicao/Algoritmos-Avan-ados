all:
	g++ -o exercise14 exercise14.cpp -g

clean:
	rm exercise14

run:
	./exercise14 < 1.in

test:
	valgrind -s --tool=memcheck --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./exercise 14 < 1.in