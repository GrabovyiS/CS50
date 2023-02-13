#include <cs50.h>
#include <stdio.h>

// Prediction of lamas population growth

int main(void)
{
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // Add to the number of years until we reach threshold
    int years = 0;
    int current_size = start_size;
    while (current_size < end_size)
    {
        // 1/3 of lamas are born, 1/4 die each year
        current_size += current_size / 3 - current_size / 4;
        years++;
    }
    printf("Years: %i\n", years);
}
