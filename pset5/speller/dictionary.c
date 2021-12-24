// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
unsigned int sz = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = hash(word);
    node *cursor = table[n];
    while (cursor !=  NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    char c = word[0];
    if (isupper(c) != 0)
    {
        int b = c - 65;
        return b;
    }
    else
    {
        int a = c - 97;
        return a;
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word[LENGTH];
    FILE *d = fopen(dictionary, "r");
    if (d == NULL)
    {
        return false;
    }
    while (fscanf(d, "%s", word) != EOF)
    {
        //Gets the hash index for a word
        int n = hash(word);
        //Mallocs enough memory for a node
        node *current = malloc(sizeof(node));
        //Checks to make sure the space malloced actually exists
        if (current == NULL)
        {
            return false;
        }
        sz++;
        //Copys the string from the dictionary to the newly created node
        strcpy(current->word, word);
        if (table[n] == NULL)
        {
            table[n] = current;
            current->next = NULL;
        }
        else
        {
            current->next = table[n];
            table[n] = current;
        }
    }
    fclose(d);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return sz;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = NULL;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}