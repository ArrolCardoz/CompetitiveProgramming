#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t start, end;
  char c;
  vector<pair<int64_t, int64_t>> Data;
  vector<pair<int64_t, int64_t>> Filtered;

  while (true) {
    cin >> start;
    if (start == -1) break;
    cin >> c >> end;

    Data.emplace_back(start, end);
  }
  sort(Data.begin(), Data.end());

  for (auto& [s, e] : Data) {
    bool found = false;
    for (auto& [lower, upper] : Filtered) {
      if (!(e < lower || upper < s)) {
        // cout << s << "<=" << lower << ' ' << upper << ">=" << e << endl;
        lower = min(s, lower);
        upper = max(e, upper);
        found = true;
        break;
      }
    }
    if (!found) Filtered.emplace_back(s, e);
  }
  int64_t ans = 0;
  for (auto& [lower, upper] : Filtered) {
    // cout << lower << ' ' << upper << endl;
    ans += (upper - (lower - 1));
  }
  cout << ans << endl;
  return 0;
}