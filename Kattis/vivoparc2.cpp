#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define A 0x8
#define B 0x4
#define C 0x2
#define D 0x1

int bitIdx(int x) {
  if (x == A)
    return 1;
  else if (x == B)
    return 2;
  else if (x == C)
    return 3;
  else if (x == D)
    return 4;
  else
    return 0;
}

using graph = vector<vector<int>>;

graph g;
vector<int> color;
vector<int> alts;

bool dfs(int x, int curcolor) {
  color[x] = curcolor;

  bool hasNext = false;
  for (int y = 0; y < g.size(); ++y) {
    if (g[x][y] && color[y] == 0) {
      alts[y] &= ~curcolor;
      hasNext = true;
    }
  }

  if (!hasNext)
    return true;

  for (int y = 0; y < g.size(); ++y) {
    if (g[x][y] && color[y] == 0) {
      if (alts[y] == 0)
        break;

      int nextColor = A;
      while (nextColor) {
        if (nextColor & alts[y]) {
          if (dfs(y, nextColor))
            return true;
        }

        nextColor >>= 1;
      }
    }
  }

  for (int y = 0; y < g.size(); ++y)
    if (g[x][y] && color[y] == 0)
      alts[y] |= curcolor;

  color[x] = 0;
  return false;
}

int main() {
  int n;
  cin >> n;

  g = vector<vector<int>>(n, vector<int>(n));
  color = vector<int>(n);
  alts = vector<int>(n, 0xF);

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
      g[i - 1][j - 1] = 1;
      g[j - 1][i - 1] = 1;
    }
  }

  for (int i = 0; i < g.size(); ++i) {
    if (color[i] == 0)
      dfs(i, A);
  }

  for (int i = 0; i < color.size(); ++i)
    cout << i + 1 << ' ' << bitIdx(color[i]) << '\n';

  return 0;
}
