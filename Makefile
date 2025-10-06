CC=g++
FLAGS=Wall

all: main

main: rubiks.cpp rubiks_ops.cpp main.cpp
	$(CC) -$(FLAGS) -o $@ $?
