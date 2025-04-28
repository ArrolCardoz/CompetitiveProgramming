#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, h;
  cin >> a >> b >> h;
  int current = 0, time = 0;

  while (true) {
    current += a;
    time++;
    if (current >= h) break;
    current -= b;
  }
  cout << time << endl;
  return 0;
}