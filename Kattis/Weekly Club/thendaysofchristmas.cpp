#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int total = 0;
  int current = 0;
  for (int i = 1; i <= n; i++) {
    current += i;
    total += current;
  }
  cout << current << endl << total << endl;
  return 0;
}