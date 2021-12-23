#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int h;
    do
    {
        //Recieves user input
        h = get_int("Please input the height you would like\n");
    
    }
    while (h < 1 || h > 8);
    //Prints a new line
    for (int i = 0; i < h; i++)
    {
        int n = h - 1;
        //Decides whether to print a space or a #
        for (int j = 0; j < h; j++)
        {
            if (i + j < n)
            {
                printf(" ");
            }
            else
            {
                printf("#");   
            }
            
        }
        printf("\n");
    }
}