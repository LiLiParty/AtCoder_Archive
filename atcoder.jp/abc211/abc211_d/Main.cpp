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


int main() {
    int N,M;
    cin >> N >> M;

    vector<vector<ll>> G(N+1);
    vector<ll> dist(N+1,-1);
    vector<ll> count(N+1,0);

    for(int i=0; i<M; i++){
        int A,B;
        cin >> A >> B;
        G[A].push_back(B); 
        G[B].push_back(A); 
    }

    queue<int> q;
    q.push(1);
    count[1] = 1;
    dist[1] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto nv: G[v]){
            if(dist[nv] == dist[v]+1){
                count[nv] += count[v];
                count[nv] %= MOD;
            }else if(dist[nv] == -1){
                count[nv] += count[v];
                count[nv] %= MOD;
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }
    }

    cout << count[N] << endl;

}
