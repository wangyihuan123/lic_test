//
// Created by Benjamin on 9/03/17.
//

#ifndef LIC_TEST_HEAD_H
#define LIC_TEST_HEAD_H

#include <stdio.h>
#include <macTypes.h>
#include <string.h>

#ifndef ALPHABET_NUMBER
# define ALPHABET_NUMBER  26
#endif


#define  MAX_READ_SIZE  65535
#define UNIT_TEST

typedef enum {
  palindrone = 1,
  anagram,
  neither
}RESULT_TYPE;

void reverse(char * const str);
bool checkAnagram(const char * const input);
bool checkPalindrone(const char * const input);

RESULT_TYPE solution(const char * const line);

// unit test declaration
void unit_test();
void unit_test_file (void);


#endif //LIC_TEST_HEAD_H
