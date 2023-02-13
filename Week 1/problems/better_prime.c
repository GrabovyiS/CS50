#include <stdio.h>
#include <cs50.h>

// This is a better version of crutch_fast_prime.c
// Abstraction made these same ideas so much more readable and clear! amazing!

bool is_prime(int);

int main(void)
{
    // Print all primes in a given range

    int start_of_range = get_int("Minimum: ");
    int end_of_range = get_int("Maximum: ");

    for (int i = start_of_range; i <= end_of_range; i++)
    {
        if (is_prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool is_prime(int number)
{
    if (number == 1)
    {
        return false;
    }

    if (number == 2 || number == 3)
    // 2 and 3 are handled separately so that we can start checking devisors from number 3 and skip evens
    {
        return true;
    }

    if (number % 2 == 0) {
        return false;
    }

    // Now, the biggest possible whole devisor is number / 3, sicnce number is odd and it can't be number / 2.
    for (int i = 3; i <= number / 3; i += 2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}