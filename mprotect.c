#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>	
#include <stdlib.h>

#define BUF_SIZE 1024

int main() {
	char* buf;
	printf("Size of buffer: %u\n", sizeof(buf));

	int pagesize = sysconf(_SC_PAGE_SIZE);
	printf("Page size: %u\n", pagesize);

	int status = posix_memalign((void**)&buf, pagesize, 4 * pagesize);
	if(status == 0){
	  puts("Error on memalign\n");
	}

	if(mprotect(buf, BUF_SIZE, PROT_READ) == -1){
	  puts("Error occurred on mprotect\n");
	}

	char text[10] = "Hello";
	puts("Should segfault after this\n");
	strcpy(buf, text);
	
	puts(buf);
}
