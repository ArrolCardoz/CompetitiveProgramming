#include <bits/stdc++.h>
using namespace std;
void solution(set<char> s) {
  string str;
  getline(cin, str);
  for (auto& it : str) {
    if (it < 'A' || it > 'z') continue;
    char curr = tolower(it);
    s.erase(curr);
  }

  if (s.empty())
    cout << "pangram" << endl;
  else {
    cout << "missing ";
    for (auto& it : s) cout << it;
    cout << endl;
  }
}

void init(set<char>& s) {
  for (int i = 0; i < 26; i++) {
    s.insert(i + 'a');
  }
}

int main() {
  int n;
  set<char> aToz;
  cin >> n;
  cin.ignore(100, '\n');
  init(aToz);
  while (n--) solution(aToz);
  return 0;
}