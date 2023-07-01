#include <stdio.h>

int main(int argc, char* argv[]) {

   if (argc == 1)
      return 0;
   
   char *filename = argv[1];

   FILE *fp = fopen(filename, "r");

   if (fp == NULL) {
      printf("wcat: cannot open file\n");
      return 1;
   }

   char buffer[256];

   while ( fgets(buffer, sizeof(buffer), fp) != NULL ) {
      printf("%s", buffer);
   }
   
   fclose(fp);

return 0;
}
