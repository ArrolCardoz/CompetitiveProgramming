#include <bits/stdc++.h>
using namespace std;

int main() {
  int total;
  cin >> total;
  int seen = 0;
  int notSeen = total;
  vector<int> cardsSeen(total, 0);
  unordered_map<string, int> faceSeen;

  int n;
  cin >> n;
  while (n--) {
    int c1, c2;
    string str1, str2;
    cin >> c1 >> c2 >> str1 >> str2;
    c1--;
    c2--;

    if (!cardsSeen[c1]) {
      faceSeen[str1]++;
      cardsSeen[c1]++;
      seen++;
      notSeen--;
    }
    if (!cardsSeen[c2]) {
      faceSeen[str2]++;
      cardsSeen[c2]++;
      seen++;
      notSeen--;
    }
    if (str1 == str2) {
      faceSeen[str1] = 3;
      seen -= 2;
      cardsSeen[c1]++;
      cardsSeen[c2]++;
    }
  }
  //   for (auto& it : cardsSeen) cerr << it << ' ';
  //   cerr << endl;
  int ans = 0;
  for (auto& it : faceSeen) {
    if (it.second == 2) {
      ans++;
      it.second++;
      seen -= 2;
    }
  }
  if (seen >= notSeen) {
    ans += (seen + notSeen) / 2;
  } else if (seen == 0 && notSeen == 2)
    ans++;
  cout << ans << endl;
  return 0;
}