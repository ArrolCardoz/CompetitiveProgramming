#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
  int numRow = mat.size();
  int numCol = mat[0].size();
  int matrix = numRow * numCol;
  numRow--;
  numCol--;
  while (matrix > 1) {
    if (w) }
}

int main() {
  vector<vector<int>> mat = {{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
  int target = 5;
  if (searchMatrix(mat, target))
    cout << "true";
  else
    cout << "False";
  return 0;
}