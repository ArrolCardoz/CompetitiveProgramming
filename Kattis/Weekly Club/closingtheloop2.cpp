#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "Case #" << i << ": ";
    int num;
    cin >> num;
    vector<int> red(0);
    vector<int> blue(0);
    for (int i = 0; i < num; i++) {
      char c;
      int lengeth;
      cin >> lengeth >> c;
      if (c == 'B')
        blue.push_back(lengeth);
      else
        red.push_back(lengeth);
    }
    sort(blue.begin(), blue.end());
    sort(red.begin(), red.end());
    int blueSize = blue.size() - 1;
    int redSize = red.size() - 1;
    int ans = 0;

    while (blueSize >= 0 && redSize >= 0) {
      ans += red[redSize];
      ans += blue[blueSize];
      ans -= 2;
      redSize--;
      blueSize--;
    }
    // cout << blueSize << ' ' << redSize << endl;

    cout << ans << endl;
  }
  return 0;
}