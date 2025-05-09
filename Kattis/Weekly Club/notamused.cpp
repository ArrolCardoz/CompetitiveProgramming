#include <bits/stdc++.h>
using namespace std;
int main() {
  string loop, action, name;
  double time;
  int day = 1;
  while (cin >> loop) {
    cout << "Day " << day << endl;
    map<string, pair<double, double>> timeSpend{};
    while (cin >> action) {
      if (action == "CLOSE") break;
      if (action == "ENTER") {
        cin >> name >> time;
        timeSpend[name].first = time;
        // cout << timeSpend[name].first << "            test" << endl;
      } else {
        cin >> name >> time;

        timeSpend[name].second += time - timeSpend[name].first;
        // cout << timeSpend[name].first << "            test22222222222222"
        //      << endl;
      }
    }
    for (auto& [n, vec] : timeSpend) {
      cout << n << " $" << fixed << setprecision(2) << vec.second * 0.10
           << endl;
    }
    cout << endl;
    day++;
  }
  return 0;
}