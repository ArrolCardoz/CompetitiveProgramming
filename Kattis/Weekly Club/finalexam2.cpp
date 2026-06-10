#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;
  char prev = ' ', curr = ' ';

  cin >> n >> prev;
  n--;
  while (n--) {
    cin >> curr;
    if (curr == prev) ans++;
    prev = curr;
  }
  cout << ans << endl;
}