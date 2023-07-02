#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
   if (argc == 1) {
      printf("wgrep:searchterm [file...]\n");
      return 1;

   }
   
   if (argc == 2) {
   // use fgets to read, input from stdin and match search term
      return 0;
   }

   char* line = NULL;
   size_t linecap = 0;

   char* search_term = argv[1];

   for (int i = 2; i < argc; i++) {

      char *filename = argv[i];
      FILE *fp = fopen(filename, "r");

      if (fp == NULL) {
         printf("wgrep:cannot open file.\n");
      } 
      
      while (getline(&line, &linecap, fp)) {
         if (strstr(line, search_term) != NULL)
           printf("%s", line);
      }

      fclose(fp);
   }
   
   return 0;
}
