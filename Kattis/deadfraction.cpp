#include <iostream>
#include <numeric>
#include <string>
#include <utility>

#define uint unsigned long long

using namespace std;

uint gcd(uint a, uint b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

pair<uint, uint> simplificar(pair<uint, uint> p) {
  uint g = gcd(p.first, p.second);
  return make_pair(p.first / g, p.second / g);
}

int main() {
  string s;

  while (cin >> s, s != "0") {
    auto last = s.find('.', 2) - 1;

    auto dig = s[last];

    while (s[last - 1] != '.' && s[last - 1] == dig)
      last--;

    uint ln = 0;
    uint ld = 1;

    uint rn = 0;
    uint rd = 9;

    if (last > 2) {
      for (int i = 2; i < last; ++i) {
        ln *= 10;
        ln += (s[i] - '0');
        ld *= 10;
      }
    }

    rd *= ld;

    if (dig == '9') {
      ln++;
    } else {
      rn = (dig - '0');
    }

    uint num = ln * 9 + rn;
    uint den = rd;

    /* cout << ln << '/' << ld << " + " << rn << '/' << rd << '\n'; */
    /* cout << num << '/' << den << '\n'; */

    uint g = gcd(num, den);
    cout << num / g << '/' << den / g << '\n';
  }

  return 0;
}
