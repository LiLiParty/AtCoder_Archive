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


int main(){
    ll x,y;
    cin >> x >> y;

    ll ans = 2000000000;
    for(ll b1=0; b1<2; b1++){
        for(ll b2=0; b2<2; b2++){
            ll ex = x;
            if(b1) ex *= -1;
            ex += abs( abs(x) - abs(y) );
            if(b2) ex *= -1;

            if( ex == y){
                ans = min(ans, b1+b2+abs( abs(x) - abs(y) ) );
            }
            
        }
    }

    cout << ans << endl;
}