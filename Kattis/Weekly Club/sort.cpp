#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  getline(cin, str);
  stringstream ss(str);
  vector<double> A;
  double input;
  char temp;
  while (ss >> input) {
    ss >> temp;
    A.push_back(input);
  }
  sort(A.begin(), A.end());
  for (auto& it : A) cout << it << ' ';
  return 0;
}