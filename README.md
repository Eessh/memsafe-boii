# Memsafe Boii

A simple header only library for handling memory in C/C++, without any possibility of memory leaks.

## Usage

Just 4 simple functions:
- ```c
  void* memsafe_boii_api__allocate(size_t mem_size) // Allocates memory
  ```
- ```c
  void* memsafe_boii_api__reallocate(void* mem_ptr, size_t new_mem_size) // Re-Allocates memory
  ```
- ```c
  void memsafe_boii_api__deallocate(void* mem_ptr) // Deallocates memory
  ```
- ```c
  // Should be called at the end of program
  // Cleans up any un-freed memory
  void memsafe_boii__clean()
  ```

See `test.c` for example usage.

## Testing

#### Compiling with `DEBUG` flag
```shell
gcc memsafe_boii.c test.c -DDEBUG -g -o test
```

#### Running test
```shell
./test

MemsafeBoii__Log: Allocation:
  memory_size: 24
  function_name: main
  line_number: 14
  file: test.c
MemsafeBoii__Log: Allocation:
  memory_size: 24
  function_name: main
  line_number: 15
  file: test.c
MemsafeBoii__Log: Deallocation:
  address: 0000022d4a531440
  function_name: main
  line_number: 17
  file: test.c
MemsafeBoii__Log: Cleanup (deallocating un-freed memory):
  address: 0000022d4a5314e0
  function_name: main
  line_number: 21
  file: test.c

 * MemsafeBoii * Total cleanups done: 1
```

## Memory Leaks check with [Valgrind](https://valgrind.org/)

No leaks were reported by valgrind 🔥

```shell
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

==113== Memcheck, a memory error detector
==113== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==113== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==113== Command: ./test
==113==
Hola
MemsafeBoii__Log: Allocation:
  memory_size: 24
  function_name: main
  line_number: 14
  file: test.c
MemsafeBoii__Log: Allocation:
  memory_size: 24
  function_name: main
  line_number: 15
  file: test.c
MemsafeBoii__Log: Deallocation:
  address: 0x4a4b480
  function_name: main
  line_number: 17
  file: test.c
MemsafeBoii__Log: Cleanup (deallocating un-freed memory):
  address: 0x4a4b5f0
  function_name: main
  line_number: 21
  file: test.c

 * MemsafeBoii * Total cleanups done: 1
==113==
==113== HEAP SUMMARY:
==113==     in use at exit: 0 bytes in 0 blocks
==113==   total heap usage: 9 allocs, 9 frees, 1,192 bytes allocated
==113==
==113== All heap blocks were freed -- no leaks are possible
==113==
==113== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
