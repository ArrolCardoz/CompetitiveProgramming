#include <bits/stdc++.h>
using namespace std;

int main() {
  int soda, student, slot, capacity;
  cin >> soda >> student >> slot >> capacity;

  vector<pair<int, int>> machines(slot);  // {cold soda, index}
  int total_cold = 0;

  for (int i = 0; i < slot; ++i) {
    cin >> machines[i].first;
    machines[i].second = i;
    total_cold += machines[i].first;
  }

  if (total_cold < student) {
    cout << "impossible" << endl;
    return 0;
  }

  // Sort machines by current cold soda level (ascending)
  sort(machines.begin(), machines.end());

  vector<int> ans(slot, 0);  // how much soda to pour in each slot

  for (int i = 0; i < slot && soda > 0; ++i) {
    int cold = machines[i].first;
    int idx = machines[i].second;
    int pour = min(soda, capacity - cold);
    ans[idx] = pour;
    soda -= pour;
  }

  // After pouring, check if remaining cold soda is enough for students
  int remaining_cold = 0;
  for (int i = 0; i < slot; ++i) {
    int final_cold = machines[i].first + ans[machines[i].second];
    if (final_cold == machines[i].first) {  // not filled
      remaining_cold += machines[i].first;
    }
  }

  if (remaining_cold < student) {
    cout << "impossible" << endl;
  } else {
    for (int x : ans) cout << x << ' ';
    cout << endl;
  }

  return 0;
}
