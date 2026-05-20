#include <bits/stdc++.h>
using namespace std;
int ans = 0;

bool compare(int a, int b) {
  if (a > b) return false;
  cerr << a << ' ' << b << endl;
  ans++;
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n), s(n);
  for (auto& it : v) cin >> it;
  s = v;
  int maxRight = 0, maxLeft = 0;
  sort(begin(s), end(s), compare);
  for (auto& it : s) cout << it << ' ';
  cout << ans << endl;
  return 0;
}