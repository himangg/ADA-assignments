#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(ll n, vector<ll> v) {
    vector<vector<ll>> dp(n, vector<ll>(2, 0));

    dp[0][0] = v[0];
    dp[0][1] = -v[0];
    dp[1][0] = max(v[0] + v[1], -v[0] + v[1]);
    dp[1][1] = max(-v[0] - v[1], v[0] - v[1]);
    dp[2][0] = max(v[0]+v[1]+v[2],max(dp[0][1]+v[1]+v[2],dp[1][1]+v[2]));
    dp[2][1] = max(-v[0]-v[1]-v[2],max(dp[0][0]-v[1]-v[2],dp[1][0]-v[2]));

    for (ll i = 3; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1] + v[i], max(dp[i - 2][1] + v[i - 1] +v[i], dp[i - 3][1] + v[i-2]+ v[i - 1] + v[i]));
        dp[i][1] = max(dp[i - 1][0] - v[i], max(dp[i - 2][0] - v[i - 1] -v[i], dp[i - 3][0] - v[i-2] - v[i - 1] - v[i]));
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
    vector<ll> v = {1,-2,3,-4,5,6,7,8};
    solve(v.size(), v);
    return 0;
}
