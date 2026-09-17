#include <bits/stdc++.h>
using namespace std;

void solution(string input, int byteSize, string form, int n) {
  string a, b;
  int numOfBytes = n / 8;
  vector<string> bytes(numOfBytes);
  int curr = 0;

  while (numOfBytes--) {
    string tempInput = input.substr(curr, byteSize);
    bytes.push_back(tempInput);
    curr += byteSize;
  }
  reverse(bytes.begin(), bytes.end());
  cout << form;
  for (auto& it : bytes) {
    cout << it;
  }
  cout << endl;
}

int main() {
  char from, to;
  int n, byteSize = 0;
  bool isBinary = false;
  string input, form, byte;
  cin >> from >> to >> n >> input;
  form = input.substr(0, 2);
  input = input.substr(2);

  isBinary = (form[1] == 'b');

  if (isBinary) {
    byteSize = 8;
  } else {
    byteSize = 2;
  }
  // convert to same form
  if (to == from) {
    cout << input << endl;
  } else {
    solution(input, byteSize, form, n);
  }

  return 0;
}