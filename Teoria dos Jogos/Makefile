all:
	g++ -o exercise16 exercise16.cpp -g

clean:
	rm exercise16

run:
	./exercise16 < 1.in

test:
	valgrind -s --tool=memcheck --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./exercise16 < 1.in