#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string str;
  while (n--) {
    cin >> str;
    if (str == "P=NP") {
      cout << "skipped" << endl;
      continue;
    }
    replace(str.begin(), str.end(), '+', ' ');
    istringstream in;
    int a, b;
    in >> a >> b;
    // auto it = str.find("+");

    // a = stoi(str.substr(0, it));
    // b = stoi(str.substr(it++));

    cout << a + b << endl;
  }
}