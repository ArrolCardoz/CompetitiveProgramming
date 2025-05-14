#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int counter = 1;
  while (cin >> n) {
    int MAX = INT_MIN;
    int MIN = INT_MAX;
    for (int i = 0; i < n; i++) {
      int input;
      cin >> input;
      if (input > MAX) MAX = input;
      if (input < MIN) MIN = input;
    }
    cout << "Case " << counter << ": " << MIN << ' ' << MAX << ' ' << MAX - MIN
         << endl;
    counter++;
  }
  return 0;
}