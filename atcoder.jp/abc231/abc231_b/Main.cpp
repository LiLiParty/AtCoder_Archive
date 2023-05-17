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
    int N;
    cin >> N;

    map<string, int> S;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        if(S.count(s)){
            S[s] = S[s] + 1;
        }else{
            S[s] = 1;
        }
    }

    int max_s = -1;
    string ans;
    for(auto s: S){
        if(max_s < s.second){
            max_s = s.second;
            ans = s.first;
        }
    }

    cout << ans << endl;
}
