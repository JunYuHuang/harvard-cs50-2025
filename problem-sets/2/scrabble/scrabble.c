#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

const int ASCII_CHAR_OFFSET = -65;
const int ASCII_CHAR_TO_VALUE[26] =
{
    1, // A
    3, // B
    3, // C
    2, // D
    1, // E
    4, // F
    2, // G
    4, // H
    1, // I
    8, // J
    5, // K
    1, // L
    3, // M
    1, // N
    1, // O
    3, // P
    10, // Q
    1, // R
    1, // S
    1, // T
    1, // U
    4, // V
    4, // W
    8, // X
    4, // Y
    10, // Z
};

int compute_score(string word);

int main(void)
{
    string player_1_word = get_string("Player 1: ");
    string player_2_word = get_string("Player 2: ");

    int player_1_score = compute_score(player_1_word);
    int player_2_score = compute_score(player_2_word);

    if (player_1_score > player_2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_1_score < player_2_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int result = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char ch = toupper(word[i]);

        // skip `ch` if it is not an uppercase alphabetical char
        if (ch < 'A' || ch > 'Z') continue;

        ch = ch + ASCII_CHAR_OFFSET;
        result += ASCII_CHAR_TO_VALUE[ch];
    }
    return result;
}