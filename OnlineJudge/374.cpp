#include <cmath>
#include <iostream>

using namespace std;

int main() {
  unsigned int B, P, M;
  while (!cin.eof()) {
    cin >> B;
    if (cin.eof())
      return 0;
    cin >> P;
    if (cin.eof())
      return 0;
    cin >> M;

    B %= M;

    if (M == 1 || B == 0) {
      cout << 0 << '\n';
      continue;
    }

    if (P == 0) {
      cout << 1 << '\n';
      continue;
    }

    int msb = 0;
    unsigned int oldp = P;
    while (oldp >>= 1)
      msb++;

    unsigned int r = B;

    while (msb--) {
      bool isOne = ((P >> msb) % 2) == 1;

      r = (r * r) % M;

      if (isOne) {
        r = (r * B) % M;
      }
    }

    cout << r << '\n';
  }
}
