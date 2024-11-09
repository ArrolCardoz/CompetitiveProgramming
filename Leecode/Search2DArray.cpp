// 74
#include <bits/stdc++.h>
using namespace std;

bool columnSearch(vector<vector<int>>& mat, int target, int row) {
  int end = mat[0].size();
  int start = 0;
  int mid;

  while (start <= end) {
    mid = start + (end - start) / 2;
    if (mat[row][mid] <= target && target <= mat[row][mid]) {
      return true;
    } else if (mat[row][mid] <= target && target >= mat[row][mid]) {
      start = mid + 1;
    } else if (mat[row][mid] >= target && target <= mat[row][mid]) {
      end = mid - 1;
    }
  }
  return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
  int n = mat.size() - 1;
  int m = mat[0].size() - 1;
  // mid
  int start = 0;
  int end = n;
  int mid = start + (end - start) / 2;

  // row search
  while (start <= end) {
    mid = start + (end - start) / 2;
    cout << mat[mid][0] << endl;
    if (mat[mid][0] <= target && target <= mat[mid][m]) {
      return columnSearch(mat, target, mid);
    } else if (mat[mid][0] <= target && target >= mat[mid][m]) {
      start = mid + 1;
    } else if (mat[mid][0] >= target && target <= mat[mid][m]) {
      end = mid - 1;
    }
  }
  return false;
}

int main() {
  vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 61;

  if (searchMatrix(mat, target))
    cout << "True";
  else
    cout << "False";
}
