#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void view(FILE* INPUT_FILE);
int copy(FILE* INPUT_FILE, FILE* OUTPUT_FILE);
int encode(FILE* INPUT_FILE, FILE* OUTPUT_FILE);
int decode(FILE* INPUT_FILE, FILE* OUTPUT_FILE);
void delete(FILE* INPUT_FILE, const char* INPUT_FILE_NAME);

static int compare_commands(const void *p1, const void *p2)
{
   const char *order = "vceud";
   char charA = *(const char *) p1;
   char charB = *(const char *) p2;

   char *posA = strchr(order, charA);
   char *posB = strchr(order, charB);

   return posA - posB;
}


int main(int argc, char *argv[]) {
   char* prompt = 
      "args [-hvcdp] INPUT_FILE OUTPUT_FILE\n\
Options:\n\
   -h, show this help message\n\
   -v INPUT_FILE, views/prints the INPUT_FILE\n\
   -c INPUT_FILE OUTPUT_FILE, copies from INPUT_FILE to OUTPUT_FILE\n\
   -e INPUT_FILE OUTPUT_FILE, compresses the INPUT_FILE to OUTPUT_FILE using\n\
      Run-length encoding.\n\
      If OUTPUT_FILE exists, if OUTPUT_FILE does not exist, use INPUT_FILE\n\
   -u INPUT_FILE OUTPUT_FILE, decode the INPUT_FILE to OUTPUT_FILE using\n\
      Run-length encoding.\n\
      If OUTPUT_FILE exists, if OUTPUT_FILE does not exist, use INPUT_FILE\n\
   -d INPUT_FILE, deletes INPUT_FILE\n\n\
   Commands are done by order of this list,\n\
   Ex: -cd INPUT_FILE OUTPUT_FILE to effectively move a file";

   if (argc < 2) {
      printf("ERR: Too little arguments\n%s\n", prompt);
      return 1;
   } else if (argc > 4) {
      printf("ERR: Too many arguments\n%s\n", prompt);
      return 1;
   }

   enum Arguments {
      VIEW,
      COPY,
      COMPRESS,
      DELETE
   };

   char opt;
   int opt_count = 0;
   char* opts = malloc(sizeof(char));

   while ((opt = getopt(argc, argv, "vceud")) != -1) {
      if (realloc(opts, sizeof(char) * ++opt_count) == NULL) {
         return 1;
      }

      switch(opt) {
         case '?':
            return 0;
         case 'h':
            printf("%s\n", prompt);
            return 0;
      }

      opts[opt_count - 1] = opt;
   }

   FILE* INPUT_FILE;
   const char* INPUT_FILE_NAME;
   FILE* OUTPUT_FILE;

   if (optind < argc) {
      INPUT_FILE_NAME = argv[optind];
      INPUT_FILE = fopen(argv[optind], "r");
      optind++;
   }

   if (optind < argc) {
      OUTPUT_FILE = fopen(argv[optind], "w");
   }

   if (INPUT_FILE == NULL) {
      printf("ERR: failed to load input file\n%s\n", prompt);
      return 1;
   }

   qsort(opts, 1, sizeof(char), compare_commands);

   if (opt_count == 0) {
      if (argc == 3)
         view(INPUT_FILE);
      else if (argc == 4)
         copy(INPUT_FILE, OUTPUT_FILE);
   } 

   else {
      for (int i = 0; i < opt_count; i++) {
         switch (opts[i]) {
            case 'v':
               view(INPUT_FILE);
               break;
            case 'c':
               copy(INPUT_FILE, OUTPUT_FILE);
               break;
            case 'e':
               encode(INPUT_FILE, OUTPUT_FILE);
               break;
            case 'u':
               decode(INPUT_FILE, OUTPUT_FILE);
               break;
            case 'd':
               delete(INPUT_FILE, INPUT_FILE_NAME);
               break;
         }
      }
   }

   free(opts);
   fclose(INPUT_FILE);
   if (!(OUTPUT_FILE)) {
      fclose(OUTPUT_FILE);
   }

   return 0;
}


void view(FILE* INPUT_FILE){
   char c;
   while (fread(&c, sizeof(char), 1, INPUT_FILE))
   {
      printf("%c", c);
   }
}

int copy(FILE* INPUT_FILE, FILE* OUTPUT_FILE) {
   char c;
   while (fread(&c, sizeof(char), 1, INPUT_FILE))
   {
      fwrite(&c, sizeof(char), 1, OUTPUT_FILE);
   }
   return 0;
}

int encode(FILE* INPUT_FILE, FILE* OUTPUT_FILE) {
   return 0;
}
int decode(FILE* INPUT_FILE, FILE* OUTPUT_FILE) {
   return 0;
}

void delete(FILE* INPUT_FILE, const char* INPUT_FILE_NAME) {
   char proclnk[0xFFF];
   char filename[0xFFF];
   int MAXSIZE = 0xFFF;
   ssize_t r;

   int fno = fileno(INPUT_FILE);
   sprintf(proclnk, "/proc/self/fd/%d", fno);
   r = readlink(proclnk, filename, MAXSIZE);
   if (r < 0)
   {
      printf("failed to readlink\n");
      exit(1);
   }

   printf("Do you really want to remove %s? [y/N] \n", filename);
   r = getchar();
   if (r == 'y' || r == 'Y') {
      if (!(remove(INPUT_FILE_NAME))) {
         printf("Failed to delete file.\n");
         return;
      }
      printf("Sucessfully deleted file.\n");
   } else {
         printf("Failed to delete file.\n");
      return;
   }
}
