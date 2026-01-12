#include <bits/stdc++.h>
using namespace std;

long long countBits(long long num) {
  int ctr = 0;
  while (num > 0) {
    if (num & 1) ctr++;
    num = num >> 1;
  }
  //   cerr << ctr << endl;
  return ctr;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    string num;
    cin >> num;
    long long ans = 0;
    long long current = 0;
    for (auto& it : num) {
      current += (it - '0');
      //   cerr << " ----------------" << current << endl;
      ans = max(ans, countBits(current));
      current *= 10;
    }
    cout << ans << endl;
  }
  return 0;
}