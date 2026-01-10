#include <bits/stdc++.h>
using namespace std;

void simulate(vector<string> moves, int r, int c) {
  int facing = 0;
  int dx = {1, 0, -1, 0};
  int dy = {0, 1, 0, -1};
  for (auto& it : moves) {
    if (it == "Forward") {
      r += dx[facing];
      c += dy[facing];

    } else if (if == "Right")
      facing = (facing + 1) % 4;
    else
      facing = (facing + 3) % 4;
  }
}

int main() {
  int finalR, finalC;
  int n;
  vector<string> moves;
  cin >> finalR >> finalC;
  cin >> n;
  moves.reserve(n);
  while (n--) {
    string input;
    cin >> input;
    moves.push_back(input);
  }
}