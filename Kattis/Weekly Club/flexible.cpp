#include <bits/stdc++.h>
using namespace std;

void solution(set<int>& ans, vector<int> area, int idx) {
  vector<int> partialSum(int(area.size()) - idx, 0);
  partial_sum(area.begin() + idx, area.end(), partialSum.begin());
  for (auto& it : partialSum) {
    // cerr << it << endl;
    ans.insert(it);
  }
  idx++;
  if (idx < (int)area.size()) solution(ans, area, idx);
}

int main() {
  int size, n;
  int prev = 0, curr;
  cin >> size >> n;

  vector<int> area(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> curr;
    area[i] = curr - prev;
    prev = curr;
  }
  area[n] = size - prev;

  set<int> ans;
  solution(ans, area, 0);
  bool first = true;

  for (auto& it : ans) {
    if (!first) cout << ' ';
    cout << it;
    first = false;
  }

  cout << '\n';
  return 0;
}