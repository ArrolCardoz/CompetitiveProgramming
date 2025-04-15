#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int a = 0, b = 0;

  cin >> str;

  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'A') {
      i++;
      a += str[i] - '0';
    } else {
      i++;
      //   cout << b << endl;
      b += str[i] - '0';
    }
  }
  //   cout << a << '=' << b << endl;
  if (a > b)
    cout << 'A' << endl;
  else
    cout << 'B' << endl;
  return 0;
}