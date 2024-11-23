// 125
#include <bits/stdc++.h>
using namespace std;
bool checkAlphaNum(char &ch) {
  if (ch >= 'A' && ch <= 'Z') ch = tolower(ch);
  if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')) return true;
  return false;
}
bool soultion(string str) {
  int startPtr = 0;
  int endPtr = str.size() - 1;
  while (startPtr < endPtr) {
    // cout << str[startPtr] << " " << str[endPtr] << endl;
    if (!checkAlphaNum(str[startPtr])) {
      startPtr++;
      continue;
    }
    if (!checkAlphaNum(str[endPtr])) {
      endPtr--;
      continue;
    }
    cout << endPtr << endl;
    // check if equal
    if (str[startPtr] == str[endPtr]) {
      startPtr++;
      endPtr--;
      continue;
    }
    return false;
  }
  return true;
}

int main() {
  string str = "A man, a plan, a canal: Panama";
  if (soultion(str))
    cout << "True";
  else
    cout << "False" << endl;

  return 0;
}