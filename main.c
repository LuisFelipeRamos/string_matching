#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "functions.h"

int main(int argc, char **argv){

    clock_t start, end;
    double execution_time;

    char* pattern = "sfdsggr";
    char* text = "shgdhsgdsagdsajsdgkjasdasdhewdsfdfsdfsdfsdfsdfsfrvervvgtrgvrgthdtyhzdfgfdgdfgfdgdfgdfgogwbildvpeainhaeuvdhlfhvuerilvhndufhvbyugvfdhnyuvbgydainhaeuvdhlfhvuerilvhndufhvbyugvfdhnyuvbgydainhaeuvdhlfhvuerilvhndufhvbyugvfdhnyuvbgydainhaeuvdhlfhvuerilvhndufhvbyugvfdhnyuvbgydainhaeuvdhlfhvuerilvhndufhvbyugvfdhnyuvbgydainhaeuvdhlfhvuerilvhndufhvbyugvfdhnyuvbgydainhaeuvdhlfhvuerilvhndufhvbyugvfdhnyuvbgydsfdsggrhvbfv";

    start = clock();
    int bf_index = brute_force_search(pattern, text, strlen(pattern), strlen(text));
    end = clock();
    execution_time = ((double) end - start)/CLOCKS_PER_SEC;
    printf("Brute force found index: %d in time %lf s\n", bf_index, execution_time);

    start = clock();
    int kmp_index = kmp(pattern, text, strlen(pattern), strlen(text));
    end = clock();
    execution_time = ((double) end - start)/CLOCKS_PER_SEC;
    printf("KMP found index: %d in time %lf s\n", kmp_index, execution_time);

    start = clock();
    int horspool_index = horspool(pattern, text, strlen(pattern), strlen(text));
    end = clock();
    execution_time = ((double) end - start)/CLOCKS_PER_SEC;
    printf("horspool found index: %d in time %lf s\n", horspool_index, execution_time);

    start = clock();
    int shift_and_index = shift_and(pattern, text, strlen(pattern), strlen(text));
    end = clock();
    execution_time = ((double) end - start)/CLOCKS_PER_SEC;
    printf("shift and found index: %d in time %lf s\n", shift_and_index, execution_time);

    return 0;
};
