#include <bits/stdc++.h>
using namespace std;

int numTree[10'000'004][4] = {0};
// 0 is sappling, 1 and 2 is adult and 3 is mature

int const MOD = 1'000'000'007;

void solution() {
  numTree[0][0] = 1;
  for (int i = 1; i < 10'000'000; i++) {
    numTree[i][0] = ((numTree[i - 1][2] + numTree[i - 1][3]) % MOD + 1) % MOD;
    numTree[i][1] = numTree[i - 1][0];
    numTree[i][2] = numTree[i - 1][1];
    numTree[i][3] = (numTree[i - 1][2] + numTree[i - 1][3]) % MOD;
  }
}

int main() {
  solution();
  int n;
  cin >> n;
  while (n--) {
    int input;
    cin >> input;
    cout << (numTree[input][1] + numTree[input][2]) % MOD << endl;
  }
  return 0;
}
