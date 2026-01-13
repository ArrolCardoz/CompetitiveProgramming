#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  // process
  unordered_map<char, char> table;
  string line1 = "QWERTYUIOP[]\\";
  for (int i = 1; i < line1.size(); i++) {
    table[line1[i]] = line1[i - 1];
  }
  line1 = "ASDFGHJKL;'";
  for (int i = 1; i < line1.size(); i++) {
    table[line1[i]] = line1[i - 1];
  }
  line1 = "ZXCVBNM,./";
  for (int i = 1; i < line1.size(); i++) {
    table[line1[i]] = line1[i - 1];
  }
  line1 = "1234567890-=";
  for (int i = 1; i < line1.size(); i++) {
    table[line1[i]] = line1[i - 1];
  }
  table[' '] = ' ';
  while (getline(cin, str)) {
    for (char c : str) {
      cout << table[c];
    }
    cout << endl;
  }

  return 0;
}