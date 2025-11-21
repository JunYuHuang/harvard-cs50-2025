#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

const string ORIGINAL_KEY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int ENCRYPTION_KEY_LENGTH = 26;
const char EMPTY_CHAR;
const string WAS_LOWER = "WAS_LOWER";
const string WAS_UPPER = "WAS_UPPER";

bool has_non_alpha_chars(string text);
bool has_duplicate_chars(string text);
string encrypt(string encryption_key, string plaintext);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    string encryption_key = argv[1];
    if (strlen(encryption_key) != ENCRYPTION_KEY_LENGTH)
    {
        printf("Key must contain %i characters.\n", ENCRYPTION_KEY_LENGTH);
        return 1;
    }
    if (has_non_alpha_chars(encryption_key))
    {
        printf("Key must contain alphabetical characters only.\n");
        return 1;
    }
    if (has_duplicate_chars(encryption_key))
    {
        printf("Key must contain unique characters only.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    string ciphertext = encrypt(encryption_key, plaintext);
    printf("ciphertext: %s\n", ciphertext);
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

string encrypt(string encryption_key, string plaintext)
{
    int N = strlen(plaintext);
    char ciphertext[N + 1];

    for (int i = 0; i < N; i++)
    {
        string original_case = "";
        char ch = plaintext[i];
        char uppercased_ch = toupper(ch);
        char cipher_ch = EMPTY_CHAR;

        if (isupper(ch))
        {
            original_case = WAS_UPPER;
        }
        else if (islower(ch))
        {
            original_case = WAS_LOWER;
        }

        for (int j = 0; j < ENCRYPTION_KEY_LENGTH; j++)
        {
            if (uppercased_ch == ORIGINAL_KEY[j])
            {
                if (original_case == WAS_UPPER)
                {
                    cipher_ch = toupper(encryption_key[j]);
                }
                else if (original_case == WAS_LOWER)
                {
                    cipher_ch = tolower(encryption_key[j]);
                }
                break;
            }
        }

        if (cipher_ch == EMPTY_CHAR)
        {
            cipher_ch = ch;
        }

        ciphertext[i] = cipher_ch;
    }

    ciphertext[N] = '\0';
    
    return ciphertext;
}
