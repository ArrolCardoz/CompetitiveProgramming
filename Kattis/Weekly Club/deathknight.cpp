#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string str;
  int ans = n;
  while (n--) {
    cin >> str;
    if (str.find("CD") != string::npos) ans--;
  }
  cout << ans;
  return 0;
}