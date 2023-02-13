#include <cs50.h>
#include <stdio.h>

// Checks credit card numbers using Luhn's algorithm
// https://cs50.harvard.edu/x/2023/psets/1/credit/

bool is_valid(long card_number);
int get_number_of_digits(long number);
int get_first_two_digits(long number);

int main(void)
{
    long card_number = get_long("Number: ");

    int first_two_digits = get_first_two_digits(card_number);


    if (is_valid(card_number) == false)
    {
        printf("INVALID\n");
    }
    else if (first_two_digits / 10 == 4)
    {
        printf("VISA\n");
    }
    else if (first_two_digits == 34 || first_two_digits == 37)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("MASTERCARD\n");
    }
}


bool is_valid(long card_number)
{
    int number_of_digits = get_number_of_digits(card_number);

    if (number_of_digits != 13 && number_of_digits != 15 && number_of_digits != 16)
    {
        return false;
    }


    int first_two_digits = get_first_two_digits(card_number);

    if (first_two_digits != 51 &&
        first_two_digits != 52 &&
        first_two_digits != 53 &&
        first_two_digits != 54 &&
        first_two_digits != 55 &&
        first_two_digits != 34 &&
        first_two_digits != 37 &&
        first_two_digits / 10 != 4)
    {
        return false;
    }


    // Luhn's algorithm, possibly could be abstracted
    int sum_of_multiplied_digits = 0;
    // This is the sum of digits of products of multiplication of initial digits by 2
    long card_digits = card_number;
    card_digits /= 10;
    // Starting from second to last digit, every other
    while (card_digits > 0)
    {
        int multiplied_digits = (card_digits % 10) * 2;
        // Digit * 2 can only have 1 or 2 digits
        sum_of_multiplied_digits += multiplied_digits % 10 + multiplied_digits / 10;
        card_digits /= 100;
    }

    int sum_of_not_multiplied = 0;
    // This is just a sum of previously ignored digits
    card_digits = card_number;
    // Starting from first digit, every other
    while (card_digits > 0)
    {
        sum_of_not_multiplied += card_digits % 10;
        card_digits /= 100;
    }

    if ((sum_of_multiplied_digits + sum_of_not_multiplied) % 10 != 0)
    {
        return false;
    }

    return true;
}


int get_number_of_digits(long number)
{
    int number_of_digits = 0;

    while (number > 0)
    {
        // 9/10 = 0 because integer (truncating to zero)
        number /= 10;
        number_of_digits++;
    }

    return number_of_digits;
}


int get_first_two_digits(long number)
{
    while (number > 100)
    {
        number /= 10;
    }

    return number;
}