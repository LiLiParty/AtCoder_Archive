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

ll Comb(ll n, ll r){
        ll num = 1;
        for(ll i = 1; i <= r; i++){
            num = num * (n - i + 1) / i;
        }
        return num;
    }


int main(){
    ll N,P;
    cin >> N >> P;
    ll odd=0;
    for(ll i=0; i<N; i++){
        ll a;
        cin >> a;
        if( a%2 == 1) odd++;
    }

    ll comb_odd=0;
    if(P==0){
        for(ll i=0; i<=odd; i+=2){
            comb_odd += Comb(odd,i);
        }
        ll ans = comb_odd * pow(2,N-odd);
        cout << ans << endl;
        return 0;
    }else{
        for(ll i=1; i<=odd; i+=2){
            comb_odd += Comb(odd,i);
        }
        ll ans = comb_odd * pow(2,N-odd);
        cout << ans << endl;
        return 0;
    }

    
}