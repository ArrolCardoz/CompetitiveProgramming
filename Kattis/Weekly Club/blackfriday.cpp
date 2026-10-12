#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& it : v) {
    cin >> it;
  }
  int num = 0;
  int idx = 0;
  int ctr = 1;
  for (auto& it : v) {
    int temp = count(v.begin(), v.end(), it);
    if (temp == 1 && it > num) {
      num = it;
      idx = ctr;
    }
    ctr++;
  }
  if (num)
    cout << idx << endl;
  else
    cout << "none" << endl;
  return 0;
}