#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  unordered_map<string, pair<int, int>> socks;
  bool pairs = false;
  cin >> n;
  while (n--) {
    string str;
    string foot;
    int num;
    cin >> str >> foot >> num;
    if (foot == "any") {
      if (socks[str].first == 0)
        socks[str].first = 0;
      else
        pairs = true;
      if (socks[str].second == 0)
        socks[str].second = 0;
      else
        pairs = true;

      socks[str] = make_pair(socks[str].first, socks[str].second);
      if (num >= 2) pairs = true;
      continue;
    }
    if (socks.find(str) == socks.end()) {
      if (foot == "left") {
        socks[str] = make_pair(num, 0);
      } else
        socks[str] = make_pair(0, num);
    } else {
      pairs = true;
      if (foot == "left") {
        socks[str] = make_pair(num, socks[str].second);
      } else
        socks[str] = make_pair(socks[str].first, num);
    }
  }
  int ans = 0;
  if (pairs) {
    for (auto &[f, s] : socks) {
      ans += max(s.first, s.second);
      if (s.first == 0 && s.second == 0) ans++;
      //   cout << ans << endl;
    }
    cout << ans + 1 << endl;
  } else
    cout << "impossible" << endl;
  return 0;
}