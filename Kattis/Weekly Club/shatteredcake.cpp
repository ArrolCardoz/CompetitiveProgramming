#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, width, totalArea = 0;
  int l, b;
  cin >> width >> n;
  while (n--) {
    cin >> l >> b;
    totalArea += l * b;
  }
  cout << totalArea / width << endl;
  return 0;
}