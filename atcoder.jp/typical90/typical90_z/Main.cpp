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

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N+1);
    for(int i=0; i<N-1; i++){
        int A,B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    queue<int> q;
    vector<int> seen(N+1,-1);
    seen[1] = 2;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int nv: G[v]){
            if(seen[nv] != -1) continue;
            q.push(nv);
            seen[nv] = seen[v] + 1;
        }
    }
    ll count = 0;
    vector<int> ans,ans2;
    for(int i=1; i<=N; i++){
        if(seen[i]%2 == 0){
            ans.push_back(i);
        }else{
            ans2.push_back(i);
        }
    }
    if(ans.size() >= N/2){
        for(int i=0; i<N/2; i++){
            cout << ans[i] << " ";
        }
    }else{
        for(int i=0; i<N/2; i++){
            cout << ans2[i] << " ";
        }
    }

}
