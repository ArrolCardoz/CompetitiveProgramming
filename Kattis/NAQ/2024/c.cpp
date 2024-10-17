
#include <bits/stdc++.h>
using namespace std;

void solution() {}

int main() {
  int n;
  int counter = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;

    cin >> a;
    if (a % 2 == 1) counter++;
  }
  cout << counter;
  return 0;
}
