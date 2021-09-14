#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
const ll mod   = 1000000007;//10^9+7
//const ll mod_1 = 998244353;

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
//約数全列挙(昇順)//計算量：O(√n)
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
    ll N,K;
    cin >> N >> K;
    vector<ll> sum_L(N+1);
    vector<ll> sum_H(N+1);
    ll sumL=0;
    ll sumH=0;
    for(ll i=0; i<N+1; i++){
        sumH += N-i;
        sum_H.at(i) = sumH; 
        sumL += i;
        sum_L.at(i) = sumL; 
    }
    ll ans=0;
    for(ll i=K-1; i<N+1; i++){
        ll plus = sum_H.at(i) - sum_L.at(i) + 1LL;
        plus %= mod;
        ans += plus;
        ans %= mod;
    }
    cout << ans << endl;
}