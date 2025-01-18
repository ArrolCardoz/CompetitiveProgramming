#include <bits/stdc++.h>
using namespace std;
bool simulate(int xFinal, int yFinal, vector<string> moves, int dx[],
              int dy[]) {
  int dir = 0, n = moves.size(), x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (moves[i] == "Forward") {
      x += dx[dir];
      y += dy[dir];
    } else if (moves[i] == "Right")
      dir = (dir + 1) % 4;
    else
      dir = (dir + 3) % 4;
  }
  if (x == xFinal && y == yFinal) return true;
  return false;
}
void checkAll(int xFinal, int yFinal, vector<string> moves, int dx[], int dy[],
              string changeMove[], unordered_map<string, int> idxMoves,
              int idx) {
  int n = moves.size();
  int currentMove = idxMoves[moves[idx]];
  //   cout << idx << endl;
  //   cout << changeMove[currentMove] << endl;
  currentMove = (currentMove + 1) % 3;

  // check Both the cases
  // case 1
  moves[idx] = changeMove[currentMove];
  //   cout << changeMove[currentMove] << endl;
  if (simulate(xFinal, yFinal, moves, dx, dy)) {
    cout << idx + 1 << ' ' << changeMove[currentMove];
    return;
  }

  // case 2
  currentMove = (currentMove + 1) % 3;
  //   cout << changeMove[currentMove] << endl;
  moves[idx] = changeMove[currentMove];
  if (simulate(xFinal, yFinal, moves, dx, dy)) {
    cout << idx + 1 << ' ' << changeMove[currentMove];
    return;
  }

  // backtrack
  currentMove = (currentMove + 1) % 3;
  //   cout << changeMove[currentMove] << endl;
  moves[idx] = changeMove[currentMove];
  checkAll(xFinal, yFinal, moves, dx, dy, changeMove, idxMoves, idx + 1);
}
int main() {
  int x, y;
  int n;
  int dir = 0;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  /*
  0=North
  1=Right
  2=Down
  3=Left
  */

  string str;
  string changeMove[3] = {"Left", "Right", "Forward"};
  unordered_map<string, int> idxMove = {
      {"Left", 0}, {"Right", 1}, {"Forward", 2}};

  vector<string> moves;
  cin >> x >> y >> n;
  for (int i = 0; i < n; i++) {
    cin >> str;
    moves.push_back(str);
  }
  checkAll(x, y, moves, dx, dy, changeMove, idxMove, 0);
  return 0;
}