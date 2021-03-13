#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

#define MAX_N (40 + 1)

int main() {
  vector<map<int, int>> max_factors(MAX_N, map<int, int>());
  max_factors[2][2] = 1;

  for (int i = 3; i < MAX_N; ++i) {
    max_factors[i] = max_factors[i - 1];

    int n = i;

    for (int j = 2; j <= n; ++j) {
      int count = 0;

      while (n % j == 0) {
        count++;
        n /= j;
      }

      max_factors[i][j] = max(max_factors[i][j], count);
    }
  }

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    unsigned long result = 1;

    for (auto &p : max_factors[N])
      result *= pow(p.first, p.second);

    cout << result << '\n';
  }
}
