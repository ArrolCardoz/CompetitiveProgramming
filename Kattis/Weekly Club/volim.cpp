#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans;
  cin >> ans;
  int n;
  cin >> n;
  int time, totalTime = 0;
  char Case;
  while (n--) {
    cin >> time >> Case;
    totalTime += time;
    if (totalTime > 210) break;
    if (Case == 'P' || Case == 'N') continue;
    ans = (ans + 1) % 8;
    if (ans == 0) ans = 8;
  }
  while (n--) {
    cin >> time >> Case;
  }

  cout << ans;
  return 0;
}