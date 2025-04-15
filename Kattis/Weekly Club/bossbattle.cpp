#include <bits/stdc++.h>
using namespace std;
void simulate(int& boom, int& boss, int& n, int& ans) {
  if (boom % n == boss % n || boom % n == (boss + 1) % n ||
      boom % n == (boss + (n - 1)) % n)
    return;
  ans++;
  boom += 2;
  boss++;
  simulate(boom, boss, n, ans);
}

int main() {
  int n;
  cin >> n;
  int ans = 1;
  int boom = 1;
  int boss = n - 1;
  simulate(boom, boss, n, ans);
  cout << ans << endl;
  return 0;
}