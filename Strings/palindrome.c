/*
 * Palindrome Check
 * ----------------
 * Check if a string is a palindrome (reads same forwards and backwards).
 *
 * Approach: Two-pointer O(n)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        /* Skip non-alphanumeric characters */
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;

        if (tolower(str[left]) != tolower(str[right])) {
            return 0; /* Not a palindrome */
        }
        left++;
        right--;
    }
    return 1; /* Is a palindrome */
}

int main() {
    char tests[][50] = {"racecar", "hello", "A man a plan a canal Panama", "madam"};
    int n = 4;

    for (int i = 0; i < n; i++) {
        printf("\"%s\" => %s\n", tests[i],
               isPalindrome(tests[i]) ? "Palindrome ✓" : "Not a Palindrome ✗");
    }

    return 0;
}
