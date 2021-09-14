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


int main(){
    ll B,C;
    cin >> B >> C;

    ll ans;

    if(B>0){
        ans = B+(C-2)/2 - (-B)-(-1)*(C-1)/2 + 1;
        //cout << ans << endl;
        //cout << (C-2)/2 << " " << (-1)*(C-1)/2 << endl;
        if(B - C/2 > 0){
            ans -= (B-C/2) - (-B+(C-1)/2) - 1;
        }
    }else if(B<0){
        ans = -B + (C-1)/2 - B - (-1)*C/2 + 1;
        if(B - (C-1)/2 > 0){
            ans -= (-B-(C-1)/2) - (B+(C-2)/2) - 1;
        }
    }else{
        ans = C/2 + (C-1)/2 + 1;
    }
    
    cout << ans << endl;
}