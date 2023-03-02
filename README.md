# Memsafe Boii

A simple header only library for handling memory in C/C++, without any possibility of memory leaks.

## Usage

Just 3 simple functions:
- `void* memsafe_boii_api__allocate(size_t mem_size)` - Allocates memory
- `void memsafe_boii_api__deallocate(void* mem_ptr)` - Deallocates memory
- `void memsafe_boii__clean()` - Cleans up any un-freed memory at the end of the program

See `test.c` for example usage.

## Testing

#### Compiling with `DEBUG` flag
```sh
gcc memsafe_boii.c test.c -DDEBUG -g -o test
```

#### Running test
```sh
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
