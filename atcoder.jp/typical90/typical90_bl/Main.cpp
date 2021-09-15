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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    ll ans = 0;
    vector<ll> ANS;

    vector<ll> diff(N-1);
    for(int i=0; i<N-1; i++){
        diff[i] = A[i+1] - A[i];
        ans += abs(diff[i]);
    }

    for(int i=0; i<Q; i++){
        ll L,R,V; cin >> L >> R >> V;
        L--; R--;
        if(L != 0){
            ans -= abs(diff[L-1]);
            diff[L-1] += V;
            ans += abs(diff[L-1]);
        }
        if(R != N-1){
            ans -= abs(diff[R]);
            diff[R] -= V;
            ans += abs(diff[R]);
        }
        
        ANS.push_back(ans);
    }

    for(ll a: ANS){
        cout << a << endl;
    }
}
