#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> repeat;
  string str;

  while (cin >> str) {
    repeat[str]++;
    if (repeat[str] > 1) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}