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
#define ALL(a)  (a).begin(),(a).end()
const ll MOD = 1000000007;//10^9+7
const ll mod = 998244353;

int main() {
    int N,Q; cin >> N >> Q;

    vector<int> Oya(N+1);
    for(int i=1; i<=N; i++) Oya[i] = i;

    vector<int> G(N+1,-1); //有向グラフ

    vector<vector<int>> Ans;
    for(int i=0; i<Q; i++){
        int q; cin >> q;
        if(q == 1){
            int x,y; cin >> x >> y;
            G[x] = y;
            Oya[y] = x;
        }else if(q == 2){
            int x,y; cin >> x >> y;
            G[x] = -1;
            Oya[y] = y;
        }else{
            int x; cin >> x;
            int V = x;
            while(V != Oya[V]){
                V = Oya[V];
            }
            vector<int> ans;
            while(1){
                ans.push_back(V);
                if(G[V] == -1){
                    break;
                }else{
                    V = G[V];
                }
            }
            cout << ans.size() << " ";
            for(int a: ans){
                cout << a << " ";
            }
            cout << '\n';
        }
    }

    /*
    int size = Ans.size();
    for(int i=0; i<size; i++){
        int s = Ans[i].size();
        for(int j=0; i<s; j++){
            cout << Ans[i][j] << " ";
        }
        cout << endl;
    }
    */
}
