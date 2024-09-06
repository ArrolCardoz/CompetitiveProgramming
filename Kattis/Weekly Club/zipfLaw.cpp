#include <bits/stdc++.h>
using namespace std;

void solution(int n) {
  bool loop = true;
  map<string, int> m;
  bool existAnswer = false;
  while (loop) {
    string str;
    getline(cin, str);
    if (str == "EndOfText") break;

    for (auto &it : str) {
      if (!isalpha(it)) it = ' ';
      tolower(it);
    }
    stringstream ss(str);
    string word;
    while (cin >> word) m[word]++;
  }
  for (auto &it : m) {
    if (it.second == n) {
      cout << it.first << endl;
      existAnswer = true;
    }
  }
  if (!existAnswer) cout << "There is no such word.";
}

int main() {
  int n;
  if (!cin >> n) cout << "There is no such word.";

  return 0;
}