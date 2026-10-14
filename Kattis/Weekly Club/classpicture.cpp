#include <bits/stdc++.h>
using namespace std;

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool solution() {
  int n;
  if (!(cin >> n)) return false;
  vector<string> names(n);
  vector<int> p(n);
  vector<vector<bool>> bad(n, vector<bool>(n, true));
  unordered_map<string, int> nameIdx;
  int m;

  iota(p.begin(), p.end(), 0);

  for (auto& it : names) cin >> it;

  sort(names.begin(), names.end());

  for (int i = 0; i < n; i++) nameIdx[names[i]] = i;

  cin >> m;

  for (int i = 0; i < m; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    bad[nameIdx[s1]][nameIdx[s2]] = false;
    bad[nameIdx[s2]][nameIdx[s1]] = false;
  }

  do {
    bool ok = true;
    for (int i = 1; i < n; i++) {
      if (!bad[p[i - 1]][p[i]]) {
        sort(p.begin() + i + 1, p.end(), greater<int>());
        ok = false;
        break;
      }
    }
    if (ok) {
      for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << names[p[i]];
      }
      cout << endl;
      return true;
    }

  } while (next_permutation(p.begin(), p.end()));
  cout << "You all need therapy." << endl;
  return true;
}
int main() {
  fastIO();
  while (solution());
  return 0;
}