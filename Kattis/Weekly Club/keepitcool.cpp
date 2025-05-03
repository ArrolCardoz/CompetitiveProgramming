#include <bits/stdc++.h>
using namespace std;
// failed attempt
int main() {
  int soda, student, slot, capacity;
  cin >> soda >> student >> slot >> capacity;
  int total = 0;

  vector<int> machince(slot, 0);
  for (auto &it : machince) {
    cin >> it;
    total += it;
  }
  if (total < student) {
    cout << "impossible" << endl;
    // cout << total << ' ' << student << endl;
    return 0;
  }
  int limit = 1;
  vector<int> ans(slot, 0);
  while (soda > 0) {
    if (limit == capacity) {
      limit = 0;
      continue;
    }
    for (int i = 0; i < slot; i++) {
      if (machince[i] == limit) {
        machince[i] += INT_MAX;
        ans[i] = capacity - limit;
        soda -= capacity - limit;
        total -= limit;
        // cout << i << ' ' << total << ' ' << soda << endl;
        if (total < student) {
          soda = capacity - limit;
          ans[i] = 0;
          total += limit;
          limit = -1;
          //   cout << total << ' ' << student << endl;
          if (limit == 0) {
            cout << "impossible" << endl;
            return 0;
          }
        }
        if (soda < 0) {
          ans[i] += soda;
          break;
        }
        // cout << soda << endl;
      }
    }
    if (limit == 0 && soda > 0) {
      cout << "impossible" << endl;
      return 0;
    }
    limit++;
  }

  for (auto &it : ans) cout << it << ' ';
  return 0;
}