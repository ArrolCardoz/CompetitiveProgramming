#include <bits/stdc++.h>
using namespace std;
bool check(string str1) {
  char vowels[] = {'a', 'i', 'o', 'u'};
  for (auto &c : vowels)
    if (str1[str1.size() - 1] == c) return true;
  return false;
}

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  if (str1[str1.size() - 1] == 'x' && str1[str1.size() - 2] == 'e')
    cout << str1 << str2 << endl;
  else if (check(str1)) {
    str1.pop_back();
    cout << str1 << "ex" << str2 << endl;

  } else if (str1[str1.size() - 1] == 'e')
    cout << str1 << "x" << str2 << endl;
  else
    cout << str1 << "ex" << str2 << endl;

  return 0;
}