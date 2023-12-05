all:
	g++ -o exercise13 exercise13.cpp -g

clean:
	rm exercise13

run:
	./exercise13 < 1.in

test:
	valgrind -s --tool=memcheck --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./exercise13 < 1.in