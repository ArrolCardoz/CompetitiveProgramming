
#include <bits/stdc++.h>
using namespace std;

int check(int n) {
  if (n < 0) n *= -1;
  if (n >= 0 && n < 15)
    return 7;
  else if (n >= 15 && n < 23)
    return 6;
  else if (n >= 23 && n < 43)
    return 4;
  else if (n >= 43 && n < 102)
    return 2;
  return 0;
}

void solution() {
  int n, m;
  cin >> n >> m;
  long long expected[n];
  long long actual[m];
  int ans = 0;
  long long sum;
  int tempAns;
  int previousAns = 0;

  for (int i = 0; i < n; i++) {
    cin >> expected[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> actual[i];
  }
  int exptCounter = 0;
  int actuCounter = 0;
  bool increment = true;
  int prevNum = 0;

  while (exptCounter < n && actuCounter < m) {
    sum = expected[exptCounter] - actual[actuCounter];
    tempAns = check(sum);
    // cout << "ANS " << ans << " TEMp " << tempAns << " SUM " << sum << endl;
    // cout << " PREV CTR " << prevNum << " expt ctr " << exptCounter << endl;
    // cout << expected[exptCounter] << " - " << actual[actuCounter] << endl;

    if (sum < 0) {
      prevNum = exptCounter;
      exptCounter++;
      increment = false;
      //   cout << " ====================" << endl;

    } else if (tempAns == 0) {
      actuCounter++;
      increment = false;
    }

    if (tempAns > previousAns && prevNum == exptCounter) {
      //   cout << ans << endl;
      ans -= previousAns;
      ans += tempAns;
      //   cout << "================" << endl;
      //   cout << ans << endl;

      if (increment) actuCounter++;
    } else if (previousAns == tempAns && prevNum == exptCounter) {
      if (increment) {
        prevNum = exptCounter;
        exptCounter++;
      }
    } else {
      //   cout << " ====================" << endl;

      if (increment) actuCounter++;
      if (prevNum != exptCounter && increment) ans += tempAns;
    }
    previousAns = tempAns;
    tempAns = 0;
    increment = true;
  }
  cout << ans;
}

int main() {
  solution();
  return 0;
}
