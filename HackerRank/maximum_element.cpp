#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline int get_maximum(const vector<int> &a) {
  if (a.empty())
    return -1;
  else
    return *max_element(a.begin(), a.end());
}

int main() {
  int t;
  cin >> t;

  vector<int> a;
  int maximum = -1;

  while (t--) {
    int q;
    cin >> q;

    if (q == 1) {
      int x;
      cin >> x;

      a.push_back(x);

      if (x > maximum)
        maximum = x;
    } else if (!a.empty()) {
      if (q == 2) {
        int last = a[a.size() - 1];
        a.pop_back();

        if (last == maximum)
          maximum = get_maximum(a);
      } else {
        cout << maximum << '\n';
      }
    }
  }
}
