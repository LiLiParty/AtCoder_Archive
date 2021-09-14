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
    int H,W,M;
    cin >> H >> W >> M;

    set<pair<int,int>> bomb_set;
    vector<pair<int,int>> num_line(H+1);
    vector<pair<int,int>> num_raw(W+1);
    for(int i=0; i<H+1; i++){
        num_line[i].first = 0;
        num_line[i].second = i;
    }
    for(int i=0; i<W+1; i++){
        num_raw[i].first = 0;
        num_raw[i].second = i;
    }
    num_line[0].first = -1;
    num_raw[0].first = -1;

    for(int i=0; i<M; i++){
        int h,w;
        cin >> h >> w;
        bomb_set.insert(mk(h,w));
        num_line[h].first++;
        num_raw[w].first++;
    }

    sort(num_line.begin(),num_line.end());
    sort(num_raw.begin(),num_raw.end());
    reverse(num_line.begin(),num_line.end());
    reverse(num_raw.begin(),num_raw.end());

    int max_line = num_line[0].first;
    int max_raw = num_raw[0].first;

    vector<int> cand_line;
    vector<int> cand_raw;

    for(int i=0; i<H; i++){
        if(max_line == num_line[i].first){
            cand_line.push_back(num_line[i].second);
        }
    }
    for(int i=0; i<W; i++){
        if(max_raw == num_raw[i].first){
            cand_raw.push_back(num_raw[i].second);
        }
    }

    ll ans = max_line + max_raw;
    for(auto cl: cand_line){
        for(auto cr: cand_raw){
            if(!bomb_set.count({cl,cr})){
                cout << ans << endl;
                return 0;
            }
        }
    }

    cout << ans - 1 << endl;


}
