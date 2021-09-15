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

ll digit_sum(ll N){
    if(N<10) return N;
    return digit_sum(N/10) + N%10;
}

int main() {
    ll N,K;
    cin >> N >> K;
    vector<bool> vis(100001,false);
    ll z = N;
    ll count = 0;
    while(1){
        if(vis[z]) break;
        vis[z] = true;
        z = (z + digit_sum(z))%100000LL;
        K--;
        if(K==0){
            cout << z << endl;
            return 0;
        }
    }
    vector<ll> cycle;
    ll T = 0;
    vector<bool> vis2(100001,false);
    while(1){
        if(vis2[z]) break;
        T++;
        cycle.push_back(z);
        vis2[z] = true;
        z = (z + digit_sum(z))%100000LL;
    }
    cout << cycle[K%T] << endl;

}
