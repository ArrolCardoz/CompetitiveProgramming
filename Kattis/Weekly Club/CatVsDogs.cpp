#include <bits/stdc++.h>
using namespace std;

int solution() {
  map<int, int> cat;
  map<int, int> badcat;

  map<int, int> dog;
  map<int, int> baddog;

  int dognum, catnum, n;

  int a, x;
  char b, y;
  cin >> catnum >> dognum >> n;
  if (n == 0) return 0;
  bool isTrue = true;
  for (int i = 0; i < n; i++) {
    cin >> b >> a >> y >> x;

    if (b == 'C') {
      isTrue = true;
      if (a > catnum) isTrue = false;
      if (isTrue) {
        cat[a]++;
        badcat[a]++;
      }
    } else {
      isTrue = true;
      if (a > dognum) isTrue = false;

      if (isTrue) {
        dog[a]++;
        baddog[a]++;
      }
    }
    // cout << baddog.size() << endl;
    // for (auto &it : baddog) cout << it.first << " " << it.second << endl;

    if (y == 'C') {
      isTrue = true;
      if (x > catnum) isTrue = false;
      if (isTrue) badcat[x]--;
    } else {
      isTrue = true;
      if (x > dognum) isTrue = false;

      if (isTrue) baddog[x]--;
    }
  }
  int catMax = -1, dogMax = -1;
  // for (auto &it : baddog) cout << it.first << " " << it.second << endl;
  //  for (auto &it : badcat) cout << it.first << " " << it.second << endl;

  int indexcat = -1, indexdog = -1;
  for (auto &it : badcat) {
    if (catMax < it.second) {
      indexcat = it.first;
      catMax = it.second;
    }
  }
  for (auto &it : baddog) {
    if (dogMax < it.second) {
      indexdog = it.first;
      dogMax = it.second;
    }
  }
  // cout << endl << indexcat << " " << indexdog << endl;
  // cout << endl << catMax << " " << dogMax << endl;
  int addcat = -1;
  int adddog = -1;
  for (auto &it : badcat) {
    if (catMax == it.second) {
      addcat++;
    }
  }
  for (auto &it : baddog) {
    if (dogMax == it.second) {
      adddog++;
    }
  }
  // cout << adddog << ' ' << badcat[indexcat] << "==" << baddog[indexcat] << '
  // '
  //  << addcat << endl;
  int ans;
  if (badcat[indexcat] == (baddog[indexdog]))
    ans = max((cat[indexcat]), (dog[indexdog])) + addcat + adddog;
  else if (badcat[indexcat] > (baddog[indexdog]))
    ans = (cat[indexcat]) + addcat;
  else
    ans = (dog[indexdog]) + adddog;
  return ans;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << solution() << endl;
  }
  return 0;
}
