
#include <bits/stdc++.h>
using namespace std;

char table[30][30];
bool checkBulbsAdj(vector<pair<int, int>> constrains, int n) {
  int count = 0;
  for (auto &it : constrains) {
    count = 0;
    if (table[it.first][it.second] >= '0' &&
        table[it.first][it.second] <= '5') {
      int num = table[it.first][it.second] - '0';
      // check top
      if (it.first != 0)
        if (table[it.first - 1][it.second] == '?') count++;
      // check left
      if (it.second != 0)
        if (table[it.first][it.second - 1] == '?') count++;
      // check right
      if (it.second + 1 != n)
        if (table[it.first][it.second + 1] == '?') count++;
      // check bottom
      if (it.first + 1 != n)
        if (table[it.first + 1][it.second] == '?') count++;
      // cout << count << " " << num << endl;
      if (count != num) return false;
    }
  }
  return true;
}
bool checkLit(vector<pair<int, int>> bulb, int n) {
  for (auto &it : bulb) {
    // cout << it.first << ' ' << it.second << endl;
    // check top
    for (int i = it.first - 1; i >= 0; i--) {
      if (table[i][it.second] == 'X' ||
          (table[i][it.second] >= '0' && table[i][it.second] <= '5')) {
        break;
      }
      if (table[i][it.second] == '?') return false;
      table[i][it.second] = '-';
    }
    // check bottom
    for (int i = it.first + 1; i < n; i++) {
      // cout << "i" << endl;
      if (table[i][it.second] == 'X' ||
          (table[i][it.second] >= '0' && table[i][it.second] <= '5')) {
        break;
      }
      // cout << "j" << endl;
      if (table[i][it.second] == '?') return false;
      table[i][it.second] = '-';
      // cout << "k" << endl;
    }
    // check right
    for (int i = it.second + 1; i < n; i++) {
      if (table[it.first][i] == 'X' ||
          (table[it.first][i] >= '0' && table[it.first][i] <= '5')) {
        break;
      }
      if (table[it.first][i] == '?') return false;
      table[it.first][i] = '-';
    }
    // check left
    for (int i = it.second - 1; i >= 0; i--) {
      if (table[it.first][i] == 'X' ||
          (table[it.first][i] >= '0' && table[it.first][i] <= '5')) {
        break;
      }
      if (table[it.first][i] == '?') return false;

      table[it.first][i] = '-';
    }
  }
  // cout << endl << endl << endl << endl;

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if (table[i][j] == '.') return false;
      // cout << table[i][j];
    }
    // cout << endl;
  }
  return true;
  return true;
}

void solution() {
  vector<pair<int, int>> constrains;
  vector<pair<int, int>> bulbs;

  int n;
  cin >> n;
  char str;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> str;
      table[i][j] = str;
      if (str >= '0' && str <= '5' || str == 'X') {
        constrains.push_back(make_pair(i, j));
      }
      if (str == '?') {
        bulbs.push_back(make_pair(i, j));
      }
    }
  }
  // for (auto &it : constrains) {
  //   cout << it.first << " " << it.second << endl;
  // }

  if (checkLit(bulbs, n) && checkBulbsAdj(constrains, n))
    cout << "1" << endl;
  else
    cout << "0" << endl;
}

int main() {
  solution();
  return 0;
}
