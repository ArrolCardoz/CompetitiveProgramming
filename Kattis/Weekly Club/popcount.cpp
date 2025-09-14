#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int ans = 0;
  cin >> str;
  for (auto& it : str) {
    if (it == '1') ans++;
  }
  cout << ans << endl;
  return 0;
}