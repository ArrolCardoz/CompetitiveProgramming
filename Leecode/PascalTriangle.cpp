#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> ans;
  for (int i = 0; i < numRows; i++) {
    vector<int> currentRow(i + 1, 1);

    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        continue;
      else
        currentRow[j] = (ans[i - 1][j - 1] + ans[i - 1][j]);
    }
    // for (auto &it : currentRow) cout << it << ' ';
    ans.push_back(currentRow);
    // cout << endl;
  }
  return ans;
}

int main() {
  int numRows = 5;
  generate(numRows);

  return 0;
}