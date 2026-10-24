#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  string str;
  cin >> str;
  int n = (int)str.size();
  vi L(n, 0);
  int k = 0;

  for (int i = 0; i < n; i++) {
    int pos = lower_bound(L.begin(), L.begin() + k, str[i]) - L.begin();
    L[pos] = str[i];
    if (pos == k) {
      k = pos + 1;
    }
  }
  cout << 26 - k << endl;
  return 0;
}