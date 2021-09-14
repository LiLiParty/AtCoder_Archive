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
    ll N,K;
    cin >> N >> K;

    vector<ll> A(N+1);
    vector<ll> LR(N);
    vector<ll> L(N);

    for(ll i=0; i<N; i++){
        cin >> A.at(i);
    }

    for(ll i=0; i<N; i++){
        for(ll j=i+1; j<N; j++){
            if(A.at(i) > A.at(j)) LR.at(i)++;
        }
        for(ll j=0; j<N; j++){
            if(A.at(i) > A.at(j)) L.at(i)++;
        }
    }

    ll ans=0;
    for(ll i=0; i<N; i++){
        ans += K*LR.at(i) % mod;
        ans +=  ( ( K*(K-1)/2 )%mod * L.at(i)%mod ) %mod; 
        //if(K*(K-1)/2 * L.at(i) < 0) cout <<"Overflow!!" <<endl;
        ans%=mod;
    }

    cout << ans << endl;

}