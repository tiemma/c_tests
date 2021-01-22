
#include <stdlib.h>

int main(void) {
    int pagesize = 100;
    int a[pagesize];
    int status = posix_memalign((void**)&a, pagesize, 4 * pagesize);
}
