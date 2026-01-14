#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    double b, s;
    cin >> b >> s;
    for (int i = -1; i < 2; i++) {
      double temp = s;
      double temp2 = b + i;
      temp = 60 / temp;
      cout << fixed << setprecision(10) << temp * temp2 << ' ';
    }
    cout << endl;
  }
  return 0;
}