all:
	g++ -o exercicio8 exercicio8.cpp -g

clean:
	rm exercicio8

run:
	./exercicio8 < 1.in

test:
	valgrind -s --tool=memcheck --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./exercicio8 < 1.in
