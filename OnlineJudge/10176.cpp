#include <cstdio>

using namespace std;

int main() {
  while (!feof(stdin)) {
    int rem = 0;

    int c;
    while ((c = fgetc(stdin)) != '#') {
      if (feof(stdin))
        return 0;

      if (c == '0' || c == '1') {
        rem = (rem * 2 + (c - '0')) % 131071;
      }
    }

    if (rem == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
