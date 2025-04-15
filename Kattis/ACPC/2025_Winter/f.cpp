#include <bits/stdc++.h>
using namespace std;

void solution(int r, int c, vector<string> &map,
              vector<vector<bool>> &isVisited, int &ans) {
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  for (int i = 0; i < 4; i++) {
    int newRow = r;
    int newCol = c;
    newRow += dx[i];
    newCol += dy[i];

    // cout << map[newRow][newCol] << endl;
    // cout << map.size() << ' ' << map[0].size() << endl;
    // check
    if (newRow >= 0 && newRow < map.size() && newCol >= 0 &&
        newCol < map[0].size() && map[newRow][newCol] == '#' &&
        !isVisited[newRow][newCol]) {
      ans++;
      isVisited[newRow][newCol] = true;
      solution(newRow, newCol, map, isVisited, ans);
    }
  }
}

int main() {
  int r, c;
  cin >> r >> c;
  vector<string> map(r);
  string str;
  vector<bool> temp1(c, false);
  vector<vector<bool>> isVisited(r, temp1);
  int ans = 1;
  int startRow;
  int startCol;
  bool startFound = false;
  for (int i = 0; i < r; i++) {
    cin >> str;
    if (!startFound)
      for (int j = 0; j < c; j++) {
        if (str[j] == 'S') {
          startRow = i;
          startCol = j;
          startFound = true;
        }
      }
    map[i] = str;
  }
  solution(startRow, startCol, map, isVisited, ans);

  cout << ans << endl;
  return 0;
}