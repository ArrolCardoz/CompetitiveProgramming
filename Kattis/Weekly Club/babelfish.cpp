#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  unordered_map<string, string> translate;
  while (getline(cin, str) && str != "") {
    stringstream ss(str);
    string s1, s2;
    ss >> s1 >> s2;
    translate[s2] = s1;
  }
  while (cin >> str) {
    if (translate.find(str) == translate.end())
      cout << "eh" << endl;
    else
      cout << translate[str] << endl;
  }
  return 0;
}