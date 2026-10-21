#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int n, m;
  cin >> n >> m;
  priority_queue<int, vector<int>, greater<int>> pqN, pqM;
  int input, ans = 0;
  while (n--) {
    cin >> input;
    pqN.push(input);
  }
  while (m--) {
    cin >> input;
    pqM.push(input);
  }

  while (!pqN.empty() && !pqM.empty()) {
    int task = pqN.top(), interval = pqM.top();
    if (task <= interval) {
      pqN.pop();
      ans++;
    }
    pqM.pop();
  }
  cout << ans << endl;

  return 0;
}