#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();

  int best = 0, winner = 0;
  for (int c = 1; c <= 5; c++) {
    vector<int> g(4);
    for (int& x : g) cin >> x;

    int score = accumulate(g.begin(), g.end(), 0);
    if (score > best) {
      best = score;
      winner = c;
    }
  }
  cout << winner << ' ' << best << '\n';
}