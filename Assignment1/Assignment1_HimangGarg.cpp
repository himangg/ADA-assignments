#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;


ll numberOfSmallerElements(vector<ll> v, ll target){
    for(int i=0;i<v.size();i++){
        if(v[i]>target){
            return i;
        }
    }
    return v.size();
}

ll findKthSmallestElement(vector<ll> v1,vector<ll> v2,vector<ll> v3, ll k, ll high, ll low){
    ll mid=0;
    if(high+low>=0) {
        mid = (high + low) / 2;
    }
    else{
        mid = (high+low-1) / 2;
    }

    ll c1,c2,c3;
    c1 = numberOfSmallerElements(v1,mid);
    c2 = numberOfSmallerElements(v2,mid);
    c3 = numberOfSmallerElements(v3,mid);

    if(low>=high){
        return low;
    }

    if (c1+c2+c3<k){
        return findKthSmallestElement(v1,v2,v3,k,high,mid+1);
    }
    else{
        return findKthSmallestElement(v1,v2,v3,k,mid,low);
    }

}

int main() {
    vector<ll> v1={1,2,3};
    vector<ll> v2={1,2,3};
    vector<ll> v3={1,2,3};
    for(int k=-10;k<=15;k++) {
        ll ans = findKthSmallestElement(v1, v2, v3, k, 3, 1);
        cout<<ans<<endl;
    }
    return 0;
}
