CC=gcc

.PHONY: build test leak temp
SRC_FILES = $(wildcard src/*.c)
TEST_SRC_FILES = $(filter-out src/main.c, $(SRC_FILES))

all: clean build run

clean:
	rm -rf ./build/economic-model.out

build:
	printf '%s\n' "> build:"
	gcc -o ./build/economic-model.out ./src/*.c

run:
	printf '%s\n' "> run:"
	./build/economic-model.out

disassemble:
	otool -tvV ./build/economic-model.out

test:
	printf '%s\n' "> test:"
	gcc -Wall -o ./test/test.out ./test/test.c $(TEST_SRC_FILES) -lcheck -I ./test/
	./test/test.out

leak:
	gcc -ggdb -o ./test/economic-model-leak.out $(SRC_FILES) -fsanitize=address -fno-omit-frame-pointer
	./test/economic-model-leak.out

temp:
	gcc -o ./build/temp.out ./temp/main.c
	./build/temp.out

