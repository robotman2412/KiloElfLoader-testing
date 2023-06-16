
cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_C_COMPILER "riscv32-unknown-linux-gnu-gcc")
set(CMAKE_C_COMPILER_FORCED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(elftest)

add_compile_definitions(KBELF_DEBUG)
add_compile_options(-ggdb)

add_subdirectory(kbelfloader)

add_executable(elftest
	src/main.c
	src/kbelfx.c
)
target_link_libraries(elftest PUBLIC -static kbelf)
