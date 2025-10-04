#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  while (true) {
    getline(cin, str);
    if (str == "I quacked the code!")
      break;
    else if (*(str.end() - 1) == '?')
      cout << "Quack!" << endl;
    else
      cout << "*Nod*" << endl;
  }
  return 0;
}