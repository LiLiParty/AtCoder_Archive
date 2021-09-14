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
//const ll mod = 998244353;

int C;

void dfs(int v, vector<int> &seen, vector<vector<int>> &G){
    seen[v] = 1;
    for(auto nv: G[v]){
        if(seen[nv]==-1) dfs(nv,seen,G);
    }
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    if(N==1){
        cout << 0 << endl;
        return 0;
    }
    ll n = N/2;
    vector<ll> F;
    vector<ll> B;
    for(int i=0; i<n; i++){
        F.push_back(A[i]);
        B.push_back(A[N-1-i]);
    }

    vector<vector<int>> G(2e5+1);
    vector<int> seen(2e5+1,-1);
    set<int> S;
    for(int i=0; i<n; i++){
        G[F[i]].push_back(B[i]);
        G[B[i]].push_back(F[i]);
        S.insert(F[i]);
        S.insert(B[i]);
    }
    int type = 0;
    for(auto s: S){
        type++;
    }
    C = 0;
    for(int i=0; i<n; i++){
        if(seen[F[i]] == -1){
            C++;
            dfs(F[i],seen,G);
        }
    }

    cout << type - C << endl;

}
