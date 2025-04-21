#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> arrows;
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;

    if (arrows[h] > 0) {
      arrows[h]--;
      arrows[h - 1]++;
    } else {
      ans++;
      arrows[h - 1]++;
    }
  }

  cout << ans << endl;
  return 0;
}
