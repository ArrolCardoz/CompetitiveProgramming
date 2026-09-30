#include <bits/stdc++.h>
using namespace std;
void solution(int64_t a, int64_t b) {
  int64_t remainder = a % b;
  int64_t mult = (a - remainder) / b;
  cout << mult << ' ' << remainder << " / " << b << endl;
}

int main() {
  int64_t a, b;
  while (cin >> a >> b) {
    if (a == 0 && b == 0) break;
    solution(a, b);
  }
  return 0;
}