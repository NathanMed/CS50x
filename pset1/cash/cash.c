#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owned: ");
    }
    while (dollars < 0);
    int change = 0;
    int cents = round(dollars * 100);
    //Checks to see if the amount give is more than a quarter, if it is it subtracts 25 from the amount and adds one to the amount of change owned
    while (cents >= 25)
    {
        cents = cents - 25;
        change++;
    }
    //Checks to see if the amount give is more than a dime, if it is it subtracts 25 from the amount and adds one to the amount of change owned
    while (cents >= 10)
    {
        cents = cents - 10;
        change++;
    }
    //Checks to see if the amount give is more than a nickel, if it is it subtracts 25 from the amount and adds one to the amount of change owned
    while (cents >= 5)
    {
        cents = cents - 5;
        change++;
    }
    //Checks to see if the amount give is more than a penny, if it is it subtracts 25 from the amount and adds one to the amount of change owned
    while (cents >= 1)
    {
        cents = cents - 1;
        change++;
    }
    printf("%i\n", change);
}