#include <bits/stdc++.h>
using namespace std;

int main() {
  int H;
  string path;
  cin >> H;
  cin >> path;

  long long i = 1;
  for (char c : path) {
    i = i * 2 + (c == 'R');
  }
  cout << (1LL << (H + 1)) - i << endl;
  return 0;
}