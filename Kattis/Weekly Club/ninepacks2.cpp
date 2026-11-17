#include <bits/stdc++.h>
using namespace std;

vector<int> A;
const int W_MAX = 205;
const int OFFSET = 100'000;
const int H_MAX = 2 * OFFSET + 1;
const int oo = 1'000'000'000;
int memo[W_MAX][H_MAX];

int f(int k, int rem) {
  if (rem < -OFFSET || rem > OFFSET) return oo;
  if (k == 0) return rem == 0 ? 0 : oo;
  int& ans = memo[k][rem + OFFSET];
  if (ans != -1) return ans;
  int skip = f(k - 1, rem);
  int take = f(k - 1, rem - A[k - 1]);
  if (take < oo) take++;
  return ans = min(skip, take);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(memo, -1, sizeof memo);

  int h, b;
  cin >> h;
  A.resize(h);
  for (auto& x : A) cin >> x;
  cin >> b;
  A.reserve(h + b);
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    A.push_back(-x);
  }

  int ans = oo;
  for (int i = 0; i < (int)A.size(); i++) {
    int r = f(i, -A[i]);
    if (r < oo) ans = min(ans, r + 1);
  }

  if (ans >= oo)
    cout << "impossible" << endl;
  else
    cout << ans << endl;
}