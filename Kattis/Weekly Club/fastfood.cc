#include <bits/stdc++.h>
using namespace std;
// For this problem I have stored the stickers required in "sticker" table
// its cost in seperate table
// Finally the total count of each sticker in a table
// I am accessing them buy the tables index as the key
// Finally I go though the prizes and take in minimum of the available tickets
// and add them all up
void solution() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> stricker(n);
  vector<int> cost(n);
  vector<int> ticketCount(m);
  for (int i = 0; i < n; i++) {
    int inputSticker, price, numstricker;

    cin >> numstricker;
    vector<int> temp(numstricker);
    for (int j = 0; j < numstricker; j++) {
      cin >> inputSticker;
      temp[j] = inputSticker;
    }
    stricker[i] = temp;
    cin >> price;
    cost[i] = price;
  }

  for (int i = 0; i < m; i++) {
    int count;
    cin >> count;
    ticketCount[i] = count;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int minimum = INT_MAX;
    for (int j = 0; j < stricker[i].size(); j++) {
      if (minimum > ticketCount[stricker[i][j] - 1]) {
        minimum = ticketCount[stricker[i][j] - 1];
      }
      // cout << minimum << '=' << ticketCount[stricker[i][j] - 1] << ' '
      //      << stricker[i][j] << endl;
    }
    ans += minimum * cost[i];
  }
  cout << ans << endl;
}

int main() {
  int repeat;
  cin >> repeat;
  while (repeat--) {
    solution();
  }
  return 0;
}