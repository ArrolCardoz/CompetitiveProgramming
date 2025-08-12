#include <bits/stdc++.h>
using namespace std;
int main() {
  string n1, n2;
  string N1 = "", N2 = "";
  cin >> n1 >> n2;
  for (int i = 2; i > -1; i--) {
    N1 += n1[i];
    N2 += n2[i];
  }
  if (N1 > N2)
    cout << N1 << endl;
  else
    cout << N2 << endl;

  return 0;
}