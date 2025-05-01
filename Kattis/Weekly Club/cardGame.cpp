// https://codeforces.com/contest/2104/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    int n;
    cin >> n;
    vector<int> aliceCards(n, 0);
    aliceCards.resize(n, 0);
    int total = 0;
    for (auto &it : aliceCards) {
      char C;
      cin >> C;
      if (C == 'A') {
        it++;
        total++;
      }
    }
    if (aliceCards[0] && aliceCards[n - 1]) {
      cout << "Alice" << endl;
    } else if (aliceCards[n - 2] && aliceCards[n - 1]) {
      cout << "Alice" << endl;
    } else if (total == n - 1) {
      if (n == 2) {
        if (aliceCards[0])
          cout << "Alice" << endl;
        else
          cout << "Bob" << endl;
      } else
        cout << "Alice" << endl;
    } else
      cout << "Bob" << endl;
  }
  return 0;
}