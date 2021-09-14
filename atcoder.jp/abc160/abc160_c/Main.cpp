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
    int K,N; //Kは湖の周、Nが軒数
    cin >> K >> N;
    vector<int> H(N); //北端からの距離配列
    for(int i=0;i<N;i++){
        cin >> H.at(i);
    }
    int maxdis = -1;
    for(int i=1;i<N;i++){
        maxdis = max( H.at(i)-H.at(i-1) , maxdis);
    }
    maxdis = max( H.at(0)+K-H.at(N-1) , maxdis);
    cout << K-maxdis;
}