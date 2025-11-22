#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> dir = {{"N", 0}, {"NE", 1}, {"E", 2}, {"SE", 3},
                                  {"S", 4}, {"SW", 5}, {"W", 6}, {"NW", 7}};
int main() {
  string start, end;
  cin >> start >> end;

  if (start == end)
    cout << "Keep going straight" << endl;
  else if (dir[start] == ((dir[end] + 4) % 8))
    cout << "U-turn" << endl;
  else {
    int s = dir[start], e = dir[end];
    for (int i = 1; i < 8; i++) {
      s = (s + 1) % 8;
      if (s == e && i < 4) {
        cout << "Turn " << 45 * i << " degrees starboard";
        return 0;
      }
      if (s == e && i < 8) {
        cout << "Turn " << 45 * (8 - i) << " degrees port";
        return 0;
      }
    }
  }
}