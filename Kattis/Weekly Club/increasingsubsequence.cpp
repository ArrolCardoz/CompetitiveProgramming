#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void printLIS(vi& p, int idx, vi& A, int& i) {
  if (p[idx] == -1) {
    cout << A[idx] << ' ';

  } else {
    printLIS(p, p[idx], A, i);
    cout << A[idx];
    if (i != idx) cout << ' ';
  }
}

bool solution() {
  int n;
  cin >> n;
  if (!n) return false;
  vi A(n), p(n, -1), L(n, 0), L_id(n, 0);
  int k = 0, lis_end = 0;
  for (auto& it : A) cin >> it;

  for (int i = 0; i < n; i++) {
    int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
    L[pos] = A[i];
    L_id[pos] = i;
    p[i] = pos ? L_id[pos - 1] : -1;
    if (pos == k - 1) lis_end = i;
    if (pos == k) {
      k = pos + 1;
      lis_end = i;
    }
  }
  cout << k << ' ';
  printLIS(p, lis_end, A, lis_end);
  cout << endl;
  return true;
}
int main() {
  fastIO();
  while (solution());
  return 0;
}