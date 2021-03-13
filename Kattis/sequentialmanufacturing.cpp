#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

#define uint unsigned long long
#define MAX 1000

using namespace std;

int main() {
  int N, P;

  cin >> N;
  cin >> P;

  vector<uint> T(N);
  vector<uint> remaining(N);

  vector<uint> K(N);
  vector<uint> counters(N);

  for (int i = 0; i < N; ++i)
    cin >> T[i];

  for (int i = 1; i < N; ++i)
    cin >> K[i];

  uint steps = 0;
  bitset<MAX> active;

  vector<string> values(N + 1, "0 ");
  vector<vector<int>> capacities(N);
  vector<vector<int>> remaining_times(N);

  for (int i = 0; i < K.size(); ++i) {
    capacities[i].push_back(K[i]);
    remaining_times[i].push_back(0);
  }

  bitset<1001> pinglist;
  bitset<1001> beginlist;
  auto ping = [&](auto idx) { pinglist[idx] = true; };
  auto begin = [&](auto idx) { beginlist[idx] = true; };

  auto update_capacities = [&]() {
    for (int i = 0; i < N; ++i) {
      capacities[i].push_back(K[i] - counters[i]);
      remaining_times[i].push_back(remaining[i]);

      values[i] += '0' + (int)pinglist[i];
      values[i] += beginlist[i] ? '|' : ' ';
    }

    values[N] += '0' + (int)pinglist[N];
    values[N] += ' ';
  };

  string bitseq =
      getenv("SEQ") != NULL ? string(getenv("SEQ")) : "0" + string(P, '1');

  bool wrong = false;
  while (P > 0 || active.any()) {
    pinglist.reset();
    beginlist.reset();

    steps++;

    if (P && bitseq[steps] == '1') {
      counters[0]++;
      active[0] = true;
      ping(N);

      P--;
    }

    for (int i = 0; i < N; ++i) {
      if (remaining[i] > 0) {
        remaining[i]--;

        if (remaining[i] == 0) {
          if (counters[i] == 0)
            active[i] = false;

          ping(i);

          if (i < N - 1) {
            counters[i + 1]++;
            active[i + 1] = true;
          }
        }
      }

      if (counters[i] > 0) {
        if (remaining[i] == 0) {
          begin(i);
          counters[i]--;

          remaining[i] = T[i];
        }

        if (i > 0 && counters[i] > K[i]) {
          cerr << "Shutdown\n";
          wrong = true;
          goto badidea;
        }
      }
    }

    update_capacities();
  }

badidea:
  if (wrong)
    update_capacities();

  for (auto c : values[N])
    cout << c;
  cout << "\n";

  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      for (auto i : capacities[i])
        cout << i << ' ';
      cout << '\n';
    }

    for (auto i : remaining_times[i])
      cout << i << ' ';
    cout << '\n';

    for (auto c : values[i])
      cout << c;
    cout << "\n\n";
  }

  cout << "\n\nResult == ";
  cout << steps - 1 << '\n';

  return 0;
}
