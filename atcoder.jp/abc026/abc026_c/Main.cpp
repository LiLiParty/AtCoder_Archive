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


int dfs(int v, vector<vector<int>> &G){
    int money = 1;
    int max_m = 0;
    int min_m = INF32;
    for(int nv: G[v]){
        int money_nv = dfs(nv,G);
        max_m = max(max_m,money_nv);
        min_m = min(min_m,money_nv);
    }
    if(min_m == INF32) min_m=0;
    return max_m + min_m + 1;
}



int main() {
    int N;
    cin >> N;

    vector<vector<int>> G(N+1);
    for(int i=2; i<=N; i++){
        int B;
        cin >> B;
        G[B].push_back(i);
    }

    cout << dfs(1,G) << endl;
}
