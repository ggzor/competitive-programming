#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  vector<unsigned int> primos;
  primos.push_back(2);
  int ultimo = 3;

  unsigned int n;
  while (cin >> n, n > 0) {
    while (primos[primos.size() - 1] < n) {
      while (1) {
        bool encontrado = true;
        for (auto primo : primos) {
          if (ultimo % primo == 0) {
            encontrado = false;
            break;
          }

          if (primo * primo > ultimo)
            break;
        }

        if (encontrado)
          break;

        ultimo++;
      }

      primos.push_back(ultimo);

      ultimo++;
    }

    for (auto p : primos) {
      if (binary_search(primos.begin(), primos.end(), n - p)) {
        cout << n << " = " << p << " + " << n - p << '\n';
        break;
      }
    }
  }
}
