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
    int H,W;
    cin >> H >> W;
    vector<vector<int>> field(H,vector<int>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> field[i][j];
        }
    }
    ll ans = -1;
    for(int bit=1; bit<(1<<H); bit++){
        map<ll,ll> M;
        vector<int> Raw; //選んだ行
        for(int i=0; i<H; i++){
            if(bit & (1<<i)){
                Raw.push_back(i);
            }
        }
        for(int j=0; j<W; j++){
            bool flag = true;
            for(int i=1; i<Raw.size(); i++){
                if(field[Raw[i-1]][j] != field[Raw[i]][j]) flag = false;
            }
            if(flag) M[ field[Raw[0]][j] ] += Raw.size();
        }
        ll c_ans = -1;
        for(auto m: M){
            c_ans = max(c_ans, m.second);
            //if(m.second == c_ans) cout << m.first << endl;
        }
        ans = max(c_ans,ans);
    }
    cout << ans << endl;

}
