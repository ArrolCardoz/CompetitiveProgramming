#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  while (cin >> n && n != 0) {
    if (n < 3)
      cout << "No such base" << endl;
    else if (n == 3)
      cout << "4" << endl;
    else if (n < 6)
      cout << "No such base" << endl;
    else {
      cout << n - 3 << endl;
    }
  }
  return 0;
}