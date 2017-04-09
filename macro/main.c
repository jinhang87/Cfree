#include <stdio.h>

#define LLVM_VERSION_MAJOR 3
#define LLVM_VERSION_MINOR 6



#ifndef HAVE_LLVM
#define HAVE_LLVM ((LLVM_VERSION_MAJOR << 8) | LLVM_VERSION_MINOR)
#endif

#if HAVE_LLVM 
#endif



int main(int argc, char *argv[])
{
	printf("Hello C-Free!\n");
	return 0;
}
