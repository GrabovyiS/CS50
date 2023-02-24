#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert_loop(string input);
int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    if (strlen(input) == 0)
    {
        return 0;
    }

    int last_digit = (int) input[strlen(input) - 1] - (int) '0';
    input[strlen(input) - 1] = '\0';

    // Add last digit, move following digits by one digit place
    // In case of 4321 it would: 1 + 10 * (2 + 10 * (3 + 10 * 4))
    return last_digit + 10 * convert(input);
}


int convert_loop(string input)
{
    int result = 0;

    for (int i = strlen(input) - 1; i >= 0; i--)
    {
        int digit = (int) input[i] - (int) '0';
        // Power of 10 of the digit with index i;
        int ten_pow = strlen(input) - i - 1;
        result += digit * pow(10, ten_pow);
    }

    return result;
}