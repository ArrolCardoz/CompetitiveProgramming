#include <bits/stdc++.h>
using namespace std;

int main() {
  string note, tonality;
  unordered_map<string, string> table = {
      {"A", ""},    {"A#", "Bb"}, {"Ab", "G#"}, {"Bb", "A#"}, {"B", ""},
      {"C", ""},    {"C#", "Db"}, {"Db", "C#"}, {"D", ""},    {"D#", "Eb"},
      {"Eb", "D#"}, {"E", ""},    {"F", ""},    {"F#", "Gb"}, {"Gb", "F#"},
      {"G", ""},    {"G#", "Ab"}};
  int ctr = 1;

  while (cin >> note >> tonality) {
    string ans = table[note];

    if (ans == "")
      cout << "Case " << ctr << ": UNIQUE" << endl;
    else
      cout << "Case " << ctr << ": " << ans << " " << tonality << endl;
    ctr++;
  }
  return 0;
}