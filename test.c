#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Size: %i\n", sizeof(useconds_t));
    return 0;
}

