#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> booths){
    vector<int> dp_end_at_ding(n,0);
    vector<int> dp_end_at_ring(n,0);

    dp_end_at_ring[0] = booths[0];
    dp_end_at_ding[0] = -booths[0];
    dp_end_at_ring[1] = max(dp_end_at_ring[0], dp_end_at_ding[0])+booths[1];
    dp_end_at_ding[1] = max(dp_end_at_ring[0], dp_end_at_ding[0])-booths[1];
    dp_end_at_ring[2] = max(dp_end_at_ring[1], dp_end_at_ding[1])+booths[2];
    dp_end_at_ding[2] = max(dp_end_at_ring[1], dp_end_at_ding[1])-booths[2];

    for (int i=3; i<n; i++) {
        dp_end_at_ring[i] = max(dp_end_at_ding[i-1], max(dp_end_at_ding[i-2]+booths[i-1], dp_end_at_ding[i-3]+booths[i-2]+booths[i-1]))+booths[i];
        //If the dp is ending at 'Ring' at Ith element, it must follow that at least 1 out of i-1,i-2,i-3th element is a Ding. Similarly for ending at Ding case :
        dp_end_at_ding[i] = max(dp_end_at_ring[i-1], max(dp_end_at_ring[i-2]-booths[i-1], dp_end_at_ring[i-3]-booths[i-2]-booths[i-1]))-booths[i];
    }

    cout << max(dp_end_at_ring[n-1], dp_end_at_ding[n-1])<<endl;
}

int main(){
    vector<int> booths = {1,9,9,-1,9,9,1,9,9};
    solve(booths.size(), booths);
}
