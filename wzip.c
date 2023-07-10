#include <stdio.h>

   int main(int argc, char* argv[]) {
      if (argc < 2)
         printf("wzip: file [file2 ...]\n");       
      
      else {
         for (int i = 1; i < argc; i++) {
            FILE *fp = fopen(argv[i],"rb");
            char prevChar, currChar;
            int count = 1;
   
            fread(&prevChar, sizeof(char), 1, fp);
            while(fread(&currChar, sizeof(char), 1, fp) > 0) {
               if (currChar == prevChar)
                   count++;
               
               else {
                  fwrite(&count, sizeof(int), 1, stdout);
                  fwrite(&prevChar, size(char), 1, stdout);
                  prevChar = currChar;
                  count = 1;
               }
            }

            fwrite(&count, sizeof(int), 1, stdout);
            fwrite(&prevChar, sizeof(char), 1, stdout);
	    
            fclose(fp);
            fclose(fpout);
        }

     }

      return 0;
   }   
