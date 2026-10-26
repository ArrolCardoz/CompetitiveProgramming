#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n;
  cin >> n;

  vi A(n), L(n, 0), LIS(n, 1), LDS(n, 1);

  for (auto& it : A) cin >> it;
  // LIS
  int k = 0;
  for (int i = 0; i < n; i++) {
    int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
    LIS[i] = pos + 1;
    L[pos] = A[i];
    if (pos == k) {
      k = pos + 1;
    }
  }
  // LDS
  k = 0;
  for (int i = n - 1; i >= 0; i--) {
    int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
    LDS[i] = pos + 1;
    L[pos] = A[i];

    if (pos == k) {
      k = pos + 1;
    }
  }

  int best = 0;
  for (int i = 0; i < n; i++) best = max(best, LDS[i] + LIS[i] - 1);
  cout << best << endl;

  return 0;
}