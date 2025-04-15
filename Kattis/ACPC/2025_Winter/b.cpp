#include <bits/stdc++.h>
using namespace std;

void solution() {}

int main() {
  int n;
  cin >> n;
  vector<int> data;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (b == 0) data.push_back(a);
  }
  sort(data.begin(), data.end());
  if (data.size() == 0)
    cout << -1 << endl;
  else
    cout << data[0] << endl;
  return 0;
}