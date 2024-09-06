#include <bits/stdc++.h>
using namespace std;

void solution(string a, string b) {
  string answer;

  int num = count(b.begin(), b.end(), '0');
  int num2 = (a.size() - num);
  bool dot = true, isTrue = true;

  for (auto i = a.end() - 1; i >= a.begin() || num > 0; i--) {
    if (num == 0) {
      dot = false;
      answer += '.';
    }

    num--;

    if (isTrue)
      answer += *i;
    else
      answer += '0';
    if (i == a.begin()) isTrue = false;
  }
  if (dot) {
    answer.push_back('.');
  }

  reverse(answer.begin(), answer.end());

  // cout << answer << endl;  // adds and removes 0 || .
  if (*answer.begin() == '.') answer = '0' + answer;
  auto it = answer.end() - 1;
  if (*it == '.') {
    answer.pop_back();
    *it--;
  }

  for (; it > answer.begin(); it--) {
    if (*it == '0') {
      answer.pop_back();

        } else {
      break;
    }
  }

  auto ite = answer.end() - 1;
  if (*ite == '.') answer.pop_back();

  cout << answer;
}

int main() {
  string a, b;
  cin >> a >> b;
  solution(a, b);
}