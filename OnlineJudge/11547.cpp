#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int t;

  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    n = (n * (567 / 9) + 7492) * (235 / 47) - 498;

    cout << abs((n / 10) % 10) << '\n';
  }
}

