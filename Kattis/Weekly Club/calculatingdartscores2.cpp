#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool getStr(int s) {
  switch (s) {
    case 0:
      return false;
    case 1:
      cout << "single ";
      return true;
    case 2:
      cout << "double ";
      return true;
    case 3:
      cout << "triple ";
      return true;
  }
  assert(false);
  return false;
}
int main() {
  fastIO();
  int n;
  cin >> n;
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= 20; j++)
      for (int k = 1; k <= 20; k++)
        for (int a = 1; a <= 3; a++)
          for (int b = 0; b <= 3; b++)
            for (int c = 0; c <= 3; c++) {
              if (i * a + j * b + k * c == n) {
                getStr(a);
                cout << i << endl;
                if (getStr(b)) cout << j << endl;
                if (getStr(c)) cout << k << endl;
                return 0;
              }
            }
  cout << "impossible" << endl;
  return 0;
}