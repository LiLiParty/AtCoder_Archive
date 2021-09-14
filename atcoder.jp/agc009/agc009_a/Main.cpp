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
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);

    for(ll i=0; i<N; i++){
        cin >> A.at(i) >> B.at(i);
    }

    //ll count=0;
    ll A_plus=0;

    for(ll i=N-1; i>=0; i--){
        ll A_n = A.at(i) + A_plus;
        if(A_n % B.at(i) != 0){
            A_plus += B.at(i) * ( A_n/B.at(i) + 1 ) - A_n;
        }
    }

    cout << A_plus << endl;
}