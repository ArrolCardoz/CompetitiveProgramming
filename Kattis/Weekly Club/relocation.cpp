#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  unordered_map<int, int> location;
  for (int i = 1; i <= n; i++) {
    int input;
    cin >> input;
    location[i] = input;
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int company, newLoc;
      cin >> company >> newLoc;
      location[company] = newLoc;
    } else {
      int company1, company2;
      cin >> company1 >> company2;
      cout << abs(location[company1] - location[company2]) << endl;
    }
  }
  return 0;
}