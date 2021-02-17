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

  // This code is recycled from an older
  // project on windows. IDK how it 
  // works anymore, but it works;
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
  
  for (int line=0; parsedata[line][0] != '\0'; line++) {
    if (strlen(parsedata[line]) > 120) {
      printf("Line %i is looking REALLY chonky. (>120 characters long)\n", line+1);
    } else if (strlen(parsedata[line]) > 90) {
      printf("Line %i is looking pretty darn chonky. (~90 characters long)\n", line+1);
    } else if (strlen(parsedata[line]) > 70) {
      printf("Line %i is looking quite chonky. (~70 characters long)\n", line+1);
    } else if (strlen(parsedata[line]) > 50) {
      printf("Line %i is looking a bit chonky. (~50 characters long)\n", line+1);
    }
  }
  
  return 0;
}
