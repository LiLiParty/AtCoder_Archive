#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
const ll mod=1000000007;

ll powmod(ll x, ll y){
    ll res=1;
    for(ll i=0; i<y; i++){
        res = res*x%mod;
    }
    return res;
}

int main(){
    ll S;
    cin >> S;
    vector<ll> dp(2001,1);
    dp.at(1) = 0;
    dp.at(2) = 0;

    for(int i=3; i<=2000; i++){
        for( int j=3; j<=2000-i; j++){
            //if(i+j==7) cout << "i: " << i << " j: " << j << endl;
            dp.at(i+j) += dp.at(i)%mod;

            dp.at(i+j) %= mod;
        }
    }

    cout << dp.at(S) << endl;
}
