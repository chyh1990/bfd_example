/*
 * =====================================================================================
 *
 *       Filename:  bfd.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/12/2012 08:33:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Yuheng (Chen Yuheng), chyh1990@163.com
 *   Organization:  Tsinghua Unv.
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <bfd.h>

void usage()
{
  printf("Usage: bfd [filename]\n");
}

int main(int argc, char* argv[])
{
  if(argc<2){
    usage();
    exit(0);
  }

  /*  load symbol table*/
  long size;
  long nsym;
  asymbol **asymtab;
  char* path = argv[1];

  bfd_init();
  bfd *abfd = bfd_openr(path, NULL);
  if(!abfd){
    perror("bfd_openr");
    exit(1);
  }

  if(!bfd_check_format(abfd, bfd_object)){
    printf("Unsupport file format\n");
    bfd_close(abfd);
    exit(1);
  }

  if((bfd_get_file_flags(abfd) & HAS_SYMS) == 0) {
    printf("No symbol\n");
    bfd_close(abfd);
    exit(1);
  }

  printf("sections: %d\n", bfd_count_sections(abfd));
  size = bfd_get_symtab_upper_bound(abfd);
  asymtab = malloc(size);
  nsym = bfd_canonicalize_symtab(abfd, asymtab); /* reads symtab*/

  /* create symbol table hash*/
  long i;
  //SymbolTable *symtab=NULL, *symbol;
  printf("symbols: %d\n", nsym);
  for (i = 0; i < nsym; i++) {
    printf("%016x  %s\n", bfd_asymbol_value(asymtab[i]), bfd_asymbol_name(asymtab[i]));
    /*  
    symbol = malloc(sizeof(Symbol));
    symbol->sym  = bfd_asymbol_name(asymtab[i]);
    symbol->addr = bfd_asymbol_value(asymtab[i]);
    HASH_ADD_KEYPTR(hh, symtab, symbol->sym, strlen(symbol->sym), symbol);
    */
  }

  free(asymtab);
  bfd_close(abfd);
  return 0;
}

