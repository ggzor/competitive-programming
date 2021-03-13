#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  vector<int> primos;
  primos.push_back(2);
  int ultimo = 3;

  while (T--) {
    int N;
    cin >> N;

    while (primos.size() < N) {
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

    cout << primos[N - 1] << '\n';
  }
}
