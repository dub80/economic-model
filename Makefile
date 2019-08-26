.PHONY: build

build:
	gcc -o ./build/economic-model.out ./src/main.c

run:
	./build/economic-model.out
