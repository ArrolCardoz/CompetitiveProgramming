#include <bits/stdc++.h>
using namespace std;

bool solution(bool first) {
  if (!first) cout << endl;
  int n;
  cin >> n;

  vector<pair<int, int>> v1(n);
  vector<int> v2(n), ans(n);

  if (!n) return false;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    v1[i] = {input, i};
  }
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    v2[i] = input;
  }
  sort(begin(v1), end(v1));
  sort(begin(v2), end(v2));
  for (int i = 0; i < n; i++) {
    ans[v1[i].second] = v2[i];
  }
  for (auto& a : ans) cout << a << endl;
  return true;
}

int main() {
  bool first = 1;
  while (solution(first)) {
    first = 0;
  }
  return 0;
}