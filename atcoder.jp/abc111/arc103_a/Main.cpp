#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9+7

//素因数分解 ex:{{2, 2}, {5, 1}, {101, 1}}
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        // その結果を push
        res.push_back({a, ex});
    }
    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}
//組み合わせ：nCr
ll Comb(ll n, ll r){
        ll num = 1;
        for(ll i = 1; i <= r; i++){
            num = num * (n - i + 1) / i;
        }
        return num;
    }
//約数全列挙(昇順)
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> V_e(100001,pair<ll,ll>(0,0));
    vector<pair<ll,ll>> V_o(100001,pair<ll,ll>(0,0));
    
    for(ll i=0; i<n; i++){
        ll v;
        cin >> v;
        if(i%2 == 0){
            V_e.at(v).first ++;
            V_e.at(v).second = v;
        }else{
            V_o.at(v).first ++;
            V_o.at(v).second = v;
        }
    }
    sort(V_e.begin(),V_e.end());
    reverse(V_e.begin(),V_e.end());
    sort(V_o.begin(),V_o.end());
    reverse(V_o.begin(),V_o.end());

    ll ans=100001;

    if( V_e.at(0).second == V_o.at(0).second){
        ll A1 = V_e.at(0).first;
        ll A2 = V_e.at(1).first;
        ll B1 = V_o.at(0).first;
        ll B2 = V_o.at(1).first;
        ans = min(n-A1-B2,n-A2-B1);
    }else{
        ll A1 = V_e.at(0).first;
        ll B1 = V_o.at(0).first;
        ans = n-A1-B1;
    }

    cout << ans << endl;
}