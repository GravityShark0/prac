#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* #include <unistd.h> */

#define ASCIIZERO 48

char *NUMTEXT[9] = {"one", "two",   "three", "four", "five",
                    "six", "seven", "eight", "nine"};

char *subbest_of_strings(char *hay, char *needle);

int main(int argc, char *argv[]) {
  FILE *input = fopen(argv[1], "r");

  char *line = NULL;
  size_t len = 0;
  long total = 0;
  while (getline(&line, &len, input) != -1) {
    int length = strlen(line);

    int lowest = 0;
    int highest = 0;
    int lowest_index = -1;
    int highest_index = -1;

    int line_length = length;
    /* Check for numbers in a string */
    for (int i = 0; i <= line_length;) {
      if (lowest_index == -1) {
        if (isdigit(line[i])) {
          lowest_index = i;
        } else {
          i++;
        }
      }

      if (highest_index == -1) {
        if (isdigit(line[line_length])) {
          highest_index = line_length;
        } else {
          line_length--;
        }
      }

      if (lowest_index != -1 && !lowest) {
        lowest = line[lowest_index] - ASCIIZERO;
      }
      if (highest_index != -1 && !highest) {
        highest = line[highest_index] - ASCIIZERO;
      }
      if (lowest && highest) {
        break;
      }
    }

    /* printf("beef low: %i index:%i highest: %i index: %i\n", lowest, */
           /* lowest_index, highest, highest_index); */

    for (int i = 0; i < 9; i++) {
      char *substring = strstr(line, NUMTEXT[i]);
      if (substring == NULL) {
        continue;
      }
      char *subbeststring = subbest_of_strings(line, NUMTEXT[i]);

      const int index = length - strlen(substring);
      /* + 1 is like an offset thing idfk */
      const int subbestindex = length - strlen(subbeststring) + 1;

      /* printf("found %s,\nindex: %i substring: %sindex: %i subbeststring: %s", */
      /*        NUMTEXT[i], index, substring, subbestindex, subbeststring); */
      /* printf("found %s at %i %i\n", NUMTEXT[i], index, subbestindex); */

      if ((lowest_index == -1) || (index < lowest_index)) {
        lowest = i + 1;
        lowest_index = index;
        /* printf("new lowest %i index: %i\n", lowest, lowest_index); */
      }

      if ((highest_index == -1) || (subbestindex > highest_index)) {
        highest = i + 1;
        highest_index = subbestindex;
        /* printf("new highest %i index: %i\n", highest, highest_index); */
      }

      /* printf("%s %c\n", substring, line[index]); */
    }
    lowest *= 10;
    highest += lowest;
    total += highest;
    printf("%i %li %s", highest, total, line);
    /* printf("%i\n", highest); */
    /* sleep(2); */
  }

  printf("total: %li\n", total);
  return 0;
}

char *subbest_of_strings(char *hay, char *needle) {
  char *substring = strstr(hay, needle);

  /* +1 adds the null operator */
  int new_hay_len = strlen(hay) - strlen(needle) + 1;
  /*printf("subbest_of_strings: length: %li substring: %s length: %li needle: "
         "%s\n newhaylen: %i\n",
         strlen(substring), substring, strlen(needle), needle, new_hay_len);*/
  char new_hay[new_hay_len];

  for (int i = 0; i < new_hay_len; i++) {
    new_hay[i] = substring[i + strlen(needle)];
    /*printf("subberstringing %c\n", substring[i + strlen(needle)]);*/
  }

  if (strstr(new_hay, needle) != NULL) {
    return subbest_of_strings(new_hay, needle);
  }

  return substring;
}
