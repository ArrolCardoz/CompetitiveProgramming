#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  vector<string> A(4);
  for (auto& row : A) cin >> row;

  int total = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      char ch = A[i][j];
      if (ch == '.') continue;
      int t = ch - 'A';
      total += abs(i - t / 4) + abs(j - t % 4);
    }
  }
  cout << total << endl;
}