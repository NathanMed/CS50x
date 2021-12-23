#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool valid_key(string s);

int main(int argc, string argv[])
{
    // this if statement is only true when there is either more than one input or when valid_key returns false 
    if (argc != 2 || !valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //The atoi() function converts a given string into an int
    int key = atoi(argv[1]);

    string s = get_string("plaintext: ");

    printf("ciphertext: ");

    int len = strlen(s);
    
    //This for loop is what actuall converts the plaintext into cipher text
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (isalpha(c))
        {
            char p = 'A';
            if (islower(c))
            {
                p = 'a';
            }
            //the equation (c - p + key) % 26 + p is the ceasar equation adjusted for the ACSII system 
            printf("%c", (c - p + key) % 26 + p);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

//This function checks the key to see if it's valid

bool valid_key(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        //The isalpha() function checks if the character is alphabetical, if it is it returns false, if isn't it returns true
        if (isalpha(s[i]))
        {
            return false;
        }
    }
    //returns true by default, so only in the case that the key is a int
    return true;
}

