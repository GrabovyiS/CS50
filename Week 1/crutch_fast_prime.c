#include <stdio.h>
#include <cs50.h>

// this is a bad execution of cool ideas. no abstraction, overloaded with comments just to understand anything, a couple of very specific cases. But its probably much faster than going through every number, especially on a bigger set of data

int main(void)
{
    // print all primes in a given range

    int start_of_range = get_int("Minimum: ");

    if (start_of_range == 1)
    {
        // one isn't prime, skip it
        start_of_range++;
    }

    if (start_of_range % 2 == 0 && start_of_range != 2)
    {
        // if the first number is even - its not prime (except for two) so skip it so that we can go through odd numbers only in a loop with i += 2
        start_of_range++;
    }

    int end_of_range = get_int("Maximum: ");

    for (int i = start_of_range; i <= end_of_range; i += 2) {
        // go through the range
        // we skip all even numbers, because all even numbers are not prime
        bool is_prime = true;

        if (i == 2)
        {
            // if we actually found an even prime
            printf("%i\n", i); // print it
            i++; // move the number so that we skip other evens
            // do not continue because 2+1 = 3 is a prime, go into main loop
        }

        for (int j = 3; j <= i/3; j += 2) {
            // check for devisors
            // skip all even numbers, because the dividend is not even
            // only check up to 1/3 of a number, because:
            // the biggest possible devisor (other than self) is i/2, but it can't be i/2 since i is odd
            // the second biggest possible devisor, then, is i/3, check for that and there is no need to continue: there can't be a bigger devisor (other than self)
            if (i % j == 0 && i != j)
            {
                // if there is a divisor other than 1 and self
                is_prime = false;
            }
        }

        if (is_prime == true)
        {
            printf("%i\n", i);
        }
    }
}
