#include <bits/stdc++.h>
using namespace std;

void soultion() {
  int inFreq[26] = {0}, outFreq[26] = {0};
  int n;
  int match = 0;
  int position = 0;
  cin >> n;
  string input, output;
  cin >> input >> output;
  for (int i = 0; i < n; i++) {
    if (input[i] == output[i]) {
      match++;
      continue;
    }
    inFreq[input[i] - 'A']++;
    outFreq[output[i] - 'A']++;
  }
  for (int i = 0; i < 26; i++) {
    if (inFreq[i] > 0 && outFreq[i] > 0) position += min(inFreq[i], outFreq[i]);
  }
  cout << match << " " << position;
}

int main() {
  soultion();
  return 0;
}