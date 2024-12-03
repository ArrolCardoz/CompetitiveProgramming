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
  cout << a << " * " << b;
  return a * b;
}

int main() {
  string str;
  long long ans = 0;
  while (getline(cin, str)) {  // Read entire line of corrupted memory
    long long counter = 0;
    long long previousCounter = 0;
    int doCtr = 0;
    int dontCtr = 0;
    string substring;

    while ((counter = str.find("mul", counter)) != string::npos) {
      substring = str.substr(previousCounter, counter - previousCounter);

      // Find the most recent do() and don't()
      doCtr = substring.rfind("do()");
      dontCtr = substring.rfind("don't()");

      // Print the current substring and the positions of do() and don't()
      cout << "Substring: " << substring << endl;
      cout << "doCtr: " << doCtr << " dontCtr: " << dontCtr << endl;

      counter += 3;  // Move past "mul"
      long long temp = findNum(str, counter);
      if (doCtr == -1 && dontCtr == -1) doCtr = 1;
      if (doCtr >= dontCtr && doCtr != string::npos) {
        previousCounter = counter;

        ans += temp;
        cout << " = " << ans << endl;
      }

      if (doCtr >= dontCtr && temp > 0) previousCounter = counter;
      doCtr = 0;
      dontCtr = 0;
    }
  }

  cout << "ANS: " << ans << endl;
  return 0;
}
