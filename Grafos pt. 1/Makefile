all:
	g++ -o exercise7 exercise7.cpp

clean:
	rm exercise7

run:
	./exercise7 < 1.in

test:
	valgrind -s --tool=memcheck --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./exercise7 < 1.in

gpt:
	g++ -o unionGraphs unionGraphs.cpp

rungpt:
	./unionGraphs < 1.in
