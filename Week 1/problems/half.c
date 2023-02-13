#include <stdio.h>
#include <cs50.h>

float get_expences(float bill, float tax_percent, float tip_percent);

int main(void)
{
    // print a half of a bill after tax and tip

    float bill = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    float tip_percent = get_float("Tip percent: ");

    float result = get_expences(bill, tax_percent, tip_percent);
    printf("You will owe %.2f each! \n", result);
}

float get_expences(float bill, float tax_percent, float tip_percent)
{
    float expences = bill;
    expences += expences * tax_percent / 100; // add tax
    expences += expences * tip_percent / 100; // add tip after tax
    return expences / 2;
}