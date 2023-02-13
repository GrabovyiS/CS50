#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool is_valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (is_valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Checks if password has diverse enough chars
bool is_valid(string password)
{
    bool has_digit = false;
    bool has_upper = false;
    bool has_lower = false;
    bool has_symbol = false;

    // Iterating through chars in string
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            has_digit = true;
        }
        if (isupper(password[i]))
        {
            has_upper = true;
        }
        if (islower(password[i]))
        {
            has_lower = true;
        }
        if (ispunct(password[i]))
        {
            has_symbol = true;
        }
    }

    if (has_digit && has_upper && has_lower && has_symbol)
    {
        return true;
    }
    return false;
}
