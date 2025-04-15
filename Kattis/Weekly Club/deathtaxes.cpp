#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  string a;
  double average = 0;
  int numStocks = 0;
  double ans = 0;
  string str;

  map<string, int> caseID = {
      {"buy", 0}, {"sell", 1}, {"split", 2}, {"merge", 3}, {"die", 4}};

  while (cin >> str) {
    switch (caseID[str]) {
      case 0:
        cin >> x >> y;
        double newAvg;
        newAvg = ((numStocks * average) + (x * y)) / (numStocks + x);
        // cout << "(" << numStocks * average << '+' << ')' << '(' << x * y <<
        // ')'
        //      << ")" << '/' << average + y << endl;
        average = newAvg;
        numStocks = numStocks + x;
        break;

      case 1:
        cin >> x >> y;
        ans += x * y;
        numStocks -= x;
        break;

      case 2:
        cin >> x;
        numStocks *= x;
        average /= x;
        break;

      case 3:
        cin >> x;
        int quotient;
        int remainder;
        quotient = numStocks / x;
        remainder = numStocks % x;
        ans += remainder * average;
        numStocks = quotient;
        average *= x;
        break;

      case 4:
        cin >> x;
        double profit = x - average;
        // cout << "PROFGISEG" << profit << endl;
        if (x > average)
          cout << fixed << setprecision(2) << numStocks * (x - (0.3 * profit))
               << endl;
        else
          cout << fixed << setprecision(2) << x * numStocks;

        return 0;
        cout << ans;
        break;
    }
    // cout << average << ' ' << numStocks << endl;
  }
  cout << ans << endl;

  return 0;
}