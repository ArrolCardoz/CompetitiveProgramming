#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
  int counter = 0;
  while (n > 0) {
    counter += (n & 1);
    n >>= 1;
  }
  return counter;
}

int division(int n) {
  int max = 0;
  int num = 0;
  int digit = 1;
  string str = to_string(n);
  for (int i = 0; i < str.size(); i++) {
    num += ((str[i] - '0'));
    // cout << num << " NUM" << str[i] - '0' << endl;
    int temp = solution(num);
    if (temp > max) max = temp;
    num *= 10;
  }
  return max;
}
int main() {
  int a;
  cin >> a;

  for (int i = 0; i < a; i++) {
    int n;
    cin >> n;
    cout << division(n) << endl;
  }
  return 0;
}