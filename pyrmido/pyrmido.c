#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int size = atoi(argv[1]);

    if ( size <= -1 )
    {
        return 1;
    }

    for (int i = 0; i < size; i++ )
    {
        for (int j = i; j < size; j++ )
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++ )
        {
            printf("#");
        }
        for (int j = 0; j < i; j++ )
        {
            printf("#");
        }

        printf(" %i \n", i + 1);
    }
    printf("\n");

    return 0;
}
