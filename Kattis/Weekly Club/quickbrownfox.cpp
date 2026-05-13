#include <bits/stdc++.h>
using namespace std;

int main() {
  set<char> atoz;
  for (int i = 0; i < 26; i++) {
    atoz.insert('a' + i);
  }
  int n;
  cin >> n;
  cin.ignore(100, '\n');
  while (n--) {
    set<char> curr = atoz;
    string str;
    getline(cin, str);
    cerr << str << endl;
    char c;
    stringstream ss(str);
    while (ss >> c) {
      if (c >= 'a' && c <= 'z')
        curr.erase(c);
      else if (c >= 'A' && c <= 'Z') {
        c = tolower(c);
        curr.erase(c);
      }
    }
    if (curr.size() == 0)
      cout << "pangram";
    else {
      cout << "missing ";
      for (auto& it : curr) {
        cout << it;
      }
    }
    cout << endl;
  }
  return 0;
}