#include <bits/stdc++.h>
using namespace std;

int main() {
  int grid[3][3];
  int n = 3;
  map<int, pair<int, int>> cords;
  long double ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      cords[a] = make_pair(i, j);
    }
  }
  for (int i = 1; i < 9; i++) {
    int x = (cords[i + 1].first - cords[i].first);
    int y = (cords[i + 1].second - cords[i].second);
    // cout << cords[i].first << " " << cords[i].second << endl;
    // cout << '(' << cords[i].first << ',' << cords[i].second << ')' << ' ' <<
    // '('
    //      << cords[i + 1].first << ',' << cords[i + 1].second << ')' << endl;
    ans += sqrt((x * x) + (y * y));
  }

  //   cout << counter << endl;
  cout << fixed << setprecision(8) << ans;
  return 0;
}