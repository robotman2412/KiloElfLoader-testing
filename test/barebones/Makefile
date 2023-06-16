
.PHONE: all clean build

all: build

build: Makefile barebones.c
	@riscv32-unknown-linux-gnu-gcc \
		-nodefaultlibs -nostdlib \
		-fPIC \
		-mno-relax \
		-o barebones.elf \
		../libstub0/libstub0.elf \
		../lib0/lib0.elf \
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
