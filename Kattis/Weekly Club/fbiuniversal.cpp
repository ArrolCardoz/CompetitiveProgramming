#include <bits/stdc++.h>
using namespace std;

int checkChar(string str, unordered_map<char, int> base27) {
  //   cout << (2 * base27[str[7]]) << "+" << (4 * base27[str[6]]) << "+"
  //        << (5 * base27[str[5]]) << "+" << (7 * base27[str[4]]) << "+"
  //        << (8 * base27[str[3]]) << "+" << (10 * base27[str[2]]) << "+"
  //        << (11 * base27[str[1]]) << "+" << (12 * base27[str[0]]) << '%' <<
  //        27;

  //   cout << '='
  //        << ((2 * base27[str[7]]) + (4 * base27[str[6]]) + (5 *
  //        base27[str[5]]) +
  //            (7 * base27[str[4]]) + (8 * base27[str[3]]) + (10 *
  //            base27[str[2]]) + (11 * base27[str[1]]) + (12 * base27[str[0]]))
  //            %
  //               27
  //        << endl;

  //   return ((2 * base27[str[7]]) + (4 * base27[str[6]]) + (5 *
  //   base27[str[5]]) +
  //           (7 * base27[str[4]]) + (8 * base27[str[3]]) + (10 *
  //           base27[str[2]]) + (11 * base27[str[1]]) + (12 * base27[str[0]]))
  //           %
  //          27;
  //   cout << ((2 * base27[str[0]]) + (4 * base27[str[1]]) + (5 *
  //   base27[str[2]]) +
  //            (7 * base27[str[3]]) + (8 * base27[str[4]]) + (10 *
  //            base27[str[5]]) + (11 * base27[str[6]]) + (13 * base27[str[7]]))
  //            %
  //               27
  //        << endl;

  return ((2 * base27[str[0]]) + (4 * base27[str[1]]) + (5 * base27[str[2]]) +
          (7 * base27[str[3]]) + (8 * base27[str[4]]) + (10 * base27[str[5]]) +
          (11 * base27[str[6]]) + (13 * base27[str[7]])) %
         27;
}

void checkConfusingDigits(string& str) {
  unordered_map<char, char> check = {{'B', '8'}, {'G', 'C'}, {'I', '1'},
                                     {'O', '0'}, {'Q', '0'}, {'S', '5'},
                                     {'U', 'V'}, {'Y', 'V'}, {'Z', '2'}};
  for (int i = 0; i < str.size(); i++) {
    if (check.find(str[i]) != check.end()) str[i] = check[str[i]];
  }
}
void solution(int k, string str) {
  string strInitilize = "0123456789ACDEFHJKLMNPRTVWX";
  unordered_map<char, int> base27;
  for (int i = 0; i < 27; i++) {
    base27[strInitilize[i]] = i;
  }
  checkConfusingDigits(str);

  // check checkChar
  //   cout << "============= " << checkChar(str, base27) << " " << str << endl;
  if (checkChar(str, base27) != base27[str[8]]) {
    cout << k << ' ' << "Invalid" << endl;
    return;
  }
  long long power = 1;
  long long ans = 0;
  for (int i = 7; i >= 0; i--) {
    if (i == 7) {
      ans += base27[str[i]];
      //   cout << power << endl;

      continue;
    }
    power *= 27;
    ans += power * base27[str[i]];
    // cout << power << endl;
  }
  cout << k << ' ' << ans << endl;
  return;
}
int main() {
  int n, k;
  string str;
  cin >> n;
  while (n--) {
    cin >> k >> str;
    solution(k, str);
  }
  return 0;
}