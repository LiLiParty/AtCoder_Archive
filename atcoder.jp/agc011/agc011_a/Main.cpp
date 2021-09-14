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
    ll N,C,K;
    cin >> N >> C >> K;

    vector<ll> T(N);
    for(ll i=0; i<N; i++){
        cin >> T.at(i);
    }
    sort(T.begin(),T.end());

    ll ans=0;
    ll i=0;
    while(i<=N-1){
        if(i==N-1){
            ans++;
            break;
        }
        ll bus = T.at(i)+K;
        //cout << bus << "分に出発" << endl; 
        ll p=1;
        //cout << T.at(i) << "分" << endl;
        while(T.at(i+1) <= bus){
            //cout << T.at(i+1) << "分" << endl;
            i++;
            p++;
            if(i+1 >= N) break;
            if(p+1>C) break;
        }
        if(p%C==0){
            ans += p/C;
        }else{
            ans += p/C + 1;
        }
        i++;
    }

    cout << ans << endl;
}