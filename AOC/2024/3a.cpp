#include <bits/stdc++.h>
using namespace std;

long long findNum(string &str, long long &counter) {
  if (str[counter] != '(') return 0;
  counter++;  // Move past '('

  long long a = 0, b = 0;

  while (isdigit(str[counter])) {
    a = a * 10 + (str[counter] - '0');
    counter++;
  }

  // Check for a comma
  if (str[counter] != ',' || a == 0) return 0;
  counter++;  // Move past ','

  while (isdigit(str[counter])) {
    b = b * 10 + (str[counter] - '0');
    counter++;
  }

  if (str[counter] != ')' || b == 0) return 0;
  counter++;  // Move past ')'

  return a * b;
}

int main() {
  string str;
  long long ans = 0;
  while (cin >> str) {
    long long counter = 0;

    while ((counter = str.find("mul", counter)) != string::npos) {
      counter += 3;  // Move past "mul"
      long long temp = findNum(str, counter);
      ans += temp;
    }
  }
  cout << "ANS: " << ans << endl;
  return 0;
}
