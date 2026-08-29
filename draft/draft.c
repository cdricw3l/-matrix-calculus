#include "../matrice.h"


int main(void)
{
    long test =  strtol("2111", NULL, 10);
    assert(test == 2111);
    test = strtol("4444444444444444444444444444444444444444444444444444444444", NULL, 10);
    printf("erno: %d\n", errno);
    assert(test == 0);
    return (0);
}