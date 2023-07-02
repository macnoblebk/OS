#include <stdio.h>

int main(int argc, char* argv[]) {
   if (argc == 1) {
      printf("wgrep:searchterm [file...]\n");
      return 1;

   }
   
   if (argc == 2) {
   // use fgets to read, input from stdin and match search term
      return 0;
   }

   char* filename;
   File *fp = NULL;

   for (int i = 2; i < argc; i++) {

      filename = argv[i];

      fp = fopen(filename, 'r');

      if (fp == NULL) {
         printf("wgrep:cannot open file.\n");
      } 

        
   }
   



   return 0;
}
