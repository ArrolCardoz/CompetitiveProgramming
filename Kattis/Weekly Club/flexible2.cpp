#include <bits/stdc++.h>
using namespace std;
#define LSOne(s) ((s) & -(s))
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int size, hi, lo = 0;
  cin >> hi >> size;
  vector<int> allSize(size + 1);
  for (int i = 0; i < size; i++) {
    int curr;
    cin >> curr;
    allSize[i] = curr - lo;

    lo = curr;
  }
  allSize[size] = hi - lo;
  set<int> ans;
  ans.insert(hi);
  for (int k = 0; k < size + 1; k++) {
    for (int i = 1; i < size + 2; i++) {
      int total = 0;
      if (k < i)
        for (int j = k; j < i; j++) {
          total += allSize[j];
        }
      if (total != 0) ans.insert(total);
    }
  }
  bool ok = false;
  for (auto& it : ans) {
    if (ok) cout << ' ';
    cout << it;
    ok = true;
  }
  cout << endl;
  return 0;
}