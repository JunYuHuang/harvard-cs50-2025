#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <math.h>

float coleman_liau_index(int letters_count, int sentences_count, int words_count);
bool is_alphabetical_char(char ch);
bool is_ending_punctuation_char(char ch);

int main(void)
{
    string text = get_string("Text: ");
    int N = strlen(text);
    int words_count = 1;
    int letters_count = 0;
    int sentences_count = 0;
    int reading_level = 0;

    for (int i = 0; i < N; i++)
    {
        if (text[i] == ' ')
        {
            words_count++;
        }
        else if (is_alphabetical_char(text[i]))
        {
            letters_count++;
        }
        else if (is_ending_punctuation_char(text[i]))
        {
            sentences_count++;
        }
    }

    reading_level = (int) round(coleman_liau_index(letters_count, sentences_count, words_count));

    if (reading_level < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (reading_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", reading_level);
    }
}

float coleman_liau_index(int letters_count, int sentences_count, int words_count)
{
    float average_letters_per_100_words = (letters_count / (float) words_count) * 100;
    float average_sentences_per_100_words = (sentences_count / (float) words_count) * 100;
    return (
        (0.0588 * average_letters_per_100_words) -
        (0.296 * average_sentences_per_100_words) - 
        15.8
    );
}

bool is_alphabetical_char(char ch)
{
    if ('a' <= ch && ch <= 'z') return true;
    if ('A' <= ch && ch <= 'Z') return true;
    return false;
}

bool is_ending_punctuation_char(char ch)
{
    return (ch == '!' || ch == '?' || ch == '.');
}