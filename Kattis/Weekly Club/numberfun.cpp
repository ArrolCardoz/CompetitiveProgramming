#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    float a, b, c;
    cin >> a >> b >> c;
    if (a + b == c)
      cout << "Possible" << endl;
    else if (a * b == c)
      cout << "Possible" << endl;
    else if (a - b == c)
      cout << "Possible" << endl;
    else if (b - a == c)
      cout << "Possible" << endl;
    else if (a / b == c)
      cout << "Possible" << endl;
    else if (b / a == c)
      cout << "Possible" << endl;
    else
      cout << "Impossible" << endl;
  }
  return 0;
}