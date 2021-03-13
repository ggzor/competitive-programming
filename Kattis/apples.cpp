#include <iostream>
#include <string>
#include <vector>

#define uint unsigned long long

using namespace std;

int main() {
  int R, C;
  cin >> R;
  cin >> C;

  cin.get();

  vector<string> a(R, string(C, '.'));

  for (int i = 0; i < R; ++i)
    getline(cin, a[i]);

  for (int x = 0; x < C; ++x) {
    int y = R;
    while (--y >= 0) {
      int floor = y;
      int apples = 0;

      while (y >= 0 && a[y][x] != '#') {
        if (a[y][x] == 'a')
          apples++;
        y--;
      }

      for (int i = floor; i > y; i--) {
        if (apples) {
          a[i][x] = 'a';
          apples--;
        } else {
          a[i][x] = '.';
        }
      }
    }
  }

  for (auto s : a)
    cout << s << '\n';
}
