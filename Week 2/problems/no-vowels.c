#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels.c word\n");
        return 1;
    }

    printf("%s\n", replace(argv[1]));
    return 0;
}

// Replaces vowels in a string
string replace(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        switch (tolower(s[i]))
        {
            case 'a':
                s[i] = '6';
                break;

            case 'e':
                s[i] = '3';
                break;

            case 'i':
                s[i] = '1';
                break;

            case 'o':
                s[i] = '0';
                break;
        }
    }

    return s;
}