#include <bits/stdc++.h>
using namespace std;

void solution(int n) {
  int r;
  int c;
  cin >> r >> c;

  vector<string> str;
  for (int i = 0; i < r; i++) {
    string temp;
    cin >> temp;
    str.push_back(temp);
  }
  cout << "Test " << n << endl;
  for (int i = r - 1; i >= 0; i--) {
    for (int j = c - 1; j >= 0; j--) {
      cout << str[i][j];
    }
    cout << endl;
  }
}
int main() {
  int test;
  cin >> test;
  for (int i = 1; i <= test; i++) solution(i);
}