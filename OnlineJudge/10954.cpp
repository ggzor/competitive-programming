#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;

  while (cin >> n, n != 0) {
    priority_queue<int, vector<int>, greater<int>> nums;

    int a;
    while (n--) {
      cin >> a;
      nums.push(a);
    }

    int total = 0;
    while (nums.size() > 1) {
      int x = nums.top();
      nums.pop();
      int y = nums.top();
      nums.pop();

      int sum = x + y;
      nums.push(sum);
      total += sum;
    }

    std::cout << total << '\n';
  }
}
