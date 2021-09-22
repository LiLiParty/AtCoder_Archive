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
    ll N; cin >> N;
    vector<tuple<ll,ll,ll>> Job(N);
    for(int i=0; i<N; i++){
        ll D,C,S; cin >> D >> C >> S;
        Job[i] = make_tuple(D,C,S);
    }
    sort(Job.begin(),Job.end());

    vector<vector<ll>> dp(N,vector<ll>(5001,0));
    //dp[何番目までの仕事を見る][仕事時間] = 報酬
    for(int i=0; i<N; i++){
        for(int j=0; j<=5000; j++){
            ll D = get<0>(Job[i]);
            ll C = get<1>(Job[i]);
            ll S = get<2>(Job[i]);
            //i番目の仕事をやらない場合

            if(i != 0) dp[i][j] = max(dp[i-1][j], dp[i][j]);
            //i番目の仕事をやる場合
            
            if( j + C <= D){
                if(i!=0) dp[i][j+C] = max( dp[i-1][j] + S, dp[i][j+C]);
                else dp[i][j+C] = S;
            }
            
        }
    }

    ll ans = -1;
    for(int j=0; j<=5000; j++){
        ans = max(dp[N-1][j],ans);
    }
    cout << ans << endl;
}
