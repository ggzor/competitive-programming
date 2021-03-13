#include <algorithm>
#include <bitset>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define uint unsigned int
#define FULL 0x3ffffff

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<uint> ss(n);

  string s;
  getline(cin, s);

  cout << setw(10) << ""
       << " ";
  for (char c = 'z'; c >= 'a'; c--) {
    cout << c;
  }
  cout << '\n';

  for (int i = 0; i < n; ++i) {
    getline(cin, s);

    for (auto c : s)
      ss[i] |= 1 << (c - 'a');

    cout << setw(10) << s << ' ' << bitset<26>(ss[i]) << '\n';
  }

  vector<uint> items((uint)(powl(2, n)));
  items[0] = 0;
  items[1] = ss[0];

  uint result = ss[0] == FULL;
  for (int i = 1; i < ss.size(); ++i) {
    uint x = ss[i];
    uint p = (uint)powl(2, i);

    for (int j = 0; j < p; j++) {
      uint v = items[j] | x;

      items[p + j] = v;

      if (v == FULL)
        result++;
    }
  }
  cout << result << '\n';

  return 0;
}
