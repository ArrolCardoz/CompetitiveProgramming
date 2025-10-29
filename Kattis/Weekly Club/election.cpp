// failed attempt idk what to do confusing question
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    double num, v1, v2, w;
    cin >> num >> v1 >> v2 >> w;
    // v1 *= 2;
    // v2 *= 2;
    // num *= 2;
    double m = v1 + v2;
    double remaining = num - m;
    v1 += ceil(remaining / 2);
    remaining = remaining - (floor(remaining / 2));

    double percentage = (v1 * 100) / num;

    // check if we win
    cerr << percentage << ' ' << v1 << ' ' << num << endl;
    if (percentage > w) {
      cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
    } else  // check if we have a chance to win
    {
      v1 += remaining;
      percentage = (v1 * 100) / num;
      if (percentage > 50) {
        cerr << (v1 * 100) / num << ' ' << v1 << ' ' << num << endl;

        cout << "PATIENCE, EVERYONE!" << endl;
      } else {
        cerr << (v1 * 100) / num << ' ' << v1 << ' ' << num << endl;

        cout << "RECOUNT!" << endl;
      }
    }
  }
  return 0;
}