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
            for (int j = -1; j < i; j++) {
                for( int k=-1 ; k<h ; k++ ) {
                    if(j==-1 && k==-1){
                        continue;
                    }
                    else if(k==-1) {
                        temp.push_back(dp[h][j] + dp[h][i - j - 1]);
                    }
                    else if(j==-1){
                        temp.push_back(dp[k][i] + dp[h-k-1][i]);
                    }
                    else{
                        temp.push_back(dp[k][j]+dp[h-k-1][j]+dp[k][i-j-1]+dp[h-k-1][i-j-1]);
                    }
                }
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
    m=2;n=3;
    vector<vector<ll>> v={{2,4,1},{4,1,3}};
    solve(m,n, v);
    return 0;
}
