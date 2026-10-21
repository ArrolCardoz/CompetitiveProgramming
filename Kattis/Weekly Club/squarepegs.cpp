#include <bits/stdc++.h>
using namespace std;

const double EXP = 1e-9;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n, m, k;
  cin >> n >> m >> k;
  priority_queue<double, vector<double>, greater<double>> plot, house;
  double input;
  int ans = 0;
  while (n--) {
    cin >> input;
    plot.push(input);
  }
  while (m--) {
    cin >> input;
    house.push(input);
  }
  while (k--) {
    cin >> input;
    house.push(hypot(input, input) / 2.0);
  }

  while (!plot.empty() && !house.empty()) {
    double plotTop = plot.top(), houseTop = house.top();
    if (plotTop > houseTop) {
      cerr << plotTop << ' ' << houseTop << endl;
      ans++;
      house.pop();
    }
    plot.pop();
  }
  cout << ans << endl;
  return 0;
}