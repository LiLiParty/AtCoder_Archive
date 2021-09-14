#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pp pair<ll,ll>
#define ll long long
#define ld long double
#define mk make_pair
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
#define rep(i, n) for(int i = 0; i < n; i++)
const ll MOD = 1000000007;//10^9+7
//const ll mod = 998244353;

//桁数マクロ
int GetDigit(int num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}
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
        res.push_back(mk(a, ex));
    }
    // 最後に残った数について
    if (N != 1) res.push_back(mk(N, 1));
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
            P.push_back( i );
        }
    }
    return P;
}
//順列数 k!
ll facctorial(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}
//組み合わせ：nCr
ll Comb(ll n, ll r){
    ll num = 1;
    for(ll i = 1; i <= r; i++){
        num = num * (n - i + 1) / i;
    }
    return num;
}
//組み合わせmod COMinit処理後COM mod(p) 1<=k<=n<=1e7
const int MAX = 10000001;
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
long long COM(int n, int k, long long p){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % p) % p;
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
ll modPow(long long a, long long n,  long p) {
    if (n == 0) return 1; // 0乗にも対応する場合
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}
//UnionFind
struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};
//dijkstra G:mk(to,weight)
void dijkstra(vector<vector<pp>> &G, int s, vector<ll> &dis){
    int N = G.size();
    dis.resize(N, INF64);
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    dis[s] = 0;
    pq.push(mk(s,dis[s]));
    while(!pq.empty()){
        pp p = pq.top();
        int v = p.first;
        int nd = p.second;
        pq.pop();
        if(dis[v] < nd) continue;
        for(auto g: G[v]){
            int nv = g.first;
            int w = g.second;
            if( dis[nv] > dis[v] + w){
                dis[nv] = dis[v] + w;
                pq.push(mk(nv,dis[nv]));
            }
        }
    }
}

bool judge(ll p, ll K, vector<int> A){
    ll k=0;
    for(int i=0; i<A.size(); i++){
        if(A[i] > p){
            k += ceil(A[i]/p);
        }
    }
    if(k <= K) return true;
    else return false;
}

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }

    ll R = 1e9;
    ll L = 1;

    while(L<=R){
        ll M = (R+L)/2;
        bool flagR,flagL,flagM;
        flagR = judge(R,K,A);
        flagL = judge(L,K,A);
        flagM = judge(M,K,A);
        if(flagL){
            cout << L << endl;
            return 0;
        }else if(flagM){
            R = M;
            continue;
        }else if(!flagM){
            L = M+1;
            continue;
        }
    }
}