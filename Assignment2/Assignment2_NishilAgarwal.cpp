#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(ll n, vector<ll> booth) {
    vector<vector<ll>> dp(n, vector<ll>(2, 0));

    dp[0][0] = booth[0];
    dp[0][1] = -booth[0];
    dp[1][0] = max(booth[0], -booth[0])+booth[1];
    dp[1][1] = max(-booth[0], booth[0])-booth[1];
    dp[2][0] = max(booth[0]+booth[1],max(dp[0][1]+booth[1],dp[1][1]))+booth[2];
    dp[2][1] = max(-booth[0]-booth[1],max(dp[0][0]-booth[1],dp[1][0]))-booth[2];

    for (ll i = 3; i < n; i++) {
        dp[i][0] = max(dp[i-1][1], max(dp[i-2][1] + booth[i-1], dp[i-3][1] + booth[i-2]+ booth[i-1])) +booth[i];
        dp[i][1] = max(dp[i-1][0], max(dp[i-2][0]-booth[i-1], dp[i-3][0]-booth[i-2]-booth[i-1])) -booth[i];
    }

    cout << max(dp[n-1][0], dp[n-1][1]);
}

int main() {
    vector<ll> booth = {1,9,9,-1,9,9,1,9,9};
    solve(booth.size(), booth);
}
