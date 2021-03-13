#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    unsigned long N;
    cin >> N;

    unsigned long last = 0;
    for (unsigned long i = 2; i * i <= N; ++i) {
      if (N % i == 0) {
        last = i;

        while (N % i == 0)
          N /= i;
      }
    }

    cout << ((last == 0 || N > 1) ? N : last) << '\n';
  }
}
