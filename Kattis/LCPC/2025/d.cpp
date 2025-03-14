#include <bits/stdc++.h>
using namespace std;

void solution() {}
int main() {
  int bricks;
  int n;
  int difference = 0;
  int least = 0;
  vector<int> layer;
  cin >> bricks >> n;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    cout << i << ' ' << temp << endl;
    layer.push_back(temp);
  }
  cout << "test" << endl;
  for (int i = 1; i < n; i++) {
    layer[i] += layer[i - 1];
    if (layer[i] < 2 * layer[i - 1] &&
        difference < layer[i] - 2 * layer[i - 1]) {
      least = i;
      difference = layer[i] - 2 * layer[i - 1];
    }
  }

  int ans = 0;
  for (int i = 0; bricks >= i * least; i++) {
    ans = layer[least] * i;
    int numBricks = 0;
    numBricks += least;
    if (numBricks > bricks) break;
  }

  cout << ans << endl;
  return 0;
}