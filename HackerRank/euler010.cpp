#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  vector<unsigned int> primos;
  primos.push_back(2);
  int ultimo = 3;

  vector<unsigned long> sumas;
  sumas.push_back(2);

  while (T--) {
    unsigned int N;
    cin >> N;

    if (N == 1) {
      cout << 0 << '\n';
      continue;
    }

    while (primos[primos.size() - 1] <= N) {
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
      sumas.push_back(sumas[sumas.size() - 1] + ultimo);

      ultimo++;
    }

    auto idx =
        distance(primos.begin(), upper_bound(primos.begin(), primos.end(), N));

    if (primos[idx] > N)
      idx--;

    cout << sumas[idx] << '\n';
  }
}
