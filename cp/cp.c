#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char* usage = "Usage: cp <input file> <output file>\ncopy a file to a file name (will override)\n";
    if (argc != 3)
    {
        printf("Not enough arguments%s", usage);
        return 1;
    }

    FILE* in = fopen(argv[1], "r");
    FILE* outtest = fopen(argv[2], "r");
    if (in == NULL)
    {
        printf("Incorrect input/n%s", usage);
        return 2;
    }

    if (outtest != NULL)
    {
        printf("Are you sure you want to overwrite %s? [Y/N]\n",argv[2]);
        char* yn = malloc(sizeof(char));
        scanf("%s",yn);
        yn[0] = tolower(yn[0]);
        if (yn[0] != 'y' || yn[0] != 'n' || strlen(yn) != 1)
        {
            return 3;
        }

        fclose(outtest);
    }


    FILE* out = fopen(argv[2], "w");

    char buffer;
    while (fread(&buffer, sizeof(char), 1, in)) 
    {
        fwrite(&buffer, sizeof(char), 1, out);
    }

    fclose(in);
    fclose(out);

    printf("haha hard drive gone\n");

    return 0;
}
