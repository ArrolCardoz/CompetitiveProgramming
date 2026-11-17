/*
Solution: This is a BFS problem where each edge/tile in the grid has multiple
states.
In order to not have infinite loop we need a visited table but we also need more
than just a boolean table because the way we enter a tile matters because we
cannot repeat 2 moves in a row. There are multiple ways to keep track of he
visited table one is through bit mask and other is just having a table with
multiple dimentions. Which is what I did since there are only 5 direction
(Up,left,down,right,NONE). which worse case is 1000*1000*5*5 = 25'000'000

This can be smaller by bit minipulation with 1000*1000*1 but it makes the code
more complicated. Since we can afford the easy option that is what I have
implemented.

BFS - The queue takes in a struct (Tile). We can use a tuple as well I used a
struct because its easier to read. The direction is calulated with the help of
delta tables for row and columns (dx and dy). The next step is to check if the
next step is valid or not. If it is check if its is destination or push it in
the queue.
 */
#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
using States = array<array<bool, 5>, 5>;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int NONE = 4;

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

struct Tile {
  int row = -1;
  int col = -1;
  int lastDir = NONE;
  int secLastDir = NONE;
  int count = 0;
};

void solution() {
  // initialize
  int rNum, cNum, startR = -1, startC = -1;
  cin >> rNum >> cNum;
  vector<vector<States>> visited(rNum, vector<States>(cNum));
  vector<string> grid(rNum);

  // input
  for (int i = 0; i < rNum; i++) {
    cin >> grid[i];
    for (int j = 0; j < cNum; j++) {
      if (grid[i][j] == 'R') {
        startR = i;
        startC = j;
      }
    }
  }
  assert(startR != -1 && startC != -1);

  // bfs
  queue<Tile> Q;
  Q.push({startR, startC, NONE, NONE, 0});
  while (!Q.empty()) {
    auto& [r, c, last, secLast, currCount] = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int newR = r + dx[i];
      int newC = c + dy[i];
      // check if valid
      if (i == last && last == secLast) continue;  // 3 in a row
      if (dx[i] == -dx[last] && dy[i] == -dy[last])
        continue;  // going backwards
      if (newR >= rNum || newR < 0 || newC < 0 || newC >= cNum)
        continue;                             // out of bound
      if (grid[newR][newC] == 'B') continue;  // is block
      if (visited[newR][newC][i][last])
        continue;  // visited earlier with same state

      if (grid[newR][newC] == 'D') {
        cout << currCount + 1 << endl;
        return;
      }
      visited[newR][newC][i][last] = true;
      Q.push({newR, newC, i, last, currCount + 1});
    }
  }
  cout << -1 << endl;
}

int main() {
  fastIO();
  int n;
  cin >> n;
  while (n--) solution();

  return 0;
}