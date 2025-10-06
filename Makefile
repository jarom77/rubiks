CC=g++
FLAGS=Wall

all: main

main: rubiks.cpp rubiks_ops.cpp main.cpp
	$(CC) -$(FLAGS) -o $@ $^

unit_test: rubiks.cpp rubiks_ops.cpp unit_test.cpp
	$(CC) -$(FLAGS) -o $@ $^

test: unit_test
	echo "g g g g w w g w g b y b b y y b b b y y y y r r y r y w o w w o o w w w r r r b b r r b r o g o g g o o o o" | ./unit_test
