CC=g++
FLAGS=Wall
RUBIKS=rubiks.o rubiks_ops.o rubiks_solve.o rubiksIterators.o

default: main

main: $(RUBIKS) main.o
	$(CC) -$(FLAGS) -o $@ $^

solve: $(RUBIKS) solve.o
	$(CC) -$(FLAGS) -o $@ $^

solve_test: solve
	echo "wrbbwboygrgggygbobrygrrogwyygwyoyobyrrbwbborwowwogwroy" | ./solve

example: $(RUBIKS) example.o
	$(CC) -$(FLAGS) -o $@ $^
	./$@

unit_test: $(RUBIKS) unit_test.o
	$(CC) -$(FLAGS) -o $@ $^

test: unit_test
	echo "ggggwwgwgbybbyybbbyyyyrryrywowwoowwwrrrbbrrbrogoggoooo" | ./unit_test

%.o: %.cpp
	$(CC) -$(FLAGS) -c -o $@ $^
