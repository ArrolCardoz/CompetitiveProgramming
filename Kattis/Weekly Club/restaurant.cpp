#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;

  while (cin >> n && n != 0) {
    int s1 = 0, s2 = 0;
    while (n--) {
      string str;
      int num;
      cin >> str >> num;
      if (str == "DROP") {
        cout << "DROP 2 " << num << endl;
        s2 += num;

            } else {
        if (s1 == 0) {
          cout << "MOVE 2->1 " << s2 << endl;
          cout << "TAKE 1 " << num << endl;
          s1 += s2;
          s2 = 0;
          s1 -= num;
        } else {
          // take all plates from take table
          if (s1 > num) {
            cout << "TAKE 1 " << num << endl;
            s1 -= num;
          } else {
            // if not enough plates
            cout << "TAKE 1 " << s1 << endl;
            s1 = 0;
            // move
            cout << "MOVE 2->1 " << s2 << endl;
            cout << "TAKE 1 " << num << endl;
            s1 += s2;
            s2 = 0;
            s1 -= num;
          }
        }
      }
    }
    cout << endl;
  }
}