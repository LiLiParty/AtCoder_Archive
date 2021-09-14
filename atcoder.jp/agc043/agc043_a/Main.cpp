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


ll H,W;
ll ans = INF64;


void dfs(ll count,ll i,ll j,vector<string> &S){
    if(S.at(i).at(j) == '#') count++;
    if(i==H-1 && j==W-1){
        ans = min(count,ans);
    }
    if( i+1 < H){
        dfs(count,i+1,j,S);
    }
    if( j+1 < W){
        dfs(count,i,j+1,S);
    }
}



int main(){
    cin >> H >> W;
    vector<string> S(H);
    for(ll i=0; i<H; i++){
        cin >> S.at(i);
    }

    vector<vector<ll>> dp(H,vector<ll>(W,INF64));
    if(S.at(0).at(0) == '#'){
        dp.at(0).at(0) = 1;
    }else{
        dp.at(0).at(0) = 0;
    }

    for(ll i=0; i<H; i++){
        for(ll j=0; j<W; j++){
            if(i+1<H){
                ll a=0;
                if(S.at(i).at(j) == '.' && S.at(i+1).at(j) == '#'){
                    a=1;
                }
                dp.at(i+1).at(j)
                = min( dp.at(i+1).at(j), dp.at(i).at(j) + a);
            }
            if(j+1<W){
                ll a=0;
                if(S.at(i).at(j) == '.' && S.at(i).at(j+1) == '#'){
                    a=1;
                }
                dp.at(i).at(j+1)
                = min( dp.at(i).at(j+1), dp.at(i).at(j) + a);
            }
        }
    }

    cout << dp.at(H-1).at(W-1) << endl;
}