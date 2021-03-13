#include <stdio.h>

int main() {
  int c;
  int quote = 0;

  while ((c = fgetc(stdin)) != EOF) {
    if (c == '"') {
      if (!quote)
        c = '`';
      else
        c = '\'';

      putc(c, stdout);
      putc(c, stdout);

      quote = !quote;
    } else {
      putc(c, stdout);
    }
  }
}

