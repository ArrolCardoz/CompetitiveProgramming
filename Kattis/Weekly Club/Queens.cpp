#include <bits/stdc++.h>
using namespace std;

string solution() {
  int n;
  vector<int> row;
  vector<int> col;
  vector<int> DiagonalLeft;
  vector<int> DiagonalRight;
  cin >> n;
  row.resize(n);
  col.resize(n);
  DiagonalLeft.resize(n + n - 1);
  DiagonalRight.resize(n + n - 1);
  n--;
  int x, y;
  for (int i = 0; i <= n; i++) {
    cin >> x >> y;
    row[x]++;
    col[y]++;
    DiagonalLeft[x + y]++;
    DiagonalRight[x - y + n]++;
    if (row[x] > 1 || col[y] > 1 || DiagonalLeft[x + y] > 1 ||
        DiagonalRight[x - y + n] > 1)
      return "INCORRECT";
  }
  return "CORRECT";
}

int main() {
  cout << solution();
  return 0;
}