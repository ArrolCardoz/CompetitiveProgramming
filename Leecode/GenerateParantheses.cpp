// 22
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
void generateString(int openCtr, int closedCtr, string str,
                    vector<string>& ans) {
  // cout << openCtr << " - Open " << closedCtr << " - Closed" << endl;
  if (openCtr == 0 && closedCtr == 0) {
    // cout << "BREAK" << endl;
    ans.push_back(str);
  } else {
    if (openCtr > 0) {
      // cout << openCtr << " > 0" << endl;
      // str.push_back('(')
      // openCtr--;
      generateString(openCtr - 1, closedCtr, str + '(', ans);
    }
    if (closedCtr > 0 && openCtr < closedCtr) {
      // cout << closedCtr << "> 0 &&" << openCtr << "<" << closedCtr << endl;

      // cout << "closed" << closedCtr << " " << openCtr << endl;
      // closedCtr--;
      generateString(openCtr, closedCtr - 1, str + ')', ans);
    }
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> ans;
  string str = "";
  generateString(n, n, str, ans);
  // cout << "SIZE " << ans.size() << endl;
  return ans;
}

int main() {
  int n = 3;
  for (auto& it : generateParenthesis(n)) cout << it << " ";
  return 0;
}
