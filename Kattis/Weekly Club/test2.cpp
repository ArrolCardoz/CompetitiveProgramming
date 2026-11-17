#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  cout << ("128.0.0.0" < "127.255.255.255") << endl;
  return 0;
}

int match(int currentIp) {
  if (currentIp < 128) return 1;
  if (currentIp < 192) return 2;
  if (currentIp < 224) return 3;
  if (currentIp < 240) return 4;
  return 5;
}

vector<int> getRegions(vector<string> ip_addresses) {
  int n = (int)ip_addresses.size();
  vector<int> answer;
  answer.reserve(n);

  for (auto& it : ip_addresses) {
    stringstream ss(it);
    string currentNumStr;
    int firstOfCurrentIp = -1;

    int count = 0;
    bool isValid = true;
    while (getline(ss, currentNumStr, '.')) {
      count++;
      // checkleading 0
      if ((int)currentNumStr.size() > 1 && currentNumStr[0] == '0') {
        isValid = false;
        break;
      }
      // check between 0-255
      if (currentNumStr.empty() || currentNumStr.size() > 3) {
        isValid = false;
        break;
      }
      for (char c : currentNumStr) {
        if (!isdigit((unsigned char)c)) isValid = false;
      }
      if (!isValid || stoi(currentNumStr) < 0 || stoi(currentNumStr) > 255) {
        isValid = false;
        break;
      }
      // only 4 octals
      if (count > 4) {
        isValid = false;
        break;
      }
      // first octal
      if (isValid && (firstOfCurrentIp == -1)) {
        firstOfCurrentIp = stoi(currentNumStr);
      }
    }
    if (isValid) {
      int currentRegion = match(firstOfCurrentIp);
      answer.push_back(currentRegion);
    } else
      answer.push_back(-1);
  }
}