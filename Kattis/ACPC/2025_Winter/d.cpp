#include <bits/stdc++.h>
using namespace std;

void solution() {}

int main() {
  int n;
  int a;
  int b;
  cin >> n;
  cin >> a;
  cout << a << ' ';
  n--;
  while (n--) {
    cin >> b;
    if (b >= a) {
      cout << b << ' ';
      a = b;
    }
  }
  return 0;
}