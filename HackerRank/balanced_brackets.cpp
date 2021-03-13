#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<char> a;
  a.reserve(1000);

  string line;
  line.resize(1000);

  while (n--) {
    a.clear();

    cin >> line;

    bool valid = true;
    for (char c : line) {
      if (a.empty()) {
        a.push_back(c);
      } else {
        char top = a[a.size() - 1];

        if ((top == '(' && c == ')') || (top == '[' && c == ']') ||
            (top == '{' && c == '}')) {
          a.pop_back();
        } else if (c == ')' || c == ']' || c == '}') {
          valid = false;
          break;
        } else {
          a.push_back(c);
        }
      }
    }

    if (valid && a.empty()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
