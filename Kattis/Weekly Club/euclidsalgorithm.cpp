#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  long long Max = max(a, b);
  long long Min = min(a, b);
  while (Min != 0) {
    long long temp = Max % Min;
    Max = Min;
    Min = temp;
  }
  cout << Max << endl;
  return 0;
}