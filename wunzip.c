#include <stdio.h>

   int main (int argc, char* argv[]) {
      char character;
      int count;
      
      if (argc  < 2) {
         printf("wunzip: file [file2 ...]\n");
         return 1;
      }

      for(int i = 1; i < argc; i++) {
         FILE *fp = fopen(argv[i], "rb");

         if (fp == NULL)
            printf("wunzip: cannot open file");

         while (fread(&count, sizeof(int), 1, fp) > 0) {
            fread(&character, sizeof(char), 1, fp);
            
            for (int i = 0; i < count; i++) {
               fwrite(&character, sizeof(char), 1, stdout);
            }

         }

         fclose(argv[i]);
      }

      return 0;
   }
