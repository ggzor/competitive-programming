
#include <iostream>

using namespace std;

inline unsigned long range(unsigned long N) { return (N * (N + 1)) / 2; }

int main() {
  int T;
  cin >> T;

  while (T--) {
    unsigned int N;
    cin >> N;
    N--;

    cout << 3 * range(N / 3) + 5 * range(N / 5) - 15 * range(N / 15) << '\n';
  }
}
