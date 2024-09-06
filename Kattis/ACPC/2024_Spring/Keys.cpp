#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  bool haveKeys = false, havePhone = false, haveWallet = false;
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (str == "phone") havePhone = true;
    if (str == "wallet") haveWallet = true;
    if (str == "keys") haveKeys = true;
  }
  if (haveKeys && havePhone && haveWallet) cout << "ready" << endl;
  if (!haveKeys) cout << "keys" << endl;
  if (!havePhone) cout << "phone" << endl;
  if (!haveWallet) cout << "wallet" << endl;
}

int main() {
  solution();
  return 0;
}
