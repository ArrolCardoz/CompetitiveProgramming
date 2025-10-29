#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> v(n);
  for (int i = 0; i < n; i++) {
    double num;
    string str;
    cin >> str >> num;
    v[i] = num;
  }
  sort(v.rbegin(), v.rend());
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i * v[i - 1];
  }
  cout << fixed << setprecision(4) << ans << endl;
}