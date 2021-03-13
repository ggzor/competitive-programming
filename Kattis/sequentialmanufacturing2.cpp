#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

#define uint unsigned long long
#define MAX 1000

using namespace std;

int main() {
  int N, P;

  cin >> N;
  cin >> P;

  vector<uint> T(N);
  vector<uint> remaining(N);

  vector<uint> K(N);
  vector<uint> counters(N);

  for (int i = 0; i < N; ++i)
    cin >> T[i];

  for (int i = 1; i < N; ++i)
    cin >> K[i];

  uint steps = 0;
  bitset<MAX> active;

  while (P > 0 || active.any()) {
    steps++;

    if (P) {
      counters[0]++;
      active[0] = true;

      P--;
    }

    for (int i = 0; i < N; ++i) {
      if (remaining[i] > 0) {
        remaining[i]--;

        if (remaining[i] == 0) {
          if (counters[i] == 0)
            active[i] = false;

          if (i < N - 1) {
            counters[i + 1]++;
            active[i + 1] = true;
          }
        }
      }

      if (counters[i] > 0) {
        if (remaining[i] == 0) {
          counters[i]--;

          remaining[i] = T[i];
        }

        if (counters[i] > K[i]) {
          cerr << "Shutdown\n";
          return 0;
        }
      }
    }
  }

  cout << steps - 1 << '\n';

  return 0;
}
