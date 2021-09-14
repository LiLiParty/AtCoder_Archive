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
    ll N;
    string S;
    cin >> N >> S;

    ll ans=0;
    for(ll i=0; i<N; i++){
        ll c1=0;
        ll c2=0;
        if(S.at(i) == 'R'){
            for(ll k=i+1; k<N; k++){
                if(S.at(k) == 'G') c1++;
                if(S.at(k) == 'B') c2++;
                if( S.at(i) != S.at(k) ){
                    if(2*k-i <= N-1){
                        if(S.at(k) != S.at(2*k-i) && S.at(i) != S.at(2*k-i)) ans--;
                    }
                }
            }
            ans += c1*c2;
        }else if(S.at(i) == 'G'){
            for(ll k=i+1; k<N; k++){
                if(S.at(k) == 'R') c1++;
                if(S.at(k) == 'B') c2++;
                if( S.at(i) != S.at(k) ){
                    if(2*k-i <= N-1){
                        if(S.at(k) != S.at(2*k-i) && S.at(i) != S.at(2*k-i)) ans--;
                    }
                }
            }
            ans += c1*c2;
        }else if(S.at(i) == 'B'){
            for(ll k=i+1; k<N; k++){
                if(S.at(k) == 'R') c1++;
                if(S.at(k) == 'G') c2++;
                if( S.at(i) != S.at(k) ){
                    if(2*k-i <= N-1){
                        if(S.at(k) != S.at(2*k-i) && S.at(i) != S.at(2*k-i)) ans--;
                    }
                }
            }
            ans += c1*c2;
        }
    }

    cout << ans << endl;
}