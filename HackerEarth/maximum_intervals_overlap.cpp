#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> tiempos;
  vector<int> primeros(n);

  for (int i = 0; i < n; ++i)
    cin >> primeros[i];

  for (int i = 0; i < n; ++i) {
    int inicio = primeros[i];
    int fin;
    cin >> fin;

    for (int i = inicio; i <= fin; ++i)
      tiempos[i]++;
  }

  cout << std::max_element(
              tiempos.begin(), tiempos.end(),
              [](auto p1, auto p2) { return p1.second < p2.second; })
              ->first
       << '\n';
}
