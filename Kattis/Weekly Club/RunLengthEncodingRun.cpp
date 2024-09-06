#include <bits/stdc++.h>
using namespace std;
// https://open.kattis.com/contests/pbp5vv/problems/runlengthencodingrun
void encoding() {
  string str;
  cin >> str;
  char prevChar = str[0];
  int counter = 0;

  for (auto &it : str) {
    // cout << it << endl << endl;
    if (prevChar == it) {
      counter++;
    } else {
      cout << prevChar << counter;
      prevChar = it;
      counter = 1;
    }
  }
  cout << prevChar << counter;
}

void decode() {
  string str;
  cin >> str;
  int pointer = -1;
  char numStr, word;
  int num;
  int loop = str.size() / 2;
  while (loop) {
    word = str[++pointer];
    numStr = str[++pointer];
    num = numStr - '0';

    for (int i = 0; i < num; i++) cout << word;
    loop--;
  }
}
int main() {
  char func;
  cin >> func;
  // getline(cin, input);
  if (func == 'E')
    encoding();
  else
    decode();
  return 0;
}