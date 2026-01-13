#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  while (getline(cin, str)) {
    int ans = 0;
    for (char c : str) {
      int x = c;
      for (int i = 0; i < 7; i++) {
        if (x & 1)
          ans ^= 1;
        else
          ans ^= 2;
        x >>= 1;
      }
    }
    if (ans == 0)
      cout << "free" << endl;
    else
      cout << "trapped" << endl;
  }
  return 0;
}