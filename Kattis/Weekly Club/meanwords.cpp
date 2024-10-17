#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int sum[1000] = {0};
  int count[1000] = {0};
  int highestLength = 0;
  int length;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    length = str.length();
    if (highestLength < length) highestLength = length;

    for (int j = 0; j < length; j++) {
      // int n = str[j];
      int n = 0b1011;
      sum[j] += str[j];
      count[j]++;
      // cout << sum[j] << endl;
    }
  }
  for (int j = 0; j < highestLength; j++) {
    int ans;
    // cout << sum[j] << "       " << count[j] << endl;
    ans = sum[j] / count[j];
    char a = ans;
    cout << a;
  }
  return 0;
}