/*
In this question the n goes up to 10^5 whereas the possible answers are only
255. So we just compute all the possible answers and print it from the computed
answers.

Computation = (i ^ ((i << 1) Since we are shifting left we if the first bit is a
1 when its greater than 255. To solve that we can either always turn the 9th bit
off or have a mask which is what I did (EIGHT_BIT_MASK).
*/
#include <bits/stdc++.h>
using namespace std;

const int EIGHT_BIT_MASK = 0b11111111;

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void computeAll(vector<int>& ans) {
  for (int i = 0; i < 256; i++) {
    ans[(i ^ ((i << 1) & EIGHT_BIT_MASK))] = i;
  }
}
int main() {
  fastIO();
  vector<int> ans(256, 0);
  computeAll(ans);

  int n;
  int i;
  bool ok = false;
  cin >> n;

  while (n--) {
    if (ok) cout << ' ';
    ok = true;
    cin >> i;
    cout << ans[i];
  }
  return 0;
}