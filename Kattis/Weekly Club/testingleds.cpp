#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  bool gotAns = false;
  int minTime = INT_MAX;
  cin >> n;
  while (n--) {
    int time, state;
    cin >> time >> state;
    if (!state) {
      gotAns = true;
      if (time < minTime) minTime = time;
    }
  }
  if (gotAns)
    cout << minTime << endl;
  else
    cout << -1 << endl;
  return 0;
}