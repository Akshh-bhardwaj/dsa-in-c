#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt) {
    int m = strlen(pat);
    int n = strlen(txt);

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        int j;
        // For current index i, check for pattern match
        for (j = 0; j < m; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
        
        // If j reached m, pattern was matched completely
        if (j == m) {
            printf("Pattern found at index %d \n", i);
        }
    }
}

int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABC";
    
    printf("Text: %s\n", txt);
    printf("Pattern: %s\n", pat);
    
    search(pat, txt);
    return 0;
}
