#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

bool solution(bool& ok) {
  int n;
  if (cin >> n && n == 0) return false;
  if (ok) cout << endl;
  ok = true;
  vector<int> A;
  vector<vector<int>> ans;
  vector<int> num(n);
  A.reserve(n);
  ans.reserve(n);

  for (auto& it : num) cin >> it;

  sort(num.begin(), num.end());

  for (auto& it : num) {
    bool makeNewList = true;
    for (int i = 0; i < (int)A.size(); i++) {
      //   cerr << k << ' ' << v << endl;
      if (A[i] < it) {
        A[i] = it;
        ans[i].push_back(it);
        makeNewList = false;
        break;
      }
    }
    if (makeNewList) {
      //   cerr << "PUSH" << it << ' ' << it << endl;
      A.push_back(it);
      ans.push_back({it});
    }
  }

  cout << A.size() << endl;
  for (auto& it : ans) {
    for (auto& a : it) cout << a << ' ';
    cout << endl;
  }
  return true;
}
int main() {
  fastIO();
  bool ok = false;
  while (solution(ok)) {
    ;
  }
  return 0;
}