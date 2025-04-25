#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int count = 0;
  int currentDirt = 0;
  int ans = 0;
  int input;
  int dirty[366] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    dirty[input] = 1;
  }

  for (int i = 1; i <= 365; i++) {
    currentDirt += count;

    if (currentDirt >= 20) {
      currentDirt = 0;
      count = 0;
      ans++;
    }
    if (dirty[i]) count++;

    // cout << currentDirt << ' ' << i << endl;
  }
  if (currentDirt != 0) ans++;
  cout << ans << endl;
}