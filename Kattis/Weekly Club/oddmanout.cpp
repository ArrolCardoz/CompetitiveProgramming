#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases, n, input, ans, caseNum = 1;
  cin >> cases;
  while (cases--) {
    cin >> n;
    ans = 0;
    while (n--) {
      cin >> input;
      ans ^= input;
    }
    cout << "Case #" << caseNum << ": " << ans << endl;
    caseNum++;
  }
  return 0;
}