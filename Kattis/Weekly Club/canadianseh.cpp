#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  getline(cin, str);
  string s = str.substr(str.size() - 3);
  //   cerr << s << '"' << "eh?" << endl;
  if (s == "eh?")
    cout << "Canadian!" << endl;
  else
    cout << "Imposter!" << endl;
  return 0;
}