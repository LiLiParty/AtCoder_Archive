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
    int N; cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    vector<vector<ll>> dp(N+1,vector<ll>(10,0));
    dp[0][A[0]]= 1;
    int Fb = A[0]; 
    int Gb = A[0];
    for(int i=1; i<=N-1; i++){
        for(int k=0; k<10; k++){
            int F = (k + A[i])%10;
            int G = (k * A[i])%10;
            dp[i][F] += dp[i-1][k];
            dp[i][G] += dp[i-1][k];
            dp[i][F] %= mod;
            dp[i][G] %= mod;
        }
        /*
        int FF = (Fb+A[i])%10;
        int GF = (Gb+A[i])%10;
        int FG = (Fb*A[i])%10;
        int GG = (Gb*A[i])%10;

        dp[i][FF] += dp[i-1][Fb];
        dp[i][GF] += dp[i-1][Gb];
        dp[i][FG] += dp[i-1][Fb];
        dp[i][GG] += dp[i-1][Gb];

        dp[i][FF] %= mod;
        dp[i][GF] %= mod;
        dp[i][FG] %= mod;
        dp[i][GF] %= mod;
        */
    }

    for(int i=0; i<10; i++){
        cout << dp[N-1][i] << endl;
    }
}
