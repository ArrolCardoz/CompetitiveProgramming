#include <bits/stdc++.h>
using namespace std;

int main() {
  // generate all till 1000
  int ans[1000];
  ans[0] = 1;
  ans[1] = 2;
  for (long long i = 2; i <= 1000; i++) {
    if (((i * (i + 1)) / 2) * ((i * (i + 1)) / 2) ==
        (((i * i) * (i + 1) * (i + 1)) / 4))
      ans[i - 1] = ans[i - 2] + 1;
  }
  int n;
  cin >> n;
  cout << n << endl;
  // same equaltion
  // so just print n

  return 0;
}