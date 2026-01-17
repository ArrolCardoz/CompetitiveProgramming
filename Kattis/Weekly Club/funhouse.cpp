#include <bits/stdc++.h>
using namespace std;

void traverse(vector<string>& grid, int& row, int& col, int& dir) {
  const int dy[] = {0, 1, 0, -1};
  const int dx[] = {-1, 0, 1, 0};
  cerr << row << ' ' << col << grid[row][col] << endl;

  cerr << dir << endl;
  row += dx[dir];
  col += dy[dir];
  cerr << row << ' ' << col << grid[row][col] << endl;

  const unordered_map<char, vector<int>> changeDir = {
      {'/', {1, 0, 3, 2}},
      {'\\', {3, 2, 1, 0}},
      {'.', {0, 1, 2, 3}},
  };
  while (grid[row][col] != 'x') {
    cerr << row << ' ' << col << ' ' << dir << endl;
    cerr << changeDir.at(grid[row][col])[dir] << endl;
    dir = changeDir.at(grid[row][col])[dir];
    row += dx[dir];
    col += dy[dir];
  }
  grid[row][col] = '&';
  return;
}

void findStart(vector<string> grid, int& row, int& col, int& dir) {
  int gridRow = grid.size() - 1;
  int gridCol = grid[0].size() - 1;

  // check first row
  for (int i = 0; i <= gridCol; i++) {
    if (grid[0][i] == '*') {
      row = 0;
      col = i;
      dir = 2;
      return;
    }
  }
  // check last row
  for (int i = 0; i <= gridCol; i++) {
    if (grid[gridRow][i] == '*') {
      row = gridRow;
      col = i;
      dir = 0;
      return;
    }
  }
  // check left col
  for (int i = 0; i <= gridRow; i++) {
    if (grid[i][0] == '*') {
      row = i;
      col = 0;
      dir = 1;
      return;
    }
  }
  // check right col
  for (int i = 0; i <= gridRow; i++) {
    if (grid[i][gridCol] == '*') {
      row = i;
      col = gridCol;
      dir = 3;
      return;
    }
  }
}

int main() {
  int counter = 1;
  int row, col;
  while (cin >> col >> row && row != 0 && col != 0) {
    int startRow, startCol, dir;

    vector<string> grid(row);

    for (auto& it : grid) cin >> it;

    findStart(grid, startRow, startCol, dir);
    traverse(grid, startRow, startCol, dir);

    cout << "HOUSE " << counter << endl;
    for (auto& it : grid) {
      cout << it << endl;
    }
    counter++;
  }
  return 0;
}