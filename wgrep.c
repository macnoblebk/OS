#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   if (argc == 1) {
      printf("wgrep:searchterm [file...]\n");
      return 1;

   }
   
   char* search_term = argv[1];
   char buffer[256];
   char* line = NULL;
   size_t linecap = 0;
   
   if (argc == 2) {
      fgets(buffer, sizeof(buffer), stdin);

      if (strstr(buffer, search_term) != NULL)
         printf("%s", buffer);
   
      return 0;
   }

   else {
         for (int i = 2; i < argc; i++) {

         char *filename = argv[i];

         FILE *fp = fopen(filename, "r");

         if (fp == NULL) 
            printf("wgrep:cannot open file.\n");
          
      
         while (getline(&line, &linecap, fp)) {
            if (strstr(line, search_term) != NULL)
              printf("%s", line);
         }

         fclose(fp);
      }

      free(line);
   }
   
   return 0;
}
