#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  //   for (int n = 3; n <= 10; n++) {
  //     cout << n << ": ";

  //   for (int n = 1; n <= 10; n++) {
  bool even = true;
  bool odd = true;
  //   cout << n << ": ";
  for (int i = 0; i < n; i++) {
    if (i % 2 != 0) {
      if (even)
        even = false;
      else
        even = true;
    }
  }
  for (int i = 1; i < n + 1; i++) {
    if (i % 2 != 0) {
      if (odd)
        odd = false;
      else
        odd = true;
    }
    //   cout << i << "->" << odd << endl;
  }

  if (even && !odd || !even && odd) {
    cout << "Either" << endl;
    //   continue;
    return 0;
  }
  if (!odd || !even) {
    cout << "Odd" << endl;
    //   continue;

    return 0;
  }
  if (even || odd) {
    cout << "Even" << endl;
    return 0;
  }
  //   }
  return 0;
}
//   }
