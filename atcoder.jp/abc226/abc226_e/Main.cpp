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

int Size = 0;
int nord_num = 0;

void dfs(int v, vector<vector<int>> &G, vector<int> &seen){
    seen[v] = 1;
    Size++;
    nord_num += (int)G[v].size();
    for(int nv: G[v]){
        if(seen[nv] == -1){
            dfs(nv,G,seen);
        }
    }
}

int main(){
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N+1);
    vector<int> seen(N+1,-1);

    for(int i=0; i<M; i++){
        int U,V; cin >> U >> V;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    ll ans = 1;

    for(int v=1; v<=N; v++){
        if(seen[v] == -1){
            Size = 0;
            nord_num = 0;
            dfs(v,G,seen);
            nord_num /= 2;
            if(Size != nord_num){
                cout << 0 << endl;
                return 0;
            }else{
                ans *= 2;
                ans %= mod;
            }
        }
    }

    cout << ans << endl;
}
