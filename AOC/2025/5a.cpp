#include <bits/stdc++.h>
using namespace std;

int main() {
  long long start, end;
  char c;
  vector<pair<long long, long long>> Data;
  while (true) {
    cin >> start;
    if (start == -1) break;
    cin >> c >> end;
    Data.push_back({start, end});
  }
  int ans = 0;
  long long str;
  while (cin >> str) {
    if (str == -1) break;
    bool spoilt = true;
    for (auto& it : Data) {
      if (it.first <= str && it.second >= str) {
        // cout << it.first << ' ' << str << ' ' << it.second << endl;
        spoilt = false;

        break;
      }
    }
    if (!spoilt) ans++;
    // cout << str << endl;
  }
  cout << ans << endl;
  return 0;
}