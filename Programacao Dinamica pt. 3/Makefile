all:
	g++ -o exercise12 exercise12.cpp -g

clean:
	rm exercise12

run:
	./exercise12 < 1.in

test:
	valgrind -s --tool=memcheck --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./exercise12 < 1.in