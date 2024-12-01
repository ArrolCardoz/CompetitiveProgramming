#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c, m;
  cin >> n >> c >> m;
  long long sum = c + m;
  int counter = 0;
  int num;
  vector<int> records;
  while (n--) {
    cin >> num;
    records.push_back(num);
  }
  for (auto &it : records) {
    if (it < sum)
      counter++;
    else {
      sum = it + c;
      c = it;
    }
  }
  cout << counter << endl;
  return 0;
}