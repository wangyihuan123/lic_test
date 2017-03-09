#include <stdio.h>
#include <macTypes.h>
#include <string.h>

#ifndef ALPHABET_NUMBER
# define ALPHABET_NUMBER  26
#endif

static bool checkAnagram(char *input);
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

static bool checkAnagram(char* input)
{
  char alphabet[ALPHABET_NUMBER];
//  char input[128] = "aaaaabcdefgfedcbaaaaa";
//  char backwards[128]="";
  int oddCounter = 0;
  register size_t str_len = strlen(input);

  memset(alphabet, 0, sizeof(alphabet));

  for( int i = 0; i < str_len; i++ )
  {
    char ch = input[i];
    alphabet[ch-'a']++;
  }

  for( int cnt=0; cnt< ALPHABET_NUMBER; cnt++ )
  {
    if (alphabet[cnt]&0x01)
      oddCounter++;
  }

  if(oddCounter > 1)
  {
    return false;
  }
  else{

    return true;
  }
}

static bool
checkPalindrone(char *input) {

  int size = sizeof(input);
  char backwards[size-1];

//  memset(backwards,0, sizeof(backwards));
  strcpy(backwards, input);
  reverse(backwards);
  if (strcmp(input, backwards) == 0)
  {
    return true;
  }
  else{
    return false;
  }

};

#define  MAX_READ_SIZE  65535
int main() {
  FILE* fp;
  char  line[MAX_READ_SIZE];
  bool result;
//  char  *input;
  fp = fopen("/Users/zxl2013/ClionProjects/lic_test/lic_test.data", "r");
  if (!fp)
  {
    printf("open file error\n");
    return 1;
  }
  while (fgets(line, sizeof(line), fp) != NULL)
  {
    size_t linelen = strlen(line) + 1;
//    trim(line);
    char input[linelen];
    strcpy(input, line);
//    line[0] = tolower(line[0]);
    result = checkAnagram(input);
    if (! result)
    {
      printf("%s is neither.\n", input);
//      return 0;
    }
    else {
      result = checkPalindrone(input);
      if (result) {
        printf("%s is a palindrone\n", input);
//      return 0;
      } else {
        printf("%s is an anagram of a palindrome\n", input);
//      return 0;
      }
    }
  }

  return 0;
}