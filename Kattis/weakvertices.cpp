#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;

  while (cin >> n, n != -1) {
    vector<bool> v(n);
    vector<int> m(n);

    int c;
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        cin >> c;
        m[y] |= (1 & (c - '0')) << x;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (!v[i]) {
        for (int j = 0; j < n; ++j) {
          if ((m[i] >> j) & 1) {
            if (m[i] & m[j]) {
              v[i] = true;
              v[j] = true;
            }
          }
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (!v[i])
        cout << i << (i + 1 < n ? " " : "");
    }
    cout << '\n';
  }
}
