#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int brute_force_search(const char *pattern, const char *text, const unsigned int pattern_length, const unsigned int text_length){

    if (pattern_length > text_length){
        return -1;
    }

    unsigned int counter;
    for (int i = 0; i < text_length - pattern_length; i++){
        counter = 0;
        for (int j = 0; j < pattern_length; j++){
            if (text[i + j] == pattern[j]){
                counter++;
            }
        }
        if (counter == pattern_length){
            return i;
        }
    }

    return -1;
};

int kmp(const char *pattern, const char *text, const unsigned int pattern_length, const unsigned int text_length){

    if (pattern_length > text_length){
        return -1;
    }

    /* Compute prefix function */
    unsigned int prefix_function[pattern_length];
    for (int i = 0; i < pattern_length; i++){
        prefix_function[i] = 0;
    }

    unsigned int k = 0;

    for (int q = 1; q < pattern_length; q++){
        while (k > 0 && pattern[k] != pattern[q]){
            k = prefix_function[k];
        }
        if (pattern[k] == pattern[q]){
            k++;
        }
        prefix_function[q] = k;
    }
    
    k = 0;
    for (int i = 0; i < text_length; i++){
        while (k > 0 && pattern[k] != text[i]){
            k = prefix_function[k - 1];
        }
        if (pattern[k] == text[i]){
            k++;
        }
        if (k == pattern_length){
            return i - pattern_length + 1;
        }
    }

    return -1;
};

/* Supomos aqui que o alfabeto é formato apenas pelas 26 letras do alfabeto latino em formato minusculo  */
int horspool(const char *pattern, const char *text, const unsigned int pattern_length, const unsigned int text_length){

    if (pattern_length > text_length){
        return -1;
    }

    const int ALPHABET_LENGTH = 26;

    unsigned int shift[ALPHABET_LENGTH];
    for (int i = 0; i < ALPHABET_LENGTH; i++){
        shift[i] = pattern_length;
    }
    for (int i = 0; i < pattern_length - 1; i++){
        unsigned int char_index = pattern[i] - 97;
        shift[char_index] = pattern_length - 1 - i;
    }
    
    unsigned int i = pattern_length - 1;
    unsigned int k;
    while (i <= text_length - 1){
        k = 0;
        while (k <= pattern_length - 1 && pattern[pattern_length - 1 - k] == text[i - k]){
            k++;
        }

        if (k == pattern_length){
            return i - pattern_length + 1;
        }
        i += shift[(int)text[i] - 97];
    }

    return -1;
}

/* Assim como no algoritmo de Horspool, assumimos aqui que o alfabeto é composto pelos caracteres minusculos do alfabeto latino */
int shift_and(const char *pattern, const char *text, const unsigned int pattern_length, const unsigned int text_length){

    if (pattern_length > text_length){
        return -1;
    }

    const int ALPHABET_LENGTH = 26;

    unsigned int M[ALPHABET_LENGTH];
    for (int i = 0; i < ALPHABET_LENGTH; i++){
        M[i] = 0;
    }

    unsigned int char_index;
    for (int i = 0; i < pattern_length; i++){
        char_index = (int)pattern[i] - 97;
        M[char_index] |= 1 << i;
    }

    unsigned int R = 0;
    for (int i = 0; i < text_length; i++){
        char_index = (int)text[i] - 97;
        R = ((R << 1) + 1) & M[char_index];
        if (R & (1 << (pattern_length - 1))){
            return i - pattern_length + 1;
        }
    }

    return -1;
}
