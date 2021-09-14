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

ll sumA,sumB;

void dfs(int v, vector<vector<ll>> &G, vector<int> &seen, vector<ll> &A, vector<ll> &B){
    seen[v] = 1;
    sumA += A[v];
    sumB += B[v];
    for(int nv: G[v]){
        if(seen[nv] != -1) continue;
        dfs(nv,G,seen,A,B);
    }
}

int main() {
    int N,M;
    cin >> N >> M;
    
    vector<ll> A(N+1),B(N+1);
    for(int i=1; i<=N; i++) cin >> A[i]; 
    for(int i=1; i<=N; i++) cin >> B[i];

    vector<vector<ll>> G(N+1);
    for(int i=0; i<M; i++){
        int c,d;cin >> c >> d;
        G[c].push_back(d);
        G[d].push_back(c);
    }

    vector<int> seen(N+1,-1);
    for(int v=1; v<=N; v++){
        if(seen[v] != -1) continue;
        sumA=0;
        sumB=0;
        dfs(v,G,seen,A,B);
        //cout << "sumA: " << sumA << "sumB: " << sumB << endl;
        if(sumA != sumB){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}