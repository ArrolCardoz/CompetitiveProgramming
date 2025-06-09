#include <bits/stdc++.h>
using namespace std;
// call in
int main() {
  int currentPos = 0;
  string input;
  int change1, change2;
  cin >> input;
  for (auto& it : input) {
    if (it == 'A') {
      change1 = 0;
      change2 = 1;
    } else if (it == 'B') {
      change1 = 1;
      change2 = 2;
    } else if (it == 'C') {
      change1 = 0;
      change2 = 2;
    }
    if (change1 == currentPos)
      currentPos = change2;
    else if (change2 == currentPos)
      currentPos = change1;
  }
  cout << currentPos + 1 << endl;
  return 0;
}