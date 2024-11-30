#include <stdio.h>
#include <string.h>

/*
Function Description
Complete the function optimizeldentifiers in the editor below.
optimizeldentifiers has the following parameter:
string s: the initial product identifiers.
Returns
int: the maximum number of operations the operations analyst can perform on the string, such that its type is equal to the initial string's type.
*/

int optimizer(char* s);

int main(void)
{
        if (optimizer("hchc") != 2) return 1;
        if (optimizer("abbc") != 0) return 2;
        if (optimizer("babdcaac") != 5) return 3;
        if (optimizer("acba") != 3) return 4;
        if (optimizer("abcd") != 0) return 5;
        if (optimizer("aa") != 1) return 6;
        if (optimizer("abcba") != 4) return 7;
        if (optimizer("aabbcc") != 2) return 8;
        if (optimizer("baabcc") != 4) return 9;
        if (optimizer("cabb") != 1) return 10;
        if (optimizer("ba") != 0) return 11;
        if (optimizer("bbba") != 2) return 12;
        if (optimizer("bbbaabb") != 6) return 13;
        if (optimizer("cabaa") != 3) return 14;
        if (optimizer("bcabc") != 3) return 15;
        if (optimizer("ac") != 0) return 16;
        if (optimizer("aabbb") != 3) return 17;
        if (optimizer("cccc") != 3) return 18;
        if (optimizer("ddcdc") != 3) return 19;
        if (optimizer("xyzxyz") != 3) return 20;
        if (optimizer("xyzy") != 2) return 21;
        if (optimizer("abababab") != 6) return 22;
        if (optimizer("a") != 0) return 23;
        if (optimizer("aaaa") != 3) return 24;
        if (optimizer("abaac") != 3) return 25;
        if (optimizer("acbcac") != 4) return 26;
        return 0;
}


int optimizer(char* s) {
        int s_len = strlen(s);
        if (s_len < 2) {
                return 0;
        }
        if (s[s_len] == '\0') {
                s_len--;
        }
        char type[2] = {*s, *(s + s_len)};
        int count = 0;

        printf("original string: %s, type: %c%c\n", s, type[0], type[1]);
        for (int i = 0; i <= s_len; i++){
                if (s[i] == type[0]) {
                        for (int j = s_len; i <= j; j--) {
                                if (s[j] == type[1]) {
                                        int new_count = i + (s_len - j);
                                        if (new_count > count) {
                                                count = new_count;

                                                printf("final string: ");
                                                for (int k = i; k <= j; k++) {
                                                        printf("%c", s[k]);
                                                }
                                                printf(", count: %i\n",new_count);
                                        }
                                }
                        }
                }
        }
        printf("final count: %i\n\n", count);
        return count;
}
