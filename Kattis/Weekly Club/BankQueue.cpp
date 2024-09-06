#include <bits/stdc++.h>
using namespace std;
bool pairsort(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) return false;
  return true;
}
int solution() {
  int money, days;
  vector<pair<int, int>> customers;
  int numDays, numCustomers;
  cin >> numCustomers >> numDays;

  for (int i = 0; i < numCustomers; i++) {
    cin >> money >> days;
    if (days > numDays) continue;
    customers.push_back({money, days});
  }

  // sort(customers.begin(), customers.end(), pairsort);

  for (auto &it : customers) swap(it.first, it.second);

  sort(customers.begin(), customers.end(), pairsort);

  for (auto &it : customers) {
    cout << it.first << " " << it.second << endl;
  }
  int numDaysCounter = numDays;
  int maxMoney = 0;
  int ans = 0;
  auto high = numCustomers;
  int pointer = 0;

  for (int i = numDays; i >= 0; i--) {
    for (int j = 0; j < numCustomers; j++) {
      if (customers[j].first < i) {
      } else if (maxMoney < customers[j].second) {
        maxMoney = customers[j].second;
        pointer = j;
      }
      // cout << j << endl;
    }
    ans += maxMoney;
    // cout << maxMoney << endl;

    maxMoney = 0;
    if (pointer != 0) customers[pointer].second = 0;

    pointer = 0;
  }

  return ans;
}
int main() {
  cout << solution();
  return 0;
}