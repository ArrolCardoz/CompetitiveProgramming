#include <bits/stdc++.h>
using namespace std;

int main() {
  map<char, bool> vowels = {{'a', true}, {'A', true}, {'e', true}, {'E', true},
                            {'i', true}, {'I', true}, {'o', true}, {'O', true},
                            {'u', true}, {'U', true}};
  string str;
  int count = 0;
  getline(cin, str);
  for (auto &s : str) {
    if (vowels[s]) count++;
  }
  cout << count << endl;
  return 0;
}