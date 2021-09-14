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

    vector<vector<int>> G(N+1);
    for(int i=0; i<M; i++){
        int A,B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    for(int i=1; i<=N; i++){
        queue<int> q;
        vector<int> lev(N+1,-1);
        int count=0;
        lev[i] = 0;
        q.push(i);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto nv: G[v]){
                if(lev[nv]==-1){
                    q.push(nv);
                    lev[nv] = lev[v] + 1;
                    if(lev[nv]==2) count++;
                }
            }
        }
        cout << count << endl;
    }
}
