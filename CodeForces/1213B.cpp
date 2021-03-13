#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int j = 0; j < n; j++)
      cin >> a[j];

    int bad = 0;
    int min = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] > min) {
        bad++;
      } else if (a[i] < min) {
        min = a[i];
      }
    }

    cout << bad << '\n';
  }
}
