#include <stdio.h>
#include <string.h>

#define MAX 100

void readString(char *str, const char *prompt) {
    printf("%s", prompt);
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
}

int findPattern(const char *str, const char *pat) {
    int i, j, found;
    int strLen = strlen(str);
    int patLen = strlen(pat);

    for (i = 0; i <= strLen - patLen; i++) {
        found = 1;
        for (j = 0; j < patLen; j++) {
            if (str[i + j] != pat[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return -1;
}

void replacePattern(char *str, const char *pat, const char *rep) {
    char result[MAX];
    int i, j, k;
    int strLen = strlen(str);
    int patLen = strlen(pat);
    int repLen = strlen(rep);
    int pos = 0;

    i = 0;
    while (i < strLen) {
        int index = findPattern(&str[i], pat);
        if (index == -1) {
            break;
        }
        for (j = 0; j < index; j++) {
            result[pos++] = str[i + j];
        }
        for (k = 0; k < repLen; k++) {
            result[pos++] = rep[k];
        }
        i += index + patLen;
    }
    while (i < strLen) {
        result[pos++] = str[i++];
    }
    result[pos] = '\0';
    strcpy(str, result);
}

int main() {
    char str[MAX], pat[MAX], rep[MAX];

    readString(str, "Enter the main string (STR): ");
    readString(pat, "Enter the pattern string (PAT): ");
    readString(rep, "Enter the replace string (REP): ");

    if (findPattern(str, pat) == -1) {
        printf("Pattern not found in the main string.\n");
    } else {
        replacePattern(str, pat, rep);
        printf("The new string is: %s\n", str);
    }

    return 0;
}