// 733
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& image, int sr, int sc, int color, int colorChange,
         vector<vector<bool>> isVisited) {
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  // base
  if (image[sr][sc] != colorChange || isVisited[sr][sc]) return;

  image[sr][sc] = color;
  isVisited[sr][sc] = true;
  for (int i = 0; i < 4; i++) {
    int newRow = sr;
    int newCol = sc;
    newRow += dx[i];
    newCol += dy[i];
    if (newRow >= 0 && newRow < image.size() && newCol >= 0 &&
        newCol < image[0].size())
      dfs(image, newRow, newCol, color, colorChange, isVisited);
  }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                              int color) {
  int row = image.size();
  int col = image[0].size();

  vector<vector<bool>> visited(row, vector<bool>(col, false));
  dfs(image, sr, sc, color, image[sr][sc], visited);
  return image;
}

int main() {}