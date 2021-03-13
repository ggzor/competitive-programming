#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    unsigned long long N;
    cin >> N;

    unsigned long long f0 = 0;
    unsigned long long f1 = 2;
    unsigned long long sum = f0 + f1;

    unsigned long long nuevo;
    while (nuevo = 4 * f1 + f0, nuevo <= N) {
      f0 = f1;
      f1 = nuevo;

      sum += nuevo;
    }

    cout << sum << '\n';
  }
}
