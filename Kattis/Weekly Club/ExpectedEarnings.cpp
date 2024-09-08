#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  double p;
  cin >> n >> k >> p;
  if ((p * (n - k)) + ((1 - p) * -k) >= 0)
    cout << "spela inte!";
  else
    cout << "spela";
  // cout << endl << (p * (n - k)) + ((1 - p) * -k);
}