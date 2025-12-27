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
const unsigned int N = 300;

// Hash table
node *table[N] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int hashed_word = hash(word);
    return (table[hashed_word] == NULL) ? false : true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    int word_len = (int)strlen(word);
    for (int i = 0; i < word_len; i++)
    {
        sum += (int)word[i];
    }

    return (unsigned int) (sum % N);
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

    free(file_dict);
    print_dictionary();
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int word_count = 0;
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL) continue;

        node *curr = table[i];
        while (curr)
        {
            word_count++;
            curr = curr->next;
        }
    }
    
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL) continue;

        node *curr = NULL;
        node *nxt = NULL;
        for (curr = table[i]; curr != NULL; curr = nxt)
        {
            nxt = curr->next;
            free(curr);
        }
    }
    return true;
}

// debugger helper function 
void print_dictionary(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL) continue;

        printf("table[%i]: \n", i);
        node *curr = NULL;
        for (curr = table[i]; curr != NULL; curr = curr->next)
        {
            printf("'%s'", curr->word);
            if (curr->next != NULL) printf(" -> ");
        }
        printf("\n\n");
    }
}