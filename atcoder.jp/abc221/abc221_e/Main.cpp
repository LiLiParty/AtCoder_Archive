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
#define INF32 2147483647 
#define INF64 9223372036854775807
#define rep(i, n) for(int i = 0; i < n; i++)
const ll MOD = 1000000007;//10^9+7
const ll mod = 998244353;

//a^n mod(p) modpow
ll modPow(long long a, long long n, long p)
{
    if (n == 0)
        return 1; // 0乗にも対応する場合
    if (n == 1)
        return a % p;
    if (n % 2 == 1)
        return (a * modPow(a, n - 1, p)) % p;
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}

int comp(vector<int> &A){
    std::map<int,int> mem;
    for(auto p: A) mem[p] = 0;
    int sz = 0;
    for(auto &p: mem) p.second = sz++;
    for(auto &p: A) p = mem[p];
    return sz;
}

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    //https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

//BIT Binary Indexed Tree
//数列a(a[0],a[1],…,a[n-1])についての区間和と点更新を扱う
//区間和,点更新,二分探索はO(log{n})で動作する
class BIT
{
public:
    //データの長さ
    ll n;
    //データの格納先
    vector<ll> a;
    //コンストラクタ
    BIT(ll n) : n(n), a(n + 1, 0) {}

    //a[i]にxを加算する
    void add(ll i, ll x)
    {
        i++;
        if (i == 0)
            return;
        for (ll k = i; k <= n; k += (k & -k))
        {
            a[k] += x;
        }
    }

    //a[i]+a[i+1]+…+a[j]を求める
    ll sum(ll i, ll j)
    {
        return sum_sub(j) - sum_sub(i - 1);
    }

    //a[0]+a[1]+…+a[i]を求める
    ll sum_sub(ll i)
    {
        i++;
        ll s = 0;
        if (i == 0)
            return s;
        for (ll k = i; k > 0; k -= (k & -k))
        {
            s += a[k];
        }
        return s;
    }

    //a[0]+a[1]+…+a[i]>=xとなる最小のiを求める(任意のkでa[k]>=0が必要)
    ll lower_bound(ll x)
    {
        if (x <= 0)
        {
            //xが0以下の場合は該当するものなし→0を返す
            return 0;
        }
        else
        {
            ll i = 0;
            ll r = 1;
            //最大としてありうる区間の長さを取得する
            //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while (r < n)
                r = r << 1;
            //区間の長さは調べるごとに半分になる
            for (int len = r; len > 0; len = len >> 1)
            {
                //その区間を採用する場合
                if (i + len < n && a[i + len] < x)
                {
                    x -= a[i + len];
                    i += len;
                }
            }
            return i;
        }
    }
    //https://qiita.com/DaikiSuyama/items/7295f5160a51684554a7
};

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    int n = comp(A);
    BIT bita(n);
    
    ll ans = 0;

    for(int j=0; j<N; j++){
        ans += modPow(2,j-1,mod) * (bita.sum_sub(A[j])%mod);
        ans %= mod;
        bita.add(A[j],  modinv( modPow(2,j,mod), mod)     );
    }

    cout << ans << endl;
}
