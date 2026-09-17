#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int i1, i2;
  vector<int> ans;
  ans.reserve(2);
  cin >> n;
  vector<int> freqTable(n);
  n = (n / 2) + 1;
  while (n--) {
    cin >> i1 >> i2;
    freqTable[i1 - 1]++;
    freqTable[i2 - 1]++;

    if (freqTable[i1 - 1] > 1) ans.push_back(i1);
    if (freqTable[i2 - 1] > 1) ans.push_back(i2);
  }
  if (ans[0] < ans[1])
    cout << ans[0] << ' ' << ans[1];
  else
    cout << ans[1] << ' ' << ans[0];
  return 0;
}
