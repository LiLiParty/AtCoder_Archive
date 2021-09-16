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

int dh[] = {1,-1,0,0};
int dw[] = {0,0,1,-1};
int ans = -1;
int H,W;

void backtrack(int h, int w, vector<string> &field, vector<vector<int>> &seen){
    
    for(int i=0; i<4; i++){
        int nh = h + dh[i];
        int nw = w + dw[i];
        if(nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if( field[nh][nw]=='#' ) continue;
        if(seen[nh][nw] == 1){
            ans = max(seen[h][w],ans);
            continue;
        }
        if(seen[nh][nw] != -1) continue;
        seen[nh][nw] = seen[h][w] + 1;
        backtrack(nh,nw,field,seen);
    }
    seen[h][w] = -1; 
}

int main() {
    cin >> H >> W;
    vector<string> field(H);
    for(int i=0; i<H; i++) cin >> field[i];

    vector<vector<int>> init(H,vector<int>(W,-1));
    vector<vector<int>> seen;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(field[i][j] != '#'){
                seen = init;
                seen[i][j] = 1;
                backtrack(i,j,field,seen);
            }
        }
    }
    if(ans <= 3) cout << -1 << endl;
    else cout << ans << endl;

}
