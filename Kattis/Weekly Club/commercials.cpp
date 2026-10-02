#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  int ans = 0, finalAns = -1;
  int input;
  while (n--) {
    cin >> input;
    ans += input - c;
    if (ans < 0) ans = 0;
    finalAns = max(ans, finalAns);
  }
  cout << finalAns << endl;
  return 0;
}