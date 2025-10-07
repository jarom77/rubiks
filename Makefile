CC=g++
FLAGS=Wall

all: main

main: rubiks.cpp rubiks_ops.cpp main.cpp
	$(CC) -$(FLAGS) -o $@ $^

unit_test: rubiks.cpp rubiks_ops.cpp unit_test.cpp
	$(CC) -$(FLAGS) -o $@ $^

test: unit_test
	echo "ggggwwgwgbybbyybbbyyyyrryrywowwoowwwrrrbbrrbrogoggoooo" | ./unit_test
