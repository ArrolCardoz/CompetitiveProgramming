#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int sum, diff;
    cin >> sum >> diff;

    int first = (sum + diff) / 2;
    int second = sum - first;
    if (first < 0 || second < 0 || (sum + diff) % 2 != 0)
      cout << "impossible" << endl;
    else {
      cout << first << ' ';
      cout << sum - first << endl;
    }
  }
  return 0;
}