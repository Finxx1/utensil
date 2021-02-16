# An explanation
Fork at it's core is a program that reads a file, tests it data, and spits out the results. However, the code can be complicated, so this document will explain the code in chunks

---

```c
#include <stdio.h>
#include <string.h>
```
Pretty simple, although keep in mind that everything included should work on both Windows and Linux.

---

```c
if (argc < 2) {
  printf("ERR: Too few arguments (%i arguments given)\n", argc);
  return 1;
}
if (argc > 2) {
  printf("ERR: Too many arguments (%i arguments given)\n", argc);
  return 1;
}
```
This code checks if you supplied the right number of arguments. The reason I didn't use ```if (argc != 2)``` is that the program would not be able to say if the number of arguments supplied are too big or too small

---

```c
FILE* fp = fopen(argv[1], "r");

if (fp == NULL) {
  printf("ERR: Unable to read file. Maybe it does not exist?\n");
}

char buf[32761] = "";

for (char c = '\0'; (c = fgetc(fp)) != EOF;) {
  strncat(buf, &c, 1);
}
fclose(fp);
```
This code reads the file the user gave, or complains of the file doesn't exist. Keep in mind that the method I used to read the file is pretty bad, but no other methods I found online worked.

---

```c
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
```
I can't really tell you how this works, but it takes an array of characters and it turn it into a 2D array split at every ```\n```. For example, 
```
t\nte\ntes\ntest
```
Becomes
```
t\n
te\n
tes\n
test\n
```
I wrote this function myself at 7:00 PM some day, so thats why I don't remember how it works, but it works.

---

```c
char key[] = ">;{}"; // A list of characters to check for;

for (int line=0; parsedata[line][0] != '\0'; line++) {
  if (parsedata[line][0] != '\n' && strchr(key, parsedata[line][strlen(parsedata[line])-2]) == NULL) {
    printf("Missing end character on line %i\n", line + 1);
  }
}
```
This is the part of the program that checks if your code is ~~bad~~ incorrect. ```key[]``` contains characters to check for at the end of a line. If the first character of the string is not a newline and strchr() cant find anything at the ending character of the line, then it uses printf to print out a message that contains the line we were testing - 1 (we start at 0, but code editors start at 1).
## Hope this helps!
