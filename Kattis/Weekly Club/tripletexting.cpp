#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  map<string, int> count;
  cin >> str;
  int n = str.size() / 3;
  for (int i = 0; i < 3; i++) {
    count[str.substr(i * n, n)]++;
  }
  int max = 0;
  string ans;
  for (auto& [a, m] : count) {
    if (m > max) {
      ans = a;
      max = m;
    }
  }
  cout << ans << endl;
  return 0;
}