#include <bits/stdc++.h>
using namespace std;

int convertMax(string str) {
  for (auto& it : str) {
    if (it == '0') it = 'D';
    if (it == '8') it = 'B';
  }
  cerr << str << endl;
  return stoi(str, nullptr, 16);
}

int convertMin(string str) {
  if (str.size() < 4) return 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'D' && i > 0) str[i] = '0';
    if (str[i] == '0' && i == 0) str[i] = '';

    if (str[i] == 'B') str[i] = '8';
  }
  cerr << str << endl;

  return stoi(str, nullptr, 16);
}

int main() {
  int n;
  cin >> n;
  string str;
  long long max = 0, min = 0;
  while (n--) {
    cin >> str;
    max += (convertMax(str));
    min += (convertMin(str));
  }
  cout << hex << uppercase << max << endl;
  cout << hex << uppercase << min << endl;
  return 0;
}