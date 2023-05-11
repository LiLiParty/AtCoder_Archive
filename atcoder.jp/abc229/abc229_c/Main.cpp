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
#include <cassert>
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

ll get_digit(ll num){
    ll digit = 0;
    while(num != 0){
        num /= 10;
        digit++;
    }
    
    return digit;
}



int main() {
    ll N,W;
    cin >> N >> W;

    vector<pair<ll,ll>> C(N);
    for(int i=0; i<N; i++){
        cin >> C[i].first >> C[i].second;
    }

    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());

    ll w = 0;
    ll ans = 0;
    for(int i=0; i<N; i++){
        if(w + C[i].second <= W){
            w += C[i].second;
            ans += C[i].first * C[i].second; 
        }else{
            ans += C[i].first * (W-w);
            break;
        }
    }

    cout << ans << endl;

}
