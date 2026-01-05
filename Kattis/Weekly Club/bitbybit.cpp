#include <bits/stdc++.h>
using namespace std;

int OR(int a, int b) {
  //   cout << a << ' ' << b << endl;

  if (a == 1 || b == 1) return 1;
  if (a == -1 || b == -1) return -1;
  return 0;
}

int AND(int a, int b) {
  //   cout << a << ' ' << b << endl;
  if (a == 0 || b == 0) return 0;
  if (a == -1 || b == -1) return -1;
  return 1;
}

int main() {
  int n;
  cin >> n;

  do {
    if (n == 0) break;

    vector<int> reg(32, -1);
    while (n--) {
      string str;
      int num;
      cin >> str >> num;
      if (str == "CLEAR")
        reg[num] = 0;
      else if (str == "SET")
        reg[num] = 1;
      else if (str == "OR") {
        int second;
        cin >> second;
        reg[num] = OR(reg[num], reg[second]);
      } else {
        int second;
        cin >> second;
        reg[num] = AND(reg[num], reg[second]);
      }
      //   cerr << reg[num] << ' ' << str << endl;
    }
    for (int i = reg.size() - 1; i >= 0; i--) {
      if (reg[i] == -1)
        cout << '?';
      else
        cout << reg[i];
    }
    cout << endl;
  } while (cin >> n);
  return 0;
}