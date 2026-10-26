#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

bool cmp(const pii& a, const pii& b) {
  if (a.first != b.first) return a < b;
  return a.second > b.second;
}

void solution() {
  int n;
  cin >> n;
  vector<pii> A(n);
  for (auto& [m, n] : A) cin >> m >> n;

  sort(A.begin(), A.end(), cmp);

  vector<int> L(n, 0);
  int k = 0;

  for (int i = 0; i < n; i++) {
    auto& [a, b] = A[i];
    int pos = upper_bound(L.begin(), L.begin() + k, -b) - L.begin();
    L[pos] = -b;
    if (pos == k) {
      k = pos + 1;
    }
  }
  cout << k << endl;
}
int main() {
  fastIO();

  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}