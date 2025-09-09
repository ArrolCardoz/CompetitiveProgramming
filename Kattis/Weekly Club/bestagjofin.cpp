#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int max = 0;
  string str;
  cin >> n;
  int input;
  string ans = "";
  while (n--) {
    cin >> str >> input;
    if (input > max) {
      max = input;
      ans = str;
    }
  }
  cout << ans << endl;
  return 0;
}