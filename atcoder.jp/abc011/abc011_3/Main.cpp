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
    int N,Ng1,Ng2,Ng3;
    cin >> N >> Ng1 >> Ng2 >> Ng3;

    vector<vector<bool>> dp(101,vector<bool> (N+1,false));

    if(N != Ng1 && N != Ng2 && N != Ng3){
        dp[0][N] = true;
    }else{
        cout << "NO" << endl;
        return 0;
    }

    for(int i=1; i<=100; i++){
        for(int n=0; n<=N; n++){
            if(dp[i-1][n]){
                if(n-1>=0 && n-1!=Ng1 && n-1!=Ng2 && n-1!=Ng3) dp[i][n-1] = true;
                if(n-2>=0 && n-2!=Ng1 && n-2!=Ng2 && n-2!=Ng3) dp[i][n-2] = true;
                if(n-3>=0 && n-3!=Ng1 && n-3!=Ng2 && n-3!=Ng3) dp[i][n-3] = true;
            }
        }
    }

    for(int i=0; i<=100; i++){
        if(dp[i][0]){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
