#include <stdio.h>


int stringLength(char *str) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}


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
      return i; 
    }
  }
  return -1; 
}


void replacePattern(char *STR, char *PAT, char *REP) {
  int strLen = stringLength(STR);
  int patLen = stringLength(PAT);
  int repLen = stringLength(REP);

  char result[1000]; 
                     
  int i = 0, j = 0, k;

  while (i < strLen) {
    
    int match = 1;
    for (k = 0; k < patLen; k++) {
      if (STR[i + k] != PAT[k]) {
        match = 0;
        break;
      }
    }

    if (match) {
      
      for (k = 0; k < repLen; k++) {
        result[j++] = REP[k];
      }
      i += patLen; 
    } else {
      
      result[j++] = STR[i++];
    }
  }

  result[j] = '\0'; 

  
  printf("Modified String: %s\n", result);
}

int main() {
  char STR[1000], PAT[100], REP[100];

  
  printf("Enter the main string (STR): ");
  scanf("%[^\n]%*c", STR);

  
  printf("Enter the pattern string (PAT): ");
  scanf("%[^\n]%*c", PAT);

  
  printf("Enter the replace string (REP): ");
  scanf("%[^\n]%*c", REP);

  
  int index = patternMatch(STR, PAT);
  if (index == -1) {
    printf("Pattern '%s' not found in the main string.\n", PAT);
  } else {
    
    replacePattern(STR, PAT, REP);
  }

  return 0;
}
