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
#include <cassert>
using namespace std;
#define pp pair<ll,ll>
#define ll long long
#define ld long double
#define mk make_pair
#define INF32 2147483647 
#define INF64 9223372036854775807
#define rep(i, n) for(int i = 0; i < n; i++)
const ll MOD = 1000000007;//10^9+7
//const ll mod = 998244353;

ll ans = 0;

void dfs(ll v, vector<vector<ll>> &G, vector<ll> &seen, vector<ll> &time){
    ans += time[v];
    seen[v] = 1;
    for(ll nv: G[v]){
        if(seen[nv] == -1){
            dfs(nv,G,seen,time);
            //cout << "次: " << nv << endl;
        }
    }
}

int main() {
    int N; cin >> N;

    vector<ll> time(N+1,0);
    vector<vector<ll>> G(N+1);
    vector<ll> seen(N+1,-1);

    for(int i=1; i<=N; i++){
        ll T,K; cin >> T >> K;
        time[i] = T;
        for(int j=0; j<K; j++){
            ll A; cin >> A;
            G[i].push_back(A);
        }
    }

    dfs(N,G,seen,time);

    cout << ans << endl;


}
