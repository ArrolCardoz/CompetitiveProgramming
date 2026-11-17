#include <bits/stdc++.h>
using namespace std;
const int void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();


  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> solve(const vector<int>& packs, int maxS) {
    vector<int> dp(maxS + 1, INF);
    dp[0] = 0;
    for (int p : packs)
        for (int s = maxS; s >= p; s--)       // downward = each pack used at most once
            dp[s] = min(dp[s], dp[s - p] + 1);
    return dp;
}

int main() {
    int h, b;
    scanf("%d", &h);
    vector<int> dogs(h);
    for (auto& x : dogs) scanf("%d", &x);
    scanf("%d", &b);
    vector<int> buns(b);
    for (auto& x : buns) scanf("%d", &x);

    // no total can exceed the smaller of the two sums
    int sumH = accumulate(dogs.begin(), dogs.end(), 0);
    int sumB = accumulate(buns.begin(), buns.end(), 0);
    int maxS = min(sumH, sumB);

    vector<int> H = solve(dogs, maxS);
    vector<int> B = solve(buns, maxS);

    int ans = INF;
    for (int s = 1; s <= maxS; s++)
        if (H[s] < INF && B[s] < INF)
            ans = min(ans, H[s] + B[s]);

    if (ans == INF) puts("impossible");
    else printf("%d\n", ans);
}