/**************************************************
 *
 * This program implement the validation of
 * palindrome or anagram with the complexity of
 * O(n). Which is better than the solution on the
 * internet () when n >> 26.
 */

#include "head.h"

void reverse(char *  str)
{
  if (*str == 1 || str == NULL)
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

bool checkAnagram(const char* const input)
{
  char alphabet[ALPHABET_NUMBER];
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
    {
      oddCounter++;
    }
  }

  if(oddCounter > 1)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool
checkPalindrone(const char * const input)
{
  int size = sizeof(input);
  char backwards[size-1];

  // memset is not necessary here
  strcpy(backwards, input);
  reverse(backwards);
  if (strcmp(input, backwards) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
};


RESULT_TYPE solution(const char * const line)
{
  bool result;
  size_t linelen = strlen(line) + 1;
  char input[linelen];

  strcpy(input, line);
  result = checkAnagram(input);
  if (! result)
  {
    return neither;
  }
  else
  {
    result = checkPalindrone(input);
    if (result)
    {
      return palindrone;
    }
    else
    {
      return anagram;
    }
  }
}

int main(int argc, char ** argv) {

#ifdef UNIT_TEST
  unit_test();
  unit_test_file();
#endif

  // assumption:
  // - Normal console input does not exceed the MAX_READ_SIZE.
  // - There will be no whitespace in the string.
  // - All characters in the string will be lower case.
  // - The string will only contain alpha characters a-z.

  char  line[MAX_READ_SIZE];

  printf("\nPlease input your word:\n");
  fscanf(stdin, "%s", line);
  switch (solution(line))
  {
    case palindrone:
      printf("%s is a palindrone\n", line);
      break;
    case anagram:
      printf("%s is an anagram of a palindrome\n", line);
      break;
    case neither:
      printf("%s is neither.\n", line);
      break;
    default:
      printf("[err]: Unknown exception\n");
  }

  return 0;
}


void unit_test (void) {
  char * test_case[7] = {"anna",
                      "aaaaaaaa",
                      "aaaaaaaab",
                      "caaaaaaaab",
                      "donotbobtonod",
                      "owefhijpfwai",
                      "igdedgide"};

  printf("---------- unit_test ----------\n");

  for (int i = 0; i < 7; i++)
  {
    fprintf(stdout, "\"%s\" will return %s.\n", test_case[i],
            checkAnagram(test_case[i])?"true":"false");
  }

}

void unit_test_file (void) {
  FILE * fp;
  char  line[MAX_READ_SIZE];
  char * test_data_file = "./lic_test.data";

  fp = fopen(test_data_file, "r");
  if (!fp)
  {
    printf("[err]: Failed to open file: %s \n", test_data_file);
    return ;
  }

  printf("---------- unit_test_file ----------\n");
  while (fgets(line, sizeof(line), fp) != NULL)
  {
    register size_t str_len = strlen(line);
    line[str_len-1] = '\0';
    fprintf(stdout, "\"%s\" will return %s.\n", line,
            checkAnagram(line)?"true":"false");
  }
}