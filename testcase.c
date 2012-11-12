/*
 * =====================================================================================
 *
 *       Filename:  testcase.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/12/2012 08:26:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Yuheng (Chen Yuheng), chyh1990@163.com
 *   Organization:  Tsinghua Unv.
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s1{
  int s1_a;
  void* s1_b;
};

struct s2{
  int a;
  int b;
  char * c;
  unsigned long d;
  long long e;
  union{
    int a;
    void *b;
  }u;
  struct s1 s;
};

int main(int argc, char* argv[])
{
  struct s2 foo;
  memset(&foo, 0, sizeof(struct s2));
  printf("FOO %d\n", foo.a);
  return 0;
}

