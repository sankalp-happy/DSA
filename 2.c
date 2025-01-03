#include <stdio.h>

// Function to calculate the length of a string
int stringLength(char *str) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

// Function to check if PAT exists in STR
int patternMatch(char *STR, char *PAT) {
  int strLen = stringLength(STR);
  int patLen = stringLength(PAT);

  for (int i = 0; i <= strLen - patLen; i++) {
    int j;
    for (j = 0; j < patLen; j++) {
      if (STR[i + j] != PAT[j]) {
        break;
      }
    }
    if (j == patLen) {
      return i; // Return the starting index of PAT in STR
    }
  }
  return -1; // PAT not found in STR
}

// Function to replace all occurrences of PAT with REP in STR
void replacePattern(char *STR, char *PAT, char *REP) {
  int strLen = stringLength(STR);
  int patLen = stringLength(PAT);
  int repLen = stringLength(REP);

  char result[1000]; // Assuming the result string will not exceed 1000
                     // characters
  int i = 0, j = 0, k;

  while (i < strLen) {
    // Check if PAT exists at the current position in STR
    int match = 1;
    for (k = 0; k < patLen; k++) {
      if (STR[i + k] != PAT[k]) {
        match = 0;
        break;
      }
    }

    if (match) {
      // Replace PAT with REP
      for (k = 0; k < repLen; k++) {
        result[j++] = REP[k];
      }
      i += patLen; // Move the index ahead by the length of PAT
    } else {
      // Copy the current character from STR to result
      result[j++] = STR[i++];
    }
  }

  result[j] = '\0'; // Null-terminate the result string

  // Print the modified string
  printf("Modified String: %s\n", result);
}

int main() {
  char STR[1000], PAT[100], REP[100];

  // Read the main string (STR)
  printf("Enter the main string (STR): ");
  scanf("%[^\n]%*c", STR);

  // Read the pattern string (PAT)
  printf("Enter the pattern string (PAT): ");
  scanf("%[^\n]%*c", PAT);

  // Read the replace string (REP)
  printf("Enter the replace string (REP): ");
  scanf("%[^\n]%*c", REP);

  // Check if PAT exists in STR
  int index = patternMatch(STR, PAT);
  if (index == -1) {
    printf("Pattern '%s' not found in the main string.\n", PAT);
  } else {
    // Replace all occurrences of PAT with REP in STR
    replacePattern(STR, PAT, REP);
  }

  return 0;
}
