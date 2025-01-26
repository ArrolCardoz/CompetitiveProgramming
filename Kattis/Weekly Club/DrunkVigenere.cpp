#include <bits/stdc++.h>
using namespace std;

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  string ans = "";
  int n1, n2;
  int temp, tempChar;
  for (int i = 0; i < str1.size(); i++) {
    n1 = str1[i] - 'A';
    n2 = str2[i] - 'A';
    if (i % 2 == 0) {
      temp = (n1 + (26 - n2)) % 26;
      tempChar = temp + 'A';
      ans += tempChar;
    } else {
      temp = (n1 + n2) % 26;
      tempChar = temp + 'A';
      ans += tempChar;
    }
  }
  cout << ans << endl;
  return 0;
}