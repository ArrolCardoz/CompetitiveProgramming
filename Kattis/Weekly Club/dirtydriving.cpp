#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p;
  cin >> n >> p;
  vector<int> dist(n);
  for (auto& it : dist) {
    cin >> it;
  }
  sort(begin(dist), end(dist));
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    int temp = (p * (i + 1));

    ans = min(ans, temp);
  }
  cout << ans << endl;
  return 0;
}
