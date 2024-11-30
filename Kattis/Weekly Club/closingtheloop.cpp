#include <bits/stdc++.h>
using namespace std;

void solution(int caseNum) {
  int num, n;
  vector<int> blue, red;
  char colour;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num >> colour;
    if (colour == 'R')
      red.push_back(num);
    else
      blue.push_back(num);
  }
  sort(blue.rbegin(), blue.rend());
  sort(red.rbegin(), red.rend());
  int counter = 0;
  int index = 0;
  int ans = 0;
  //   cout << "hi" << endl;
  while (blue.size() > index && red.size() > index) {
    ans += blue[index];
    ans += red[index];
    counter += 2;
    index++;
  }
  cout << "Case #" << caseNum << ": " << (ans - counter) << endl;
}
int main() {
  int n;
  cin >> n;
  int num;
  for (int i = 1; i <= n; i++) {
    solution(i);
  }
  return 0;
}