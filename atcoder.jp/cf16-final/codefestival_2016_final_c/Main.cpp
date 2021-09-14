#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
const ll MOD = 1000000007;//10^9+7


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
//素数列挙
vector<int> Eratosthenes( const int N )
{
    std::vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    std::vector<int> P;
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}
//組み合わせ：nCr
ll Comb(ll n, ll r){
    ll num = 1;
    for(ll i = 1; i <= r; i++){
        num = num * (n - i + 1) / i;
    }
    return num;
}
//組み合わせmod COMinit処理後COM 1<=k<=n<=1e7
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
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
//a^n mod(p)
ll modPow(long long a, long long n, long long p) {
    if (n == 0) return 1; // 0乗にも対応する場合
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}


void dfs(ll Ki,vector<vector<ll>> &K, vector<vector<ll>> &G, vector<ll> &seen_k, vector<ll> &seen_L){
    seen_k.at(Ki) = 1;
    
    for(ll Li: K.at(Ki)){
        if(seen_L.at(Li) != -1) continue;
        seen_L.at(Li) = 1;
        
        for(ll Kl: G.at(Li)){
            if(seen_k.at(Kl) != -1) continue;
            dfs(Kl,K,G,seen_k,seen_L);
        }
        
    }
}



int main(){
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> K(N+1);
    vector<vector<ll>> G(M+1);
    

    for(ll i=1; i<=N; i++){
        ll k;
        cin >> k;
        for(ll j=0; j<k; j++){
            ll L;
            cin >> L;
            G.at(L).push_back(i);
            K.at(i).push_back(L);
        }
    }

    vector<ll> seen_k(1000001,-1);
    vector<ll> seen_L(1000001,-1);

    dfs(1,K,G,seen_k,seen_L);

    bool flag = true;
    for(ll i=1; i<=N; i++){
        if(seen_k.at(i) == -1){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }



}