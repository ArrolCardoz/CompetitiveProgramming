#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int num, NUM;
    cin >> num;
    NUM = num;
    int sum = 0, input, MIN = INT_MAX, MAX = INT_MIN;
    while (num--) {
      cin >> input;
      sum += input;
      if (input > MAX) MAX = input;
      if (input < MIN) MIN = input;
    }
    sum /= NUM;
    int ans = 0;
    MAX = abs(sum - MAX);
    MIN = abs(sum - MIN);
    cout << 2 * (MIN + MAX) << endl;
  }
}