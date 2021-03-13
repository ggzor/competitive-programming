#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string line;
  getline(cin, line);

  deque<char> result;
  auto it = result.end();

  for (auto c : line) {
    switch (c) {
    case 'L':
      it--;
      break;
    case 'R':
      it++;
      break;
    case 'B':
      it = result.erase(it - 1, it);
      break;
    default:
      it = result.insert(it, c) + 1;
      break;
    }
  }

  for (auto c : result)
    cout << c;
  cout << '\n';

  return 0;
}
