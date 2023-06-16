
.PHONE: all clean build

all: build

build: Makefile libstub0.c
	@riscv32-unknown-linux-gnu-gcc \
		-nodefaultlibs -nostdlib \
		-fpic \
		-o libstub0.elf \
		-shared libstub0.c
	echo CC libstub0.c
	

clean:
	rm -f libstub0.elf
