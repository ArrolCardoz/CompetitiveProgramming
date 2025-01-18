#include <bits/stdc++.h>
using namespace std;

bool checkLine(int n, char grid[24][24], int r, int c, int dr, int dc) {
  int numW = 0, numB = 0;
  int i = 0;
  while (i < n) {
    // cout << r << ' ' << c << endl;

    if (grid[r][c] == 'W')
      numW++;
    else
      numB++;
    r += dr;
    c += dc;
    i += (dr + dc);
  }
  // cout << numW << ' ' << numB << endl;

  if (numW == numB) return true;
  return false;
}
bool checkCount(int n, char grid[24][24], int r, int c, int dr, int dc) {
  int numW = 0, numB = 0;
  int i = 0;
  while (i < n) {
    if (grid[r][c] == 'W') {
      numB = 0;
      numW++;
    } else {
      numW = 0;
      numB++;
    }
    if (numW == 3 || numB == 3) return false;
    r += dr;
    c += dc;
    i += (dr + dc);
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  char grid[24][24];
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c;
      grid[i][j] = c;
    }
  }
  for (int i = 0; i < n; i++) {
    // check Row
    if (!checkLine(n, grid, 0, i, 1, 0)) {
      cout << '0';
      return 0;
    }
    // count Row
    if (!checkCount(n, grid, 0, i, 1, 0)) {
      cout << '0';
      return 0;
    }
    // check Col
    if (!checkLine(n, grid, i, 0, 0, 1)) {
      cout << '0';
      return 0;
    }
    // count Col
    if (!checkCount(n, grid, i, 0, 0, 1)) {
      cout << '0';
      return 0;
    }
  }

  cout << '1';
  return 0;
}