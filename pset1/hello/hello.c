#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Gets the name of the person 
    string name = get_string("What is your name?\n");
    //Prints out "hello, name"
    printf("hello, %s\n", name);
}