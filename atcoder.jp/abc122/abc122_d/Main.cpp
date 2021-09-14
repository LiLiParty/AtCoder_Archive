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

ll dp[101][5][5][5];

int main() {
    int N; cin >> N;

    //dp[文字数n][１文字目][２文字目][3文字目]
    dp[0][0][0][0] = 1;

    for(int n=0; n<N; n++){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                for(int k=0; k<5; k++){
                    for(int l=1; l<5; l++){
                        if (i == 1 && j == 2 && l == 3) continue;
                        if (i == 1 && k == 2 && l == 3) continue;
                        if (j == 1 && k == 2 && l == 3) continue;
                        if (j == 2 && k == 1 && l == 3) continue;
                        if (j == 1 && k == 3 && l == 2) continue;
                        dp[n+1][j][k][l] += dp[n][i][j][k];
                        dp[n+1][j][k][l] %= MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            for(int k=1; k<5; k++){
                ans += dp[N][i][j][k];
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;
}
