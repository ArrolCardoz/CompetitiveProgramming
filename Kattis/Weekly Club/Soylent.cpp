#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
  //   if (n == 0) cout << '0';
  int ans = n / 400;
  if (n % 400 > 0) ans++;
  return ans;
}

int main() {
  int a;
  cin >> a;
  for (int i = 0; i < a; i++) {
    int n;
    cin >> n;
    cout << solution(n) << endl;
  }
}