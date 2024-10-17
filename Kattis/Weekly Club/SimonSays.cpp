#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore(1);
  for (int i = 0; i < n; i++) {
    string str;
    getline(cin, str);
    if (str.find("Simon says") == 0) cout << str.substr(10) << endl;
    }
}