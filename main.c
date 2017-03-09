#include <stdio.h>
#include <macTypes.h>
#include <string.h>

static bool checkAnagram(void);
void reverse(char *str);

void reverse(char *str)
{
  if (*str == 1)
  {
    return;
  }

  char *start = str;
  char *end = start + strlen(str) - 1;
  char temp;

  while (end > start)
  {
    temp = *start;
    *start = *end;
    *end = temp;

    ++start;
    --end;
  }
}

static bool checkAnagram(void)
{
  char  Apl[26];
  char input[128] = "cbcabacbc";
  char backwards[128]="";
  char oddtimes=0;
  int temp3,temp4= 0;
  int oddCounter = 0;

  for(int i=0;i<26;i++)
  {
    Apl[i] = '\0';
  }
  temp3 = StrLength(input);
  temp4 = strlen(input);
  for( int i = 0; i < strlen(input); i++ )
  {
    char ch = input[i];
    Apl[ch-'a']++;
  }
  for( int cnt=0; cnt< 26;cnt++ )
  {
    //printf(oddOccur);
    char tmp = Apl[cnt];
    char tmp2;
    if (Apl[cnt]%2 == 1) {
      oddCounter++;
      tmp2 = oddCounter % 2;
      //if (oddOccur % 2 == 1) // more than 1 char should have odd frequency
      //  oddtimes++;
    }
    //if( cnt%2 == 1 )
    //  oddOccur++;
  }
  if(oddCounter >1)
  {
    printf("neither\n");
    return false;
  }
  else{
    strcpy(backwards, input);
    reverse(backwards);
    if (strcmp(input, backwards) == 0)
    {
      printf("%s is a palindrone\n", input);
    }
    else{
      printf("%s is a anogram\n", input);
    }

    return true;
  }
  //return true;
}



int main() {
  bool result;

  result = checkAnagram();

  return 0;
}