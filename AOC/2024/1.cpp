#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vec1, vec2;
  int a, b;
  // while (cin >> a >> b) {
  //   vec1.push_back(a);
  //   vec2.push_back(b);
  // }
  // sort(vec1.begin(), vec1.end());
  // sort(vec2.begin(), vec2.end());
  int ans;
  // for (int i = 0; i < vec1.size(); i++) {
  //   ans += abs(vec1[i] - vec2[i]);
  // }
  // cout << ans;

  map<int, int> count1, count2;

  while (cin >> a >> b) {
    vec1.push_back(a);
    vec2.push_back(b);
    count1[a]++;
    count2[b]++;
  }
  for (int i = 0; i < vec1.size(); i++) {
    ans += (count2[vec1[i]] * vec1[i]);
    cout << count2[vec1[i]] << " " << vec1[i] << endl;
  }

  cout << ans;
  return 0;
}