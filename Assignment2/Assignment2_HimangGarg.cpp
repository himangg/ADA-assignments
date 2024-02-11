#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll maxOfTwo(ll a,ll b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

ll maxOfThree(ll a,ll b,ll c){
    if(a>b){
        if(a>c) {
            return a;
        }
        else{
            return c;
        }
    }
    else{
        if(b>c) {
            return b;
        }
        else{
            return c;
        }
    }
}

void solve(ll n, vector<ll> v) {
    vector<vector<ll>> dp(n, vector<ll>(2, 0));

    dp[0][0] = v[0];
    dp[0][1] = -v[0];
    dp[1][0] = maxOfTwo(v[0] + v[1], -v[0] + v[1]);
    dp[1][1] = maxOfTwo(-v[0] - v[1], v[0] - v[1]);
    dp[2][0] = maxOfThree(v[0]+v[1]+v[2],dp[0][1]+v[1]+v[2],dp[1][1]+v[2]);
    dp[2][1] = maxOfThree(-v[0]-v[1]-v[2],dp[0][0]-v[1]-v[2],dp[1][0]-v[2]);

    for (ll i = 3; i < n; i++) {
        dp[i][0] = maxOfThree(dp[i - 1][1] + v[i], dp[i - 2][1] + v[i - 1] +v[i], dp[i - 3][1] + v[i-2]+ v[i - 1] + v[i]);
        dp[i][1] = maxOfThree(dp[i - 1][0] - v[i], dp[i - 2][0] - v[i - 1] -v[i], dp[i - 3][0] - v[i-2] - v[i - 1] - v[i]);
    }

    cout << maxOfTwo(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
    vector<ll> v = {1,-2,3,-4,5,6,7,8};
    solve(v.size(), v);
    return 0;
}
