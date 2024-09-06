#include <bits/stdc++.h>
using namespace std;
bool solution(int x) {
  bool isTrue = true;
  if (x < 0) return false;
  string num = to_string(x);
  auto start = num.begin();
  auto end = num.end() - 1;
  for (int i = 0; i * i <= x; i++) {
    if (*start != *end) {
      isTrue = false;
      break;
    } else if (start == end || start > end)
      break;
    end--;
    start++;
  }
  return isTrue;
}

int main() {
  int x;
  cin >> x;
  cout << solution(x);
  return 0;
}