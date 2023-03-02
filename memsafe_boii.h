#ifndef MEMSAFE__BOII
#define MEMSAFE__BOII

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define memsafe_boii_api__allocate(mem_size)                                                       \
	memsafe__boii__allocate(mem_size, __FILE__, __LINE__, __FUNCTION__)
#define memsafe_boii_api__deallocate(entity)                                                       \
	memsafe__boii__deallocate(entity, __FILE__, __LINE__, __FUNCTION__)
#define memsafe_boii_api__clean() memsafe__boii__clean(__FILE__, __LINE__, __FUNCTION__)

/**
 * This is the allocation record, which will be stored
 * in a linked list of allocation records.
 */
typedef struct memsafe__boii__allocation
{
	void* mem_address;
	size_t mem_size;
	char* func_call_file;
	size_t func_call_line;
	char* func_name;

	struct memsafe__boii__allocation* next;
} memsafe__boii__allocation;

/**
 * This is the linked list for the allocation records.
 */
typedef struct memsafe__boii__allocation_list
{
	memsafe__boii__allocation* head;
	memsafe__boii__allocation* tail;
} memsafe__boii__allocation_list;

/**
 * Creates/allocates memory for a new allocation record.
 *
 * Returns `NULL` if unable to create record.
 */
static memsafe__boii__allocation* memsafe__boii__allocation_new(void* mem_address,
																																size_t mem_size,
																																const char* func_call_file,
																																size_t func_call_line,
																																const char* func_name);

/**
 * Frees/deallocates memory for the allocation record.
 */
static void memsafe__boii__allocation_free(memsafe__boii__allocation* record);

/**
 * Creates/allocates memory for a new allocation record list.
 *
 * Returns `NULL` if unable to create new allocation record list.
 */
static memsafe__boii__allocation_list* memsafe__boii__allocation_list_new();

/**
 * Adds the new allocation record to the record list.
 */
static void memsafe__boii__allocation_list_add_record(memsafe__boii__allocation_list* list,
																											memsafe__boii__allocation* record);

/**
 * Removes the allocation record for the address pointed by the entity.
 */
static void memsafe__boii__allocation_list_remove_record(memsafe__boii__allocation_list* list,
																												 void* entity);

/**
 * Frees/deallocates memory for allocation record list.
 */
static void memsafe__boii__allocation_list_free(memsafe__boii__allocation_list* list);

/**
 * Actual variable which holds the records.
 */
static memsafe__boii__allocation_list memory_allocations_record_list =
	(memsafe__boii__allocation_list){.head = NULL, .tail = NULL};

/**
 * Allocates memory of given size and
 * logs the function in debug mode (`#define DEBUG`) which called allocate.
 *
 * Returns `NULL` if unable to allocate memory.
 *
 * Stores a record of this allocation, for
 * detecting memory leaks if not deallocated.
 *
 * It is advised to call `memsafe__boii__clean()`
 * at the end of your program, it clears up all
 * of the un-freed memory, preventing memory leaks.
 */
void* memsafe__boii__allocate(size_t mem_size,
															const char* func_call_file,
															size_t func_call_line,
															const char* func_name);

/**
 * Deallocates memory of the given pointer
 * and logs the function in debug mode (`#define DEBUG`) which called allocate.
 *
 * Removes the record for allocation.
 */
void memsafe__boii__deallocate(void* entity,
															 const char* func_call_file,
															 size_t func_call_line,
															 const char* func_name);

/**
 * Cleans up all of the un-freed memory.
 *
 * It is advised to call `memsafe__boii__clean()`
 * at the end of your program, preventing memory leaks.
 */
void memsafe__boii__clean(const char* func_call_file, size_t func_call_line, const char* func_name);

#endif
