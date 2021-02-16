#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

  if (argc < 2) {
    printf("ERR: Too few arguments (%i arguments given)\n", argc);
    return 1;
  }

  if (argc > 2) {
    printf("ERR: Too many arguments (%i arguments given)\n", argc);
    return 1;
  }

  FILE* fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("ERR: Unable to read file. Maybe it does not exist?\n");
  }

  char buf[32761] = "";

  for (char c = '\0'; (c = fgetc(fp)) != EOF;) {
    strncat(buf, &c, 1);
  }
  fclose(fp);

  // This code is recycled from an older project on windows. IDK how it works anymore, but it works;
  char parsedata[181][181] = { { 0 } };
  int y = 0;
  int weird_x = 0;
  for (int x = 0; weird_x < (int)strlen(buf); x++) {
    if (buf[weird_x] == '\n') {
      parsedata[y][x] = buf[weird_x];
      x = -1;
      y++;
      weird_x++;
      continue;
    }
    parsedata[y][x] = buf[weird_x];
    weird_x++;
  }
  // End of weird code;

  char key[] = ">;{}"; // A list of characters to check for;

  for (int line=0; parsedata[line][0] != '\0'; line++) {
    if (parsedata[line][0] != '\n' && strchr(key, parsedata[line][strlen(parsedata[line])-2]) == NULL) {
      printf("Missing end character on line %i\n", line + 1);
    }
  }

  return 0;
}