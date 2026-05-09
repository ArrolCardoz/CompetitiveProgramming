#include <bits/stdc++.h>
using namespace std;
void solution() {
  int n, m;
  cin >> n >> m;
  vector<int> ticketPrize(n), ticket(m);
  vector<vector<int>> ticketReq(n);
  // input ticket
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    ticketReq[i].resize(num);
    for (auto& it : ticketReq[i]) {
      cin >> it;
    }
    cin >> ticketPrize[i];
  }

  for (auto& it : ticket) cin >> it;
  int ans = 0;
  int ctr = 0;

  for (int i = 0; i < n; i++) {
    int total = INT_MAX;

    for (int j = 0; j < (int)ticketReq[i].size(); j++) {
      // cerr << ticketReq[i][j] << ':' << ticket[ticketReq[i][j] - 1] << ' ';
      total = min(total, ticket[ticketReq[i][j] - 1]);
    }
    // cerr << endl;
    // cerr << "TOTAL:" << total << endl;
    ans = ans + (total * ticketPrize[ctr]);
    // cerr << "ANS" << ticketPrize[ctr] << endl;
    ctr++;
  }

  cout << ans << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    solution();
  }
}