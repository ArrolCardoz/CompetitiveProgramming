#include <bits/stdc++.h>
using namespace std;
map<string, int> p;
map<string, string> name;

void solution() {
  int n, m;
  cin >> n >> m;
  string str1, str2, str;
  string temp1, temp2;
  char char1, char2;
  for (int i = 0; i < n; i++) {
    cin >> char1 >> str1 >> char2 >> str2;
    temp1 = char1;
    temp2 = char2;
    str = temp1 + temp2;
    p[str]++;
    name[str] = temp1 + str1 + " " + temp2 + str2;
  }
  //   for (auto &it : name) cout << it.first << ' ' << it.second << endl;
  //   cout << endl << endl << endl << endl;
  for (int i = 0; i < m; i++) {
    cin >> str1;
    if (p[str1] > 1)
      cout << "ambiguous" << endl;
    else if (p[str1] == 1)
      cout << name[str1] << endl;
    else
      cout << "nobody" << endl;
  }
}

int main() {
  solution();
  return 0;
}
