// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file_dict = fopen(dictionary, "r");
    if (file_dict == NULL)
    {
        printf("Failed to open %s\n", dictionary);
        return false;
    }

    char ch;
    char word[LENGTH + 1];
    int index = 0;
    while (fread(&ch, sizeof(char), 1, file_dict))
    {
        // `ch` is a lowercase alphabetical char
        if (ch != '\n')
        {
            word[index] = ch;
            index++;
            continue;
        }

        // `ch` is a newline char -- save the word and start another
        word[index] = '\0';
        unsigned int hashed_word = hash(word);
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Failed to allocate memory for a new node '%s'\n", word);
            return false;
        }

        strcpy(new_node->word, word);
        new_node->next = NULL;

        // no linked list at `word[index]` -- start one
        if (table[hashed_word] == NULL)
        {
            table[hashed_word] = new_node;
        }

        // existing list at `word[index]` -- append node to end of it
        else
        {
            node *curr = table[hashed_word];
            while (curr && curr->next)
            {
                curr = curr->next;
            }
            curr->next = new_node;
        }

        // reset index for starting a new word
        index = 0;
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
