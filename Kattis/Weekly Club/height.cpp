#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int data;
    int ans = 0;
    cin >> data;
    cout << data << ' ';
    vector<int> num(20);
    for (auto &it : num) cin >> it;
    bool acendOrder = true;
    while (acendOrder) {
      acendOrder = false;
      for (int i = 1; i < 20; i++) {
        if (num[i - 1] > num[i]) {
          swap(num[i - 1], num[i]);
          ans++;
          acendOrder = true;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}