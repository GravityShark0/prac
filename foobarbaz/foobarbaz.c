#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    char* usage = "./foobarbaz <num>";
    
    if (argc != 2)
    {
        printf("%s",usage);
        return 1;
    }

    int n = atoi(argv[1]);

    struct map {
        int divisor;
        const char* name;
    };

    struct map maps[] = {
        {3, "Foo"},
        {5, "Bar"},
        {7, "Baz"}
    };


    for (int i = 1; i <= n; i++)
    {
        bool isDivisible = false;
        for (int j = 0; j < (sizeof(maps) / sizeof(maps[0])); j++)
        {
            if (i % maps[j].divisor == 0)
            {
                printf("%s",maps[j].name);
                isDivisible = true;
            }
        }
        if (isDivisible == true)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
