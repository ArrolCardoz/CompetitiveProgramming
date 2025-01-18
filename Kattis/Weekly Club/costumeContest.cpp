#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  map<string, int> count;
  string str;
  cin >> n;
  while (n--) {
    cin >> str;
    count[str]++;
  }
  int min = INT_MAX;

  for (auto &[a, b] : count) {
    if (b < min) min = b;
  }

  for (auto &[a, b] : count) {
    if (b == min) cout << a << endl;
  }
  return 0;
}