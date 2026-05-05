#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  char c;
  while (cin >> c >> a) {
    cout << '{' << '\'' << c << '\'' << "," << a << '}' << ',' << ' ';
  }
  return 0;
}