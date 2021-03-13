#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string line;
  while (getline(cin, line) && line != "DONE") {
    auto i = line.begin();
    auto j = line.end() - 1;

    bool valid = true;
    while (i < j) {
      while ((*i == '.' || *i == ',' || *i == '!' || *i == '?' || *i == ' ') &&
             i < j)
        i++;
      while ((*j == '.' || *j == ',' || *j == '!' || *j == '?' || *j == ' ') &&
             i < j)
        j--;

      if (i < j && tolower(*i) != tolower(*j)) {
        valid = false;
        break;
      }

      i++;
      j--;
    }

    if (valid)
      cout << "You won't be eaten!\n";
    else
      cout << "Uh oh..\n";
  }
}
