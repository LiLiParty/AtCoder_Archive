#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
const ll mod=1000000007;//10^9+7

ll divisor_num(ll a){ //aの約数の個数,O(√a)
    ll ans = 1;
    for (ll i = 2; i <= sqrt(a); i++) {
        ll cnt = 0;
        while (a % i == 0) {
            cnt++;
            a /= i;
        }
        ans *= (cnt + 1);
        if (a == 1) break;
    }
    if (a != 1) ans *= 2;
    return ans;
}


int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> dp(N+3,0);
    dp.at(0) = 1;
    for(ll i=0; i<M; i++){
        ll a;
        cin >> a;
        dp.at(a) = -1;
    }

    for(ll i=0; i<N+1; i++){
        if(dp.at(i) == -1) continue;
        if( dp.at(i+1) != -1){
            dp.at(i+1) += dp.at(i);
            dp.at(i+1) %= mod;
        }
        if( dp.at(i+2) != -1){
            dp.at(i+2) += dp.at(i);
            dp.at(i+2) %= mod;
        }
    }
    

    cout << dp.at(N) << endl;
}