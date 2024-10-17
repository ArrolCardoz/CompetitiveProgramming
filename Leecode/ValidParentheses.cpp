// 20
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool isValid(string str) {
  string s;
  stringstream ss(str);
  ss >> s;
  unordered_map<char, char> check;
  check['}'] = '{';
  check[']'] = '[';
  check[')'] = '(';

  stack<char> stk;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
      stk.push(s[i]);
    } else {
      if (stk.empty()) return false;
      if (check[s[i]] != stk.top()) return false;
      stk.pop();
    }
  }
  if (stk.empty()) return true;
  return false;
}

int main() {
  string s = {"]"};
  if (isValid(s))
    cout << "True";
  else
    cout << "false";
  return 0;
}