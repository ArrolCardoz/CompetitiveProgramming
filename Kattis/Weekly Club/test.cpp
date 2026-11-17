#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  map<char, int> freqTable;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    char c = s[i];
    int start = i + 1;
    int end = start;
    while ((end < n) && (s[end] < 'a')) end++;
    end--;
    string subStrOfInt = s.substr(start, end);
    cerr << subStrOfInt << endl;
    int freqOfChar = stoi(subStrOfInt);
    freqTable[c] += freqOfChar;
    i = end;
  }
  string ans = "";
  for (auto& [m, n] : freqTable) {
    ans += m;
    ans += to_string(n);
  }
  cout << ans << endl;
  return 0;
}