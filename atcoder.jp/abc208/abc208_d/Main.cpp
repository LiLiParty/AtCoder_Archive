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
    int N,M;
    cin >> N >> M;

    vector<vector<ll>> dp(N+1,vector<ll>(N+1,INF32));
    for(int i=1; i<=N; i++){
        dp[i][i] = 0;
    }
    for(int i=1; i<=M; i++){
        int A,B,C;
        cin >> A >> B >> C;
        dp[A][B] = C;
    }
    
    ll ans=0;
    for(int k=0; k<N; k++){
        for(int s=1; s<=N; s++){
            for(int t=1; t<=N; t++){
                dp[s][t] = min(dp[s][t],dp[s][k+1] + dp[k+1][t]);
                if(dp[s][t] < INF32 && dp[s][t] != 0){
                    //cout << "("<< s << " " << t << " " << k << " )" << dp[s][t] << endl;
                    ans+= dp[s][t];
                }
            }
        }
    }

    cout << ans << endl;
}
