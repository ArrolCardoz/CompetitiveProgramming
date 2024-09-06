#include <bits/stdc++.h>
using namespace std;

void solution() {}

int main() {
  int n;
  cin >> n;
  vector<int> answer;

  while (n != 0) {
    map<int, int> m1;
    map<int, int> Sortedm1;

    vector<int> arr;
    vector<int> arr2;

    int num;
    for (int i = 0; i < n; i++) {
      cin >> num;
      m1[i] = num;
      arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    for (auto &it : arr) {
      Sortedm1[arr[i]] = i;
      i++;
    }

    for (int i = 0; i < n; i++) {
      cin >> num;
      arr2.push_back(num);
    }
    sort(arr2.begin(), arr2.end());

    for (int i = 0; i < n; i++) {
      answer.push_back(arr2[Sortedm1[m1[i]]]);
    }
    answer.push_back(11111);

    cin >> n;
  }
  for (auto &it : answer) {
    if (it != 11111)
      cout << it << endl;
    else
      cout << endl;
  }
  return 0;
}