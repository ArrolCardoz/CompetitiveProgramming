#include <bits/stdc++.h>
using namespace std;

int main() {
  long long k, m, n;
  cin >> k >> m >> n;
  long long check = k % (m + n);
  if (check < m)
    cout << "Barb" << endl;
  else
    cout << "Alex" << endl;
  return 0;
}