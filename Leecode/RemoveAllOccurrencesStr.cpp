// 1910
#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string str, string part) {
  int partSize = part.size();
  int address;
  while (true) {
    address = str.find(part);

    if (address > str.length()) break;

    str.erase(address, partSize);
    // cout << str << endl;
  }
  return str;
}

int main() {
  string str = "daabcbaabcbc";
  string part = "abc";
  cout << removeOccurrences(str, part) << endl;
  return 0;
}