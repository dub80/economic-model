CC=gcc

.PHONY: build test leak

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
	gcc -Wall -o ./test/economic-model.out ./test/economic-model.c ./src/actors/person.c -lcheck -I ./test/
	./test/economic-model.out

check-leak:
	gcc -ggdb -o ./test/economic-model-leak.out ./src/main.c ./src/actors/person.c -fsanitize=address -fno-omit-frame-pointer
	./test/economic-model-leak.out