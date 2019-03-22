#include <stdio.h>
#include <string.h>
/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    int length = strlen(y);
    for (int i = 0; i < length; i++) {
        x[i] = y[i];
    }
    x[length + 1] = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    int length = strlen(str);
    char *p = NULL;
    for (int i = 0; i < length; i++) {
        if (str[i] == c) {
            p = &str[i];
            break;
        }
    }
    return p;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    int hayLen = strlen(haystack);
    int needleLen = strlen(needle);
    char *p = NULL;
    for (int i = 0; i < hayLen; i++) {
        if (haystack[i] == needle[0]) {
            int cur = i + 1;
            int found = 1;
            for (int j = 1; j < needleLen - 1; j++) {
                if (needle[j] != haystack[cur]) {
                    found = 0;
                    break;
                }
                cur += 1;
            }
            if (found) {
                p = &haystack[i];
                break;
            }
        }
    }
    return p;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");
    

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    char buffer[1024];
    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
    return 0;
}
#endif
