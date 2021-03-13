#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  unordered_map<string, string> original;
  unordered_set<string> repeated;
  unordered_set<string> pool;

  string word;
  while (cin >> word, word != "#") {
    vector<int> counts(26, 0);
    for (auto c : word)
      counts[tolower(c) - 'a']++;

    stringstream ss;
    for (vector<int>::size_type i = 0; i < counts.size(); i++) {
      if (counts[i])
        ss << (char)(i + 'a') << counts[i];
    }

    string signature = ss.str();
    if (!repeated.count(signature)) {
      if (pool.count(signature)) {
        pool.erase(pool.find(signature));
        repeated.insert(signature);
      } else {
        pool.insert(signature);
        original[signature] = word;
      }
    }
  }

  vector<string> results(pool.size());
  transform(pool.begin(), pool.end(), results.begin(),
            [&](string s) { return original[s]; });
  sort(results.begin(), results.end());
  for (auto &w : results)
    cout << w << '\n';
}
