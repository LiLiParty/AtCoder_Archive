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

void dfs_color(int v, vector<vector<int>> &G, vector<int> &Color){
    for(auto nv: G[v]){
        if(Color[nv]==0){
            Color[nv] = Color[v]*-1;
            dfs_color(nv,G,Color);
        }
    }
}

int main() {
    int N,Q;
    cin >> N >> Q;
    
    vector<vector<int>> G(N+1);
    vector<int> Color(N+1,0);
    for(int i=0; i<N-1; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    Color[1] = 1;
    dfs_color(1,G,Color);
    /*
    cout << "Debug" << endl;
    cout << Color[1] << " " << Color[2] << " " << Color[3] << endl;
    */

    for(int i=0; i<Q; i++){
        int c,d;
        cin >> c >> d;
        if(Color[c] == Color[d]){
            cout << "Town" << endl;
        }else{
            cout << "Road" << endl;
        }
    }



}
