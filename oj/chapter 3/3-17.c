#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

bool is_reversed(char* sequence1, char* sequence2) {
    int len1 = strlen(sequence1);
    int len2 = strlen(sequence2);

    if (len1 != len2) {
        return false;
    }

    for (int i = 0; i < len1; ++i) {

        if (sequence1[i] != sequence2[len1 - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char input_sequence[MAX_LENGTH + 1];
    scanf("%s", input_sequence); 
    char* amp_pos_1 = strchr(input_sequence, '&');
    char* amp_pos_2 = strchr(input_sequence, '@');
    if (amp_pos_1 == NULL) {
        printf("0\n"); 
        return 0;
    }

    *amp_pos_1 = '\0';
    *amp_pos_2 = '\0';
    char* sequence1 = input_sequence;
    char* sequence2 = amp_pos_1 + 1;

    if (strchr(sequence1, '&') != NULL || strchr(sequence2, '&') != NULL) {
        printf("0\n"); 
    }
    else {

        if (is_reversed(sequence1, sequence2)) {
            printf("1\n"); 
        }
        else {
            printf("0\n"); 
        }
    }

    return 0;
}
