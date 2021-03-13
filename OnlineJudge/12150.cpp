#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;

  while (cin >> N, N != 0) {
    vector<int> a(N, 0);
    bool valid = true;

    int C, P;
    for (int i = 0; i < N; i++) {
      cin >> C >> P;

      if (valid) {
        int idx = i + P;

        if (0 <= idx && idx < N && a[idx] == 0) {
          a[idx] = C;
        } else {
          valid = false;
        }
      }
    }

    if (valid) {
      bool first = true;
      for (auto x : a) {
        if (!first)
          cout << ' ';
        else
          first = false;

        cout << x;
      }
      cout << '\n';
    } else {
      cout << "-1\n";
    }
  }
}
