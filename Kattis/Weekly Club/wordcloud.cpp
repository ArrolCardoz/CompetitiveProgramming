#include <bits/stdc++.h>
using namespace std;

void solution(int cloudNum, int w, int n) {
  string str;
  int count;
  int maxHeight = 0;

  unordered_map<string, int> words;
  unordered_map<int, string> idWord;
  for (int i = 0; i < n; i++) {
    cin >> str >> count;
    if (count < 5) continue;
    maxHeight = max(count, maxHeight);
    words[str] = count;
    idWord[words.size() - 1] = str;
  }

  // compute point
  vector<int> point(words.size());
  for (int i = 0; i < words.size(); i++) {
    point[i] = 8 + ((40 * (words[idWord[i]] - 4) + (maxHeight - 4 - 1)) /
                    (maxHeight - 4));

    // cout << idWord[i] << ' ' << point[i] << endl;
  }
  vector<int> width(words.size());

  // width
  for (int i = 0; i < point.size(); i++) {
    width[i] = ((9 * idWord[i].size() * point[i]) + 15) / 16;

    // cout << ((9 * idWord[i].size() * point[i]) + 15) / 16 << endl;
  }
  int ans = 0;
  int maxPoint = 0;
  int temp = 0;
  for (int i = 0; i < point.size(); i++) {
    if (temp == 0)
      temp += width[i];
    else
      temp += width[i] + 10;

    if (temp > w) {
      ans += maxPoint;
      maxPoint = 0;
      temp = 0;
      temp += width[i];
    }
    // cout << temp << ' ' << idWord[i] << endl;
    maxPoint = max(maxPoint, point[i]);
  }
  ans += maxPoint;

  cout << "CLOUD " << cloudNum << ": " << ans << endl;
}

int main() {
  int a, b;
  int count = 1;
  cin >> a >> b;
  while (a != 0 && b != 0) {
    solution(count, a, b);
    cin >> a >> b;
    count++;
  }
  return 0;
}
