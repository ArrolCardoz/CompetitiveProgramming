#include <bits/stdc++.h>
using namespace std;

void solution() {
  priority_queue<pair<int, int>> buyPQ;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      sellPQ;
  int deal = 0;
  int n;
  cin >> n;
  while (n--) {
    string type, temp1, temp2;
    int num, price;
    cin >> type >> num >> temp1 >> temp2 >> price;
    if (type == "buy")
      buyPQ.push({price, num});
    else
      sellPQ.push({price, num});

    while (!sellPQ.empty() && !buyPQ.empty() &&
           sellPQ.top().first <= buyPQ.top().first) {
      auto sellTop = sellPQ.top();
      auto buyTop = buyPQ.top();
      sellPQ.pop();
      buyPQ.pop();

      int traded = min(sellTop.second, buyTop.second);
      deal = sellTop.first;
      sellTop.second -= traded;
      buyTop.second -= traded;

      if (sellTop.second > 0) sellPQ.push(sellTop);
      if (buyTop.second > 0) buyPQ.push(buyTop);
    }

    if (!sellPQ.empty())
      cout << sellPQ.top().first << ' ';
    else
      cout << "- ";
    if (!buyPQ.empty())
      cout << buyPQ.top().first << ' ';
    else
      cout << "- ";
    if (deal)
      cout << deal << '\n';
    else
      cout << "-\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}