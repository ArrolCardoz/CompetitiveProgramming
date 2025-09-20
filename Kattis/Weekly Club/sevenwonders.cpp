#include <bits/stdc++.h>
using namespace std;

int main() {
  string str, cards = "TCG";
  cin >> str;
  int ans = 0;
  int mini = 51;
  for (auto& it : cards) {
    int ctr = count(str.begin(), str.end(), it);
    ans += ctr * ctr;
    mini = min(mini, ctr);
  }
  ans += 7 * mini;
  cout << ans << endl;
  return 0;
}