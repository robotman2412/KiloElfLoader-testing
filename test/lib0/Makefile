
.PHONE: all clean build

all: build

build: Makefile lib0.c
	@riscv32-unknown-linux-gnu-gcc \
		-nodefaultlibs -nostdlib \
		-fpic \
		-o lib0.elf \
		-shared lib0.c
	@riscv32-unknown-linux-gnu-gcc \
		-nodefaultlibs -nostdlib \
		-fpic \
		-o lib0.S \
		-S lib0.c
	echo CC lib0.c
	

clean:
	rm -f lib0.elf
