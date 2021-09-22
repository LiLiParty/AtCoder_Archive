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

//UnionFind
struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); 
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int H,W,Q; 
int Hash(int h, int w){
    return h*W + w;
}

int dh[] = {1,-1,0,0};
int dw[] = {0,0,1,-1};

int main() {
    cin >> H >> W >> Q;
    UnionFind Union(H*W + W + 1);
    set<int> Set;
    vector<string> ans;
    for(int i=0; i<Q; i++){
        int t; cin >> t;
        if(t == 1){
            int r,c; cin >> r >> c;
            int red = Hash(r,c);
            Set.insert(red);
            for(int i=0; i<4; i++){
                int h = r + dh[i];
                int w = c + dw[i];
                if( h < 1 || h > H || w < 1 || w > W) continue;
                if(Set.count(Hash(h,w))){
                    Union.merge(red,Hash(h,w));
                }
            }
        }else{
            int ra,ca,rb,cb; cin >> ra >> ca >> rb >> cb;
            if(Union.issame(Hash(ra,ca),Hash(rb,cb)) && Set.count(Hash(ra,ca)) && Set.count(Hash(rb,cb))){
                ans.push_back("Yes");
            }else{
                ans.push_back("No");
            }
        }
    }
    for(string a: ans){
        cout << a << endl;
    }
}
