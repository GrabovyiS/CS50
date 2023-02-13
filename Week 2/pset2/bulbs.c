#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string input = get_string("Message: ");
    const int STRING_LENGTH = strlen(input);
    int string_in_decimal[STRING_LENGTH];
    int string_in_binary[STRING_LENGTH][BITS_IN_BYTE];

    // Get binary values for each character
    for (int i = 0; i < STRING_LENGTH; i++)
    {
        int character_in_decimal = (int) input[i];
        // Convert number to binary
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            // 7 - j is for correct order of bits in an array. Usually order during conversion is reversed.
            string_in_binary[i][7 - j] = character_in_decimal % 2;
            character_in_decimal /= 2;
        }
    }

    // Print the bulbs
    for (int i = 0; i < STRING_LENGTH; i++)
    {
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(string_in_binary[i][j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
