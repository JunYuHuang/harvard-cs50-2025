#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>

const int ENCRYPTION_KEY_LENGTH = 26;

bool has_non_alpha_chars(string text);
bool has_duplicate_chars(string text);
string encrypt(string key, string plaintext);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    string key = argv[1];
    if (strlen(key) != ENCRYPTION_KEY_LENGTH)
    {
        printf("Key must contain %i characters.\n", ENCRYPTION_KEY_LENGTH);
        return 1;
    }
    if (has_non_alpha_chars(key))
    {
        printf("Key must contain alphabetical characters only.\n");
        return 1;
    }
    if (has_duplicate_chars(key))
    {
        printf("Key must contain unique characters only.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    string ciphertext = encrypt(key, plaintext);

    printf("ciphertext: %s\n", ciphertext);

    if (ciphertext) free(ciphertext);

    return 0;
}

bool has_non_alpha_chars(string text)
{
    for (int i = 0, N = strlen(text); i < N; i++)
    {
        if (!isalpha(text[i])) return true;
    }
    return false;
}

bool has_duplicate_chars(string text)
{
    int N = strlen(text);
    char uppercased_text[N + 1];    // +1 for '\0' null terminator

    for (int i = 0; i < N; i++)
    {
        uppercased_text[i] = toupper(text[i]);
    }
    uppercased_text[N] = '\0';  // null terminator

    // check for duplicates
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (uppercased_text[i] == uppercased_text[j])
            {
                return true;
            }
        }
    }

    return false;
}

string encrypt(string key, string plaintext)
{
    int N = strlen(plaintext);
    char *ciphertext = malloc(N + 1);

    if (!ciphertext)
    {
        return NULL;    // if `malloc()` call failed
    }

    for (int i = 0; i < N; i++)
    {
        char ch = plaintext[i];

        if (isalpha(ch))
        {
            bool is_lower = islower(ch);
            char uppercased_ch = toupper(ch);

            // Get index / position in the alphabet from range [0, 25] inclusive
            int alpha_index = uppercased_ch - 'A';

            // Get cipherchar mapped to the original alphabetic mapped index
            char cipher_ch = key[alpha_index];

            // Restore original case
            ciphertext[i] = is_lower ? tolower(cipher_ch) : toupper(cipher_ch);
        }
        else
        {
            // leave non-alphabetical chars unchanged
            ciphertext[i] = ch;
        }
    }

    ciphertext[N] = '\0';
    
    return ciphertext;
}
