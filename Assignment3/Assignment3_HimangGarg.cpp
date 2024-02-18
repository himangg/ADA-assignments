#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(ll m,ll n, vector<vector<ll>> v) {
    vector<vector<ll>> dp={};
    for(int i=0;i<m;i++){
        vector<ll> temp={};
        for(int j=0;j<n;j++){
            temp.push_back(-1);
        }
        dp.push_back(temp);
    }
    for(int h=0;h<m;h++) {
        for (int i = 0; i < n; i++) {
            vector<ll> temp = {v[h][i]};
            for( int k=0 ; k<h ; k++ ) {
                temp.push_back(dp[k][i]+dp[h-k-1][i]);
            }
            for (int j=0; j < i; j++) {
                temp.push_back(dp[h][j]+dp[h][i-j-1]);
            }
            dp[h][i] = *max_element(temp.begin(), temp.end());
        }
    }

    for(int h=0;h<m;h++) {
        for (int i = 0; i < n; i++) {
            cout<<dp[h][i]<<' ';
        }
    }
    cout<<endl<<"ANSWER: "<<dp[m-1][n-1];
}

int main() {
    int m,n;
    m=3;n=3;
    vector<vector<ll>> v={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    solve(m,n,v);
    return 0;
}
