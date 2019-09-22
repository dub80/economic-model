CC=gcc
CFLAGS=-I/usr/include/gsl
LDFLAGS=-lgsl -lgslcblas -lm
CC=gcc
SRC_FILES = $(wildcard src/*.c)
TEST_SRC_FILES = $(filter-out src/main.c, $(SRC_FILES))
.PHONY: build test leak temp

all: clean build run

clean:
	rm -rf ./build/economic-model.out

build:
	$(CC) -Wall -o ./build/economic-model.out $(SRC_FILES) $(LDFLAGS)

run:
	./build/economic-model.out

disassemble:
	otool -tvV ./build/economic-model.out

test:
	$(CC) -Wall -o ./test/test.out ./test/test.c $(TEST_SRC_FILES) $(LDFLAGS) -lcheck -I ./test/
	./test/test.out

leak:
	$(CC) -Wall -ggdb -o ./test/economic-model-leak.out $(SRC_FILES) -fsanitize=address -fno-omit-frame-pointer $(LDFLAGS)
	./test/economic-model-leak.out

check-leak:
	valgrind --leak-check=full --show-leak-kinds=all ./build/economic-model.out

temp:
	$(CC) -Wall -o ./build/temp.out ./temp/main.c $(LDFLAGS)
	./build/temp.out
