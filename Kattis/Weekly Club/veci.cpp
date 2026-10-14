#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  string n;
  cin >> n;
  if (next_permutation(n.begin(), n.end()))
    cout << n << endl;
  else
    cout << 0 << endl;
  return 0;
}