
#include <kbelf.h>
#include <stdio.h>

int main(int argc, char **argv) {
	printf("Hi Ther.\n");
	
	kbelf_dyn dyn = kbelf_dyn_create(1);
	if (!dyn) {
		printf("No dyn :c\n");
		return 1;
	}
	
	if (!kbelf_dyn_set_exec(dyn, "test/barebones/barebones.elf", NULL)) {
		printf("No exec :c\n");
		return 1;
	}
	
	if (!kbelf_dyn_load(dyn)) {
		printf("No image :c\n");
		return 1;
	}
	
	printf("# PREINIT: %zu\n", kbelf_dyn_preinit_len(dyn));
	for (size_t i = 0; i < kbelf_dyn_preinit_len(dyn); i++) {
		printf("  0x%08lx\n", kbelf_dyn_preinit_get(dyn, i));
	}
	printf("\n");
	
	printf("# INIT: %zu\n", kbelf_dyn_init_len(dyn));
	for (size_t i = 0; i < kbelf_dyn_init_len(dyn); i++) {
		printf("  0x%08lx\n", kbelf_dyn_init_get(dyn, i));
	}
	printf("\n");
	
	printf("# FINI: %zu\n", kbelf_dyn_fini_len(dyn));
	for (size_t i = 0; i < kbelf_dyn_fini_len(dyn); i++) {
		printf("  0x%08lx\n", kbelf_dyn_fini_get(dyn, i));
	}
	printf("\n");
	
	void (*initptr)(void);
	for (size_t i = 0; i < kbelf_dyn_preinit_len(dyn); i++) {
		initptr = (void *) kbelf_dyn_preinit_get(dyn, i);
		initptr();
	}
	for (size_t i = 0; i < kbelf_dyn_init_len(dyn); i++) {
		initptr = (void *) kbelf_dyn_init_get(dyn, i);
		initptr();
	}
	
	printf("Time for exec.\n");
	int (*fptr)(void);
	fptr = (void *) kbelf_dyn_entrypoint(dyn);
	int res = fptr();
	printf("Return value: %d (0x%08x)\n", res, res);
	
	
	
	// kbelf_file exec = kbelf_file_open("test/barebones/barebones.elf", NULL);
	// if (!exec) {
	// 	printf("No exec :c\n");
	// 	return 1;
	// }
	
	// kbelf_file lib = kbelf_file_open("test/lib0/lib0.elf", NULL);
	// if (!lib) {
	// 	printf("No exec :c\n");
	// 	return 1;
	// }
	
	// kbelf_inst execi = kbelf_inst_load(exec, 1);
	// if (!execi) {
	// 	printf("No execi :c\n");
	// }
	// kbelf_inst libi  = kbelf_inst_load(lib, 1);
	// if (!libi) {
	// 	printf("No libi :c\n");
	// }
	
	// kbelf_reloc reloc = kbelf_reloc_create();
	// if (!reloc) {
	// 	printf("No new reloc :c\n");
	// 	return 1;
	// }
	// if (!kbelf_reloc_add(reloc, exec, execi)) {
	// 	printf("No reloc exec :c\n");
	// 	return 1;
	// }
	// if (!kbelf_reloc_add(reloc, lib,  libi)) {
	// 	printf("No reloc lib :c\n");
	// 	return 1;
	// }
	// if (!kbelf_reloc_perform(reloc)) {
	// 	printf("No reloc :c\n");
	// 	return 1;
	// }
	
	// printf("Time for exec.\n");
	// int (*fptr)(void);
	// fptr = (void *) kbelf_inst_entrypoint(execi);
	// int res = fptr();
	// printf("Return value: %d (0x%08x)\n", res, res);
	
	return 0;
}
