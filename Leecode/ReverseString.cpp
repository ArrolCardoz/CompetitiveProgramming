// 344
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) { reverse(s.begin(), s.end()); }

int main() {
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  reverseString(s);
  for (auto& it : s) cout << it;
  return 0;
}