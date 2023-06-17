
.PHONE: all clean build

all: build

build: Makefile barebones.c
	@riscv32-unknown-linux-gnu-gcc \
		-nodefaultlibs -nostdlib \
		-fPIC \
		-mno-relax \
		-o barebones.elf \
		barebones.c
	@riscv32-unknown-linux-gnu-gcc \
		-nodefaultlibs -nostdlib \
		-fPIC \
		-mno-relax \
		-o barebones.S \
		-S barebones.c
	echo CC barebones.c
	

clean:
	rm -f barebones.elf
