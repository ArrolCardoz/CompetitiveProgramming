#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int max = 0;
    int dupe = 0;
    int total = 0;
    int idx;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int vote;
      cin >> vote;
      total += vote;
      if (max < vote) {
        max = vote;
        dupe = 0;
        idx = i + 1;
      } else if (max == vote)
        dupe = 1;
    }
    if (dupe)
      cout << "no winner" << endl;
    else {
      if (total < max * 2)
        cout << "majority ";
      else
        cout << "minority ";
      cout << "winner " << idx << endl;
    }
  }
  return 0;
}