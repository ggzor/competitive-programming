#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using graph = vector<vector<int>>;
#define m 4

int n;
graph adj;
vector<int> color;

bool step(int x) {
  for (color[x] += 1; color[x] <= m; color[x]++) {
    bool repetido = false;
    for (int y = 0; y < adj.size(); ++y) {
      if (adj[x][y] != 0 && color[x] == color[y]) {
        repetido = true;
        break;
      }
    }

    if (!repetido)
      return false;
  }

  color[x] = 0;
  return true;
}

bool dfs(int x) {
  if (x == n)
    return true;

  while (true) {
    if (step(x))
      return false;
    else if (dfs(x + 1))
      return true;
  }
}

int main() {
  cin >> n;

  adj = vector<vector<int>>(n, vector<int>(n));
  color = vector<int>(n);

  int i, j;
  while (true) {
    cin >> i;
    if (cin.eof())
      break;
    cin.get();
    if (cin.eof())
      break;
    cin >> j;

    if (i != j && i <= n && j <= n) {
      adj[i - 1][j - 1] = 1;
      adj[j - 1][i - 1] = 1;
    }
  }

  dfs(0);
  for (int i = 0; i < color.size(); ++i)
    cout << i + 1 << ' ' << color[i] << '\n';

  return 0;
}
