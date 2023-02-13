#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string input = get_string("Text: ");
    // Determine the reading level of inputted text
    // index = 0.0588 * L - 0.296 * S - 15.8, L - average letters per 100 words, S - average sentences per 100 words
    int total_letters = count_letters(input);
    int total_words = count_words(input);
    int total_sentences = count_sentences(input);

    // Find avg for one word, then * 100
    float L = ((float) total_letters / total_words) * 100;
    float S = ((float) total_sentences / total_words) * 100;

    int grade = round(0.0588 * L - 0.296 * S - 15.8);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int letters_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters_count++;
        }
    }

    return letters_count;
}

int count_words(string text)
{
    int words_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // If enocuntered a letter, move until the word is over, then add a word
        if (isalpha(text[i]))
        {
            while (isalpha(text[i]) || text[i] == '\'' || text[i] == '-')
            {
                i++;
            }
            words_count++;
        }
    }

    return words_count;
}


int count_sentences(string text)
{
    int sentences_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences_count++;
        }
    }

    return sentences_count;
}