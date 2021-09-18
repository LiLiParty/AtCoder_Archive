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

int ctoi(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

int main() {
    int N,X,Y; cin >> N >> X >> Y;
    vector<vector<int>> dp(X+1,vector<int>(Y+1,1000000000));
    dp[0][0] = 0;

    for(int i=0; i<N; i++){
        int A,B; cin >> A >> B;
        for(int i=X; i>=0; i--){
            for(int j=Y; j>=0; j--){
                if(dp[i][j] >= 0){
                    dp[min(i+A, X)][min(j+B,Y)] = min(dp[i][j] + 1, dp[min(i+A, X)][min(j+B,Y)]);
                    //if(min(i+A, X)==X && min(j+B,Y)==Y) cout << "a" << endl;
                }
            }
        }
    }
    if(dp[X][Y] == 1000000000){
        cout << -1 << endl;
    }else{
        cout << dp[X][Y] << endl;
    }
}
