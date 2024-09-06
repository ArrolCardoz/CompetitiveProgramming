#include <bits/stdc++.h>
using namespace std;

void solution() {
  double money, bet, answer;
  char sign;
  cin >> money >> bet >> sign;

  if (sign == '+')
    answer = (bet * (money / 100));
  else
    answer = (money * 100 / bet);
  cout << fixed << setprecision(5) << answer << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solution();
  return 0;
}
