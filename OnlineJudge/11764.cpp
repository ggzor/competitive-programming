#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int T;

  cin >> T;

  for (int i = 0; i < T; ++i) {
    int N, low = 0, high = 0;
    cin >> N;

    int prev, cur;
    cin >> prev;

    for (int j = 1; j < N; ++j) {
      cin >> cur;

      if (prev < cur)
        high++;
      else if (prev > cur)
        low++;

      prev = cur;
    }

    cout << "Case " << i + 1 << ": " << high << ' ' << low << '\n';
  }
}

