#include<stdio.h>
int main() {
  char STR[100],PAT[100],REP[100],ans[100];
  int i,j,c,m,k,flag=0;
  printf("\nEnter the MAIN string: \n");
  gets(STR);
  printf("\nEnter a PATTERN string: \n");
  gets(PAT);
  printf("\nEnter a REPLACE string: \n");
  gets(REP);
  i = m = c = j = 0;
  while ( STR[c] != '\0') {
    if ( STR[m] == PAT[i] ) {
      i++;
      m++;
      if ( PAT[i] == '\0') {
        flag=1;
        for(k=0; REP[k] != '\0';k++,j++) ans[j] = REP[k];
        i=0;
        c=m;
      }
    } else {
      ans[j] = STR[c];
      j++;
      c++;
      m = c;
      i=0;
    }
  }
  if(flag==0) {
    printf("Pattern doesn't found!!!");
  } else {
    ans[j] = '\0';
    printf("\nThe RESULTANT string is:%s\n" ,ans);
  }
  return 0;
}
