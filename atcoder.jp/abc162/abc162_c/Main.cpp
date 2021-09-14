#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1000000007;

//↓combination(ll a, ll b) でaCr計算。
//------------------------------------------------------------------------------------------
ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}
ll kj(ll x){
    ll s = 1;
    for(ll i = 1; i <= x; i++){
        s = s * i % MOD;
    }
    return s;
}
ll combination(ll a, ll b){
    if(a == 0 && b == 0) return 1;
    if(a < b || a < 0) return 0;
    return (kj(a) * mpow(kj(b), MOD-2) % MOD) * mpow(kj(a-b), MOD-2) % MOD;
}
//---------------------------------------------------------------------------------------------
//↑combination(ll a, ll b) でaCr計算。

int main(){
    int K;
    cin >> K;
    ll sum=0;
    for(int i=1; i <= K; i++){
        for(int j=1; j <= K; j++){
            for(int k=1; k <= K; k++){
            sum += gcd(gcd(i,j),k);
            }
        }
    }
    cout << sum;
}
