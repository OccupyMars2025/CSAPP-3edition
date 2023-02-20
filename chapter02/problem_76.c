#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


void* my_calloc(size_t nmemb, size_t size)
{
    if ((nmemb == 0) || (size == 0))
        return NULL;
    size_t total_bytes = nmemb * size;

    if (nmemb != total_bytes / size) 
    {
        return NULL;
    }
    void* p = malloc(total_bytes);
    if (p == NULL)
        return NULL;
    memset(p, 0, total_bytes);
    return p;
}

int main(void)
{
    int *p1 = my_calloc(4, sizeof(int));    // allocate and zero out an array of 4 int
    int *p2 = my_calloc(1, sizeof(int[4])); // same, naming the array type directly
    int *p3 = my_calloc(4, sizeof *p3);     // same, without repeating the type name
 
    if(p2) {
        for(int n=0; n<4; ++n) // print the array
            printf("p2[%d] == %d\n", n, p2[n]);
    }
 
    free(p1);
    free(p2);
    free(p3);

    void* p;
    p = my_calloc(0x1234, 1);
    assert(p != NULL);
    int* int_p = (int*) p;
    for (size_t i = 0; i < 0x1234 / 4; i++)
    {
        printf("%d, ", int_p[i]);
        assert(int_p[i] == 0);
    }
    free(p);
    

    p = my_calloc(SIZE_MAX, 2);
    assert(p == NULL);
    free(p);
}