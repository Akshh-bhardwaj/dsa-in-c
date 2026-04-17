/*
 * Anagram Check
 * -------------
 * Check if two strings are anagrams of each other.
 * Two strings are anagrams if they contain the same characters
 * in the same frequency.
 *
 * Approach: Frequency count using array O(n)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHA 26

int isAnagram(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2)) return 0;

    int freq[ALPHA] = {0};

    for (int i = 0; s1[i]; i++) {
        freq[tolower(s1[i]) - 'a']++;
    }
    for (int i = 0; s2[i]; i++) {
        freq[tolower(s2[i]) - 'a']--;
    }

    for (int i = 0; i < ALPHA; i++) {
        if (freq[i] != 0) return 0;
    }
    return 1;
}

int main() {
    char pairs[][2][20] = {
        {"listen", "silent"},
        {"hello",  "world"},
        {"anagram", "nagaram"},
        {"rat",    "car"}
    };
    int n = 4;

    for (int i = 0; i < n; i++) {
        printf("\"%s\" and \"%s\" => %s\n",
               pairs[i][0], pairs[i][1],
               isAnagram(pairs[i][0], pairs[i][1]) ? "Anagram ✓" : "Not Anagram ✗");
    }

    return 0;
}
