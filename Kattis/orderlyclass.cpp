#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
  string A, B;
  getline(cin, A);
  getline(cin, B);
  int N = A.size();

  auto left =
      distance(A.begin(), mismatch(A.begin(), A.end(), B.begin()).first);

  auto right =
      distance(A.rbegin(), mismatch(A.rbegin(), A.rend(), B.rbegin()).first);

  right = N - right - 1;

  vector<vector<int>> idx(26, vector<int>());
  for (int i = right; i < N; ++i) {
    idx[B[i] - 'a'].push_back(i);
  }

  long long count = 0;

  for (int i = 0; i <= left; ++i) {
    int c = A[i] - 'a';
    auto it = lower_bound(idx[c].begin(), idx[c].end(), i);

    if (it != idx[c].end()) {
      if (*it == i)
        it++;

      for (; it < idx[c].end(); it++) {
        int j = *it;
        int d = j - i + 1;

        bool valid = true;
        for (int k = 1; k < d; ++k) {
          if (A[i + k] != B[j - k]) {
            valid = false;
            break;
          }
        }

        if (valid) {
          /* cout << i << ' ' << j << '\n'; */
          count++;
        }
      }
    }
  }

  cout << count << '\n';
}
