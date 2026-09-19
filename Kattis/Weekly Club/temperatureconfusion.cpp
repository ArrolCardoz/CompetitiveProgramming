#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  char temp;
  cin >> a >> temp >> b;
  a = (5 * a) - (160 * b);
  b = 9 * b;
  int g = gcd((a), b);
  a /= g;
  b /= g;
  cout << a << '/' << b << endl;
  return 0;
}