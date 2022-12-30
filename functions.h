#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* Description: brute force search in text to check if pattern exists.
Input: pointer to the strings of the pattern and the text, and size of both strings.
Output:  If the pattern exists in text, return the index where it first occurs. If it doens't, returns -1. */
int brute_force_search(const char *pattern, const char *text, const unsigned int pattern_length, const unsigned int text_length);

/* Description: KMP (Knuth - Morris - Pratt) algorithm  to check if pattern exists in text.
Input: pointer to the strings of the pattern and the text, and size of both strings.
Output:  If the pattern exists in text, return the index where it first occurs. If it doens't, returns -1. */
int kmp(const char *pattern, const char *text, const unsigned int pattern_length, const unsigned int text_length);

/* Description: Horspool algorithm to check if pattern exists in text.
Input: pointer to the strings of the pattern and the text, and size of both strings.
Output:  If the pattern exists in text, return the index where it first occurs. If it doens't, returns -1. */
int horspool(const char *pattern, const char *text, const unsigned int pattern_length, const unsigned int text_length);

/* Description: shift_and algorithm to check if pattern exists in text.
Input: pointer to the strings of the pattern and the text, and size of both strings.
Output:  If the pattern exists in text, return the index where it first occurs. If it doens't, returns -1. */
int shift_and(const char *pattern, const char *text, const unsigned int pattern_length, const unsigned int text_length);

#endif