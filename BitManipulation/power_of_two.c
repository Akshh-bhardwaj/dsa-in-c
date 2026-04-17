#include <stdio.h>

int powerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int num = 16;
    printf("Is %d a power of two? %s\n", num, powerOfTwo(num) ? "Yes" : "No");
    return 0;
}
