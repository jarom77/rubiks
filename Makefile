CC=g++
FLAGS=Wall
RUBIKS=rubiks.o rubiks_ops.o rubiks_solve.o rubiksIterators.o

default: solve_begin solve_easy solve_med solve_hard

all: main solve example unit_test

solve_begin: solve
	echo "bbbrwwrwwgggyyoyyoyyyrrrrrrwoowoowooobbybbybbggrggwggw" | ./$<

solve_easy: solve
	echo "ygrowwboyobbbybbyogoogrggrryyryorybwbwrybrwwggrwggwoow" | ./$<

solve_med: solve
	echo "owwbwroobyyryyygwrrrbbrgrrwggoboyyooyrywbwbbbwggogowgg" | ./$<

solve_hard: solve
	echo "wrbbwboygrgggygbobrygrrogwyygwyoyobyrrbwbborwowwogwroy" | ./$<

main: $(RUBIKS) main.o
	$(CC) -$(FLAGS) -o $@ $^

solve: $(RUBIKS) solve.o
	$(CC) -$(FLAGS) -o $@ $^

example: $(RUBIKS) example.o
	$(CC) -$(FLAGS) -o $@ $^

unit_test: $(RUBIKS) unit_test.o
	$(CC) -$(FLAGS) -o $@ $^

test: unit_test
	echo "ggggwwgwgbybbyybbbyyyyrryrywowwoowwwrrrbbrrbrogoggoooo" | ./$@

%.o: %.cpp
	$(CC) -$(FLAGS) -c -o $@ $^
