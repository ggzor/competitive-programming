#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, int> species;

  string line;
  line.reserve(30);

  int count;

  getline(cin, line);
  getline(cin, line);

  for (int i = 0; i < n; i++) {
    species.clear();
    count = 0;

    while (getline(cin, line) && line != "") {
      species[line]++;
      count++;
    }

    cout << fixed;
    cout << setprecision(4);
    for (auto p : species) {
      cout << p.first << ' ' << (double)(p.second * 100) / count << '\n';
    }

    if (i < n - 1)
      cout << '\n';
  }
}
