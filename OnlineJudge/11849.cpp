#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;

  while (cin >> N, cin >> M, N != 0 && M != 0) {
    vector<int> jack(N);
    for (int i = 0; i < N; ++i)
      cin >> jack[i];

    vector<int> jill(M);
    for (int j = 0; j < M; ++j)
      cin >> jill[j];

    int dup = 0;
    int i = 0, j = 0;
    bool completed = false;

    while (i < N && j < M && !completed) {
      if (jack[i] == jill[j]) {
        i++;
        j++;
        dup++;
      } else if (jack[i] > jill[j]) {
        j++;
      } else {
        i++;
      }
    }

    cout << dup << '\n';
  }
}
