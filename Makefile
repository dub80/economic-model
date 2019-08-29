CC=gcc

.PHONY: build test

all: clean build run

clean:
	rm -rf ./build/economic-model.out

build:
	gcc -o ./build/economic-model.out ./src/main.c ./src/actors/person.c

run:
	./build/economic-model.out

disassemble:
	otool -tvV ./build/economic-model.out

test:
	gcc -Wall -o ./test/economic-model.out ./test/economic-model.c -lcheck -I ./test/
	./test/economic-model.out
