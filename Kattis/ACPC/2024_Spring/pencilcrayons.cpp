#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  map<string, int> v;
  string str;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> str;
      v[str]++;
      if (v[str] > 1) ans++;
    }
    // for (auto& it : v) cout << it.first << " " << it.second << endl;
    // cout << endl << endl << endl << endl;
    v.clear();
  }

  cout << ans;
}

int main() {
  solution();
  return 0;
}
