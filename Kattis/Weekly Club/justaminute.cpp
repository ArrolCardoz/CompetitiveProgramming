#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  float totalMin = 0;
  float totalSec = 0;
  while (n--) {
    float m, s;
    cin >> m >> s;
    totalMin += m;
    totalSec += s;
  }
  float ans = totalSec / (totalMin * 60);
  if (ans > 1)
    cout << fixed << setprecision(10) << ans << endl;
  else
    cout << "measurement error" << endl;
  return 0;
}