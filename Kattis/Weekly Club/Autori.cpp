#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
  string answer;
  for (auto i = s.begin(); i < s.end(); i++) {
    if (*i <= 'Z' && *i >= 'A') answer += *i;
  }
  return answer;
}

int main() {
  string s;
  cin >> s;
  cout << solution(s);
  return 0;
}