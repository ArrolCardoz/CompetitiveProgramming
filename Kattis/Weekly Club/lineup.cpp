#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  n--;
  string s1, s2;
  bool ace = false, dec = false;
  cin >> s1;
  while (n--) {
    cin >> s2;
    if (s1 > s2)
      dec = true;
    else
      ace = true;
    s1 = s2;
  }
  if (ace && dec)
    cout << "NEITHER" << endl;
  else if (ace)
    cout << "INCREASING" << endl;
  else
    cout << "DECREASING" << endl;
  return 0;
}