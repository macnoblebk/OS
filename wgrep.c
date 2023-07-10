#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void wgrep(FILE *fp, const char *searchTerm) {
   char *line = NULL;
   size_t len = 0;
 
   while (getline(&line, &len, fp) != -1) {
      if (strstr(line, searchTerm) != NULL) 
         printf("%s", line);
   
   }
   
   free(line);
}

int main(int argc, char* argv[]) {
  
   if (argc < 2) {
      printf("wgrep: searchterm [file...]\n");
      return 1;
   }
   
   const char* searchTerm = argv[1]; 
   if (argc == 2) {
      char buffer [128];
      while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
         if (strstr(buffer, searchTerm)!= NULL)
            printf("%s", buffer);
            return 0;
      }
   } 
   
   else {
      for (int i = 2; i < argc; i++) {
   
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL) { 
           printf("wgrep: me cannot open file\n");
           return 1;
        }

        wgrep(fp, searchTerm);
        fclose(fp);
      }
   }

   return 0;
}
