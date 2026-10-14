#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int countSwap(const string& s1, const string& s2) {
  int maxPtr1 = s1.size();
  int maxPtr2 = s2.size();
  int total = 0;
  int ptr1 = 0, ptr2 = 0;
  while (ptr1 < maxPtr1 && ptr2 < maxPtr2) {
    if (s1[ptr1] == s2[ptr2]) {
      ptr1++;
      ptr2++;
      total++;
    } else {
      if (s1[ptr1] < s2[ptr2]) {
        ptr1++;

      } else
        ptr2++;
    }
  }
  return total;
}

int countChange(const vector<string>& str) {
  int total = 0;
  for (int i = 1; i < (int)str.size(); i++) {
    total += countSwap(str[i - 1], str[i]);
  }
  return total;
}

int main() {
  int n;
  cin >> n;
  vector<string> vs(n);
  for (auto& s : vs) cin >> s;

  vector<vector<int>> cost(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cost[i][j] = countSwap(vs[i], vs[j]);

  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  int ans = 127 * 100 * 100;
  do {
    int cur = 0;
    for (int i = 1; i < n; i++) cur += cost[p[i - 1]][p[i]];
    ans = min(ans, cur);
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << endl;
  return 0;
}