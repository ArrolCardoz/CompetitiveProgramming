#include <bits/stdc++.h>
using namespace std;

int main() {
  int monthly, n, input, total = 0;
  cin >> monthly;
  cin >> n;
  while (n--) {
    total += monthly;
    cin >> input;
    total -= input;
  }
  cout << total + monthly << endl;
  return 0;
}