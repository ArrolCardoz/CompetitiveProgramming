#include <bits/stdc++.h>
using namespace std;

void solution() {}

int main() {
  string str;
  cin >> str;
  bool u = true, a = true, p = true, c = true;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'U') u = false;
    if (str[i] == 'A') a = false;
    if (str[i] == 'P') p = false;
    if (str[i] == 'C') c = false;
  }
  if (u) cout << 'U';
  if (a) cout << 'A';
  if (p) cout << 'P';
  if (c) cout << 'C';

  return 0;
}