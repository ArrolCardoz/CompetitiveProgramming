#include <bits/stdc++.h>
using namespace std;
int ctr = 0;
void solution() {
  int n;
  string str;
  cin >> n;
  cin >> str;
  bool s = 0, p = 0;

  while (n--) {
    string input;
    getline(cin, input);
    cerr << input << endl;
    if (input == "pea soup") p = 1;
    if (input == "pancakes") s = 1;
  }
  cerr << s << ' ' << p << endl;
  if (s && p) {
    cout << str << endl;
    ctr++;
  }
}

int main() {
  int n;
  cin >> n;
  while (n--) solution();
  if (!ctr) cout << "Anywhere is fine I guess" << endl;

  return 0;
}