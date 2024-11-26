#include <bits/stdc++.h>
using namespace std;

int main() {
  int grid[3][3];
  int n = 3;
  long double diagonal = 1.41421356237;
  long double ans = 0;
  int counter = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      grid[i][j] = a;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        if (grid[i + 1][j] > grid[i][j] || grid[i][j + 1] > grid[i][j]) {
          counter++;
        }
      } else if (i == 3 && j == 3) {
        if (grid[i - 1][j] > grid[i][j] || grid[i][j - 1] > grid[i][j]) {
          counter++;
        }
      }

      else if (i == 0) {
        if (grid[i + 1][j] > grid[i][j] || grid[i][j + 1] > grid[i][j] ||
            grid[i][j - 1] > grid[i][j]) {
          counter++;
        }
      } else if (j == 0) {
        if (grid[i + 1][j] > grid[i][j] || grid[i][j + 1] > grid[i][j] ||
            grid[i - 1][j] > grid[i][j]) {
          counter++;
        }
      } else if (grid[i + 1][j] > grid[i][j] || grid[i][j + 1] > grid[i][j] ||
                 grid[i - 1][j] > grid[i][j] || grid[i][j - 1] > grid[i][j]) {
        counter++;
      }
    }
  }
  //   cout << counter << endl;
  ans += counter;
  ans += (9 - counter) * diagonal;
  cout << fixed << setprecision(8) << ans;
  return 0;
}