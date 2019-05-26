#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[128];

// Creates the shift table for all 128 char in the ascii table.
// Mapping to a char is done with its index, so if 't' has value 1,
// value at index 19 will be 1.
void shiftTable(char *searchStr)
{
    int i;

    for (i = 0; i < 128; i++)
        table[i] = strlen(searchStr);

    for (i = 0; i < strlen(searchStr) - 1; i++)
        table[searchStr[i]] = strlen(searchStr) - i - 1;
}

int horspool(char *str, char *searchStr)
{
    int i, j, k, flag = 1, searchStrLen = strlen(searchStr);
    shiftTable(searchStr);

    i = searchStrLen - 1;
    while (i < strlen(str)) // Main loop to loop through main string
    {
        k = 0;

        // 2nd loop to loop through the pattern to check it
        while (k < searchStrLen && str[i - k] == searchStr[searchStrLen - k - 1])
            k++;

        if (k == searchStrLen) // When all char match
            return i - searchStrLen + 2;
        else
            i += table[str[i]]; // Shifting with table's value
    }
    return -1;
}

int main()
{
    char str[50], searchStr[50];
    int pos;

    printf("Enter a string: \n");
    scanf("%s", str);

    printf("Enter the string to search for: \n");
    scanf("%s", searchStr);

    pos = horspool(str, searchStr);
    if (pos == -1)
        printf("The substring was not found in the main string\n");
    else
        printf("The substring is present at %d\n", pos);

    return (0);
}
