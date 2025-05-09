#include <bits/stdc++.h>
using namespace std;
// failed attempt
int main() {
  int soda, student, slot, capacity;
  cin >> soda >> student >> slot >> capacity;
  int total = 0;
  vector<int> machince(slot, 0);
  vector<int> machinceSort;
  for (auto &it : machince) {
    cin >> it;
    if (it != 0) machinceSort.push_back(it);
    total += it;
  }

  if (total < student) {
    cout << "impossible" << endl;
    // cout << total << ' ' << student << endl;
    return 0;
  }
  sort(machinceSort.begin(), machinceSort.end());
  int pointer = 0;
  int limit = machinceSort[pointer];
  vector<int> ans(slot, 0);
  while (soda > 0) {
    if (limit != 0) limit = machinceSort[pointer];
    // cout << "TEST" << limit << endl;
    if (limit == capacity) {
      limit = 0;
      continue;
    }
    for (int i = 0; i < slot; i++) {
      // cout << machince[i] << ' ' << limit << endl;
      if (machince[i] == limit) {
        machince[i] = -10;
        ans[i] = capacity - limit;
        soda -= capacity - limit;
        total -= limit;
        // cout << i << ' ' << total << ' ' << soda << ' ' << limit << endl;
        if (total < student) {
          machince[i] = limit;
          ans[i] = 0;
          soda += capacity - limit;
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
        }
        // cout << soda << endl;
        break;
      }
    }
    if (limit == 0 && soda > 0) {
      cout << "impossible" << endl;
      return 0;
    }
    pointer++;
  }

  for (auto &it : ans) cout << it << ' ';
  return 0;
}