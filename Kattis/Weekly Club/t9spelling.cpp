#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<char, int> repeat = {
      {'a', 1}, {'d', 1}, {'g', 1}, {'j', 1}, {'m', 1}, {'p', 1}, {'t', 1},
      {'w', 1}, {'b', 2}, {'d', 2}, {'h', 2}, {'k', 2}, {'n', 2}, {'q', 2},
      {'u', 2}, {'x', 2}, {'c', 3}, {'f', 3}, {'i', 3}, {'l', 3}, {'o', 3},
      {'r', 3}, {'v', 3}, {'y', 3}, {'s', 4}, {'z', 4}, {' ', 1}, {'e', 2}};
  unordered_map<char, int> buttonNum = {
      {'a', 2}, {'b', 2}, {'c', 2}, {'d', 3}, {'e', 3}, {'f', 3}, {'g', 4},
      {'h', 4}, {'i', 4}, {'j', 5}, {'k', 5}, {'l', 5}, {'m', 6}, {'n', 6},
      {'o', 6}, {'p', 7}, {'q', 7}, {'r', 7}, {'s', 7}, {'t', 8}, {'u', 8},
      {'v', 8}, {'w', 9}, {'x', 9}, {'y', 9}, {'z', 9}, {' ', 0},
  };
  cin.ignore(1);

  for (int i = 1; i <= n; i++) {
    cout << "Case #" << i << ':' << ' ';
    string str;
    getline(cin, str);
    // cout << str << endl;
    char prv = '0';
    for (auto& it : str) {
      int m = repeat[it];
      if (prv == buttonNum[it]) cout << ' ';
      while (m--) cout << buttonNum[it];
      prv = buttonNum[it];
    }
    cout << endl;
  }
}