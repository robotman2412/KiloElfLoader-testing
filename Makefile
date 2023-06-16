
.PHONY: all clean build run gdb

all: build run

build:
	@mkdir -p build
	@cmake -B build
	@make -s -C build
	@make -s -C test build

clean:
	rm -rf build
	@make -s -C test clean

run:
	./build/elftest
