// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
    typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
#define HASHTABLE_SIZE 10000

// Hash table
node *table[HASHTABLE_SIZE];

int Count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //convert word to lower case
    int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    
    // Adds null terminator to end string
    word_copy[n] = '\0';
    
    //hash word to obtain hash value
    int i = hash(word_copy);
    
    
    //Access linked list at that index in the hash table
    node *temp = table[i];
    
    while (temp != NULL)
    {
        if (strcasecmp(temp->word,  word_copy) == 0)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % HASHTABLE_SIZE;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open dectionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        unload();
        return false;
    }
    
    char word[LENGTH + 1];

    //Read strings from file
    while (fscanf(file, "%s", word) != EOF)
    {
        
        //Create a new node
        node *new_node = malloc(sizeof(node));
        //check if node is NULL
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        
        //copy word drom Dic. to node
        strcpy(new_node->word, word);
        
        //Hash word
        unsigned int i = hash(new_node->word);
        
        //
        
        // Initializes head to point to hashtable index/bucket
        node *head = table[i];
        
        if (head == NULL)
        {
            table[i] = new_node;
            Count++;
        }
        
        //
        
        new_node->next = table[i];
        table[i] = new_node;
        
        Count++;
        
    }
    
    
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return Count / 2;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *head = NULL;
    node *cursor = head;
    // freeing linked lists
    while (cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return true;
}