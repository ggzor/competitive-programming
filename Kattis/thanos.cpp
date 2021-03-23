#include <cmath>
#include <iostream>

using uint = unsigned int;
using namespace std;

int main() {
  uint T;

  cin >> T;

  while (T--) {
    uint P, R, F;
    cin >> P >> R >> F;

    uint d = F / P;
    if (d == 0 || R == 1) {
      cout << 0 << '\n';
    } else {
      cout << (uint)(logl(d) / logl(R)) + 1 << '\n';
    }
  }
}
