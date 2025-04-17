#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[4] = {0};
  cin >> a[1] >> a[2] >> a[3];
  a[2] *= 2;
  a[3] *= 3;

  int arrive, depart;
  int ans = 0;
  int time[100] = {0};
  for (int i = 0; i < 3; i++) {
    cin >> arrive >> depart;
    for (int i = arrive - 1; i < depart - 1; i++) time[i]++;
  }

  for (int i = 0; i < 100; i++) ans += a[time[i]];

  cout << ans << endl;
  return 0;
}
