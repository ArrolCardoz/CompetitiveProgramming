#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, vector<int>> data;
  int n, maxTime = 0;
  cin >> n;
  int time, money;
  while (n--) {
    cin >> time >> money;
    data[time].push_back(money);
  }
  auto it = data.rbegin();
  maxTime = it->first;
  int ans = 0;

  priority_queue<int> MostPizzaCost;
  for (int i = maxTime; i > 0; i--) {
    for (auto& a : data[i]) MostPizzaCost.push(a);
    if (MostPizzaCost.empty()) continue;
    ans += MostPizzaCost.top();
    MostPizzaCost.pop();
  }
  cout << ans << endl;
  return 0;
}