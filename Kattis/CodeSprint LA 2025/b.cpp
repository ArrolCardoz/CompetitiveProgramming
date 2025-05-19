#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> runes(n);

  for (auto& a : runes) cin >> a;
  sort(runes.begin(), runes.end());

  int groupSize = n / k;
  int left = groupSize * (k / 2);
  int right = n - groupSize * (k / 2);

  set<int> possibleCoreRunes;
  for (int i = left; i < right; i++) {
    possibleCoreRunes.insert(runes[i]);
  }
  int ans = 0;
  vector<int> inAns;
  for (auto& it : possibleCoreRunes) {
    if (find(inAns.begin(), inAns.end(), it) == inAns.end()) {
      inAns.push_back(it);
      ans += count(runes.begin(), runes.end(), it);
    }
  }
  cout << ans << endl;
  return 0;
}
