// cppTheory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

// this app will look into memory allocation and pointers with respect
// to C++, read the comments to find out what's happening...

// STACK - the fixed memory (RAM) given to an application

// HEAP - a free pool of memory available to the application (dynamic memory (allocation))
// note: not an implementation of the 'heap' data structure (different topic).

// these two are NOT for C++:
// malloc(amount) - C memory allocation, returns a (void) pointer to the heap
// free(pointer) - C function for freeing memory pointers on the heap

// how to do it in C++:
// new ... - C++ for creating a pointer to dynamic memory (... = variable name)
// delete ... - C++ for removing a pointer to dynamic memory

int _tmain(int argc, _TCHAR* argv[]) // the entry point of the program
{
	// >>>>>>>>>>>>>>>>>>>>>THIS IS C CODE <<<<<<<<<<<<<<<<<<<<<<<<
	int *a; // goes on stack in main method allocation (pointer variable)
	a = (int*)malloc(sizeof(int)); // pointer to address of block of memory on heap

	*a = 10; // the only way to use heap memory is through pointers

	a = (int*)malloc(sizeof(int)); // reserves a new block in the heap (bad)
	*a = 20; // sets the memory in the heap to 20

	// the above code is bad because one pointer is created and memory is reserved
	// for it, then another chunk of memory is reserved using the same reference as
	// the first one, this creates a 'referenceless' chunk of memory in the heap
	// with the value of 10 - this is a minor memory leak.

	delete a; // frees the pointer, deallocating the memory on the heap.
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>> END <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

	// >>>>>>>>>>>>>>>>>>> THE REST IS C++ <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	// allocating arrays is very similar...
	int *arrayPointer; // defines a memory pointer
	arrayPointer = new int[10]; // reserves a block of memory on the heap for 10 integers

	// at this point the application has a pointer and some reserved memory on the heap,
	// it needs to be used then deleted to avoid a memory leak.

	// a memory leak is when an application reserves memory (heap - RAM) then effectively
	// loses or ignores its reference to that memory as such it tries to reserve more,
	// this - especially in loops - can lead to huge amounts of memory being unnecessarily
	// reserved, stopping other applications or the OS from using it.

	delete(arrayPointer); // remove the memory reservation from the heap

	// here no pointers exist and the heap is completely clear :)

	return 0;
}

// >>>>>>>>>>>>>>>>> GRAPHICAL REPRESENTATION <<<<<<<<<<<<<<<<<<<<<<<<<<
// 
// the box represents the RAM within the system, HEAP can vary in size
// ___________________________________________________________________
// |                                                                   |
// |                                                                   |
// |                              HEAP                                 |
// |                        (dynamic memory)                           |
// |                                                                   |
// |___________________________________________________________________|
// |                                                                   |
// |                             STACK                                 |
// |                      (for storing functions                       |
// |                       and local variables)                        |
// |___________________________________________________________________|
// |                                                                   |
// |                          MAIN FUNCTION                            |
// |                     and its local variables                       |
// |___________________________________________________________________|
// |                                                                   |
// |                         GLOBAL THINGS                             |
// |___________________________________________________________________|

