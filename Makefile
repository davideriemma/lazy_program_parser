# Makefile

all: main

main: ../main.c
	gcc -g -o $@ $^