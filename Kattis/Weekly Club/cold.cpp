#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int counter = 0;
  while (n--) {
    int a;
    cin >> a;
    if (a < 0) counter++;
  }
  cout << counter << endl;
  return 0;
}