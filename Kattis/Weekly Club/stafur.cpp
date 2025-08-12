#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_map<char, bool> vowels = {{'A', true}, {'E', true}, {'I', true},
                                      {'O', true}, {'U', true}, {'Y', true}};
  char c;
  cin >> c;
  if (vowels.find(c) != vowels.end()) {
    if (c == 'Y')
      cout << "Kannski " << endl;
    else
      cout << "Jebb" << endl;
  } else
    cout << "Neibb" << endl;
  return 0;
}