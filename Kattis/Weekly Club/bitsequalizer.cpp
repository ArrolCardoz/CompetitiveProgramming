#include <bits/stdc++.h>
using namespace std;

int solution(string s, string t) {
  int ans = 0;
  unordered_map<char, int> freqs, freqt;
  for (auto& it : s) freqs[it]++;
  for (auto& it : t) freqt[it]++;
  if (freqs['0'] + freqs['?'] < freqt['0']) return -1;
  if (freqs['1'] > freqt['1']) return -1;

  // clear all ?
  while (freqs['?']) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '?') {
        ans++;
        freqs['?']--;
        if (t[i] == '1' && freqs['1'] < freqt['1']) {
          s[i] = '1';
          freqs['1']++;
        } else {
          s[i] = '0';
          freqs['0']++;
        }
      }
      //   cerr << s << endl;
    }
  }
  if (s == t) return ans;
  // swap
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) {
      for (int j = i; j < s.size(); j++) {
        if (s[j] != t[j] && s[i] != s[j]) {
          char temp = s[i];
          s[i] = s[j];
          s[j] = temp;
          ans++;
          break;
        }
      }
      //   cerr << s << endl;
    }
  }
  return ans;
}

int main() {
  int n;
  int ctr = 1;
  cin >> n;
  while (n--) {
    string s, t;
    cin >> s >> t;
    cout << "Case " << ctr << ": " << solution(s, t) << endl;
    ctr++;
  }
}