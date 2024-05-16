#include <stdio.h>
#include <string.h>

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0;  // Length of the previous longest prefix suffix
    lps[0] = 0;   // LPS[0] is always 0

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search algorithm
void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    // Create lps[] that will hold the longest prefix suffix values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // Index for txt[]
    int j = 0; // Index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char txt[100], pat[100];

    printf("Enter the text: ");
    if (!fgets(txt, sizeof(txt), stdin)) {
        printf("Error reading text\n");
        return 1;
    }
    txt[strcspn(txt, "\n")] = '\0'; // Remove the newline character

    printf("Enter the pattern: ");
    if (!fgets(pat, sizeof(pat), stdin)) {
        printf("Error reading pattern\n");
        return 1;
    }
    pat[strcspn(pat, "\n")] = '\0'; // Remove the newline character

    KMPSearch(pat, txt);

    return 0;
}
