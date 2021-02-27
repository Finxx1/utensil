#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
  const char* dir = "\"C:\\Program Files\\utensil\\bin\\";
#endif
#ifdef __unix__
  const char* dir = "/opt/utensil/bin/";
#endif

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
    printf("whisk - Text editor.\n");
    return 0;
  }
  if (!strcmp(argv[1], "spatula")) {
    if (argc != 3) {
      printf("spatula requires 1 argument!\n");
      return 1;
    }
    char* tmp = malloc(strlen(argv[2]) + strlen(dir) + strlen("spatula "));
    strcpy(tmp, dir);
    strcat(tmp, "spatula ");
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
    char* tmp = malloc(strlen(argv[2]) + strlen(dir) + strlen("fork "));
    strcpy(tmp, dir);
    strcat(tmp, "fork ");
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
    char* tmp = malloc(strlen(argv[2]) + strlen(dir) + strlen("knife "));
    strcpy(tmp, dir);
    strcat(tmp, "knife ");
    strcat(tmp, argv[2]);
    system(tmp);
    free(tmp);
    return 0;
  }
  if (!strcmp(argv[1], "whisk")) {
    if (argc != 3) {
      printf("whisk requires 1 argument!\n");
      return 1;
    }
    char* tmp = malloc(strlen(argv[2]) + strlen(dir) + strlen("whisk "));
    strcpy(tmp, dir);
    strcat(tmp, "whisk ");
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
    char* tmp = malloc(strlen("/opt/utensil/bin/spoon"));
    strcpy(tmp, dir);
    strcat(tmp, "spoon");
    system(tmp);
    free(tmp);
    return 0;
  }
  return 0;
}
