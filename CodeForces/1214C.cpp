#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n % 2 != 0) {
    cout << "No\n";
  } else {
    stack<char> parens;
    bool valid = true;
    while (n--) {
      char c;
      cin >> c;

      if (parens.empty()) {
        parens.push(c);
      } else {
        char top = parens.top();

        if (top == '(') {
          if (c == ')') {
            parens.pop();
          } else if (c == '(') {
            parens.push(c);
          }
        } else if (top == ')') {
          if (c == ')') {
            valid = false;
            break;
          } else if (c == '(') {
            parens.push(c);
          }
        }
      }
    }

    if (!valid) {
      cout << "No\n";
    } else {
      if (parens.empty()) {
        cout << "Yes\n";
      } else if (parens.size() != 2) {
        cout << "No\n";
      } else {
        char first = parens.top();
        parens.pop();
        char second = parens.top();

        if (second == ')' && first == '(') {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
      }
    }
  }
}
