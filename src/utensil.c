#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc == 1) {
    printf("Please specify which program you want to run, or use 'list' to get a list of programs available.\n");
    return 1;
  }
  if (!strcmp(argv[1], "list")) {
    printf("Available programs:\n");
    printf("spatula - Creates a development envirnment quickly.\n");
    printf("fork - Analyzes C code and find lines without an ending.\n");
    printf("knife - Analyzes C code and find lines that are thick.\n");
    printf("spoon - Create a simple man page easily.\n");
    return 0;
  }
  if (!strcmp(argv[1], "spatula")) {
    if (argc != 3) {
      printf("spatula requires 1 argument!\n");
      return 1;
    }
    char* tmp = malloc(strlen(argv[2]) + strlen("/opt/utensil/bin/spatula "));
    strcpy(tmp, "/opt/utensil/bin/spatula ");
    strcat(tmp, argv[2]);
    system(tmp);
    free(tmp);
    return 0;
  }
  if (!strcmp(argv[1], "fork")) {
    if (argc != 3) {
      printf("fork requires 1 argument!\n");
      return 1;
    }
    char* tmp = malloc(strlen(argv[2]) + strlen("/opt/utensil/bin/fork "));
    strcpy(tmp, "/opt/utensil/bin/fork ");
    strcat(tmp, argv[2]);
    system(tmp);
    free(tmp);
    return 0;
  }
  if (!strcmp(argv[1], "knife")) {
    if (argc != 3) {
      printf("knife requires 1 argument!\n");
      return 1;
    }
    char* tmp = malloc(strlen(argv[2]) + strlen("/opt/utensil/bin/knife "));
    strcpy(tmp, "/opt/utensil/bin/knife ");
    strcat(tmp, argv[2]);
    system(tmp);
    free(tmp);
    return 0;
  }
  if (!strcmp(argv[1], "spoon")) {
    if (argc != 2) {
      printf("spoon requires 0 arguments!\n");
      return 1;
    }
    char* tmp = malloc(strlen("/opt/utensil/bin/spoon") + 1);
    strcpy(tmp, "/opt/utensil/bin/spoon");
    system(tmp);
    free(tmp);
    return 0;
  }
  return 0;
}
