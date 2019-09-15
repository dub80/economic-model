CC=gcc

.PHONY: build test leak
TEST_SRC_FILES = $(filter-out src/main.c, $(wildcard src/*.c))

all: clean build run

clean:
	rm -rf ./build/economic-model.out

build:
	gcc -o ./build/economic-model.out ./src/*.c

run:
	./build/economic-model.out

disassemble:
	otool -tvV ./build/economic-model.out

test:
	gcc -Wall -o ./test/economic-model.out ./test/economic-model.c $(TEST_SRC_FILES) -lcheck -I ./test/
	./test/economic-model.out -v

check-leak:
	gcc -ggdb -o ./test/economic-model-leak.out ./src/*.c -fsanitize=address -fno-omit-frame-pointer
	./test/economic-model-leak.out