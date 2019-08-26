.PHONY: build

all: clean build run

clean:
	rm -rf ./build/economic-model.out

build:
	gcc -o ./build/economic-model.out ./src/main.c ./src/actors/person.c

run:
	./build/economic-model.out
