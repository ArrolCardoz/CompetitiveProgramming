#include <bits/stdc++.h>
using namespace std;

string reverseWords(string str) {
  reverse(str.begin(), str.end());  // adjust the order of the word
  string answer = "";
  string word = "";
  for (int i = 0; i < str.size(); i++) {  // adjust the form of the word
    if (str[i] != ' ')
      word += str[i];
    else {
      if (word.length() > 0) {
        reverse(word.begin(), word.end());
        //   cout << word << endl;
        answer += " " + word;
        word = "";
      }
    }
  }
  if (word.length() > 0) {
    reverse(word.begin(), word.end());
    answer += " " + word;
  }
  return answer.substr(1);
}

int main() {
  string str = "  hello world  ";
  cout << reverseWords(str) << endl;
  return 0;
}