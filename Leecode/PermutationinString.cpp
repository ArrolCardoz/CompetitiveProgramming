// 567

#include <bits/stdc++.h>
using namespace std;
bool checkFreq(int s1[], int s2[]) {
  for (int i = 0; i < 26; i++) {
    if (s1[i] != s2[i]) return false;
  }
  return true;
}
bool checkInclusion(string s1, string s2) {
  int feqStr[26] = {0};

  for (int i = 0; i < s1.length(); i++) {
    feqStr[s1[i] - 'a']++;
  }

  int windowSize = s1.length();
  for (int i = 0; i < s2.length(); i++) {
    int windowInd = 0;

    int index = i;
    int feqWin[26] = {0};

    while (windowInd < windowSize && index < s2.length()) {
      feqWin[s2[index] - 'a']++;
      index++;
      windowInd++;
    }
    if (checkFreq(feqStr, feqWin)) return true;
  }

  return false;
}

int main() {
  string s1 = "ab";
  string s2 = "eidaboo";
  if (checkInclusion(s1, s2))
    cout << "True";
  else
    cout << "False";

  return 0;
}
