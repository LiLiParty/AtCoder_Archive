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
    int N,D;
    cin >> N >> D;
    vector<vector<int>> data(N, vector<int>(D));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            cin >> data.at(i).at(j);
        }
    }
    int ans=0; //答え
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            ll sum = 0; //ルートの中身
            for (int k = 0; k < D; k++) {
                sum += pow(data[i][k] - data[j][k],2);
            }
            ld x = sqrtl(ld(sum));
            if(floor(x)==x) ans++;
        }
    }
    cout << ans;
}
