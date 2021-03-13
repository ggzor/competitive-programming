#include <iostream>
#include <string>

using namespace std;

int main() {
  string n;
  while (cin >> n, n != "0") {
    int rem = 0;

    for (auto i : n)
      rem = ((rem * 10) + (i - '0')) % 17;

    cout << (rem == 0 ? 1 : 0) << '\n';
  }
}
