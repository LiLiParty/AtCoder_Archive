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
    ll N;
    cin >> N;
    ll ans = powmod(10,N) - 2*powmod(9,N) + powmod(8,N);
    ans %= mod;
    ans = (ans+mod)%mod;
    cout << ans << endl;
}
