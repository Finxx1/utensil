#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef __linux__
	#include <stdio_ext.h>
#endif

// https://stackoverflow.com/a/35181970
void  touppper(char * temp) {
  char * name;
  name = strtok(temp,":");

  // Convert to upper case
  char *s = name;
  while (*s) {
    *s = toupper((unsigned char) *s);
    s++;
  }

}


int main() {
  printf("What is the name of your project?\n");
  char name[50];
  fgets(name, sizeof(name), stdin);
  strtok(name, "\n");
  char uppername[50];
  strcpy(uppername, name);
  touppper(uppername);

  printf("Which of these catagories does your program fall under?:\n");
  printf("1: A user command executed from the shell\n");
  printf("2: A system call performed by the kernel\n");
  printf("3: A library\n");
  printf("4: A device driver\n");
  printf("5: An options file\n");
  printf("6: A game\n");
  printf("7: An overview of a topic\n");
  printf("8: A root command that only admins can perform\n");
  char section = fgetc(stdin);
  
  #ifdef __linux__
    __fpurge(stdin);
  #else
    fpurge(stdin);
  #endif
  
  printf("Can you give a VERY SHORT description of your project?\n");
  char shortdesc[100];
  fgets(shortdesc, sizeof(shortdesc), stdin);
  strtok(shortdesc, "\n");
  
  printf("\nCan you provide an example of using this program? (Put unnecessary options in []'s)\n");
  char synopsis[100];
  fgets(synopsis, sizeof(synopsis), stdin);
  strtok(synopsis, "\n");
  
  printf("Now can you write a more detailed description of your program? (Dont use newlines)\n");
  char desc[1000];
  fgets(desc, sizeof(desc), stdin);
  strtok(desc, "\n");
  
  char *filename = malloc(sizeof(name) + 2*sizeof(char));
  strcpy(filename, name);
  strcat(filename, ".");
  strncat(filename, &section, 1);
  FILE* fp = fopen(filename, "w");
  
  fprintf(fp, ".TH %s %c\n", uppername, section);
  fprintf(fp, ".SH NAME\n");
  fprintf(fp, "%s \\- %s\n", name, shortdesc);
  fprintf(fp, ".SH SYNOPSIS\n");
  fprintf(fp, "%s\n", synopsis);
  fprintf(fp, ".SH DESCRIPTION\n");
  fprintf(fp, "%s\n", desc);
  fclose(fp);
  
  return 0;
}
