CC=g++
FLAGS=Wall

all: main

main: rubiks.o rubiks_ops.o rubiks_solve.o rubiksIterators.o main.o
	$(CC) -$(FLAGS) -o $@ $^

solve: rubiks.o rubiks_ops.o rubiks_solve.o rubiksIterators.o solve.o
	$(CC) -$(FLAGS) -o $@ $^

solve_test: solve
	echo "wrbbwboygrgggygbobrygrrogwyygwyoyobyrrbwbborwowwogwroy" | ./solve

unit_test: rubiks.o rubiks_ops.o unit_test.o
	$(CC) -$(FLAGS) -o $@ $^

test: unit_test
	echo "ggggwwgwgbybbyybbbyyyyrryrywowwoowwwrrrbbrrbrogoggoooo" | ./unit_test

%.o: %.cpp
	$(CC) -$(FLAGS) -c -o $@ $^
