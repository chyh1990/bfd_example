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
  int s2_a;
  int s2_b;
  char * s2_c;
  unsigned long s2_d;
  long long s2_e;
  union{
    int s2_u_a;
    void *s2_u_b;
  }u;
  struct s1 s2_s;
};

struct s2 gFoo = {2,3};

int main(int argc, char* argv[])
{
  struct s2 foo;
  memset(&foo, 0, sizeof(struct s2));
  printf("sizeof(foo)=%d\n", (int)sizeof(foo));
  printf("foo.s2_a=%d\n", foo.s2_a);
  return 0;
}

