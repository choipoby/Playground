// test.cpp
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d: %d\n", i, rand());
    }
    return 0;
}