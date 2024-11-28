#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int row = matrix.size();
  int col = matrix[0].size();
  int rows = 0;        // rowStart
  int cols = 0;        // colStart
  int rowe = row - 1;  // rowEnd
  int cole = col - 1;  // colEnd
  vector<int> ans;
  while (rows <= rowe && cols <= cole) {
    // top
    for (int i = cols; i <= cole; i++) {
      ans.push_back(matrix[rows][i]);
      //   cout << "HI1" << endl;
    }
    // right
    for (int i = rows + 1; i <= rowe; i++) {
      ans.push_back(matrix[i][cole]);
      //   cout << "HI2" << endl;
    }

    // end
    for (int i = cole - 1; i >= cols; i--) {
      if (rows == rowe) break;

      ans.push_back(matrix[rowe][i]);
      //   cout << "HI3" << endl;
    }

    // left
    for (int i = rowe - 1; i >= rows + 1; i--) {
      if (cole == cols) break;
      ans.push_back(matrix[i][cols]);
      //   cout << "HI4" << endl;
    }
    // cout << "rowStart" << rows << " rowEnd" << rowe << endl;
    // cout << "rowStart" << cols << " rowEnd" << cole << endl;

    rows++;
    rowe--;
    cols++;
    cole--;
  }
  return ans;
}
int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (auto& it : spiralOrder(matrix)) cout << it << ' ';
  return 0;
}