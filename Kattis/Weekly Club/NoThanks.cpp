#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
  vector<int> arr;
  int ans = 0;
  int input;

  for (int i = 0; i < n; i++) {
    cin >> input;
    arr.push_back(input);
  }
  sort(arr.begin(), arr.end());
  ans += arr[0];
  for (int i = 1; i < n; i++) {
    if ((arr[i - 1] + 1) == arr[i]) {
      // cout << arr[i - 1] << " " << arr[i] << endl;
      continue;
    }
    // cout << arr[i] << endl;
    ans += arr[i];
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << solution(n);
  return 0;
}