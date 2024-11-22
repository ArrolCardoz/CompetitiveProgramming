#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
  int numRow = mat.size();
  int numCol = mat[0].size();
  int currentRow = 0;
  numRow--;
  numCol--;
  cout << numRow << endl;
  while (currentRow <= numRow && numCol > -1) {
    if (mat[currentRow][numCol] == target) {
      return true;
    }
    if (mat[currentRow][numCol] > target)
      numCol--;
    else
      currentRow++;
  }
  return false;
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