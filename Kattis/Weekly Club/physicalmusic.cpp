#include <bits/stdc++.h>
using namespace std;
void solution() {
  int n;
  cin >> n;
  vector<int> music(n);
  for (auto& it : music) cin >> it;

  int minDown = music[n - 1];
  set<int> ans;
  for (int i = n - 2; i >= 0; i--) {
    if (music[i] < minDown) {
      minDown = music[i];
    } else
      ans.insert(music[i]);
  }
  cout << ans.size() << endl;
  for (auto& it : ans) cout << it << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}