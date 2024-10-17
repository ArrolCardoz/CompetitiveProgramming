#include <iostream>
#include <stack>
#include <string>

using namespace std;

string simplifyPath(string path) {
  string fileName = "";
  stack<string> stk;

  for (int i = 0; i < path.size(); i++) {
    // cout << stk.size() << "SIZE++++" << endl;
    string str = "";

    if (path[i] == '/') {
      if (path[i + 1] == '.' && path[i + 2] == '.' && path[i + 3] == '/') {
        // cout << "DOT================" << endl;
        if (!stk.empty()) {
          //   cout << "YES" << endl;
          int n = (stk.top()).size() + 1;
          //   cout << n << " N" << endl;
          while (n != 0) {
            fileName.pop_back();
            n--;
            // cout << fileName << endl;
          }
          stk.pop();
          i += 2;
        } else {
          i += 2;
        }
        i++;
      }
      if (path[i + 1] == '.' && path[i + 2] == '/') {
        if (stk.empty()) {
          i++;
        }
        i++;
      }
      if (path[i - 1] != '/') fileName += '/';
      //   cout << i << endl;
      i++;
      while (path[i] != '/' && i < path.size()) {
        // cout << i << endl;

        // cout << path[i] << endl;

        str += path[i];
        i++;
      }
      //   cout << str << endl;
      stk.push(str);
      fileName += str;
      if (i != path.size() - 1) i--;
    }
  }
  return fileName;
}

int main() {
  string path = "../include/Angel.h";
  cout << simplifyPath(path);
  return 0;
}
