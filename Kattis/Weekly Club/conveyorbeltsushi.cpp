#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int>& table) {
  int temp = table[table.size() - 1];
  for (int i = (int)table.size() - 1; i > 0; i--) {
    table[i] = table[i - 1];
  }
  table[0] = temp;
}

int main() {
  unordered_map<int, int> price;
  int n;
  int cycle;
  int time, person, currentTime = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int priz;
    cin >> priz;
    price[i] = priz;
  }
  cin >> cycle >> n;
  cycle++;
  int plateCounter = 0;
  vector<int> table(cycle, -1), ans(cycle, 0);
  table[0] = 0;

  cin >> time >> person;
  while (true) {
    // cout << n << endl;
    if (time > currentTime) {
      // time passes
      currentTime++;
      rotate(table);

      if (table[0] == -1) {
        plateCounter++;
        plateCounter %= price.size();
        table[0] = plateCounter;
      }

    } else if (time == currentTime) {
      if (table[person] != -1) {
        ans[person] += price[table[person]];
        table[person] = -1;
      }
      n--;
      if (n) cin >> time >> person;
    }
    if (!n) break;
  }
  for (int i = 1; i < (int)ans.size(); i++) {
    cout << ans[i] << endl;
  }

  return 0;
}