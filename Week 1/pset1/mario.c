#include <cs50.h>
#include <stdio.h>

// Prints a symmetrical mario tower

void print_tower(int tower_height);
void print_floor(int floor_length, int tower_height);


int main(void)
{
    int tower_height;

    do
    {
        tower_height = get_int("Height: ");
    }
    while (1 > tower_height || tower_height > 8);

    print_tower(tower_height);
}


// Prints the whole tower
void print_tower(int tower_height)
{
    for (int i = 1; i <= tower_height; i++)
    {
        print_floor(i, tower_height);
        printf("\n");
    }
}


// Prints only one floor
void print_floor(int floor_length, int tower_height)
{
    // Prints half a tower
    for (int i = 0; i < tower_height - floor_length; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < floor_length; i++)
    {
        printf("#");
    }

    printf("  ");

    // Prints the other half of the bricks
    for (int i = 0; i < floor_length; i++)
    {
        printf("#");
    }
}