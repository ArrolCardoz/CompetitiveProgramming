#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int N = n;
  priority_queue<double, vector<double>, greater<double>> prio;
  while (N--) {
    double temp;
    cin >> temp;
    prio.push(temp);
  }
  double top = prio.top();
  double tank = 1;
  while (top < tank) {
    prio.pop();
    top = (top + tank) / 2;
    tank = top;
    prio.push(top);
    top = prio.top();
    // cout << top << ' ' << tank << endl;
  }
  //   cout << endl;
  double sum = 0;
  while (!prio.empty()) {
    // cout << prio.top() << endl;
    sum += prio.top();
    prio.pop();
  }

  if (n == 0) n = 1;
  //   cout << sum << endl;
  //   cout << n << endl;
  cout << fixed << setprecision(10) << sum << endl;
  return 0;
}